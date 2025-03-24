import pandas as pd
import numpy as np
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.pipeline import Pipeline
from sklearn.model_selection import StratifiedKFold
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, roc_auc_score

# Load training data
x_train = pd.read_csv("data_readinglevel/x_train.csv")
y_train = pd.read_csv("data_readinglevel/y_train.csv")
y = (y_train["Coarse Label"] == "Key Stage 4-5").astype(int)

# best params from search
best_min_df = 1
best_max_df = 0.85
best_ngram = (1,2)
best_C = 10

pipe = Pipeline([
    ("vect", CountVectorizer(lowercase=True, stop_words='english',
                             min_df=best_min_df, max_df=best_max_df, 
                             ngram_range=best_ngram, binary=False)),
    ("lr", LogisticRegression(max_iter=2000, solver='lbfgs', C=best_C))
])

cv = StratifiedKFold(n_splits=3, shuffle=True, random_state=42)

all_y_true = []
all_y_pred = []

# Do CV and collect predictions for confusion matrix
for train_i, val_i in cv.split(x_train["text"], y):
    Xtr, Xval = x_train.iloc[train_i]["text"], x_train.iloc[val_i]["text"]
    ytr, yval = y.iloc[train_i], y.iloc[val_i]
    pipe.fit(Xtr, ytr)
    preds_bin = pipe.predict(Xval)  # hard predictions
    all_y_true.extend(yval.tolist())
    all_y_pred.extend(preds_bin.tolist())

# Generate confusion matrix
cm = confusion_matrix(all_y_true, all_y_pred)
disp = ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=["Key Stage 2-3","Key Stage 4-5"])
disp.plot(cmap="Blues")
disp.ax_.set_title("Confusion Matrix (LogReg with best BoW params)")
import matplotlib.pyplot as plt
plt.show()
