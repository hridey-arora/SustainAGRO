#include <dht11.h>
#define DHT11PIN 4
dht11 DHT11;
int greenLight = 11; //Defining pins
int blueLight = 12;
int redLight   = 2;
int piezoBuzzer = 3;
int maximumMoistureLevel; //The max moisture level   and current moisture levels will be needed for percentage calculations
int currentMoistureLevel;//Like   so: current/max*100 = Moisture level as a percentage

void moistureDetection(){   //Create a function for all the long code, to keep the loop free
  if(currentMoistureLevel   >= 800) //If the moisture is above 90%
  { 
    digitalWrite(greenLight, LOW);
     digitalWrite(blueLight, LOW);
    digitalWrite(redLight, HIGH); //Switch   on red light, and sound the buzzer
    tone(piezoBuzzer, 5000, 500);
    delay(2000);
   }

  else if (currentMoistureLevel >= 320)
  {//if the moisture level is in between 60 and 90%
    digitalWrite(greenLight,   LOW);
    digitalWrite(blueLight, LOW);
    digitalWrite(redLight, HIGH);   //Switch red light on, but don't sound the buzzer
  }
  else if (currentMoistureLevel >= 100)
  {//if the moisture   level is in between 30 and 60%
    digitalWrite(greenLight, LOW);
    digitalWrite(blueLight,   HIGH);//Just switch yellow light on
    digitalWrite(redLight, LOW);
  }
  else   //Otherwise the moisture level is below 30%, and therefore it's good enough
   {
    digitalWrite(greenLight, HIGH);//Switch green light on
    digitalWrite(blueLight,   LOW);
    digitalWrite(redLight, LOW);
  }
}

void setup() {
  {
   Serial.begin(9600);
   
  }
   for (int i = 0; i < 4; i++)//Use a for loop, to not have to initiate all the pins   by hand
  {
    pinMode(i, OUTPUT);
  }
  pinMode (A0, INPUT); //A0   is the pin used for the Soil Moisture Sensor
  maximumMoistureLevel = analogRead(A0);
  
}

void   loop() {
  {
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(800);

}
  {
  currentMoistureLevel = analogRead(A0); //Keep renewing the readings   for the current moisture level
  moistureDetection();
  delay(800); //Short   delay to not overload the program
  Serial.print("Moisture : ");
  Serial.println(currentMoistureLevel);
  }
  
}