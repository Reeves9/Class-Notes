#implimenting extended euclidean algorithm
def gcd_extended(a, b):
    if a == 0:
        return b, 0, 1
    else:
        gcd, x, y = gcd_extended(b % a, a)
        return gcd, y - (b // a) * x, x

num1,num2 = map(int,input("enter numbers to find gcd of: ").split())
gcd = gcd_extended(num1,num2)
print(f"gcd of {num1} and {num2} is {gcd[0]}")