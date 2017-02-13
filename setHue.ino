const int potPin = A0; // Precisa ser analógico
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

// A função setHue define os valores analógicos (PWM)
// dos pinos r, g e b em função da definição de hue
void setHue(int hue, int r, int g, int b){
  // Função a ser definida
}