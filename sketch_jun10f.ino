#include <Servo.h>

// Создаем объект сервопривода Servo myservo;

// Пины джойстика

int joyXPin = A0;

int joyYPin = A1;

int joyButtonPin = 2;

// Переменные для хранения значений осей джойстика int joyXValue = 0;

int joyYValue = 0;

// Пины для сервопривода int servopin = 9;

// Переменные для перемещения

сервопривода

int servoAngle = 0;

int servostep = 1;

void setup() { // Инициализируем пины

джойстика

pinMode(joyButtonPin,

INPUT_PULLUP);

// Инициализируем сервопривод

myservo.attach(servoPin); myservo.write(servo Angle);

}

void loop) (

// Читаем значения осей джойстика

joyXValue =

analogRead(joyXPin);

joyYValue

analogRead(joyYPin);

// Если кнопка

джойстика нажата, то вращаем сервопривод if

(digitalRead(joyButtonPin) == LOW) {

// Увеличиваем значение угла сервопривода на шаг

servoAngle += servostep;

// Проверка на выход за

пределы диапазона угла

сервопривода (0-180)

if (servoAngle > 180) { servoAngle = 0; }

// Перемещаем сервопривод в заданный

угол

myservo.write(servo Angle);

}

// Иначе движение сервопривода зависит от позиции джойстика else {

// Преобразуем

значения осей джойстика в диапазон углов сервопривода (0-180)

int angleX = map(joyXValue, 0, 1023, 0,

180);

int angley = map(joyYValue, 0, 1023, 0, 180);

// Выбираем значение угла сервопривода на основе позиции джойстика

servoAngle = angleX;

// Перемещаем сервопривод в заданный угол

myservo.write(servoAngle);

// Небольшая задержка для стабильности работы

delay(50);
}
