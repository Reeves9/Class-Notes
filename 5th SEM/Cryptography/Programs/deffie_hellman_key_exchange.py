import random

# Alice generates public and private keys
p = 23  # A prime number p is taken
g = 9  # A primitive root for p, g is taken

a = random.randint(1, p-1)  # Alice chooses a random private value a
x = int(pow(g, a, p))  # Alice's public value x

# Bob generates public and private keys
b = random.randint(1, p-1)  # Bob chooses a random private value b
y = int(pow(g, b, p))  # Bob's public value y

# Alice and Bob exchange public values

# Alice computes secret key
ka = int(pow(y, a, p))

# Bob computes secret key
kb = int(pow(x, b, p))

print(f"Alice's private key: {a}")
print(f"Alice's public key: {x}")
print(f"Bob's private key: {b}") 
print(f"Bob's public key: {y}")
print(f"Secret key on Alice's side: {ka}")
print(f"Secret key on Bob's side: {kb}")
