import numpy as np
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB

emails = [
    ('Hey, how are you?', 'regular'),
    ('Buy now, limited offer!', 'spam'),
    ('Meeting tomorrow at 10 AM', 'regular'),
    ('Get rich quick!', 'spam'),
    ('Congrats! you have won this prize!','spam')
    ('You have won 2 bonus prizes. Reply to claim it','spam')
]

X = [email[0] for email in emails]
y = [email[1] for email in emails]

vectorizer = CountVectorizer()
X_vectorized = vectorizer.fit_transform(X)

naive_bayes = MultinomialNB()
naive_bayes.fit(X_vectorized, y)

while True:
    email = input("Enter an email (or 'quit' to exit): ")
    if email.lower() == 'quit':
        break
    email_vectorized = vectorizer.transform([email])
    prediction = naive_bayes.predict(email_vectorized)
    print("Predicted label:", prediction[0])
