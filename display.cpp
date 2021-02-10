//display code from https://github.com/lora-aprs/LoRa_APRS_Tracker
//

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#include "display.h"

Adafruit_SSD1306 display(128, 64, &Wire);

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
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false))
	{
		Serial.println("SSD1306 allocation failed");
		while (1);
	}
	Serial.println("Display init done!");
}
void clear_display()
{
  display.clearDisplay();
  display.display();
}

void turn_off_display()
{
	display.ssd1306_command(SSD1306_DISPLAYOFF);
}

void show_display(String header, int wait)
{
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.setCursor(0,0);
	display.println(header);
	display.display();
	delay(wait);
  display.clearDisplay();
  delay(wait);
}

void show_display(String header, String line1, int wait)
{
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.setCursor(0,0);
	display.println(header);
	display.setTextSize(1);
	display.setCursor(0,16);
	display.println(line1);
	display.display();
  delay(wait);
}

void show_display(String header, String line1, String line2, int wait)
{
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.setCursor(0,0);
	display.println(header);
	display.setTextSize(1);
	display.setCursor(0,16);
	display.println(line1);
	display.setCursor(0,26);
	display.println(line2);
	display.display();
  delay(wait);
}

void show_display(String header, String line1, String line2, String line3, int wait)
{
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.setCursor(0,0);
	display.println(header);
	display.setTextSize(1);
	display.setCursor(0,16);
	display.println(line1);
	display.setCursor(0,26);
	display.println(line2);
	display.setCursor(0,36);
	display.println(line3);
	display.display();
  delay(wait);
}

void show_display(String header, String line1, String line2, String line3, String line4, int wait)
{
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.setCursor(0,0);
	display.println(header);
	display.setTextSize(1);
	display.setCursor(0,16);
	display.println(line1);
	display.setCursor(0,26);
	display.println(line2);
	display.setCursor(0,36);
	display.println(line3);
	display.setCursor(0,46);
	display.println(line4);
	display.display();
  delay(wait);
}

void show_display(String header, String line1, String line2, String line3, String line4, String line5, int wait)
{
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.setCursor(0,0);
	display.println(header);
	display.setTextSize(1);
	display.setCursor(0,16);
	display.println(line1);
	display.setCursor(0,26);
	display.println(line2);
	display.setCursor(0,36);
	display.println(line3);
	display.setCursor(0,46);
	display.println(line4);
	display.setCursor(0,56);
	display.println(line5);
	display.display();
  delay(wait);
}