import os
import pandas as pd
import numpy as np
import re
from app import normalize
train_spam_folder = '/Users/baljinnyamdayan/Downloads/spam_data/train/spam'
train_ham_folder = '/Users/baljinnyamdayan/Downloads/spam_data/train/ham'
dev_spam_folder = '/Users/baljinnyamdayan/Downloads/spam_data/dev/spam'
dev_ham_folder = '/Users/baljinnyamdayan/Downloads/spam_data/dev/ham'

def create_word_counts_dataframe(folder_path):
    email_text = []

    for filename in os.listdir(folder_path):
        try:
            with open(os.path.join(folder_path, filename), 'r', encoding='utf-8') as f:
                email_text.append(f.read())
        except UnicodeDecodeError:
            print(f"Error: could not read file {filename} due to encoding issue")

    from sklearn.feature_extraction.text import CountVectorizer

    vectorizer = CountVectorizer()
    X = vectorizer.fit_transform(email_text)

    df = pd.DataFrame(X.toarray(), columns=vectorizer.get_feature_names_out())

    return df

def calculate_word_probabilities(spam_df, ham_df, a=1):
    total_spam_words = spam_df.sum().sum()
    total_ham_words = ham_df.sum().sum()

    num_spam_emails = spam_df.shape[0]
    num_ham_emails = ham_df.shape[0]

    p_spam = num_spam_emails / (num_spam_emails + num_ham_emails)
    p_ham = num_ham_emails / (num_spam_emails + num_ham_emails)

    spam_word_probs = {}
    for word in spam_df.columns:
        count = spam_df[word].sum()
        prob = (count + a) / (total_spam_words + a * len(spam_df.columns))
        spam_word_probs[word] = prob

    ham_word_probs = {}
    for word in ham_df.columns:
        count = ham_df[word].sum()
        prob = (count + a) / (total_ham_words + a * len(ham_df.columns))
        ham_word_probs[word] = prob

    return p_spam, p_ham, spam_word_probs, ham_word_probs

train_spam_df = create_word_counts_dataframe(train_spam_folder)
train_ham_df = create_word_counts_dataframe(train_ham_folder)

dev_spam_df = create_word_counts_dataframe(dev_spam_folder)
dev_ham_df = create_word_counts_dataframe(dev_ham_folder)

p_spam, p_ham, spam_word_probs, ham_word_probs = calculate_word_probabilities(train_spam_df, train_ham_df)

def calculate_email_probabilities(email_df, p_spam, p_ham, spam_word_probs, ham_word_probs):
    email_probs = []
    for i in range(email_df.shape[0]):
        email_prob = {}
        email_prob['spam'] = p_spam
        email_prob['ham'] = p_ham
        for word in email_df.columns:
            if email_df.iloc[i][word] > 0:
                if word in spam_word_probs:
                    email_prob['spam'] *= spam_word_probs[word]
                if word in ham_word_probs:
                    email_prob['ham'] *= ham_word_probs[word]
                    
        email_probs.append(email_prob)

    email_probs_df = pd.DataFrame(email_probs)

    return email_probs_df

dev_spam_probs_df = calculate_email_probabilities(dev_spam_df, p_spam, p_ham, spam_word_probs, ham_word_probs)
dev_ham_probs_df = calculate_email_probabilities(dev_ham_df, p_spam, p_ham, spam_word_probs, ham_word_probs)

def calculate_accuracy(df):
    num_correct = df[(df['spam'] > df['ham']) & (df['spam'] > 0.5)].shape[0] + df[(df['ham'] > df['spam']) & (df['ham'] > 0.5)].shape[0]

    num_incorrect = df[(df['spam'] > df['ham']) & (df['spam'] <= 0.5)].shape[0] + df[(df['ham'] > df['spam']) & (df['ham'] <= 0.5)].shape[0]

    accuracy = num_correct / (num_correct + num_incorrect)

    return accuracy

dev_spam_accuracy = calculate_accuracy(dev_spam_probs_df)
dev_ham_accuracy = calculate_accuracy(dev_ham_probs_df)
dev_spam_accuracy,dev_ham_accuracy = normalize(dev_spam_accuracy,dev_ham_accuracy)


print(f"Accuracy on dev_spam: {dev_spam_accuracy}")
print(f"Accuracy on dev_ham: {dev_ham_accuracy}")

