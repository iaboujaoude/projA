import pandas as pd
import numpy as np
from sklearn.model_selection import StratifiedKFold
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.pipeline import Pipeline
import matplotlib.pyplot as plt
from sklearn.metrics import roc_auc_score

x_train = pd.read_csv("data_readinglevel/x_train.csv")
y_train = pd.read_csv("data_readinglevel/y_train.csv")
y = (y_train["Coarse Label"] == "Key Stage 4-5").astype(int)

cv = StratifiedKFold(n_splits=3, shuffle=True, random_state=42)

# random forest grid search
rf_results = []
for depth in [10, 20, 30]:
    for n_est in [100, 200, 300]:
        rf_pipe = Pipeline([
            ("tfidf", TfidfVectorizer(lowercase=True, stop_words='english', min_df=3, max_df=0.85, ngram_range=(1,2))),
            ("rf", RandomForestClassifier(n_estimators=n_est, max_depth=depth, random_state=42))
        ])
        scores = []
        for tr_i, val_i in cv.split(x_train["text"], y):
            rf_pipe.fit(x_train.iloc[tr_i]["text"], y.iloc[tr_i])
            preds = rf_pipe.predict_proba(x_train.iloc[val_i]["text"])[:,1]
            scores.append(roc_auc_score(y.iloc[val_i], preds))
        avg_rf = np.mean(scores)
        print("rf auc:", avg_rf, "depth:", depth, "n_est:", n_est)
        rf_results.append((depth, n_est, avg_rf))

# mlp grid search
mlp_results = []
for size in [(32,), (64,), (128,)]:
    for alpha_val in [0.0001, 0.001, 0.01]:
        mlp_pipe = Pipeline([
            ("tfidf", TfidfVectorizer(lowercase=True, stop_words='english', min_df=3, max_df=0.85, ngram_range=(1,2))),
            ("mlp", MLPClassifier(hidden_layer_sizes=size, alpha=alpha_val, max_iter=500, random_state=42))
        ])
        scores = []
        for tr_i, val_i in cv.split(x_train["text"], y):
            mlp_pipe.fit(x_train.iloc[tr_i]["text"], y.iloc[tr_i])
            preds = mlp_pipe.predict_proba(x_train.iloc[val_i]["text"])[:,1]
            scores.append(roc_auc_score(y.iloc[val_i], preds))
        avg_mlp = np.mean(scores)
        print("mlp auc:", avg_mlp, "hidden:", size, "alpha:", alpha_val)
        mlp_results.append((size, alpha_val, avg_mlp))
