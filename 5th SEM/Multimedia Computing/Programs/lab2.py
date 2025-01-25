from PIL import Image
import numpy as np

# open an image and show it's properties
image = Image.open("Routine.jpg")
print(image.size)
print(image.format)
print(image.mode)

# to convert image to an array
nparray = np.array(image)
print(nparray.shape)
print(type(nparray))
print(nparray)

# from nparray to image
pilImage = Image.fromarray(nparray)
print(pilImage.mode)
print(pilImage.size)

# create random np.array and convert it to image
x = np.random.randint(0, 256, (512, 512, 3), dtype=np.uint8)
print(x)
print(type(x))
print(x.shape)
img = Image.fromarray(x)
img.save("sample.jpg")