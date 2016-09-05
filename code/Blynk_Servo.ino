/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example shows how to use ordinary Arduino Serial
 * to connect your project to Blynk.
 * Feel free to apply it to any other example. It's simple!
 *
 * 1. Optional, but recommended.
 *    Connect additional USB-serial adapter to see the prints.
 *
 * 2. Edit auth token and upload this sketch.
 *
 * 3. Run the script (script located in "scripts" folder of library root,
 *    e.g. 'blynk-library/scripts') for redirecting traffic to server:
 *
 *      for Windows:
 *                     1. Open cmd.exe
 *                     2. Write (put your path to the blynk-ser.bat folder):
 *                          cd C:\blynk-library\scripts
 *                     3. Write (COM4 is port with your Arduino):
 *                          blynk-ser.bat -c COM4
 *                     4. And press "Enter", press "Enter" and press "Enter"
 *
 *      for Linux and OSX:
 *
 *                    bash ./blynk-ser.sh (may need to run with sudo)
 *
 *    You can specify port, baud rate, and server endpoint like this:
 *      ./blynk-ser.sh -c <serial port> -b <baud rate> -s <server address> -p <server port>
 *
 *    For instance :
 *      ./blynk-ser.sh -c /dev/ttyACM0 -b 9600 -s blynk-cloud.com -p 8442
 *
 *    Run blynk-ser.sh -h for more information
 *
 *    Be sure to select the right serial port (there may be multiple).
 *
 *    Attention!
 *        Arduino IDE may complain with "programmer is not responding".
 *        You need to terminate script before uploading new sketch.
 *
 * 4. Start blynking! :)
 *
 **************************************************************/

#include <Servo.h>
#include <SoftwareSerial.h>

// You could use a spare Hardware Serial on boards that have it (like Mega)
SoftwareSerial DebugSerial(2, 3); // RX, TX

// Creamos un objeto Servo llamado servo1 y la variable que almacena el pin utilizado
Servo servo1;
int pin_servo = 5;

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "d47f7ddd19bf4cf9a3e2f27c4df48be4";

void setup()
{
  // Debug console
  DebugSerial.begin(9600);

  // Blynk will work through Serial
  Serial.begin(9600);
  Blynk.begin(auth, Serial);

  // Seteamos el pin que controlara a servo1
  servo1.attach(pin_servo);
}

void loop()
{
  Blynk.run();
}

// Definimos la funcion que escribirá la posicion del servo
// Cuando el valor del pin virtual V1 cambie

BLYNK_WRITE(V1){
  int value = param.asInt();
  servo1.write(value);
}

