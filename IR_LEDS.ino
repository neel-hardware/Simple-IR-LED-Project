#include <IRremote.h>//library containing all IR functions
#define RECV_PIN 3//define IR reciever pin
#define gPin 11//define green LED pin
#define w1Pin 12//define white LED pin
#define wPin 6//define white LED pin
#define bPin 10//define blue LED pin

void setup() {
  //sets up the pins to deliver voltage to the LED
  pinMode(gPin, OUTPUT);
  pinMode(w1Pin, OUTPUT);
  pinMode(wPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  Serial.begin(9600);//sets up the serial
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);//sets up the IR by inputing the digital pin connected to the module and also indicates an LED respons when thereis a signal 
}

void loop() {
  if (IrReceiver.decode()) {//if there is a IR signal
    int command = IrReceiver.decodedIRData.command;//the signal
    switch (command) { //what the signal means
      case 28://ie: 28 stands for the OK button 
        Serial.println("OKAY");//prints what the command stands for 
        //turns off all leds
        digitalWrite(gPin, LOW);
        digitalWrite(w1Pin, LOW);
        digitalWrite(wPin, LOW);
        digitalWrite(bPin, LOW);
        break;
      case 24:
        Serial.println("UP");
        digitalWrite(gPin, HIGH);//turns on green
        break;
      case 82: 
        Serial.println("DOWN");
        digitalWrite(w1Pin, HIGH); //turns on white1
        break;
      case 8:
        Serial.println("LEFT");
        digitalWrite(bPin, HIGH); //turns on blue
        break;	
      case 90: 
        Serial.println("RIGHT"); 
        digitalWrite(wPin, HIGH); //turns on white2
        break;
      case 69:
        Serial.println("1");
        break;		
      case 70:
        Serial.println("2");
        //turns on all LEDs
        digitalWrite(gPin, HIGH);
        digitalWrite(w1Pin, HIGH);
        digitalWrite(wPin, HIGH);
        digitalWrite(bPin, HIGH);
        break;
      case 71:
        Serial.println("3");
        break;	
      case 68:
        Serial.println("4");
        break;
      case 64:
        Serial.println("5");
        break;
      case 67:
        Serial.println("6");
        break;
      case 7:
        Serial.println("7");
        break;
      case 21:
        Serial.println("8");
        break;
      case 9:
        Serial.println("9");
        break;
      case 22:
        Serial.println("*");
        break;
      case 13:
        Serial.println("#");
        break;
      default:	
        Serial.println("UNDEFINED");	  
    } 	   
		
    delay(100);
    IrReceiver.resume();
  }
}