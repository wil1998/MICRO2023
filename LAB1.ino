int i;
int d=150;
void setup()
{
  
  for (i=1; i<9; i++){
  pinMode(i, OUTPUT);
  }
}

void loop()
{
  
   for(i=8;i>1;i--){
    digitalWrite(i,HIGH);
    delay(d);
    digitalWrite(i,LOW);
    delay(d);
  }
  
  for(i=1;i<8;i++){
    digitalWrite(i,HIGH);
    delay(d);
    digitalWrite(i,LOW);
    delay(d);
  }
}
