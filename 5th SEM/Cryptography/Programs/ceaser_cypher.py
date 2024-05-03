def caesar_cipher(text, shift, mode):
    result = ""
    for char in text:
        if char.isalpha():
            if mode == "encrypt":
                result += chr((ord(char) + shift - 65) % 26 + 65)
            else:  
                result += chr((ord(char) - shift - 65) % 26 + 65)
        else:
            result += char
    return result

plain_text = input("enter plain text")
key = input("enter key")
choice = input("Enter 'encrypt' or 'decrypt' ")
if choice == "encrypt":
    encrypted_text = caesar_cipher(plain_text, int(key), "encrypt")
    print(f"Encrypted text: {encrypted_text}")
else:
    decrypted_text = caesar_cipher(plain_text, int(key), "decrypt")
    print(f"Decrypted text: {decrypted_text}")

