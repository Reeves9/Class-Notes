def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a,a)

num1,num2 = map(int,input("enter numbers to find gcd of: ").split())
ans = gcd(num1,num2)
print(f"GCD is {ans}")
