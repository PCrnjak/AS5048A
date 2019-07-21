# AS5048A
 Library for AS5048A encoder 

## Library

* Using this library you can check direction of rotation , speed and position .
* Tested on arduino uno and STM32 blue pill.
* encoder should be connected like this:

1. stm32 (Blue Pill) wiring : CS to PA4 , CLK to PA5 , MOSI to 3.3V , MISO to PA6

2. UNO wiring :CS to PIN 10 , CLK to PIN 13 , MOSI to 5v , MISO to PIN 12

* you can find example code in AS5048_example



## Rotary Magnetic Holder ,used to test and evaluate your sensor

STL folder contains files for encoder testing jig.
Design is compatible only with these test [boards](https://www.aliexpress.com/item/32978099591.html?spm=a2g0s.9042311.0.0.33344c4dNwWwRd)
There are 2 versions (both use same wheel stl file): 
- encoder_housing , uses no ball bearing 
  - encoder_housing_no_bearing , uses 15x28x7 ball bearing

both models also need 2 M2 5mm screws
 

<img src="https://user-images.githubusercontent.com/30388414/61593399-49756d80-abdf-11e9-98f9-847e967b6eda.jpg" width="400"> <img src="https://user-images.githubusercontent.com/30388414/61593393-39f62480-abdf-11e9-83a3-a46f03c20ad5.jpg" width="400">
