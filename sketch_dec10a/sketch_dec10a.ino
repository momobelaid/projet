const int Digital = 8; 
const int PORTE = 5; 
int flame;
char data;
int a;
void setup ()
{
 
  pinMode (Digital,INPUT);    
  pinMode (PORTE,INPUT);    
  Serial.begin (9600);
}
  

void loop ()
{
  
  flame = digitalRead (Digital);
  a=digitalRead(PORTE);
  Serial.print(flame);
  Serial.print(",");
  Serial.flush();
  delay(500);
  
if (Serial.available()) {data = Serial.read();}


 if(data=='x')
  {
      Serial.println ("NON Flamme");
  }
  else if (data=='y')
  {
      Serial.println ("Flamme");
      
  }

  delay (2000);
}
