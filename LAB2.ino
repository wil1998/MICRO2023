int led=5;
int led2=6;

void setup()
{
  pinMode(led,OUTPUT);
   pinMode(led2,OUTPUT);
 Serial.begin(9600); //Inicia comunicación serial
}

void loop()
{
  int valor= analogRead(A1);
  
  if (valor>=800 && valor<=1024){
  	digitalWrite(led,HIGH); //Enciende el LED
    //delay(1000);
  }else{
      digitalWrite(led,LOW); //Apaga el LED
    
  }
  
   if (valor>=0 && valor<401){
  	digitalWrite(led2,HIGH); //Enciende el LED
    //delay(1000);
  }else{
      digitalWrite(led2,LOW); //Apaga el LED
    
  }
                              
  Serial.println(valor);
//Retardo para la visualización de datos en la consola
  delay(100);

}