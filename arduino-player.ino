#include <U8x8lib.h>

enum Notes { CoB2 = 123, CoC3 = 131, CoCS3 = 139, CoD3 = 147, CoDS3 = 156, CoE3 = 165, CoF3 = 175, CoFS3 = 185, CoG3 = 196, CoGS3 = 208, CoA3 = 220, CoAS3 = 233, CoB3 = 247, CoC4 = 262, CoCS4 = 277, CoD4 = 294, CoDS4 = 311, CoE4 = 330, CoF4 = 349, CoFS4 = 370, CoG4 = 392, CoGS4 = 415, CoA4 = 440, CoAS4 = 466, CoB4 = 494, CoC5 = 523, CoCS5 = 554, CoD5 = 587, CoDS5 = 622, CoE5 = 659, CoF5 = 698, CoFS5 = 740, CoG5 = 784, CoGS5 = 831, CoA5 = 880, CoAS5 = 932,  CoB5 = 988, CoC6 = 1047, CoCS6 = 1109, CoD6 = 1175, CoDS6 = 1245, CoE6 = 1319,  CoF6 = 1397, CoFS6 = 1480, CoG6 = 1568, CoGS6 = 1661, CoA6 = 1760, CoAS6 = 1865, CoB6 = 1976 };

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

int beforevalue = -1;
int value = 0;

int min = 0;
int sec = 0;
int buffer = 0;

void mytone(int freq, int dist) {
  tone(5, freq, dist - 50);
  mydelay(dist);
}

void mydelay(int dist) {
  delay(dist);

  buffer += dist;
  while (buffer >= 1000) {
    buffer -= 1000;
    sec += 1;
  }
  if (sec >= 60) {
    sec -= 60;
    min += 1;
  }

  char tmp[3] = "";
  char playtime[5] = {'0',':','0','0','\0'};

  itoa(min, tmp, 10);
  playtime[0] = tmp[0];

  itoa(sec, tmp, 10);
  if (sec < 10) {
    playtime[3] = tmp[0];
  }
  else {
    playtime[2] = tmp[0];
    playtime[3] = tmp[1];
  }

  u8x8.setCursor(3, 5);
  u8x8.print(playtime);
}

void play_prologue() {
  mytone(CoG3, 250);
  mydelay(125);
  mytone(CoG3, 125);
  mytone(CoC4, 500);
  mytone(CoD4, 500);
  mytone(CoE4, 500);
  mytone(CoF4, 500);
  mytone(CoG4, 500);
  mytone(CoC5, 1000);
  mytone(CoB4, 375);
  mytone(CoA4, 125);
  mytone(CoA4, 750);
  mytone(CoG4, 250);
  mydelay(250);
  mytone(CoFS4, 250);
  mytone(CoFS4, 250);
  mytone(CoA4, 250);
  mytone(CoG4, 250);
  mydelay(250);
  mytone(CoE4, 1000);
  mytone(CoE4, 375);
  mytone(CoE4, 125);
  mytone(CoE4, 500);
  mytone(CoE4, 500);
  mytone(CoFS4, 500);
  mytone(CoGS4, 500);
  mytone(CoA4, 1250);
  mytone(CoA4, 250);
  mytone(CoB4, 250);
  mytone(CoC5, 250);
  mytone(CoD5, 1250);
  mytone(CoA4, 250);
  mytone(CoA4, 250);
  mytone(CoC5, 250);
  mytone(CoC5, 500);
  mytone(CoB4, 500);
  mytone(CoA4, 500);
  mytone(CoG4, 500);
  mytone(CoE5, 1250);
  mytone(CoF5, 250);
  mytone(CoE5, 250);
  mytone(CoD5, 250);
  mytone(CoC5, 1000);
  mytone(CoA4, 500);
  mytone(CoC5, 500);
  mytone(CoD5, 1250);
  mytone(CoE5, 250);
  mytone(CoD5, 250);
  mytone(CoC5, 250);
  mytone(CoB4, 1500);
  mytone(CoG4, 500);
  mytone(CoG5, 1250);
  mydelay(250);
  mytone(CoF5, 250);
  mytone(CoG5, 250);
  mytone(CoA5, 1250);
  mytone(CoA4, 250);
  mytone(CoB4, 250);
  mytone(CoC5, 250);
  mytone(CoF5, 1000);
  mytone(CoE5, 1000);
  mytone(CoC5, 1000);
}

void shapeone(){
  mytone(CoCS4, 150);   // 1.1
  mydelay(300);
  mytone(CoE4, 150);
  mydelay(300);         // 1.2
  mytone(CoCS4, 150);
  mydelay(150);
  mytone(CoCS4, 150);   // 1.3
  mydelay(300);
  mytone(CoE4, 150);
  mydelay(300);         // 1.4  
  mytone(CoCS4, 150);
  mydelay(150);
  mytone(CoCS4, 150);   // 2.1
  mydelay(300);
  mytone(CoE4, 150);
  mydelay(300);         // 2.2
  mytone(CoCS4, 150);
  mydelay(150);
  mytone(CoDS4, 150);   // 2.3
  mydelay(300);
  mytone(CoCS4, 150);
  mydelay(300);         // 2.4  
  mytone(CoB3, 150);
  mydelay(150);
}

