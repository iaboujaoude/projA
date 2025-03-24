import pandas as pd
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.pipeline import Pipeline
from sklearn.model_selection import RandomizedSearchCV, GroupKFold
from sklearn.metrics import roc_auc_score, make_scorer
from scipy.stats import uniform, randint

# Load training data
x_train = pd.read_csv("data_readinglevel/x_train.csv")
y_train = pd.read_csv("data_readinglevel/y_train.csv")
y = (y_train["Coarse Label"] == "Key Stage 4-5").astype(int)

# Group by author to simulate test conditions
groups = y_train["author"]

# Pipeline
pipe = Pipeline([
    ("tfidf", TfidfVectorizer(lowercase=True, stop_words=None)),
    ("lr", LogisticRegression(max_iter=3000, solver='lbfgs'))
])

# Hyperparam search space
param_dist = {
    "tfidf__min_df": randint(1, 6),                  # between 1 and 5
    "tfidf__max_df": uniform(0.7, 0.25),             # from 0.7 to 0.95
    "tfidf__ngram_range": [(1,1), (1,2)],
    "lr__C": uniform(0.01, 9.99)                     # from 0.01 to ~10
}

# Random search with GroupKFold
cv = GroupKFold(n_splits=3)
random_search = RandomizedSearchCV(
    pipe,
    param_distributions=param_dist,
    n_iter=25,                          # you can increase for more thorough search
    scoring=make_scorer(roc_auc_score, needs_proba=True),
    cv=cv.split(x_train["text"], y, groups=groups),
    verbose=2,
    n_jobs=-1,
    random_state=42
)

# Run search
random_search.fit(x_train["text"], y)
print("✅ Best params found:", random_search.best_params_)
print("✅ Best CV AUC:", random_search.best_score_)
