import os

import cv2

current_directory = os.getcwd()

items = os.listdir(current_directory + "/images")
jpgs = [item for item in items if "jpg" in item]
jpg_len = len(jpgs)
avg_image = 0

gray_img_list = []

for item in items:
    if "jpg" in item:
        try:
            image = cv2.imread(current_directory + "/images/" + item)
            print(item, "is read")
            resized_image = cv2.resize(image, [500, 500])
            gray_image = cv2.cvtColor(resized_image, cv2.COLOR_RGB2GRAY)
            gray_img_list.append(gray_image)
            avg_image += gray_image / jpg_len
        except Exception as e:
            print(e)

for gray_img, jpg in zip(gray_img_list, jpgs):
    result = avg_image - gray_img
    if not os.path.exists(current_directory + "/result"):
        os.makedirs(current_directory + "/result")
    cv2.imwrite(
        current_directory + "/result/" + str(jpg) + "_gray_avg" + ".jpg",
        result,
    )
