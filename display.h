//display code from https://github.com/lora-aprs/LoRa_APRS_Tracker
//

#ifndef DISPLAY_H_
#define DISPLAY_H_

#define OLED_SDA		21
#define OLED_SCL		22
#define OLED_RESET		16

void setup_display();
void clear_display();

void show_display(String header, String line1, String line2, int wait = 0);

#endif
