#include <AS5048A.h>
#define CS PA4

#define sample 50
// define our CS PIN
AS5048A ABS(CS);

int pos =0;
int  dir_ =0 ;
float sped = 0;

void setup() {

  
Serial.begin(9600);
// set up SPI 
ABS.SPI_setup();

}

void loop() {
// gives you position value , does not need ABS.get_info
/// pos = ABS.get_raw(); 


/// place this in your main loop, and it will update every sample time you defined
ABS.get_info(sample);

/// now you can call any of these and get speed, direction or position
dir_  = ABS.get_DIR();
//Serial.println(dir_ );
pos= ABS.get_pos();
//Serial.println(pos);
sped = ABS.get_speed();
//Serial.println(sped,8);



}
