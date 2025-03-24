import pandas as pd
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.pipeline import Pipeline

# Load training data
x_train = pd.read_csv("data_readinglevel/x_train.csv")
y_train = pd.read_csv("data_readinglevel/y_train.csv")
y = (y_train["Coarse Label"] == "Key Stage 4-5").astype(int)

# Load test data
x_test = pd.read_csv("data_readinglevel/x_test.csv")

# Use best-found parameters from random search
best_min_df = 4
best_max_df = 0.9105
best_ngram = (1, 2)
best_C = 0.3228

# Set up pipeline with best parameters
pipe = Pipeline([
    ("tfidf", TfidfVectorizer(lowercase=True, stop_words=None,
                              min_df=best_min_df, max_df=best_max_df,
                              ngram_range=best_ngram)),
    ("lr", LogisticRegression(max_iter=3000, solver='lbfgs', C=best_C))
])

# Train on full training data
pipe.fit(x_train["text"], y)

# Predict on test set (probabilities)
test_preds = pipe.predict_proba(x_test["text"])[:,1]

# Save predictions in leaderboard format
np.savetxt("yproba1_test.txt", test_preds, fmt="%.6f")

print("✅ Final leaderboard predictions saved as yproba1_test.txt")
