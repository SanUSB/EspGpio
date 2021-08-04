# EspGpio[![N|Solid](http://sanusb.blogspot.com.br/favicon.ico)](http://sanusb.org/)
This project shows an IoT ESP32 and ESP266 microcontrollers pins switching.

This project for all shows an ESP32 and ESP266 microcontrollers Update Environment for Internet programming with same generic sketch using the website  [sanusb.org/espgpio](http://sanusb.org/espupdate). In this project, the free version of Firebase (Google JSON objects Database) was implemented to generate the cloud update trigger for .bin files. 

This project shows an ESP32 and ESP266 microcontrollers pins switching for graphical access with same generic sketch  using the website [sanusb.org/espgpio](http://sanusb.org/espupdate). In this project, the free version of Firebase (Google JSON objects Database) was  implemented to allow the IoT interaction between the users and the remote ESP microcontrollers.

The graphical environment generated at [sanusb.org/espgpio](http://sanusb.org/espupdate) has 30 gpio pins that must be selected by the user to load switching through relays or electronic devices such as LEDs.

Variable b is an even integer represented by the sum of powers of 2 for pinset actuation. Avoid using pin Gpio 1 on Nodemcu ESP8266, which is pin Tx, as it prevents debug serial communication of the program by the serial monitor, and Gpio pins 06 to 11 on the ESP32 Devkit, as they are used for flash recording.
 
If there is any power failure or power outage, then return to normal, the status of the previous pins when the voltage drop is restored, as the status of the pins is updated and consulted in Firebase, which is a bank of persistent data. The user profile name entered on the website  sanusb.org/espgpio may be alphanumeric (for example: sanusb123 or sandrojuca).

To install the ESP32 and ESP8266 boards in Arduino IDE, follow these next instructions: In your Arduino IDE, go to File> Preferences. 
Insert into the "Additional Board Manager URLs":

https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
Open the Boards Manager: Go to Tools > Board > Boards Manager: Search for ESP32 and press install button for the "ESP32 by Espressif Systems". Also search for ESP8266 and press install button for the "ESP8266 by ESP8266 Community".

The dependencies of the EspGpio tool are the Firebase libraries. For ESP8266:

https://github.com/mobizt/Firebase-ESP8266

For ESP32:

https://github.com/mobizt/Firebase-ESP32

To install all the libraries, including https://github.com/SanUSB/EspGpio , follow the steps:

Arduino IDE -> Sketch -> Include Library -> Add .zip Libraries.

You can usually find the installed ESP32 and ESP8266 libraries at:

On Windows:

   C:\Users\UserName\Documents\Arduino\libraries (tested)
On Linux:

  /home/UserName/Arduino/Libraries (tested).
On OSX:

  ~/Documents/Arduino/libraries.
In the installed EspGpio library folder there is an example for testing this proposed tool called EspGpioStart.ino.


After the graphical pin switching is finished, the new verification status is sent to 
http://sanusb.org/espgpio/YourProfile/conf.php in order to confirm the remote pin switching.
 
Using EspGpio it is not necessary to open ports on the router or enable firewall permissions.

Tutorial: https://youtu.be/qVwPTHlmpDM. See also: https://youtu.be/En_hFO5f4U8.

*Have fun!*
