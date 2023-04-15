#include <LiquidCrystal.h>//Libreria del LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor;//Valor del sensor de Temperatura
float tmp;
float suma;
float c=0;//Temperatura en Celsius
float k=0;//Tenperatura en Kelvin
void setup() {

  lcd.begin(16,2);//Iniciamos el LCD
  Serial.begin(9600);

  lcd.print("TEMPERATURA:");lcd.setCursor(0,1);lcd.print("C y K");
  delay(2000);lcd.clear();

  lcd.setCursor(0,0);lcd.print("T:");lcd.setCursor(9,0);lcd.print("C");
  lcd.setCursor(0,1);lcd.print("T:");lcd.setCursor(9,1);lcd.print("K");
}

void loop() {
  suma=0;
  for (int i=0; i<5;i++){//Promedio de 5 temperaturas
     sensor=analogRead(A0);
     tmp=((sensor*5000.0)/1023)/10;
     suma=tmp+suma;
     delay(500);
  }
  Serial.println(suma/5.0,1);//Muestra la temperatura
  c=suma/5.0;
  k=c+273.15;
  lcd.setCursor(2,0);lcd.print(c);//Muestra en pantalla LCD el valor en Celcius
  lcd.setCursor(2,1);lcd.print(k);//Muestra en pantalla LCD el valor en Kelvin
}
