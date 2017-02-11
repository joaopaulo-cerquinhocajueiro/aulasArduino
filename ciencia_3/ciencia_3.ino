const int buttonPin = 4;
const int r   = 3;
const int g   = 5;
const int b   = 6;
int ledValue;
int lastValue;

int color = r;

void setup(){
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop(){
  ledValue = digitalRead(buttonPin);
  if(lastValue == LOW && ledValue == HIGH){
    digitalWrite(color,HIGH);  
  } else if(lastValue == HIGH && ledValue == LOW){
    digitalWrite(color,LOW);
    int newColor;
    if (color == r){
      newColor = g;
    }
    if (color == g){
      newColor = b;
    }
    if (color == b){
      newColor = r;
    }
    color = newColor;
  }
  lastValue = ledValue;
}
