/*
 Tempo de atraso
 
 Baseado no Debounce da biblioteca de exemplos do arduino.

 O acionamento do led pelo botão é atrasado. O objetivo é identificar quanto é
 o atraso percebido por uma pessoa como sendo instantâneo.

 O circuito:
 * LED no pino 13 para o terra.
 * Botão para cinco V no pino 2.
 * Resistor de 10K do pino 2 para o terra

 created 17 january 2017
 by João P. C. Cajueiro

 This example code is in the public domain.

 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int butao2 = 3;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int buttonState;             // the current reading from the input pin
int butao2State;
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long atraso = 0;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > atraso) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      digitalWrite(ledPin, buttonState);
    }
  }

  lastButtonState = reading;

  /******************************************
  Código para mudar o atraso a partir do botao
  ******************************************/
  /*int butao2Atual = digitalRead(butao2);
  if (butao2Atual != butao2State){
    butao2State = butao2Atual;
    if(butao2Atual == HIGH){
      atraso = random(1000);
      Serial.println(atraso);
    }
  }
  */
  /******************************************
  Código para mudar o atraso pela porta serial
  ******************************************/

  //Pode-se usar o código do processing encontrado no exemplo Dimmer
  if (Serial.available()){
    atraso = Serial.read();
  }
}
