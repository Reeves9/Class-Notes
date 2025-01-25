import numpy as np
from math import gcd
from sympy import Matrix

# Function to generate key matrix for encryption
def generate_key_matrix(key):
    # Convert key string to uppercase
    key = key.upper()
    # Compute the size of the matrix
    n = int(np.sqrt(len(key)))
    # Create an empty matrix
    key_matrix = np.zeros((n, n), dtype=int)
    # Fill the matrix with the numeric values of the letters
    for i in range(n):
        for j in range(n):
            key_matrix[i][j] = ord(key[i * n + j]) - 65  # ASCII 'A' is 65
    return key_matrix

# Function to encrypt plaintext
def hill_cipher_encrypt(plaintext, key):
    plaintext = plaintext.upper().replace(" ", "")
    n = int(np.sqrt(len(key)))
    key_matrix = generate_key_matrix(key)
    
    # Check if the length of plaintext is a multiple of n
    if len(plaintext) % n != 0:
        # Pad with 'X' if necessary
        plaintext += 'X' * (n - len(plaintext) % n)
    
    ciphertext = ""
    for i in range(0, len(plaintext), n):
        # Generate vector from plaintext segment
        vector = np.zeros((n, 1), dtype=int)
        for j in range(n):
            vector[j][0] = ord(plaintext[i + j]) - 65
        
        # Perform matrix multiplication
        result = np.dot(key_matrix, vector) % 26
        
        # Convert result back to letters
        for j in range(n):
            ciphertext += chr(result[j][0] + 65)
    
    return ciphertext

# Function to decrypt ciphertext
def hill_cipher_decrypt(ciphertext, key):
    ciphertext = ciphertext.upper().replace(" ", "")
    n = int(np.sqrt(len(key)))
    key_matrix = generate_key_matrix(key)
    
    # Compute the modular inverse of the key matrix
    determinant = int(round(Matrix(key_matrix).det()))
    determinant_inverse = None
    for i in range(26):
        if (determinant * i) % 26 == 1:
            determinant_inverse = i
            break
    
    # Find the adjugate of the key matrix
    key_matrix_adj = Matrix(key_matrix).adjugate().tolist()
    
    # Multiply the adjugate by the determinant inverse, then mod 26
    key_matrix_inv = [[(determinant_inverse * key_matrix_adj[i][j]) % 26 for j in range(n)] for i in range(n)]
    
    # Decrypt the ciphertext
    plaintext = ""
    for i in range(0, len(ciphertext), n):
        # Generate vector from ciphertext segment
        vector = np.zeros((n, 1), dtype=int)
        for j in range(n):
            vector[j][0] = ord(ciphertext[i + j]) - 65
        
        # Perform matrix multiplication with the inverse key matrix
        result = np.dot(key_matrix_inv, vector) % 26
        
        # Convert result back to letters
        for j in range(n):
            plaintext += chr(result[j][0] + 65)
    
    return plaintext

# Example usage:
if __name__ == "__main__":
    key = "GYBNQKURP"
    plaintext = "HELLO WORLD"
    
    # Encrypting the plaintext
    encrypted_text = hill_cipher_encrypt(plaintext, key)
    print("Encrypted:", encrypted_text)
    
    # Decrypting the ciphertext
    decrypted_text = hill_cipher_decrypt(encrypted_text, key)
    print("Decrypted:", decrypted_text)
