# Project A Folder Explanation

This folder has all my code and outputs for CS 135 Project A (Spring 2025).

### Files:

- **load_train_data.py**  
  Just prints 8 random training examples and their labels, for a quick check.

- **load_BERT_embeddings.py**  
  Demo to show how the BERT embeddings are loaded and what they look like.

- **bow_grid_search.py**  
  Manual grid search for Problem 1 with CountVectorizer and Logistic Regression.  
  Tests different min_df, max_df, ngrams, and C values, and plots results.

- **bow_random_search.py**  
  Randomized search with TFIDFVectorizer and Logistic Regression.  
  Uses GroupKFold by author to avoid overfitting. Found best params.

- **bow_confusion_matrix.py**  
  After finding the best hyperparams for BoW model, this script makes a confusion matrix plot.

- **problem1_to_txt.py**  
  Takes the best model from the random search and uses it to predict probabilities for the test set.  
  Saves those predictions in `yproba1_test.txt` for leaderboard submission.

- **yproba1_test.txt**  
  The final prediction probabilities I submitted to the leaderboard.

- **p2_search.py**  
  Early grid search for Problem 2. Tries out Random Forests and MLP classifiers with different settings.  
  Prints out AUROC scores for each setup.

- **Figure_1.png**  
  Plot from grid search results for visual reference.

---

### Data location:
All CSV and BERT embeddings go in `data_readinglevel/` folder:
- `x_train.csv`, `y_train.csv`, `x_test.csv`
- `x_train_BERT_embeddings.npz`, `x_test_BERT_embeddings.npz`

---

### What’s done:
- ✅ Problem 1 hyperparameter search
- ✅ Confusion matrix for Problem 1
- ✅ Leaderboard submission for Problem 1  
- ✅ Started Problem 2 with grid search for RF and MLP.

---

### What’s next:
- Finalize Problem 2 models (maybe try stacking or other classifiers).
- Export predictions for Problem 2 once done.

---

*Let me know if you need anything else.*
