import tensorflow as tf
from tensorflow.keras.preprocessing import image
import numpy as np
import argparse

# Load trained model
model = tf.keras.models.load_model("model.h5")

def predict(img_path):
    img = image.load_img(img_path, target_size=(128,128))
    x = image.img_to_array(img)/255.0
    x = np.expand_dims(x, axis=0)
    pred = model.predict(x)[0][0]

    if pred < 0.5:
        return "🌱 Green Plant (Healthy)"
    else:
        return "🍂 Dried Plant (Stressed)"

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--image", required=True, help="Path to image")
    args = parser.parse_args()

    result = predict(args.image)
    print("Prediction:", result)
