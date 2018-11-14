#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int buzzerPin=8;
int lpg_sensor=7;
int gas_value;

void setup() {
     pinMode(buzzerPin,OUTPUT);
     pinMode(lpg_sensor,INPUT);
     mySerial.begin(9600);
     Serial.begin(9600);
}

void loop() {
     gas_value=digitalRead(lpg_sensor);
     if(gas_value==0)
     {
      digitalWrite(buzzerPin,HIGH);
      mySerial.print("AT+CMGF=1");
      delay(1000);
      mySerial.print("AT+CMGF\"+918283804494\"\r");
      mySerial.print("GAS LEAKING!!");
      delay(200);
      mySerial.print((char)26);
     }
}
