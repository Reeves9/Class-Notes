def vigenere_cipher_encrypt(plain_text, key):
    # Convert both plain_text and key to uppercase
    plain_text = plain_text.upper()
    key = key.upper()
    
    encrypted_text = []
    key_index = 0
    
    for char in plain_text:
        if char.isalpha():  # Process only alphabetic characters
            # Shift character by key_index in the alphabet
            shifted = chr(((ord(char) - 65 + ord(key[key_index % len(key)]) - 65) % 26) + 65)
            encrypted_text.append(shifted)
            key_index += 1
        else:
            encrypted_text.append(char)  # Non-alphabetic characters remain unchanged
    
    return ''.join(encrypted_text)


def vigenere_cipher_decrypt(cipher_text, key):
    # Convert both cipher_text and key to uppercase
    cipher_text = cipher_text.upper()
    key = key.upper()
    
    decrypted_text = []
    key_index = 0
    
    for char in cipher_text:
        if char.isalpha():  # Process only alphabetic characters
            # Shift character backwards by key_index in the alphabet
            shifted = chr(((ord(char) - 65 - (ord(key[key_index % len(key)]) - 65)) % 26) + 65)
            decrypted_text.append(shifted)
            key_index += 1
        else:
            decrypted_text.append(char)  # Non-alphabetic characters remain unchanged
    
    return ''.join(decrypted_text)


# Example usage:
plain_text = "Hello, World!"
key = "KEY"

encrypted_text = vigenere_cipher_encrypt(plain_text, key)
print("Encrypted:", encrypted_text)

decrypted_text = vigenere_cipher_decrypt(encrypted_text, key)
print("Decrypted:", decrypted_text)
