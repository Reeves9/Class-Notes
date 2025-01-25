import random 

#define the alphabet
alphabet = "abcdefghijklmnopqrstuvwxyz"

#create a random permutation of the alphabet
random.seed(42)
cipher_alphabet = list(alphabet)
random.shuffle(cipher_alphabet)
cipher_alphabet = ''.join(cipher_alphabet)

print("alphabet: ",alphabet)
print("shuffled alphabet: ",cipher_alphabet)

#create a dictionary for the encryption and decription mapping
encryption_mapping = {}
decryption_mapping = {}

for i in range(len(alphabet)):
    encryption_mapping[alphabet[i]] = cipher_alphabet[i]
    decryption_mapping[cipher_alphabet[i]] = alphabet[i]

print("encryption mapping: ",encryption_mapping)
print("decryption mapping: ",decryption_mapping)

#encrypt a message using the mapping
def encrypt(message):
    encrypted_message = ""
    for char in message:
        if char.isalpha():
            encrypted_message += encryption_mapping[char.lower()]
        else:
            encrypted_message += char
    return encrypted_message

#decrypt a message using the mapping
def decrypt(message):
    decrypted_message = ""
    for char in message:
        if char.isalpha():
            decrypted_message += decryption_mapping[char.lower()]
        else:
            decrypted_message += char
    return decrypted_message

message = input("enter message: ")
choice = input("encrypt or decrypt: ")
if choice == "encrypt":
    print(encrypt(message))
elif choice == "decrypt":
    print(decrypt(message))
else:
    print("invalid choice")