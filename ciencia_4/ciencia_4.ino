const int buttonPin = 4;
const int r   = 3;
const int g   = 5;
const int b   = 6;

const int potPin = A4;

int ledValue;
int buttonValue;
int lastValue;

int color = r;

void setup(){
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop(){
  buttonValue = digitalRead(buttonPin);
  if(lastValue == HIGH && buttonValue == LOW){
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
    ledValue = 0;
  }
  if (buttonValue == HIGH){
    ledValue = analogRead(potPin)/4;
  }
  lastValue = buttonValue;
  analogWrite(color,ledValue);
  delay(10);
}
