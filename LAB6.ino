#include <DHT.h>//Libreria del Servomotor
#include <DHT_U.h>
#include <Servo.h>
Servo servoMotor;

int DHTPIN = 2; //Pin digital donde se conecta el sensor
#define Type DHT11 //Tipo de sensor

DHT HT (DHTPIN,Type);//Iniciamos el sensor

void setup() {
  Serial.begin(9600);
  HT.begin();//Inicia sensor
  servoMotor.attach(9);//Conecta al pin 9
  servoMotor.write(0);//inicia el servo en 0 grados
}

void loop() {
  delay(5000); //medidas cada 5 segundos
  float T=HT.readTemperature();//Leemos la temperatura en celsius
   if (T>30){
 // Desplazamos a la posición 180º
  Serial.print("Temperatura: ");
  Serial.println(T);
 	servoMotor.write(180);
	delay(1000);
  }else{
    // Desplazamos a la posición 90º
  Serial.print("Temperatura: ");
   Serial.println(T);
	 servoMotor.write(90);
	 delay(1000);
  }
}
