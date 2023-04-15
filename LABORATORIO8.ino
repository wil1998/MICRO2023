//SIN CONECTAR EL PIN OE
//LA VEL TOMA MEDIDA DE COLOR DEPENDE SI DA VUELTA COMPLETA O MEDIA O CUARTA VUELTA...SI ES DE 1 VUELTA LA LECTURA DE COLOR TARDA...SI ES DE 1/4VUELTA LEE MAS RAPIDO EL COLOR 
#include <Stepper.h> // incluye libreria stepper
Stepper motor1(2048, 8, 10, 9, 11);//Pines conectado al arduino
int RPin= 12;//PIN RGB-ROJO
int VPin = 13;//PIN RGB-VERDE
int APin= 7;//PIN RGB-AZUL
const int s0 = 2;  //PIN SO CONECTADA AL ARDUINO
const int s1 = 3;  //PIN S1 CONECTADA AL ARDUINO
const int s2 = 4;  //PIN S2 CONECTADA AL ARDUINO
const int s3 = 5;  //PIN S3 CONECTADA AL ARDUINO
const int out = 6; //PIN OUT CONECTADA AL ARDUINO   
int rojo = 0;   //LECTURA COLOR ROJO
int verde = 0;  // LECTURA COLOR VERDE
int azul = 0;   //LECTURA COLOR AZUL
void setup() {
Serial.begin(9600);//INICIAMOS EL MONITOR SERIAL
motor1.setSpeed(3); // en RPM (valores de 1, 2 o 3 para 28BYJ-48)
pinMode(RPin, OUTPUT);
pinMode(VPin, OUTPUT);
pinMode(APin, OUTPUT);
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
  color();//FUNCION DE LECTURA DE COLOR
  Serial.print("ROJO= ");  
  Serial.print(rojo, DEC);  
  Serial.print(" VERDE= ");  
  Serial.print(verde, DEC);   
  Serial.print(" AZUL= "); 
  Serial.print(azul, DEC); 

  if (rojo < azul && verde > azul && rojo < 190) {  
  Serial.println("     ROJO"); 
  digitalWrite(RPin, HIGH);//PRENDE ROJO Y GIRA HORARIO
  digitalWrite(VPin, LOW);
  digitalWrite(APin, LOW);
  motor1.step(512);// GIRA SENTIDO HORARIO
  }   
  else if (azul < rojo && azul < verde && verde > rojo)  {  
   Serial.println("     VALIDO SOLO ROJO Y VERDE");     
   digitalWrite(RPin, LOW);// NO PRENDE
  digitalWrite(VPin, LOW);
  digitalWrite(APin, LOW);   
   motor1.step(0);// NO GIRA 
  } else if (rojo > verde && azul > verde ) {  
  Serial.println("     VERDE");    
  digitalWrite(RPin, LOW);//PRENDE VERDE Y GIRA ANTIHORARIO
  digitalWrite(VPin, HIGH);
  digitalWrite(APin, LOW);   
  motor1.step(-512);// GIRA SENTIDO ANTIHORARIO
  }  
  else{Serial.println("  ");  
  }
  delay(500);     
}  
void color(){    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}