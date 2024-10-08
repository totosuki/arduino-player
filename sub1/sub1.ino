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

void shape_FSTLOOP(int i){
  for(int ni = 0; ni < i; ni++){
    shape_one_X(CoCS3,CoCS3,CoCS3);
    shape_one_X(CoFS2,CoFS2,CoFS2);
    shape_one_X(CoA2,CoA2,CoA2);
    shape_one_X(CoB2,CoB2,CoB2);
  }
}

void shape_SNDLOOP(int i){
  for(int nj = 0; nj < i; nj++){
    shape_threeLOOP(CoCS3,CoE3,CoCS3);
    shape_one_X(CoDS3,CoCS3,CoB2);
  }
}

void shape_TRDLOOP_A(int i){
  for(int nk = 0; nk < i; nk++){
    shape_two_A(CoCS2,CoCS3,CoCS3);
    shape_two_A(CoFS2,CoFS3,CoFS3);
    shape_two_A(CoA2,CoA3,CoA3);
    shape_two_A(CoB2,CoB3,CoB3);
  }
}

void shape_TRDLOOP_B(int i){
  for(int nl = 0; nl < i; nl++){
    shape_one_X(CoCS2,CoCS3,CoCS3);
    shape_one_X(CoFS2,CoFS3,CoFS3);
    shape_one_X(CoA2,CoA3,CoA3);
    shape_one_X(CoB2,CoB3,CoB3);
  }
}

void shape_TRDLOOP_C(int i){
  for(int nm = 0; nm < i; nm++){
    shape_two_A(CoCS2,CoCS3,CoCS3);
    shape_two_B(CoFS2,CoFS3,CoFS3);
    shape_two_A(CoA2,CoA3,CoA3);
    shape_two_B(CoB2,CoB3,CoB3);
  }
}

void shape_FTHLOOP(){
  shape_one_X(CoCS2,CoCS3,CoCS3);
  shape_one_X(CoFS2,CoFS3,CoFS3);
  shape_one_X(CoA2,CoA3,CoA3);
}

void play_shape_of_you() {
  shape_FSTLOOP(2);                 // 1 ~ 4.4
  shape_SNDLOOP(3);                 // 5 ~ 10.4
  shape_threeLOOP(CoCS3,CoE3,CoCS3);      // 11 ~ 12.2
  mytone(CoDS3, 150);           // 12.3
  mydelay(1050);
  shape_SNDLOOP(3);                 // 13 ~ 18.4
  shape_threeLOOP(CoCS3,CoE3,CoCS3);      // 19 ~ 20.2
  mytone(CoDS3,150);            // 20.3
  mydelay(150);
  mytone(CoGS2,300);            
  mytone(CoB2,300);             // 20.4
  mytone(CoCS3,300);
  shape_SNDLOOP(4);                 // 21 ~ 28.4
  shape_TRDLOOP_A(4);               // 29 ~ 36.4
  shape_TRDLOOP_B(3);               // 37 ~ 42.4
  shape_FTHLOOP();                  // 44 ~ 44.2
  mytone(CoB2, 150);            // 44.3
  mydelay(1050);
  shape_TRDLOOP_C(3);               // 45 ~ 50.4
  shape_two_A(CoCS2,CoCS3,CoCS3);         // 51 ~ 51.2
  shape_two_A(CoFS2,CoFS3,CoFS3);         // 51.3 ~ 51.4
  mytone(CoA2, 450);
  mytone(CoA3, 450);
  mytone(CoA3, 600);
  mytone(CoGS2,300);
  mytone(CoB2,300);
  mytone(CoCS3,300);
  shape_TRDLOOP_C(8);
  mytone(CoCS3,2400);
}

void MEGA_ONELOOP(int a, int b) {
  mytone(a, 250);
  mytone(a, 250);
  mytone(a, 125);
  mytone(a, 250);
  mytone(b, 125);
  mydelay(125);
  mytone(b, 250);
  mytone(b, 125);
  mytone(b, 125);
  mytone(b, 125);
  mytone(b, 250);
}

void MEGA_TWOLOOP(int a, int b, int c, int d) {
  mytone(a, 250);
  mytone(b, 250);
  mytone(a, 125);
  mytone(a, 125);
  mytone(b, 125);
  mytone(c, 250);
  mytone(c, 125);
  mytone(d, 125);
  mytone(c, 125);
  mytone(c, 125);
  mytone(c, 125);
  mytone(d, 250);
}

void MEGA_TRELOOP(int a) {
  mytone(a, 250);
  mytone(a, 250);
  mytone(a, 125);
  mytone(a, 250);
  mytone(a, 250);
  mytone(a, 250);
  mytone(a, 125);
  mytone(a, 125);
  mytone(a, 125);
  mytone(a, 250);
}

