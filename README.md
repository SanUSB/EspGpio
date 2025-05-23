# EspGpio[![N|Solid](http://sanusb.blogspot.com.br/favicon.ico)](http://sanusb.org/)

https://ingenius.ups.edu.ec/index.php/ingenius/article/view/6294/5636
https://ingenius.ups.edu.ec/index.php/ingenius/article/view/6294/5637

This project makes possible an IoT ESP32 and ESP266 microcontrollers pins switching quikly over the internet.

This project makes it possible an ESP32 microcontrollers pins switching through graphical access with same generic sketch 
using the website [app.sanusb.org/espgpio](https://app.sanusb.org/espgpio). In this project, the free version of Firebase (Google JSON objects Database) was 
implemented to allow the IoT interaction between the users and the remote ESP microcontrollers.  . 

TThe graphical environment generated at [app.sanusb.org/espgpio](https://app.sanusb.org/espgpio) has 30 gpio pins that must be selected by the user to load switching through relays or electronic devices such as LEDs.

Variable b is an even integer represented by the sum of 2 raised to the power of pin number for pinset actuation. Avoid using pin Gpio 1 on Nodemcu ESP8266, which is pin Tx, as it prevents debug serial communication of the program by the serial monitor, and Gpio pins 06 to 11 on the ESP32 Devkit, as they are used for flash recording.
 
If there is any power failure or power outage, then return to normal, the status of the previous pins when the voltage drop is restored, as the status of the pins is updated and consulted in Firebase, which is a bank of persistent data. The user profile name entered on the website  sanusb.org/espgpio may be alphanumeric (for example: sanusb123 or sandrojuca).

To install the ESP32 board in Arduino IDE, follow these next instructions: In your Arduino IDE, go to File> Preferences. 
Insert into the "Additional Board Manager URLs":

https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json

Open the Boards Manager: Go to Tools > Board > Boards Manager: Search for ESP32 and press install button for the "ESP32 by Espressif Systems". 


To install EspGpio download https://github.com/SanUSB/EspGpio and follow the steps:

Arduino IDE -> Sketch -> Include Library -> Add .zip Libraries.

You can usually find the installed ESP32 and ESP8266 libraries at:

On Windows:

   C:\Users\UserName\Documents\Arduino\libraries (tested)
On Linux:

  /home/UserName/Arduino/Libraries (tested).
On OSX:

  ~/Documents/Arduino/libraries.


In the installed EspGpio library folder there is an example for testing this proposed tool called EspGpioStart.ino.


The EspGpio tool already includes dependencies for the Firebase libraries: 

https://github.com/SanUSB/Firebase_ESP32_Client (old library tested) of https://github.com/mobizt/Firebase-ESP32


After the graphical pin switching is finished, the new verification status is sent to 
https://app.sanusb.org/espgpio/YourProfile/conf.php in order to confirm the remote pin switching. Automatic steps illustration:

![](https://github.com/SanUSB/EspGpio/blob/main/EspGpioStart/espgpio_illustration.png)
 
The EspGpio tool already includes dependencies for the Firebase libraries: 

https://github.com/SanUSB/Firebase_ESP32_Client (old library tested) of https://github.com/mobizt/Firebase-ESP32

Using EspGpio it is not necessary to open ports on the router or enable firewall permissions.

Tutorial: https://youtu.be/QrxweDmkUy4 . See also: https://youtu.be/En_hFO5f4U8 .

*Have fun!*
