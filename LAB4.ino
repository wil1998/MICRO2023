int pin1=11; //Para enviar el PWM
int pin2=12; //Entrada 2 del L293D
int pin7=13; //Entrada 7 del L293D
int VelBase= 200;// velocidad
int pinLDR=A0; //FotorResistenia
int valorfr; 
int pwm1; //Variable del PWM 1
int pwm2; //Variable del PWM 2

int psr=4; //Pin donde se encuentra el pulsador, entrada
int led=5; //Pin donde se encuentra el LED, salida
int valpsr;
//
void setup()
{
   Serial.begin(9600);//Iniciando comunicación serial del Arduino
   pinMode(pin1,OUTPUT);
   pinMode(pin2,OUTPUT);
   pinMode(pin7,OUTPUT);
   pinMode(psr, INPUT); 
   pinMode(led,OUTPUT);
}

void loop()
{
  //digitalWrite(pin1,HIGH);
  valorfr=analogRead(pinLDR);//A0
  //delay(100);
  valpsr=digitalRead(psr);//Lee el valor del pulsador-----el valor siempre es 1, es 0 cuando pulsamos el btn
  pwm1 = map(valorfr,79,990,0,255);
  pwm2 = map(valorfr,990,79,0,255);
  if (valpsr==LOW){
  //Pulsador oprimido
  
  digitalWrite(led,HIGH); //Enciende el LED
  digitalWrite(pin2,1); //1 derecha 
  digitalWrite(pin7,0); //0 
  analogWrite(pin1,pwm1);
  }else{
  digitalWrite(led,LOW); //Apaga el LED
  digitalWrite(pin2,0); //0 izquierda 
  digitalWrite(pin7,1); //1  
  analogWrite(pin1,pwm1); 
  }
  //digitalWrite(pin15,pwm1);//der
  //digitalWrite(pin10,pwm2);//izq

 //Serial.println(valpsr);
 
 Serial.println(valorfr);
  delay(500);
 
 
  
  }