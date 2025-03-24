import pandas as pd
import numpy as np
from sklearn.model_selection import StratifiedKFold
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.pipeline import Pipeline
import matplotlib.pyplot as plt

x_train = pd.read_csv("data_readinglevel/x_train.csv")
y_train = pd.read_csv("data_readinglevel/y_train.csv")
y = (y_train["Coarse Label"] == "Key Stage 4-5").astype(int)

# set up grid search by hand
min_dfs = [1, 3, 5]
max_dfs = [0.7, 0.85, 0.95]
ngrams = [(1,1), (1,2)]
cs = [0.01, 0.1, 1, 10, 100]

results = []

cv = StratifiedKFold(n_splits=3, shuffle=True, random_state=1)

for md in min_dfs:
    for mxd in max_dfs:
        for ng in ngrams:
            for cval in cs:
                print("trying:", md, mxd, ng, cval)
                pipe = Pipeline([
                    ("vect", CountVectorizer(lowercase=True, stop_words='english', min_df=md, max_df=mxd, ngram_range=ng, binary=False)),
                    ("lr", LogisticRegression(max_iter=2000, solver='lbfgs', C=cval))
                ])
                scores = []
                for train_i, val_i in cv.split(x_train["text"], y):
                    Xtr, Xval = x_train.iloc[train_i]["text"], x_train.iloc[val_i]["text"]
                    ytr, yval = y.iloc[train_i], y.iloc[val_i]
                    pipe.fit(Xtr, ytr)
                    val_pred = pipe.predict_proba(Xval)[:,1]
                    from sklearn.metrics import roc_auc_score
                    score = roc_auc_score(yval, val_pred)
                    scores.append(score)
                avg_score = np.mean(scores)
                print("auc:", avg_score)
                results.append((md, mxd, ng, cval, avg_score))

# convert to df and sort
res_df = pd.DataFrame(results, columns=["min_df","max_df","ngram","C","auc"])
res_df = res_df.sort_values("auc", ascending=False)
print(res_df.head())

# quick plot
plt.figure(figsize=(10,5))
plt.scatter(res_df["C"], res_df["auc"])
plt.xscale("log")
plt.xlabel("C")
plt.ylabel("AUC")
plt.title("Grid Search Results (best params on top)")
plt.show()
