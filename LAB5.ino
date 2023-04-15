#include <Stepper.h> // incluye libreria stepper
int sensor;
float tmp;
float suma;
float c=0;
Stepper motor1(2048, 8, 10, 9, 11);
void setup() {
  Serial.begin(9600);//Para usar el monitor Serial
  motor1.setSpeed(3); // en RPM (valores de 1, 2 o 3 para 28BYJ-48)
}

void loop() {   
  suma=0;
  for (int i=0; i<5;i++){ // Media de 5 Temperaturas
     sensor=analogRead(A0);
     tmp=((sensor*5000.0)/1023)/10;
     suma=tmp+suma;
     delay(100);
  }
  c=suma/5.0;//Temperatura

  if(c>30){// Si la Temperatura es mayor a 30 gira sentido Horario
    Serial.println(c);    
    motor1.step(-1024);// Gira Media Vuelta
    delay(2000); // Se detiene 2 segundos    
  }else{  // Por lo contrario gira sentido Antihorario
    Serial.println(c);
    motor1.step(1024); // Gira media vuelta inversa
    delay(2000); // Se detiene 2 segundos
  }
}
