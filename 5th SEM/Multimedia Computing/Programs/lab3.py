#wap to read lenna.png convert it to jpg and tiff. display size of the image
from PIL import Image
import os

# Read the Lenna image
img = Image.open("Lenna.png")

# Convert the image to JPEG and TIFF formats
img.save("Lenna.jpg", "JPEG")
img.save("Lenna.tiff", "TIFF")

# Display the size of the image
jpg_size = os.path.getsize("Lenna.jpg")
tiff_size = os.path.getsize("Lenna.tiff")
png_size = os.path.getsize("Lenna.png")
print("png size: {} bytes".format(png_size))
print("jpeg size: {} bytes".format(jpg_size))
print("tiff size: {} bytes".format(tiff_size))   

# Convert into greyscale
img_grey = img.convert('L')
img_grey.save("Lenna_grey.jpg", "JPEG")

# Resize the Image
width,height = img.size
img_resized = img.resize((int(width/2),int(height/2)))
img_resized.save("Lenna_resized.jpg", "JPEG")

# Rotate the Image
img_rotated = img.rotate(90)
img_rotated.save("Lenna_rotated.jpg", "JPEG")

