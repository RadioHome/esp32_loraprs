//display code from https://github.com/lora-aprs/LoRa_APRS_Tracker
//

#include <Wire.h>
//#include <Adafruit_SSD1306.h>
#include <U8x8lib.h>
#include <U8g2lib.h>

#include "display.h"
//Oled 
//U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display (U8G2_R0, OLED_RESET);


void setup_display()
{
#ifdef OLED_RESET
	pinMode(OLED_RESET, OUTPUT);
	digitalWrite(OLED_RESET, LOW);
	delay(20);
	digitalWrite(OLED_RESET, HIGH);
#endif

  Serial.println("Setup screen...");
	Wire.begin(OLED_SDA, OLED_SCL);
	if(!display.begin())
	{
		Serial.println("Oled allocation failed");
		while (1);
	}
	Serial.println("Display init done!");
}
void clear_display()
{
  display.clearDisplay();
  display.display();
}

void show_display(String header, String line1, String line2, int wait)
{
	display.clearBuffer();
	display.setFont(u8g2_font_ncenB10_tf);
  display.drawStr(0, 16, header.c_str());
  display.setFont(u8g2_font_ncenB08_tf);
  display.drawStr(0, 32, line1.c_str());
  display.drawStr(0, 48, line2.c_str());
  display.sendBuffer();
  delay(wait);
}
