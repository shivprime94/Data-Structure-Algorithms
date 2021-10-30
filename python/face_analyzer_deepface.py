from deepface import DeepFace
import cv2
import matplotlib.pyplot as plt

happy_man = 0
sad_man = 0
happy_woman = 0
sad_woman = 0


def face_recognition_func(img_path):
    img = cv2.imread(img_path)
    plt.imshow(img[:, :, ::-1])
    demography = DeepFace.analyze(img_path)

    gender = demography["gender"]
    emotion = demography["dominant_emotion"]
    characteristics = {"gender": gender, "emotions": emotion}
    return characteristics


list_of_images = [
    r"C:\Users\dhane\PycharmProjects\pythonProject\me.jpg"

]

for images in list_of_images:
    face_data = face_recognition_func(images)
    if face_data["gender"] == "Man":
        if face_data["emotions"] == "happy":
            happy_man += 1
        elif face_data["emotions"] == "sad":
            sad_man += 1
    elif face_data["gender"] == "Woman":
        if face_data["emotions"] == "happy":
            happy_woman += 1
        elif face_data["emotions"] == "sad":
            sad_woman += 1
    else:
        print("Something went wrong!")

print(f"There are {happy_man} happy male customers.")
print(f"There are {sad_man} sad male customers.")
print(f"There are {happy_woman} happy female customers.")
print(f"There are {sad_woman} sad female customers.")
