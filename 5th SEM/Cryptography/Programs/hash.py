import hashlib

#this impliments the sha1 encryption method
def sha1_hash(string):
    sha1 = hashlib.sha1()
    sha1.update(string.encode('utf-8'))
    return sha1.hexdigest()

#this impliments the sha256 encryption method
def sha256_hash(string):
    sha256 = hashlib.sha256()
    sha256.update(string.encode('utf-8'))
    return sha256.hexdigest()
#this impliments the md5 encryption method

def md5_hash(string):
    md5 = hashlib.md5()
    md5.update(string.encode('utf-8'))
    return md5.hexdigest()

string = input("enter a string: ")

sha1 = sha1_hash(string)
sha256 = sha256_hash(string)
md5 = md5_hash(string)

print("sha1 hash is     ",sha1,"bits=",len(sha1)*4) 
print("sha256 hash is   ",sha256,"bits=",len(sha256)*4) 
print("md5 hash is      ",md5,"bits=",len(md5)*4) 


