#include <LiquidCrystal.h>

int Trigger = 8; //Pin digital 8 para el Trigger del sensor
int Echo = 9; //Pin digital 9 para el Echo del sensor
int LEDR=13;//LED ROJO
int LEDA=6;//LED AMARILLO
int LEDV=7;//LED VERDE

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);//Iniciamos la pantalla LCD

void setup()
{
  lcd_1.begin(16, 2); //Iniciamos el LCD.
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT); //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(LEDR,OUTPUT);
  pinMode(LEDA,OUTPUT);
  pinMode(LEDV,OUTPUT);
  lcd_1.print("DISTANCIA:");
  delay(1000);lcd_1.clear();
  lcd_1.setCursor(0,0);lcd_1.print("DISTANCIA DE:");lcd_1.setCursor(6,1);lcd_1.print("cm");
}

void loop()
{
 long t; //tiempo que demora en llegar el eco
 long d; //distancia en centimetros
 digitalWrite(Trigger, HIGH);
 delayMicroseconds(10); //Enviamos un pulso de 10us
 digitalWrite(Trigger, LOW);
 
 t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
 d = (t/2.0)/29; //escalamos el tiempo a una distancia en cm
 
  if (d<20){//Si la distancia es < a 20cm enciende LED ROJO
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDV,LOW);
    lcd_1.setCursor(4,1);lcd_1.print(" ");
    lcd_1.setCursor(5,1);lcd_1.print(" ");
  }
  if(d>=20 && d<=40){//Si la distancia esta entre 20cm y 40cm enciende LED AMARILLO
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDV,LOW);
    lcd_1.setCursor(4,1);lcd_1.print(" ");
    lcd_1.setCursor(5,1);lcd_1.print(" ");
  }
  if (d>40){  //Si la distancia es > a 40cm enciende LED VERDE
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDV,HIGH);   
  }
 lcd_1.setCursor(3,1);lcd_1.print(d);
 Serial.print("Distancia: ");
 Serial.print(d); //Enviamos serialmente el valor de la distancia
 Serial.print("cm");
 Serial.println();
 delay(500); //Hacemos una pausa de 500ms
}