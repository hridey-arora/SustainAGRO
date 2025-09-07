# 🌱 SustainAGRO – Smart Soil, Climate & Plant Health Monitoring  

## 📖 Project Overview  
**SustainAGRO** is a Arduino-based smart monitoring system which aims for Agriculture Improvement through:

- 🌡️ **IoT sensors**: soil moisture, temperature, humidity monitoring.  
- 📷 **OV7670 Camera**: captures real-time crop images.  
- 🤖 **Computer Vision (CNN model)**: classifies plants as Green (healthy) or Dried (stressed).  
- 📊 **Yield Recommendation**: suggests the crop with the best potential based on soil & climate conditions.  
- 🖥️ **Farmer Dashboard**: easy-to-use interface to visualize plant health & sensor readings.  

This project helps farmers improve irrigation, detect plant stress early, and maximize yield.  

---

## ⚙️ Features  
- ✅ Real-time soil, temperature, and humidity monitoring with Arduino.  
- ✅ Alerts via LEDs + Buzzer for extreme conditions.  
- ✅ OV7670 camera captures plant images for CV analysis.  
- ✅ CNN-based classification → 🌱 Healthy vs 🍂 Stressed plants.  
- ✅ Flask web dashboard for farmers to monitor conditions & get recommendations.  

---

## 🛠️ Components Used  
- Arduino UNO / ESP32  
- OV7670 Camera Module  
- DHT11 Sensor (temperature & humidity)  
- Soil Moisture Sensor  
- LEDs (Green/Blue/Red) + Buzzer  
- Servo (optional for irrigation pump simulation)  
- Computer with Python (for CV + dashboard)

---

## 🔌 Workflow  

1. 🌱 **Sensors** → Arduino collects soil/climate data.  
2. 📷 **OV7670 Camera** → Captures crop/leaf images.  
3. 🧠 **CNN Model (`model.h5`)** → Classifies plant health.  
4. 🖥️ **Dashboard** → Displays plant health + best crop suggestion.  

---

## 📜 Usage Instructions  

### 1️⃣ Arduino Setup  
- Upload `Arduino_Code/SustainAGRO.ino` to monitor soil & climate.  
- Upload `Arduino_Code/ov7670_capture.ino` to capture plant images.  

### 2️⃣ Train the CV Model  
- Place images in `dataset/green` and `dataset/dried`.  
- Open `train_model.ipynb` and run all cells.  
- A trained model (`model.h5`) will be saved.  

### 3️⃣ Run Plant Health Prediction  
```bash
cd CV_Model
python predict.py --image sample_images/

