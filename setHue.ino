const int potPin = A0; // Precisa ser anal�gico
const int rPin   = 3; // precisa ser PWM
const int gPin   = 5; // precisa ser PWM
const int bPin   = 6; // precisa ser PWM

void setup(){
  pinMode(potPin,INPUT);
  pinMode(rPin,OUTPUT);
  pinMode(rPin,OUTPUT);
  pinMode(rPin,OUTPUT);
}

void loop(){
  setHue(analogRead(potPin, rPin, gpIn, bPin));
}

// A fun��o setHue define os valores anal�gicos (PWM)
// dos pinos r, g e b em fun��o da defini��o de hue
void setHue(int hue, int r, int g, int b){
  // Fun��o a ser definida
}