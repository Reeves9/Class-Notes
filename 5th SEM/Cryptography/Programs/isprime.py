num = int(input("Enter a number"))
counter = 0
for i in range(1,num+1):
    if num%i==0:
        counter = counter + 1

# print(counter)
if counter == 2:
    print("prime")
else:
    print("not prime")
