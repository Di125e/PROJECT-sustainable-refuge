# PROJECT-sustainable-refuge
Taking the idea of ​​a bus stop as a shelter, it will be made of bamboo and will have various functions such as solar power, irrigation control, panic button, bus viewer, and light and motion sensors.
Firstly, wireless communication has been developed using LoRa technology, which uses a type of radiofrequency modulation.
The HELTEC board brings at your disposal its own library based on ESP32+LoRa, which apart from being compatible with ESP32 includes WiFi kit, Wireless Stick and Wireelss Shell.
For the electrical system used, pins 33 (Buzzer) 38 (Button) 25 (LED) have been established guided by the datasheet of the Heltec ESP32 LoRa board. 20K resistors have also been used for the push button and LED.
In the connection sector, the emitting LoRa has been assigned a panic button that will be located in the shelter, which when pressed will emit an immediate signal to a receiver within the range of 2km verified, it will make an alert sound, by means of a buzzer and a led will turn on. These will not be turned off until the button on the LoRa receiver is touched, meanwhile the two will be in a loop of corresponding images
