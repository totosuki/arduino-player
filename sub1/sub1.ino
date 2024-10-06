#include <U8x8lib.h>

enum Notes { CoB2 = 123, CoC3 = 131, CoCS3 = 139, CoD3 = 147, CoDS3 = 156, CoE3 = 165, CoF3 = 175, CoFS3 = 185, CoG3 = 196, CoGS3 = 208, CoA3 = 220, CoAS3 = 233, CoB3 = 247, CoC4 = 262, CoCS4 = 277, CoD4 = 294, CoDS4 = 311, CoE4 = 330, CoF4 = 349, CoFS4 = 370, CoG4 = 392, CoGS4 = 415, CoA4 = 440, CoAS4 = 466, CoB4 = 494, CoC5 = 523, CoCS5 = 554, CoD5 = 587, CoDS5 = 622, CoE5 = 659, CoF5 = 698, CoFS5 = 740, CoG5 = 784, CoGS5 = 831, CoA5 = 880, CoAS5 = 932,  CoB5 = 988, CoC6 = 1047, CoCS6 = 1109, CoD6 = 1175, CoDS6 = 1245, CoE6 = 1319,  CoF6 = 1397, CoFS6 = 1480, CoG6 = 1568, CoGS6 = 1661, CoA6 = 1760, CoAS6 = 1865, CoB6 = 1976 };

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

int beforevalue = -1;
int value = 0;

int min = 0;
int sec = 0;
int buffer = 0;

void mytone(int freq, int dist) {
  tone(5, freq * 4, dist - 10);
  mydelay(dist);
}

void mydelay(int dist) {
  unsigned long st = millis();

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

  while (millis() - st < dist) {
    // 何も処理をせず待機
  }
}

void play_prologue() {
  mytone(CoC4, 500);  // 2
  mytone(CoB3, 500); 
  mytone(CoA3, 500);
  mytone(CoG3, 500);
  mytone(CoE3, 1000); // 3
  mytone(CoF3, 1000);
  mytone(CoC4, 500);  // 4
  mytone(CoG3, 500);
  mytone(CoC3, 500); 
  mytone(CoG3, 500); 
  mytone(CoC3, 500);  // 5
  mytone(CoE3, 500);
  mytone(CoG3, 500); 
  mytone(CoC4, 500); 
  mytone(CoE3, 500);  // 6
  mytone(CoD4, 500); 
  mytone(CoC4, 500);
  mytone(CoB3, 500);
  mytone(CoA3, 500);  // 7
  mytone(CoB3, 500); 
  mytone(CoC4, 500);
  mytone(CoA3, 500); 
  mytone(CoFS3, 500); // 8
  mytone(CoA3, 500); 
  mytone(CoD4, 500);
  mytone(CoFS3, 500); 
  mytone(CoG3, 500);  // 9
  mytone(CoA3, 500); 
  mytone(CoB3, 500);
  mytone(CoG3, 500);
  mytone(CoE3, 500);  // 10
  mytone(CoGS3, 500); 
  mytone(CoB3, 500);
  mytone(CoE3, 500);
  mytone(CoA3, 500);  // 11
  mytone(CoB3, 500); 
  mytone(CoC4, 500);
  mytone(CoA3, 500); 
  mytone(CoFS3, 500); // 12
  mytone(CoA3, 500); 
  mytone(CoD4, 500); 
  mytone(CoFS3, 500);
  mytone(CoG3, 500);  // 13
  mytone(CoA3, 500);
  mytone(CoB3, 500); 
  mytone(CoG3, 500); 
  mytone(CoCS3, 500); // 14
  mytone(CoE3, 500);
  mytone(CoA3, 500);
  mytone(CoCS3, 500);
  mytone(CoD3, 500);  // 15
  mytone(CoE3, 500); 
  mytone(CoF3, 500); 
  mytone(CoD3, 500);
  mydelay(500);       // 16
  mytone(CoG3, 500);
  mydelay(500);
  mytone(CoG3, 500);
  mytone(CoC3, 500);  // 17
  mytone(CoE3, 500);
  mytone(CoC4, 500);
  mydelay(500);
  // 18 END
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
      u8x8.print("MEGALOVANILA");
    }
  }

  if (digitalRead(6) == 1) {
    clear_display();
    if (value == 0) {
      u8x8.setCursor(2, 2);
      u8x8.print("  Prologue  ");
      u8x8.setCursor(7, 5);
      u8x8.print("/0:31");
      play_prologue();
    }
    else if (value  == 1) {
      u8x8.setCursor(2, 2);
      u8x8.print("Shape of You");
      u8x8.setCursor(7, 5);
      u8x8.print("/2:45");
      // play_shape_of_you();
    }
    else if (value == 2) {
      u8x8.setCursor(2, 2);
      u8x8.print("MEGALOVANILA");
      u8x8.setCursor(7, 5);
      u8x8.print("/2:35");
      // play_megalovanila();
    }
    min = 0;
    sec = 0;
  }

  beforevalue = value;
}