void shapeseven(){
  mytone(CoB4, 150);    // 7.1
  mytone(CoGS4, 150);
  mytone(CoGS4, 150);
  mytone(CoGS4, 150);
  mydelay(150);         // 7.2
  mytone(CoGS4, 300);
  mytone(CoGS4, 150);
  mytone(CoFS4, 150);   // 7.3
  mytone(CoE4, 150);
  mytone(CoE4, 150);
  mytone(CoE4, 150);
  mydelay(150);         // 7.4
  mytone(CoE4, 150);
  mydelay(150);
  mytone(CoE4, 150);
}

void shapethirteen(){
  mytone(CoCS4, 600);   // 13
  mytone(CoCS4, 300);   
  mytone(CoB3, 300);
  mytone(CoCS4, 300);
  mytone(CoGS4, 300);
  mytone(CoE4, 75);
  mytone(CoFS4, 525);
}

void shapefourteen(){
  mytone(CoFS4, 150);   // 14
  mytone(CoFS4, 300);
  mytone(CoGS4, 150);
  mytone(CoFS4, 300);   // 14.2
  mytone(CoE4, 300);
  mytone(CoCS4, 300);   // 14.3
  mytone(CoE4, 300);
  mytone(CoGS4, 150);
  mytone(CoFS4, 150);
  mytone(CoE4, 300);
}

void shapetwentyone(){
  mytone(CoCS4, 150);
  mytone(CoE4, 150);
  mytone(CoFS4, 150);
  mytone(CoGS4, 300);   // 21.3
  mytone(CoFS4, 150);
  mytone(CoE4, 150);
  mytone(CoE4, 300);    // 21.4
  mytone(CoFS4, 300);
}

void shapetwentynine(){
  mytone(CoCS4, 300);   // 29
  mytone(CoCS4, 300);
  mytone(CoE4, 300);
  mytone(CoE4, 300);
  mytone(CoFS4, 300);
  mytone(CoFS4, 300);
  mytone(CoGS4, 300);
  mytone(CoGS4, 300);
  mydelay(750);         // 30
  mytone(CoCS4, 150);
  mytone(CoE4, 150);
  mytone(CoFS4, 150);
  mytone(CoGS4, 300);   // 30.3
  mytone(CoFS4, 150);
  mytone(CoE4, 150);
  mytone(CoE4, 600);    // 30.4
}

