import pandas as pd
import numpy as np
from sklearn.neural_network import MLPClassifier

def load_arr_from_npz(npz_path):
    npz_file_obj = np.load(npz_path)
    arr = npz_file_obj.f.arr_0.copy()
    npz_file_obj.close()
    return arr

# Load training data
data_dir = 'data_readinglevel'
x_train_tab = pd.read_csv(f"{data_dir}/x_train.csv")
y_train = pd.read_csv(f"{data_dir}/y_train.csv")
y = (y_train["Coarse Label"] == "Key Stage 4-5").astype(int)

# Load BERT embeddings and numeric features
x_bert_train = load_arr_from_npz(f"{data_dir}/x_train_BERT_embeddings.npz")
numeric_cols = x_train_tab.columns[4:]
x_numeric_train = x_train_tab[numeric_cols].values
X_train_full = np.hstack((x_bert_train, x_numeric_train))

# Load test data
x_test_tab = pd.read_csv(f"{data_dir}/x_test.csv")
x_bert_test = load_arr_from_npz(f"{data_dir}/x_test_BERT_embeddings.npz")
x_numeric_test = x_test_tab[numeric_cols].values
X_test_full = np.hstack((x_bert_test, x_numeric_test))

# Fit final MLP with best parameters
best_mlp = MLPClassifier(
    hidden_layer_sizes=(128, 64),
    alpha=0.01,
    learning_rate_init=0.01,
    max_iter=1000,
    random_state=42
)
best_mlp.fit(X_train_full, y)

# Predict probabilities on test set
test_proba = best_mlp.predict_proba(X_test_full)[:, 1]

# Save as single-column txt file (no headers, no indexes)
np.savetxt("yproba1_test.txt", test_proba, fmt="%.6f")

print("✅ Exported leaderboard file: yproba2_test.txt (single column of float probabilities)")