void MEGA_FSTLOOP() {
  MEGA_ONELOOP(CoD3,CoD3);
  MEGA_ONELOOP(CoC3,CoC3);
  MEGA_ONELOOP(CoB2,CoB2);
  MEGA_ONELOOP(CoAS2,CoC3);
}

void MEGA_SNDLOOP(int i) {
  for(int ni = 0; ni < i; ni++) {
    MEGA_TWOLOOP(CoD2,CoD3,CoD2,CoD3);
    MEGA_TWOLOOP(CoC2,CoC3,CoC2,CoC3);
    MEGA_TWOLOOP(CoB1,CoB2,CoB1,CoB2);
    MEGA_TWOLOOP(CoAS1,CoAS2,CoC2,CoC3);
  }
}

void MEGA_TRDLOOP(int j) {
  for(int nj = 0; nj < j; nj++) {
    MEGA_TWOLOOP(CoAS1,CoAS2,CoAS1,CoAS2);
    MEGA_TWOLOOP(CoC2,CoC3,CoC2,CoC3);
    MEGA_TWOLOOP(CoD2,CoD3,CoD2,CoD3);
    MEGA_TWOLOOP(CoCS2,CoCS3,CoDS2,CoDS3);
  }
}

void MEGA_FoTHLOOP(int k) {
  for(int nk = 0; nk < k; nk++) {
    MEGA_TRELOOP(CoAS1);
    MEGA_TRELOOP(CoC2);
    MEGA_TRELOOP(CoB1);
    MEGA_TRELOOP(CoB1);
    MEGA_TRELOOP(CoAS1);
    MEGA_TRELOOP(CoC2);
    MEGA_TRELOOP(CoD2);
    MEGA_TRELOOP(CoD2);
  }
}

void MEGA_fiTHLOOP(int l) {
  for(int nl = 0; nl < l; nl++) {
    MEGA_TWOLOOP(CoAS1,CoAS2,CoAS1,CoAS2);
    MEGA_TWOLOOP(CoC2,CoC3,CoC2,CoC3);
    MEGA_TWOLOOP(CoD2,CoD3,CoCS2,CoCS3);
    MEGA_TWOLOOP(CoC2,CoC3,CoB1,CoB2);
    MEGA_TWOLOOP(CoAS1,CoAS2,CoAS1,CoAS2);
    MEGA_TWOLOOP(CoC2,CoC3,CoC2,CoC3);
    MEGA_TWOLOOP(CoD2,CoD3,CoD2,CoD3);
    MEGA_TWOLOOP(CoD2,CoD3,CoD2,CoD3);
  }
}

void play_megalovanila() {
  mydelay(16000);

  MEGA_FSTLOOP();

  MEGA_SNDLOOP(3);

  mytone(CoD2,125);
  mytone(CoD2,125);
  mytone(CoD3,250);
  mytone(CoD2,125);
  mytone(CoD2,125);
  mytone(CoD3,125);
  mytone(CoD2,250);
  mytone(CoD2,125);
  mytone(CoD3,125);
  mytone(CoD2,125);
  mytone(CoD2,125);
  mytone(CoD2,125);
  mytone(CoD3,125);
  mytone(CoD2,125);

  mytone(CoC2,125);
  mytone(CoC2,125);
  mytone(CoD3,250);
  mytone(CoC2,125);
  mytone(CoC2,125);
  mytone(CoD3,125);
  mytone(CoC2,250);
  mytone(CoC2,125);
  mytone(CoD3,125);
  mytone(CoC2,125);
  mytone(CoC2,125);
  mytone(CoC2,125);
  mytone(CoD3,250);

  mytone(CoB1,125);
  mytone(CoB1,125);
  mytone(CoD3,250);
  mytone(CoB1,125);
  mytone(CoB1,125);
  mytone(CoD3,125);
  mytone(CoB1,250);
  mytone(CoB1,125);
  mytone(CoD3,125);
  mytone(CoB1,125);
  mytone(CoB1,125);
  mytone(CoB1,125);
  mytone(CoD3,250);

  mytone(CoAS1,250);
  mytone(CoD3,250);
  mytone(CoAS1,125);
  mytone(CoAS1,125);
  mytone(CoD3,125);
  mytone(CoC2,250);
  mytone(CoC2,125);
  mytone(CoD3,125);
  mytone(CoC2,125);
  mytone(CoC2,125);
  mytone(CoC2,125);
  mytone(CoD3,250);

  MEGA_TRDLOOP(4);

  MEGA_FoTHLOOP(2);

  MEGA_fiTHLOOP(2);

  mydelay(3000);
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
      play_shape_of_you();
    }
    else if (value == 2) {
      u8x8.setCursor(2, 2);
      u8x8.print("MEGALOVANILA");
      u8x8.setCursor(7, 5);
      u8x8.print("/2:35");
      play_megalovanila();
    }
    min = 0;
    sec = 0;
  }

  beforevalue = value;
}