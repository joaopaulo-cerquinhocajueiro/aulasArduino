//Variação do Hue de um led RGB

/*
O potenciômetro define o hue interpolando entre estes pontos:
0  - red = 255, green = 0, blue = 0
341(1024/3) - red = 0, green = 255, blue = 0
683(2*1024/3) - - red = 0, green = 0, blue = 255
1024 - mesmo que 0
*/

const int buttonPin = 4;
const int r   = 3;
const int g   = 5;
const int b   = 6;

const int potPin = A4;

int potValue;
int buttonValue;
int lastValue;

int rval,gval,bval;

void setup(){
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop(){
  buttonValue = digitalRead(buttonPin);
  if (buttonValue == HIGH){
    potValue = analogRead(potPin);
    if(potValue<=341){
      gval = map(potValue,0,341,0,255);
      rval = 255 - gval;
      bval = 0; 
    } else if(potValue<=683){
      bval = map(potValue,342,683,0,255);
      gval = 255 - bval;
      rval = 0; 
    } else {
      rval = map(potValue,684,1023,0,255);
      bval = 255 - rval;
      gval = 0; 
    }
  analogWrite(r,rval*0.3);
  analogWrite(g,gval*0.3);
  analogWrite(b,bval*0.3);    
  } else if(buttonValue == LOW && lastValue == HIGH){
    digitalWrite(r,LOW);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
  }
  delay(10);
  lastValue = buttonValue;
}
