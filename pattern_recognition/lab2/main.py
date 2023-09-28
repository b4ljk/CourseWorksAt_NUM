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
