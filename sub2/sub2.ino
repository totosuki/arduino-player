#include <U8x8lib.h>

enum Notes { CoA0 = 27, CoAS0 = 29, CoB0 = 31, CoC1 = 33, CoCS1 = 35, CoD1 = 37, CoDS1 = 39, CoE1 = 41, CoF1 = 44, CoFS1 = 46, CoG1 = 49, CoGS1 = 52, CoA1 = 55, CoAS1 = 58, CoB1 = 62, CoC2 = 65, CoCS2 = 69, CoD2 = 73, CoDS2 = 78, CoE2 = 82, CoF2 = 87, CoFS2 = 92, CoG2 = 98, CoGS2 = 104, CoA2 = 110, CoAS2 = 117, CoB2 = 123, CoC3 = 131, CoCS3 = 139, CoD3 = 147, CoDS3 = 156, CoE3 = 165, CoF3 = 175, CoFS3 = 185, CoG3 = 196, CoGS3 = 208, CoA3 = 220, CoAS3 = 233, CoB3 = 247, CoC4 = 262, CoCS4 = 277, CoD4 = 294, CoDS4 = 311, CoE4 = 330, CoF4 = 349, CoFS4 = 370, CoG4 = 392, CoGS4 = 415, CoA4 = 440, CoAS4 = 466, CoB4 = 494, CoC5 = 523, CoCS5 = 554, CoD5 = 587, CoDS5 = 622, CoE5 = 659, CoF5 = 698, CoFS5 = 740, CoG5 = 784, CoGS5 = 831, CoA5 = 880, CoAS5 = 932, CoB5 = 988, CoC6 = 1047, CoCS6 = 1109, CoD6 = 1175, CoDS6 = 1244, CoE6 = 1319, CoF6 = 1397, CoFS6 = 1480, CoG6 = 1568, CoGS6 = 1661, CoA6 = 1760, CoAS6 = 1865, CoB6 = 1976, CoC7 = 2093, CoCS7 = 2217, CoD7 = 2349, CoDS7 = 2489, CoE7 = 2637, CoF7 = 2794, CoFS7 = 2960, CoG7 = 3136, CoGS7 = 3322, CoA7 = 3520, CoAS7 = 3730, CoB7 = 3951, CoC8 = 4186, CoCS8 = 4435, CoD8 = 4699, CoDS8 = 4978 };

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

void shape_one_X(int a,int b,int c){
  mytone(a, 150);
  mydelay(300);
  mytone(b, 150);
  mydelay(300);
  mytone(c, 150);
  mydelay(150);
}

void shape_two_A(int a,int b,int c){
  mytone(a, 450);
  mytone(b, 450);
  mytone(c, 300);
}

void shape_two_B(int a,int b, int c){
  mytone(a, 450);
  mytone(b,150);
  mydelay(300);
  mytone(c,150);
  mydelay(150);
}

void shape_threeLOOP(int a,int b, int c){
  for(int three = 0; three < 3; three++){
      shape_one_X(a,b,c);
    }
}

void  STLOOP(int i){
  for(int ni = 0; ni < i; ni++){
    shape_one_X(CoCS2,CoCS2,CoCS2);
    shape_one_X(CoFS1,CoFS1,CoFS1);
    shape_one_X(CoA1,CoA1,CoA1);
    shape_one_X(CoB2,CoB2,CoB2);
  }
}

void shape_SNDLOOP(int i){
  for(int nj = 0; nj < i; nj++){
    shape_one_X(CoGS2,CoGS2,CoGS2);
    shape_one_X(CoFS2,CoFS2,CoFS2);
    shape_one_X(CoA2,CoA2,CoA2);
    mytone(CoB2, 150);
    mydelay(300);
    mytone(CoB2, 150);
    mydelay(600);
  }
}

void shape_TRDLOOP_A(int i){
  for(int nk = 0; nk < i; nk++){
    shape_two_A(CoCS1,CoCS2,CoCS2);
    shape_two_A(CoFS1,CoFS2,CoFS2);
    shape_two_A(CoA1,CoA2,CoA2);
    shape_two_A(CoB1,CoB2,CoB2);
  }
}

void shape_TRDLOOP_B(int i){
  for(int nl = 0; nl < i; nl++){
    shape_one_X(CoCS1,CoCS2,CoCS2);
    shape_one_X(CoFS1,CoFS2,CoFS2);
    shape_one_X(CoA1,CoA2,CoA2);
    shape_one_X(CoB1,CoB2,CoB2);
  }
}

void shape_TRDLOOP_C(int i){
  for(int nm = 0; nm < i; nm++){
    shape_two_A(CoCS1,CoCS2,CoCS2);
    shape_two_B(CoFS1,CoFS2,CoFS2);
    shape_two_A(CoA1,CoA2,CoA2);
    shape_two_B(CoB1,CoB2,CoB2);
  }
}

void shape_FTHLOOP(){
  shape_one_X(CoCS1,CoCS2,CoCS2);
  shape_one_X(CoFS1,CoFS2,CoFS2);
  shape_one_X(CoA1,CoA2,CoA2);
}

void play_shape_of_you() {
  shape_one_X(CoGS3,CoGS3,CoGS3);
  shape_one_X(CoA3,CoA3,CoA3);
  shape_one_X(CoA3,CoA3,CoA3);
  shape_one_X(CoFS3,CoFS3,CoFS3);
  shape_FSTLOOP(1);
  shape_SNDLOOP(3);
  shape_one_X(CoGS2,CoGS2,CoGS2);
  shape_one_X(CoFS2,CoFS2,CoFS2);
  shape_one_X(CoA2,CoA2,CoA2);
  mytone(CoB2, 150);
  mydelay(1050);
  shape_SNDLOOP(3);
  shape_one_X(CoGS2,CoGS2,CoGS2);
  shape_one_X(CoFS2,CoFS2,CoFS2);
  shape_one_X(CoA2,CoA2,CoA2);
  mytone(CoB2, 150);
  mydelay(1050);
  shape_SNDLOOP(4);

  shape_TRDLOOP_A(4);               // 29 ~ 36.4
  shape_TRDLOOP_B(3);               // 37 ~ 42.4
  shape_FTHLOOP();                  // 44 ~ 44.2
  mytone(CoB1, 150);            // 44.3
  mydelay(1050);
  shape_TRDLOOP_C(3);               // 45 ~ 50.4
  shape_two_A(CoCS1,CoCS2,CoCS2);         // 51 ~ 51.2
  shape_two_A(CoFS1,CoFS2,CoFS2);         // 51.3 ~ 51.4
  mytone(CoA1, 450);
  mytone(CoA2, 450);
  mytone(CoA2, 600);
  mytone(CoGS1,300);
  mytone(CoB1,300);
  mytone(CoCS2,300);
  shape_TRDLOOP_C(8);
  mytone(CoCS2,2400);
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
      // play_prologue();
    }
    else if (value  == 1) {
      u8x8.setCursor(2, 2);
      u8x8.print("Shape of You");
      u8x8.setCursor(7, 5);
      u8x8.print("/2:45");
      play_shape_of_you();
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