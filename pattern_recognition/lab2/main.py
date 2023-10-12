import os
import typing as t

import cv2
import matplotlib.pyplot as plt
import numpy as np
from sklearn.metrics import mean_squared_error

current_directory = os.getcwd()


def concat_dynamically(items: t.List):
    """Concat images dynamically"""
    length = len(items)
    aspect_ration = 16 / 9
    rows = int(np.sqrt(length))
    cols = int(np.ceil(length / rows))
    print(rows, cols)
    images = []
    for i in range(rows):
        images.append(cv2.hconcat(items[i * cols : (i + 1) * cols]))
    return cv2.vconcat(images)


image = cv2.imread("skull.tif", -1)
images_list = []
for x in range(1, 9):
    divider = 2**x - 1
    print(x)
    current_image = image.copy()
    for idx_i, i in enumerate(current_image):
        for idx_j, z in enumerate(i):
            current_image[idx_i][idx_j] = round(z / divider) * divider

    images_list.append(current_image)

cat1 = cv2.hconcat(images_list[:4])
cat2 = cv2.hconcat(images_list[4:])
cat = cv2.vconcat([cat1, cat2])
cv2.imwrite(f"{current_directory}/result/skull.tif", cat)

# TASK2

# Your existing code...
image = cv2.imread("rose.tif", -1)
images_list = []
images_list_difference = []

interplotation = {
    "nearest": cv2.INTER_NEAREST,
    # cv2.IMREAD_UNCHANGED,
    "linear": cv2.INTER_LINEAR,
    "cubic": cv2.INTER_CUBIC,
}
original_flat = image.flatten()

sizes = [128, 64, 32]
sizes_dict = {key: [] for key in sizes}
print(image.shape)
for key, _intr in interplotation.items():
    for size in sizes:
        current_image = cv2.resize(image, (size, size), interpolation=_intr)
        current_image = cv2.resize(current_image, (1024, 1024), interpolation=_intr)

        images_list.append(current_image)
        difference_image = image - current_image

        images_list_difference.append(difference_image)
        sizes_dict[size].append([current_image, "method: " + key])


for key, value in sizes_dict.items():
    difference_flat = [img[0].flatten() for img in value]
    errors = [mean_squared_error(original_flat, diff) for diff in difference_flat]
    closest_index = np.argmin(errors)
    print(f"Size: {key}")
    print(value[closest_index][1])
    print(f"Closest index: {closest_index}")

    most_different_index = np.argmax(errors)
    print(value[most_different_index][1])
    print(f"Most different index: {most_different_index}")


fig, axs = plt.subplots(len(interplotation), len(sizes), figsize=(15, 15))

for i, img in enumerate(images_list):
    ax = axs[i // len(sizes)][i % len(sizes)]
    ax.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    ax.set_title(
        f"Method: {list(interplotation.keys())[i//len(sizes)]}, Size: {sizes[i%len(sizes)]}",
        fontsize=20,
    )
    ax.axis("off")

plt.tight_layout()
plt.savefig(f"{current_directory}/result/rose.png")

fig, axs = plt.subplots(len(interplotation), len(sizes), figsize=(15, 15))

for i, img in enumerate(images_list_difference):
    ax = axs[i // len(sizes)][i % len(sizes)]
    ax.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    ax.set_title(
        f"Method: {list(interplotation.keys())[i//len(sizes)]}, Size: {sizes[i%len(sizes)]}",
        fontsize=20,
    )
    ax.axis("off")

plt.tight_layout()
plt.savefig(f"{current_directory}/result/rose_difference.png")


# TASK 3 CONTRAST STRETCHING
# create folder if it does not exists path: result/contrast_stretching
if not os.path.exists(f"{current_directory}/result/contrast_stretching"):
    os.makedirs(f"{current_directory}/result/contrast_stretching")

img = cv2.imread("input/lab3photo.tif")


gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

min_val, max_val, _, _ = cv2.minMaxLoc(gray)

scale = (255 - 0) / (max_val - min_val)
shift = 0 - (scale * min_val)

stretched = cv2.convertScaleAbs(gray, alpha=scale, beta=shift)

bit1 = cv2.bitwise_and(stretched, 0x80)


cat = cv2.hconcat([gray, stretched, bit1])

cv2.imwrite(f"{current_directory}/result/contrast_stretching/lab3photo.tif", cat)


# TASK 4 GRAY-LEVEL SLICING

img = cv2.imread("input/task4.tif")

gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
bit2 = cv2.bitwise_and(gray, 0xC0)

gray = cv2.resize(gray, [400, 400])
bit1 = cv2.resize(gray, [400, 400])
bit2 = cv2.resize(gray, [400, 400])

for i in range(bit1.shape[0]):
    for j in range(bit1.shape[1]):
        if bit1[i][j] < 150 and bit1[i][j] > 70:
            bit1[i][j] = 37
        else:
            bit1[i][j] = 230

for i in range(bit2.shape[0]):
    for j in range(bit2.shape[1]):
        if bit2[i][j] < 150 and bit2[i][j] > 70:
            bit2[i][j] = 70
        else:
            bit2[i][j] = 180

titles = ["Original", "Grayscaled", "128bit Operation"]
images = [gray, bit1, bit2]

# Add titles to the images using cv2.putText()
font = cv2.FONT_HERSHEY_SIMPLEX
font_scale = 1
color = (0, 255, 0)  # yellow color
thickness = 2

for i in range(len(images)):
    cv2.putText(
        images[i], titles[i], (10, 30), font, font_scale, color, thickness, cv2.LINE_AA
    )

cat = cv2.hconcat(images)
cv2.imwrite(f"{current_directory}/result/gray_level_slicing/task4.png", cat)

# TASK 5 BIT-PLANE SLICING


if not os.path.exists(f"{current_directory}/result/bitplaneslicing"):
    os.makedirs(f"{current_directory}/result/bitplaneslicing")

img = cv2.imread("input/Fig0314(a)(100-dollars).tif")
img = cv2.resize(img, (380, 250))
images = []

for i in range(8):
    j = np.bitwise_and(img, 1 << i)
    j = np.uint8(j * 255)

    images.append(j)

# Create a subplot for each image
fig, axs = plt.subplots(3, 3, figsize=(9, 9))

# Add the original image to the list
images = [img] + images

# Fill the last subplot with black image (to maintain shape)
images.append(np.zeros_like(img))

for i in range(3):
    for j in range(3):
        # Index for iterating over the images
        k = 3 * i + j

        # When k is 0, it means it is the input image
        if k == 0:
            title = "Input"
        else:
            title = f"Bit Plane {k}" if k <= 8 else ""

        # Display the image and set the title
        axs[i, j].imshow(cv2.cvtColor(images[k], cv2.COLOR_BGR2RGB))
        axs[i, j].set_title(title, fontsize=20)
        axs[i, j].axis("off")

# Adjusting space between plots
plt.tight_layout()

# Saving the figure
plt.savefig(f"{current_directory}/result/bitplaneslicing/task5.png")
