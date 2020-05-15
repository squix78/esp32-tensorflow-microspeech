# esp32-tensorflow-microspeech

ESP32 wake word detection with tensor flow. This project demonstrates how signals from a I2S microphone can be 
processed to detect keywords such as "yes" and "no".

## Hardware

This project is running on the [LillyGo TTGO T-Camera](https://www.banggood.com/custlink/vKDDuGnnRQ) and nearly reaches
5 inferences per second.

## Running the code

Download/ clone this repository and open it with Platformio in VSCode. Compile it and flash it to your ESP32. The board
requires a microphone to properly work.

## Credits

This sample was created based on the [TinyML](https://www.oreilly.com/library/view/tinyml/9781492052036/) book by 
Pete Warden, Daniel Situnayake. Getting the code to run in platformio for ESP32 and the Arduino platform was done with the 
help of Wezley Sherman's [Medium Blog Post](https://towardsdatascience.com/tensorflow-meet-the-esp32-3ac36d7f32c7)