void shapehalf(){
  mytone(CoCS4, 300);   // 5.1
  mytone(CoCS4, 300);
  mytone(CoCS4, 150);   // 5.2
  mytone(CoCS4, 300);
  mytone(CoCS4, 150);
  mydelay(150);         // 5.3
  mytone(CoCS4, 300);
  mytone(CoCS4, 150);
  mydelay(150);         // 5.4
  mytone(CoCS4, 300);
  mytone(CoCS4, 150);
  mytone(CoCS4, 300);   // 6.1
  mytone(CoCS4, 300);
  mytone(CoE4, 150);    // 6.2
  mytone(CoGS4, 150);
  mydelay(150);
  mytone(CoGS4, 150);
  mydelay(150);         // 6.3
  mytone(CoFS4, 1050);
    shapeseven();
  mytone(CoFS4, 300);   // 8.1
  mytone(CoGS4, 150);
  mydelay(150);
  mytone(CoFS4, 150);   // 8.2
  mytone(CoE4, 150);
  mydelay(150);
  mytone(CoCS4, 750);
  mydelay(600);         // 8.4
    shapeseven();
  mytone(CoE4, 300);    // 10.1
  mytone(CoE4, 300);
  mytone(CoFS4, 150);   // 10.2
  mytone(CoGS4, 150);
  mydelay(150);
  mytone(CoGS4, 150);
  mydelay(150);         // 10.3
  mytone(CoFS4, 1050);
    shapeseven();
  mytone(CoFS4, 300);   // 12.1
  mytone(CoGS4, 150);
  mydelay(150);
  mytone(CoFS4, 150);   // 12.2
  mytone(CoE4, 150);
  mydelay(150);
  mytone(CoCS4, 300);
  mydelay(150);
  mytone(CoGS3, 300);
  mytone(CoB3, 300);    // 12.4
  mytone(CoCS4, 300);
    shapethirteen();
    shapefourteen();
  mytone(CoCS4, 600);   // 15
  mytone(CoB4, 150);
  mytone(CoGS4, 150);
  mytone(CoGS4, 300);
  mytone(CoFS4, 150);
  mytone(CoE4, 150);
  mytone(CoE4, 300);
  mytone(CoCS4, 600);
    shapefourteen();
    shapethirteen();
    shapefourteen();
  mytone(CoCS4, 600);   // 19
  mytone(CoB4, 150);
  mytone(CoGS4, 150);
  mytone(CoGS4, 300);
  mytone(CoFS4, 150);
  mytone(CoE4, 150);
  mytone(CoE4, 300);
  mytone(CoCS4, 600);
  mytone(CoFS4, 150);   // 20.1
  mytone(CoFS4, 300);
  mytone(CoGS4, 150);
  mytone(CoFS4, 300);   // 20.2
  mytone(CoE4, 300);
  mytone(CoCS4, 300);   // 20.3
  mytone(CoGS3, 300);
  mytone(CoB3, 300);
  mytone(CoCS4, 300);
  mydelay(750);         // 21
    shapetwentyone();
  mytone(CoFS4, 600);   // 22
  mydelay(100);         // 22.2
    shapetwentyone();
  mytone(CoCS4, 600);   // 23
  mydelay(150);         // 23.2
    shapetwentyone();
  mytone(CoFS4, 600);   // 24
  mytone(CoCS4, 150);
  mytone(CoE4, 150);
  mytone(CoFS4, 300);
  mytone(CoGS4, 300);   // 24.3
  mytone(CoFS4, 150);
  mytone(CoE4, 150);
  mytone(CoE4, 600);
  mydelay(900);         // 25
  mytone(CoFS4, 300);
  mytone(CoGS4, 300);
  mytone(CoB4, 150);
  mytone(CoGS4, 150);
  mytone(CoFS4, 300);
  mytone(CoE4, 300);
  mytone(CoFS4, 600);   // 26.1
  mydelay(150);         // 26.2
    shapetwentyone();
  mytone(CoCS4, 300);   // 27.1
  mytone(CoCS4, 150);
  mytone(CoCS4, 150);
  mytone(CoCS4, 150);
  mytone(CoE4, 150);
  mytone(CoFS4, 150);
  mytone(CoGS4, 150);
  mydelay(300);         // 27.3
  mytone(CoCS4, 300);
  mytone(CoE4, 300);
  mytone(CoFS4, 300);
  mytone(CoFS4, 600);   // 28.1
  mydelay(150);
    shapetwentyone();
    shapetwentynine();
    shapetwentynine();
  mytone(CoCS4, 300);   // 33
  mytone(CoCS4, 300);
  mytone(CoE4, 300);
  mytone(CoE4, 300);
  mytone(CoFS4, 300);
  mytone(CoFS4, 300);
  mytone(CoGS4, 300);
  mytone(CoGS4, 300);
  mydelay(750);         // 34
  mytone(CoCS4, 150);
  mytone(CoE4, 150);
  mytone(CoFS4, 150);
  mytone(CoGS4, 300);   // 34.3
  mytone(CoFS4, 150);
  mytone(CoE4, 150);
  mytone(CoE4, 450);    // 34.4
  mytone(CoCS4, 150);
  mydelay(750);         // 35
  mytone(CoCS4, 150);
  mytone(CoE4, 150);
  mytone(CoFS4, 150);
  mytone(CoGS4, 300);
  mytone(CoCS4, 300);
  mytone(CoE4, 300);
  mytone(CoFS4, 300);
  mytone(CoFS4, 600);   // 36
  mytone(CoCS4, 150);
  mytone(CoE4, 150);
  mytone(CoFS4, 150);
  mytone(CoGS4, 150);
  mydelay(150);
  mytone(CoGS4, 150);
  mytone(CoFS4, 150);
  mytone(CoE4, 150);
}

void play_shape_of_you() {
  shapeone();           // 1 ~ 2.2
  shapeone();           // 3 ~ 4.2
  shapehalf();
  mytone(CoFS4, 600);   // 36.4
  shapehalf();
  mytone(CoFS4, 300);   // 68.4
  mytone(CoGS4, 300);
  mytone(CoCS5, 2400);  // 70
}

void clear_display() {
  for (int i=0;i<8;i++) {
    u8x8.setCursor(0, i);
    u8x8.print("               ");
  }
}

void setup() {
  Serial.begin(9600);
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_8x13B_1x2_f);
}

void loop() {
  value = analogRead(A0);
  value = map(value, 0, 1023, 0, 3);

  if (value != beforevalue) {
    clear_display();

    if (value == 0) {
      u8x8.setCursor(2, 3);
      u8x8.print("  Prologue  ");
    }
    else if (value == 1) {
      u8x8.setCursor(2, 3);
      u8x8.print("Shape of You");
    }
    else if (value == 2) {
      u8x8.setCursor(2, 3);
      u8x8.print("Nanika");
    }
  }

  if (digitalRead(6) == 1) {
    clear_display();
    if (value == 0) {
      u8x8.setCursor(2, 2);
      u8x8.print("  Prologue  ");
      play_prologue();
    }
    else if (value  == 1) {
      u8x8.setCursor(2, 2);
      u8x8.print("Shape of You");
      play_shape_of_you();
    }
    else if (value == 2) {
      u8x8.setCursor(2, 2);
      u8x8.print("   Nanika   ");
    }
  }

  beforevalue = value;
}
