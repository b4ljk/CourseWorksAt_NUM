import os

import cv2
import numpy as np

current_directory = os.getcwd()

image = cv2.imread("skull.tif", -1)

for x in range(1, 9):
    divider = 2**x - 1
    print(x)
    current_image = image.copy()
    for idx_i, i in enumerate(current_image):
        for idx_j, z in enumerate(i):
            current_image[idx_i][idx_j] = round(z / divider) * divider

    cv2.imwrite(f"{current_directory}/result/skull_{divider}.tif", current_image)
print(round(0.503))

# TASK2

image = cv2.imread("rose.tif", -1)

interplotation = {
    "nearest": cv2.INTER_NEAREST,
    # cv2.IMREAD_UNCHANGED,
    "linear": cv2.INTER_LINEAR,
    "cubic": cv2.INTER_CUBIC,
}

sizes = [128, 64, 32]
print(image.shape)
for key, _intr in interplotation.items():
    for size in sizes:
        current_image = cv2.resize(image, (size, size), interpolation=_intr)
        current_image = cv2.resize(current_image, (1024, 1024), interpolation=_intr)
        cv2.imwrite(
            f"{current_directory}/result/rose_{_intr}_{size}_{key}.tif", current_image
        )
        difference_image = image - current_image
        cv2.imwrite(
            f"{current_directory}/result/rose_{_intr}_{size}_{key}_difference.tif",
            difference_image,
        )

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
if not os.path.exists(f"{current_directory}/result/gray_level_slicing"):
    os.makedirs(f"{current_directory}/result/gray_level_slicing")

img = cv2.imread('input/task4.tif')
images = []

gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
bit2 = cv2.bitwise_and(gray, 0xC0)

gray = cv2.resize(gray, [400, 400])
bit1 = cv2.resize(gray, [400, 400])
bit2 = cv2.resize(gray, [400, 400])

for i in range(bit1.shape[0]):
    for j in range(bit1.shape[1]):
        if (bit1[i][j] < 150 and bit1[i][j] > 70):
            bit1[i][j] = 37
        else:
            bit1[i][j] = 230

for i in range(bit2.shape[0]):
    for j in range(bit2.shape[1]):
        if (bit2[i][j] < 150 and bit2[i][j] > 70):
            bit2[i][j] = 70
        else:
            bit2[i][j] = 180


images.append(gray)
images.append(bit1)
images.append(bit2)

cat = cv2.hconcat(images)
cv2.imwrite(f"{current_directory}/result/gray_level_slicing/task4.tif", cat)

# TASK 5 BIT-PLANE SLICING
if not os.path.exists(f"{current_directory}/result/bitplaneslicing"):
    os.makedirs(f"{current_directory}/result/bitplaneslicing")

img = cv2.imread('input/Fig0314(a)(100-dollars).tif')
img = cv2.resize(img, (380, 250))
images = []

for i in range(8):
    j = np.bitwise_and(img, 1 << i)
    j = np.uint8(j * 255)
    images.append(j)

row1 = images[:4]
row2 = images[4:]

row1_cat = cv2.hconcat(row1)
row2_cat = cv2.hconcat(row2)

final_image = cv2.vconcat([row1_cat, row2_cat])
cv2.imwrite(f"{current_directory}/result/bitplaneslicing/task5.tif", final_image)