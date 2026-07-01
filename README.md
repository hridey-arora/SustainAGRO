# 🌱 SustainAGRO – Smart Soil, Climate & Plant Health Monitoring

## 📖 Project Overview
**SustainAGRO** is an Arduino-based smart agriculture monitoring system for soil, climate, and plant-health tracking.

It combines:

- 🌡️ **IoT sensors** for soil moisture, temperature, and humidity monitoring.
- 📷 **OV7670 camera capture** for collecting plant images.
- 🤖 **Computer vision** to classify plants as healthy or stressed.
- 📊 **Crop recommendations** based on soil and climate conditions.
- 🖥️ **Flask dashboard** to visualize sensor readings and recommendations.

The goal is to help farmers improve irrigation decisions, detect plant stress early, and make better crop-planning choices.

---

## ⚙️ Features
- ✅ Real-time soil, temperature, and humidity monitoring with Arduino.
- ✅ LED and buzzer alerts for extreme conditions.
- ✅ OV7670 camera sketch for plant image capture.
- ✅ CNN-based health classification: healthy vs stressed plants.
- ✅ Flask web dashboard for sensor values and crop suggestions.

---

## 🗂️ Repository Structure

```text
Arduino_Code/
  SustainAGRO.ino
  ov7670_capture.ino
CV_Model/
  predict.py
  train_model.ipynb
  dataset/
Dashboard/
  app.py
  templates/
README.md
```

---

## 🛠️ Components Used
- Arduino UNO / ESP32
- OV7670 camera module
- DHT11 sensor for temperature and humidity
- Soil moisture sensor
- LEDs and buzzer
- Servo motor, optional for irrigation-pump simulation
- Computer with Python for CV and dashboard workflows

---

## 🔌 Workflow
1. 🌱 **Sensors**: Arduino collects soil and climate data.
2. 📷 **Camera**: OV7670 captures crop or leaf images.
3. 🧠 **Model**: `model.h5` classifies plant health.
4. 🖥️ **Dashboard**: Flask displays plant health, sensor values, and crop suggestions.

---

## 📜 Usage Instructions

### 1. Arduino Setup
- Upload `Arduino_Code/SustainAGRO.ino` to monitor soil and climate.
- Upload `Arduino_Code/ov7670_capture.ino` to capture plant images.
- Adjust pin mappings in the sketches if your wiring differs.

### 2. Python Setup

```bash
python -m venv .venv
.venv\Scripts\activate
pip install -r requirements.txt
```

On macOS/Linux, activate the environment with:

```bash
source .venv/bin/activate
```

### 3. Train the CV Model
- Place training images in `CV_Model/dataset/green` and `CV_Model/dataset/dried`.
- Open `CV_Model/train_model.ipynb` and run all cells.
- Save the trained model as `CV_Model/model.h5`.

### 4. Run Plant Health Prediction

```bash
cd CV_Model
python predict.py --image sample_images/leaf.jpg
```

### 5. Run the Dashboard

```bash
cd Dashboard
python app.py
```

Open the local Flask URL shown in the terminal, usually `http://127.0.0.1:5000`.

---

## 🚀 Future Improvements
- Connect live Arduino serial readings to the dashboard.
- Add historical charts for soil moisture, temperature, and humidity.
- Replace mock dashboard values with real sensor and model outputs.
- Add irrigation-control automation with safety thresholds.
- Expand the plant-health model with more crop and disease classes.

---

## ⚠️ Notes
- `model.h5` is generated after training and may not be committed to the repository.
- Camera and sensor readings depend on calibration, lighting, and wiring quality.
- Use safe power handling when connecting pumps, motors, or external power supplies.
