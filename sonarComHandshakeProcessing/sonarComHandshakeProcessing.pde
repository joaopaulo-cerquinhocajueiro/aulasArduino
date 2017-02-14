import processing.serial.*;

boolean found;
String portName;
Serial arduinoPort;

int lf = 10;
int angle,distance;      // Data received from the serial port
String myString;
String[] data;

void setup(){
   size(500, 250);
   background(255);
   println ("scan open com ports...");
 
  int lastPort = Serial.list().length -1;
 
  while (lastPort<0)
  {
    println("No com ports in use. Rescanning...");
    delay(1000);
    lastPort = Serial.list().length -1;
  }
 
 println("Locating device...");
 
  println(Serial.list());
 
  found = false;
  while (!found)
  {
    portName = Serial.list()[lastPort];
    println("Connecting to -> " + portName);
    delay(200);
 
    try {
      arduinoPort = new Serial(this, portName, 9600);
      arduinoPort.clear();
      arduinoPort.bufferUntil(10);
      delay(2000);
      arduinoPort.write('H');   // Send  Hello
      delay(200);
      
      int l = 10;
      while (!found && l >0)
      {
        if(arduinoPort.available()>0){
          int inByte = arduinoPort.read();
          if(inByte == 'A'){
            found = true;
            break;
          }
        }
        delay(200);
        println("Waiting for response from device on " + portName);
        l--;
      }
 
      if (!found)
      {
        println("No response from device on " + portName);
        arduinoPort.clear();
        arduinoPort.stop();
        delay(300);
      }
 
    }
    catch (Exception e) {
      println("Exception connecting to " + portName);
      println(e);
    }
 
    lastPort--;
    if (lastPort <0)
      lastPort = Serial.list().length -1;
  }
}

void draw() {
    
  while (arduinoPort.available() > 0) {
    myString = arduinoPort.readStringUntil(lf);
    if (myString != null) {
//      println(myString);
      data = splitTokens(myString);
//      print("angle: ");
//      print(data[0]);
//      print(", dist: ");
//      println(data[1]);
    angle = int(data[0]);
    distance = int(data[1]);
    fill(255,5);
    rect(0,0,width,height);
    stroke(0);
    strokeWeight(3);
    line(250,250,250+(distance*cos(angle*3.14159/180)),250-(distance*sin(angle*3.14159/180)));
    }
  }
}