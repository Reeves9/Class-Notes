def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a,a)

num1,num2 = map(int,input("enter two numbers: ").split())
hcf = gcd(num1,num2)
if hcf == 1:
    print(f"{num1} and {num2} are relatively prime")
else:
    print(f"{num1} and {num2} are not relatively prime")

