const int botao = 2;
const int botao2 = 3;
const int led = 13;

long tempo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(botao,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  while(digitalRead(botao2)==LOW);
  for(int i=0;i<10;i++){
    delay(2000+random(3000));
    // put your main code here, to run repeatedly:
    digitalWrite(led,HIGH);
    tempo = millis();
    while(digitalRead(botao)==LOW);
    tempo = millis()-tempo;
    digitalWrite(led,LOW);
    Serial.print(i);
    Serial.print('\t');
    Serial.println(tempo);
  }
}
