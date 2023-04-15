// Incluir la librería para el sensor de color TCS3200
const int s0 = 1;  //Pines que se usan en arduino
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;    
int rojo = 0;  
int verde = 0;  
int azul = 0;  

// Configurar los pines para el motor paso a paso
#include <Stepper.h> // incluye libreria stepper
Stepper motor1(2048, 8, 10, 9, 11);

// Configurar los pines para el LED RGB
#define LED_R 7
#define LED_G 6
#define LED_B 13

// Inicializar el sensor de color TCS3200
void setup() {
  motor1.setSpeed(3); // en RPM (valores de 1, 2 o 3 para 28BYJ-48)
  // Configurar los pines para el LED RGB como salidas
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(out,INPUT); 
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW); 
}

void loop() {
  color();
  // Visualizar el color en el LED RGB
  analogWrite(LED_R, rojo);
  analogWrite(LED_G, verde);
  analogWrite(LED_B, azul);

  // Controlar el motor paso a paso según el color detectado
  if (rojo > verde && rojo > azul) {
    // Color rojo detectado
    motor1.step(-1024);// Gira Media Vuelta
    delay(200); // Se detiene 2ms segundos  
    }
   else if (verde > rojo && verde > azul) {
    // Color verde detectado
    motor1.step(1024);// Gira Media Vuelta
    delay(200); // Se detiene 2ms segundos  
    }
  }
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}

