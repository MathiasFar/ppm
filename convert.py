from PIL import Image
with Image.open("image.ppm") as im:
     im.save("result.jpg")
