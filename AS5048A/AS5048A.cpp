
#include "AS5048A.h"




#define AS5048A_resolution  0.02197399
float AS5048A_resolution_in_rad = AS5048A_resolution * 0.01745329 ; 

/// globals 
  uint16_t old_result_AS5048A ;
  uint32_t previousMillis_AS5048A ;  
  int16_t diff_AS5048A;
  int DIR_AS5048A;
  int16_t res_info_AS5048A;
  
  
  
  
  
AS5048A::AS5048A(int chipSelectPin ){
  value = chipSelectPin;
  pinMode(value, OUTPUT);
  
}


/// sets up our SPI communication parameters
void AS5048A::SPI_setup(){  
  
SPI.begin();
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode (SPI_MODE1) ;
if (F_CPU == 16000000UL){
    SPI.setClockDivider(SPI_CLOCK_DIV2);  
}else if(F_CPU == 72000000UL){
    SPI.setClockDivider(SPI_CLOCK_DIV8);  
}
 
}



/// ends SPI communication
void AS5048A::end_SPI(){
	SPI.end();
}



/// tells us position .
/// does not depend on any other function .
/// call this if you dont care about direction and speed or you want to calculate it yourself.
uint16_t AS5048A::get_raw(){
  
uint16_t result ;
uint16_t result1 ;
uint16_t result2 ;
digitalWrite(value, LOW);
result1 = SPI.transfer(0b00000000);
result1 &= 0b00111111;  
result1 = result1 << 8;
result2 = SPI.transfer(0b00000000); 
result = result1 | result2;
digitalWrite(value, HIGH);
return result; 

}



/// samples position every sample_all time
/// using that we can get position, direction and speed
void AS5048A::get_info(int sample){
 
 
  sample_all = sample ;
  uint32_t currentMillis = millis();
 
  
// We take sample every sample_all . Time is in ms 
if(currentMillis-previousMillis_AS5048A >= sample_all ){
  previousMillis_AS5048A=currentMillis;
  res_info_AS5048A = AS5048A::get_raw();
  diff_AS5048A=res_info_AS5048A-old_result_AS5048A;

 
 if (diff_AS5048A==0){
  //do nothing
}else if (abs(diff_AS5048A) < 8192 ){  // if angle changes less then 180 deg
 // if diff_AS5048A is positive we are rotating clockwise
 // if diff_AS5048A is negative we are rotating counterclockwise

     if (diff_AS5048A > 0)
        DIR_AS5048A = 1;     // rotating clockwise
     else
        DIR_AS5048A = 0;    // rotating counterclockwise
}
old_result_AS5048A=res_info_AS5048A; 

}
}



/// tells us direction 1 clockwise, 0 counterclockwise
/// call this only if you have  "get_info" in your main loop
bool AS5048A::get_DIR(){
bool val;
val = DIR_AS5048A;
return val;
}



/// tells us position , same as "get_raw" but it is always updated by "get_info"
/// if you want to know position in that exact moment in code call "get_raw"
/// call this only if you have  "get_info" in your main loop
uint16_t AS5048A::get_pos(){
	uint16_t pos;
	pos = res_info_AS5048A;
	return pos;
}



/// calculates speed in rad/s 
/// call this only if you have "get_info" in your main loop
float AS5048A::get_speed(){
	float speed;
	speed = ((abs(diff_AS5048A)*AS5048A_resolution_in_rad)/(sample_all / 1000.0));	// in rad/s ??
    Serial.println(AS5048A_resolution_in_rad,8);
	return speed;

}