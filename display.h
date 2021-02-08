#ifndef DISPLAY_H_
#define DISPLAY_H_

#define OLED_SDA		21
#define OLED_SCL		22
//#define OLED_RESET		16

void setup_display();
void turn_off_display();
void clear_display();

void show_display(String header, int wait = 0);
void show_display(String header, String line1, int wait = 0);
void show_display(String header, String line1, String line2, int wait = 0);
void show_display(String header, String line1, String line2, String line3, int wait = 0);
void show_display(String header, String line1, String line2, String line3, String line4, int wait = 0);
void show_display(String header, String line1, String line2, String line3, String line4, String line5, int wait = 0);

#endif
