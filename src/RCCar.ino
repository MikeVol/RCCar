#include <Servo.h>

Servo rcServo;
int rcServoDegree=90;
static int rcServoDigPos=7;
boolean SetupCalled=false;
int command;
int intervall=50;

void setup(){
    rcServo.attach(rcServoDigPos);
    Serial.begin(115200);
}


void loop(){

    if(Serial.available()>0){
        if(SetupCalled==false){
            Serial.println("Commencing Servo Setup");
            rcServo.write(60);
            delay(1000);
            rcServo.write(130);
            delay(1000);
            rcServo.write(90);
            delay(1000);
            Serial.println("Servo Setup complete");
            SetupCalled=true;
        }

        command=Serial.read();

        if(command==97){
            if (rcServoDegree < 130) {
                rcServoDegree += 5;
            }
            Serial.print("left");
            Serial.print("\t");
            Serial.println(rcServoDegree);
            rcServo.write(rcServoDegree);
            delay(15);
            command=Serial.read();
        }
        if(command==100){
            if (rcServoDegree > 60) {
                rcServoDegree -= 5;
            }
            Serial.print("right");
            Serial.print("\t");
            Serial.println(rcServoDegree);
            rcServo.write(rcServoDegree);
            delay(15);
            command=Serial.read();
        }
        if(command==119){
            rcServoDegree=90;
            Serial.print("straight");
            Serial.print("\t");
            Serial.println(rcServoDegree);
            rcServo.write(rcServoDegree);
            delay(15);
            command=Serial.read();
        }
        rcServo.write(rcServoDegree);
        delay(100);
    }
}
