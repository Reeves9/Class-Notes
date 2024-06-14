# implimenting a simple hash function
import hashlib
def simple_hash(string):
    hash_value = 0
    for char in string:
        hash_value = (hash_value * 31 + ord(char)) % (2 ** 32)
    return hash_value
def sha1_hash(string):
    sha1 = hashlib.sha1()
    sha1.update(string.encode('utf-8'))
    return sha1.hexdigest()


string = input("enter a string")
print("hash is ",sha1_hash(string)) 