from PIL import Image
import numpy as np
import matplotlib.pyplot as plt

grey_image = Image.open("Lenna_grey.jpg")
grey_array = np.array(grey_image)

threshold = 128
binary_array = np.where(grey_array > threshold, 0, 255)

binary_image = Image.fromarray(binary_array.astype(np.uint8))

plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.imshow(grey_image, cmap='gray')
plt.title('Grayscale Image')
plt.axis('off')

plt.subplot(1, 2, 2)
plt.imshow(binary_image, cmap='binary')
plt.title('Binary Image')
plt.axis('off')

plt.show()

#histogram of binary image
plt.figure(figsize=(8, 6))
plt.hist(binary_array, bins=2, range=(0, 255))
plt.title('Histogram of Binary Image')
plt.xlabel('Pixel Value')
plt.ylabel('Frequency')
plt.show()

