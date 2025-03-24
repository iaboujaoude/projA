import pandas as pd
import numpy as np
from sklearn.model_selection import StratifiedKFold
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import roc_auc_score

# Function to load npz embeddings
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

# Load BERT embeddings
x_bert = load_arr_from_npz(f"{data_dir}/x_train_BERT_embeddings.npz")

# Grab numeric features from x_train.csv (like char_count, sentence_count, etc.)
numeric_cols = x_train_tab.columns[4:]  # assuming text, title, author, genre first
x_numeric = x_train_tab[numeric_cols].values

# Concatenate BERT + numeric features
X_full = np.hstack((x_bert, x_numeric))

cv = StratifiedKFold(n_splits=3, shuffle=True, random_state=42)

# Grid search for MLP on combined features
mlp_results = []
for hidden_size in [(64,), (128,), (64, 32), (128, 64)]:
    for alpha_val in [0.0001, 0.001, 0.01]:
        for lr_init in [0.001, 0.01]:
            scores = []
            for tr_i, val_i in cv.split(X_full, y):
                mlp = MLPClassifier(hidden_layer_sizes=hidden_size, alpha=alpha_val, 
                                    learning_rate_init=lr_init, max_iter=500, random_state=42)
                mlp.fit(X_full[tr_i], y.iloc[tr_i])
                preds = mlp.predict_proba(X_full[val_i])[:,1]
                score = roc_auc_score(y.iloc[val_i], preds)
                scores.append(score)
            avg_auc = np.mean(scores)
            print(f"mlp auc: {avg_auc:.4f} hidden: {hidden_size} alpha: {alpha_val} lr: {lr_init}")
            mlp_results.append((hidden_size, alpha_val, lr_init, avg_auc))

# You can save results if you want:
# results_df = pd.DataFrame(mlp_results, columns=["hidden_size", "alpha", "lr_init", "auc"])
# results_df.to_csv("p2_mlp_results.csv", index=False)