
const int buttonPin = 4;
const int ledPin       = 3;
int ledValue;

void setup(){
	pinMode(ledPin,OUTPUT);
	pinMode(buttonPin,INPUT);
}

void loop(){
	ledValue = digitalRead(buttonPin);
	digitalWrite(ledPin,ledValue);
}