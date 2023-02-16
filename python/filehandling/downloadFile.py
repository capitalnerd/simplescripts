import requests

image_url = input("Image Path: ")
filename = image_url.split("/")[-1]
response = requests.get(image_url)

with open(filename, "wb") as f:
    f.write(response.content)
