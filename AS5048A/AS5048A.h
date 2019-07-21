#ifndef AS5048A_h
#define AS5048A_h

#include "SPI.h"

//stm32 (Blue Pill) wiring :
// CS to PA4 , CLK to PA5 , MOSI to 3.3V , MISO to PA6
//UNO wiring :
//CS to PIN 10 , CLK to PIN 13 , MOSI to 5v , MISO to PIN 12

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

/// globals
extern  uint16_t old_result_AS5048A ;
extern	uint32_t previousMillis_AS5048A ;
extern  int16_t diff_AS5048A;
extern  int DIR_AS5048A;
extern  int16_t res_info_AS5048A;


class AS5048A{
	
	public:
	
		// Constructor
		AS5048A(int chipSelectPin);
		// Methods
		void get_info(int sample);
		void SPI_setup();
		void end_SPI();
		uint16_t get_raw();
		uint16_t get_pos();
		bool get_DIR();
		float get_speed();
		
	 private:
	 
		int sample_all;
		int value;
      
    
};


#endif
