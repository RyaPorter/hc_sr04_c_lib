# HC-SR04 C library
A small library for controlling the HC-SR04 ultrasonic sensor.

I had the `Echo` and `Trigger` pins on GPIO 10 and 11 respectively. I was also using the RPi Pico so the code assumes the presence of the `pico_sdk`. Macros are provided in `sdk_wrapper.h` to easily change system functions used by the code like gpio pins and sleeping.
