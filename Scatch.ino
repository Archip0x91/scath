#include <SoftwareSerial.h>

#include <Servo.h>

#include <AceWire.h> 

#include <LiquidCrystal.h>

SoftwareSerial BTSerial(11,12); // RX, ТХ

#define LED_PIN 13 const int xAxisPin = A0; const int yAxisPin = A1;

const int servoPin = 9;

int xAxis Value 

int yAxis Value;

Servo servo; // Создаем экземпляр класса LiquidCrystal_2C для управления дисплеем

 LiquidCrystal_I2C lcd(0x27,16, 2); // Указываем адрес экрана на шине 12С и количество колонок и строк

void setup() { 

Icd.init(); // Инициализация экрана

pinMode(LED_PIN, OUTPUT);

pinMode(xAxisPin, INPUT);

pinMode(yAxisPin, INPUT);

servo attach(servoPin);

Serial.begin(9600);

BTSerial.begin(9600);

}

void loop(){

Icd.backlight();  //Включаем подсветку экрана 

Icd setCursor(0, 0); // Устанавливаем курсор в начало первой строки

 Icd.print("Hello"); // Вывод текста на экран в первой строке

if (BTSerial.available()) { char command= BTSerial.read(); if (command 10) ( digitalWrite(LED_PIN,LOW);

Serial.println("LED OFF"); } else if (command == 1')

digitalWrite(LED_PIN, HIGH);

    

 Serial.println("LED ON"); 

xAxisValue =analogRead(xAxisPin); yAxisValue =analogRead(yAxisPin); int servoAngle

map(xAxisValue, 0, 1023, 0, 180); servo.write(servo Angle); delay(15);

}

