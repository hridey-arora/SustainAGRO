from flask import Flask, render_template
import random

app = Flask(__name__)

@app.route("/")
def index():
    # Mock sensor & CV results (replace with actual integration)
    soil = random.randint(200, 800)
    temp = random.randint(20, 40)
    hum = random.randint(30, 90)
    plant = random.choice(["🌱 Green Plant (Healthy)", "🍂 Dried Plant (Stressed)"])
    crop = random.choice(["Wheat", "Rice", "Maize", "Soybean"])
    
    return render_template("index.html", soil=soil, temp=temp, hum=hum, plant=plant, crop=crop)

if __name__ == "__main__":
    app.run(debug=True)
