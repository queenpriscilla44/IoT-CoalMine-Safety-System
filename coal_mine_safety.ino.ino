#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11
#define BUZZER D5
#define MQ4 A0
#define MPU6050_ADDR 0x68

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  WiFi.begin("SSID", "PASSWORD");
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(BUZZER, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int gasValue = analogRead(MQ4);

  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);
  int16_t accX = Wire.read() << 8 | Wire.read();
  int16_t accY = Wire.read() << 8 | Wire.read();
  int16_t accZ = Wire.read() << 8 | Wire.read();

  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print(" H:");
  lcd.print(h);

  lcd.setCursor(0,1);
  lcd.print("Gas:");
  lcd.print(gasValue);

  if (t > 37 || h > 80 || gasValue > 400 || abs(accX) > 20000) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}
