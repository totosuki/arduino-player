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

void MEGA_ONELOOP(int i) {
  mytone(i, 125);
  mytone(i, 125);
  mytone(CoD5, 250);

  mytone(CoA4, 375);
  mytone(CoGS4, 187.5);
  mydelay(62.5);
  mytone(CoG4, 250);
  mytone(CoF4, 250);
  mytone(CoD4, 125);
  mytone(CoF4, 125);
  mytone(CoG4, 125);
}

void MEGA_TWOLOOP(int j,int k) {
  mytone(j,250);
  mytone(j,250);
  mydelay(125);
  mytone(j,250);
  mytone(k,250);
  mytone(k,250);
  mydelay(375);
  mytone(k,250);
}

void MEGA_FSTLOOP(int l) {
  for(int nl = 0; nl < l; nl++){
    MEGA_ONELOOP(CoD4);
    MEGA_ONELOOP(CoC4);
    MEGA_ONELOOP(CoB3);
    MEGA_ONELOOP(CoAS3);
  }
}

void MEGA_SNDLOOP(int m){
  for(int nm = 0; nm < m; nm++){
    mydelay(1000);
    mytone(CoF4, 125);
    mytone(CoD4, 125);
    mytone(CoF4, 125);
    mytone(CoG4, 125);
    mytone(CoGS4, 125);
    mytone(CoG4, 125);
    mytone(CoF4, 125);
    mytone(CoD4, 125);

    mytone(CoGS4, 62.5);
    mytone(CoG4, 62.5);
    mytone(CoF4, 62.5);
    mytone(CoD4, 62.5);
    mytone(CoF4, 250);
    mytone(CoG4, 1125);
    mytone(CoGS4, 250);
    mytone(CoA4, 125);

    mytone(CoC5, 250);
    mytone(CoA4, 125);
    mytone(CoGS4, 125);
    mytone(CoG4, 125);
    mytone(CoF4, 125);
    mytone(CoD4, 125);
    mytone(CoE4, 125);
    mytone(CoF4, 250);
    mytone(CoG4, 250);
    mytone(CoA4, 250);
    mytone(CoC5, 250);

    mytone(CoCS5, 250);
    mytone(CoGS4, 250);
    mytone(CoGS4, 125);
    mytone(CoG4, 125);
    mytone(CoF4, 125);
    mytone(CoG4, 1125);

    mytone(CoF4, 250);
    mytone(CoG4, 250);
    mytone(CoA4, 250);
    mytone(CoF5, 250);
    mytone(CoE5, 500);
    mytone(CoD5, 500);

    mytone(CoE5, 500);
    mytone(CoF5, 500);
    mytone(CoG5, 500);
    mytone(CoE5, 500);

    mytone(CoA5, 1000);
    mytone(CoA5, 125);
    mytone(CoGS5, 125);
    mytone(CoG5, 125);
    mytone(CoFS5, 125);
    mytone(CoF5, 125);
    mytone(CoE5, 125);
    mytone(CoDS5, 125);
    mytone(CoD5, 125);

    mytone(CoCS5, 1000);
    mytone(CoDS5, 1000);

  
  }
}

void MEGA_TRDLOOP_A(int n){
  for(int nn = 0; nn < n; nn++){
    MEGA_TWOLOOP(CoAS3,CoAS3);
    MEGA_TWOLOOP(CoC4,CoC4);
    MEGA_TWOLOOP(CoD4,CoCS4);
    MEGA_TWOLOOP(CoC4,CoB3);
  }
}

void MEGA_TRDLOOP_B(int o){
  for(int no = 0; no < o; no++){
    MEGA_TWOLOOP(CoAS3,CoAS3);
    MEGA_TWOLOOP(CoC4,CoC4);
    MEGA_TWOLOOP(CoD4,CoD4);
    MEGA_TWOLOOP(CoD4,CoD4);
  }
}

void MEGA_TRDLOOP() {
  MEGA_TRDLOOP_A(1);
  MEGA_TRDLOOP_B(1);
  MEGA_TRDLOOP_A(1);
  MEGA_TRDLOOP_B(1);
}

void play_megalovanila() {
  MEGA_FSTLOOP(4);

  mytone(CoF4, 250);
  mytone(CoF4, 125);
  mytone(CoF4, 125);
  mydelay(125);
  mytone(CoF4, 250);
  mytone(CoF4, 250);
  mytone(CoD4, 250);
  mytone(CoD4, 500);
  mydelay(125);

  mytone(CoF4, 250);
  mytone(CoF4, 125);
  mytone(CoF4, 125);
  mydelay(125);
  mytone(CoG4, 250);
  mytone(CoGS4, 250);
  mytone(CoG4, 41);   //
  mydelay(1);
  mytone(CoG4, 41); //  微調整区間 125ms
  mydelay(1);
  mytone(CoG4, 41);   //
  mytone(CoF4, 125);
  mytone(CoD4, 125);
  mytone(CoF4, 125);
  mytone(CoG4, 125);
  mydelay(250);

  mytone(CoF4, 250);
  mytone(CoF4, 125);
  mytone(CoF4, 125);
  mydelay(125);
  mytone(CoG4, 250);
  mytone(CoGS4, 125);
  mydelay(125);
  mytone(CoA4, 250);
  mytone(CoC5, 250);
  mytone(CoA4, 375);

  mytone(CoD5, 250);
  mytone(CoD5, 250);
  mytone(CoD5, 125);
  mytone(CoA4, 125);
  mytone(CoD5, 125);
  mytone(CoC5, 625);
  mytone(CoG5, 500);

  mytone(CoA5, 250);
  mytone(CoA5, 125);
  mytone(CoA5, 125);
  mydelay(125);
  mytone(CoA5, 250);
  mytone(CoA5, 250);
  mytone(CoG5, 125);
  mydelay(125);
  mytone(CoG5, 625);

  mytone(CoA5, 250);
  mytone(CoA5, 125);
  mytone(CoA5, 125);
  mydelay(125);
  mytone(CoA5, 250);
  mytone(CoG5, 125);
  mydelay(125);
  mytone(CoA5, 125);
  mydelay(125);
  mytone(CoD6, 125);
  mydelay(125);
  mytone(CoA5, 125);
  mytone(CoG5, 250);

  mytone(CoD6, 250);
  mytone(CoA5, 250);
  mytone(CoG5, 250);
  mytone(CoF5, 250);
  mytone(CoC6, 250);
  mytone(CoG5, 250);
  mytone(CoF5, 250);
  mytone(CoE5, 250);

  mytone(CoAS4, 250);
  mytone(CoC5, 125);
  mytone(CoD5, 125);
  mydelay(125);
  mytone(CoF5, 250);
  mytone(CoC6, 1125);

  MEGA_SNDLOOP(2);

  mytone(CoAS3, 1500);
  mytone(CoF4, 500);

  mytone(CoE4, 1000);
  mytone(CoD4, 1000);

  mytone(CoF4, 4000);

  mytone(CoAS3, 1500);
  mytone(CoF4, 500);

  mytone(CoE4, 1000);
  mytone(CoD4, 1000);

  mytone(CoD4, 1000);
  mytone(CoD4, 83);   //
  mytone(CoCS4, 83); //  微調整区間 250ms
  mytone(CoC4, 83);   
  mydelay(1);           //

  mytone(CoB3, 83);   //
  mytone(CoAS3, 83); //  微調整区間 250ms
  mytone(CoA3, 83);   //
  mydelay(1);           //

  mytone(CoGS3, 83);   //
  mytone(CoG3, 83); //  微調整区間 250ms
  mytone(CoFS3, 83);   //
  mydelay(1);           //

  mytone(CoF3, 83);   //
  mytone(CoE3, 83); //  微調整区間 250ms
  mytone(CoDS3, 83);   //
  mydelay(1);           //

  mytone(CoD3, 2000);

  mytone(CoAS3, 1500);
  mytone(CoF4, 500);

  mytone(CoE4, 1000);
  mytone(CoD4, 1000);

  mytone(CoF4, 2000);

  mydelay(250);
  mytone(CoF4, 125);
  mydelay(125);
  mytone(CoG4, 250);
  mytone(CoF4, 125);
  mytone(CoC4, 125);
  mydelay(125);
  mytone(CoC4, 250);
  mytone(CoA3, 250);
  mytone(CoG3, 125);
  mytone(CoA3, 125);
  mytone(CoC4, 125);

  mytone(CoAS3, 1500);
  mytone(CoF4, 500);

  mytone(CoE4, 1000);
  mytone(CoD4, 1000);

  mytone(CoD4, 125);
  mydelay(125);
  mytone(CoF4, 250);
  mytone(CoE4, 375);
  mytone(CoC4, 125);
  mydelay(125);
  mytone(CoE4, 250);
  mytone(CoD4, 250);
  mytone(CoG3, 125);
  mytone(CoA3, 125);
  mytone(CoC4, 125);

  mydelay(250);
  mytone(CoF4, 250);
  mytone(CoE4, 375);
  mytone(CoC4, 125);
  mydelay(125);
  mytone(CoE4, 250);
  mytone(CoD4, 250);
  mytone(CoG3, 125);
  mytone(CoA3, 125);
  mytone(CoC4, 125);

  MEGA_TRDLOOP();

  MEGA_ONELOOP(CoAS3);
  MEGA_ONELOOP(CoC4);
  MEGA_ONELOOP(CoD4);
  MEGA_ONELOOP(CoD4);
  MEGA_ONELOOP(CoAS3);
  MEGA_ONELOOP(CoC4);
}

void you_1_1(int a,int b,int c,int d) {
  mytone(a, 750);
  mytone(b, 187); // 微調整区間 375ms
  mytone(c, 188); //
  mytone(d, 375);
}

void you_1_2(int a,int b,int c,int d,int e) {
  mytone(a, 375);
  mytone(b, 375);
  mytone(c, 188); // 微調整区間 375ms
  mytone(d, 187); //
  mytone(e, 188); // 微調整区間 375ms
  mytone(e, 187); //
}

void you_1_3(int a,int b,int c,int d) {
  mytone(a, 750);
  mytone(b, 188); // 微調整区間 375ms
  mytone(c, 187); //
  mytone(d, 188); // 微調整区間 375ms
  mytone(d, 187); //
}

void you_1_4(int a,int b,int c) {
  mytone(a, 375);
  mytone(b, 375);
  mytone(c, 750);
}

void you_1_5(int a,int b,int c,int d,int e) {
  mytone(a, 375);
  mytone(b, 375);
  mytone(c, 188); // 微調整区間 375ms
  mytone(d, 187); //
  mytone(e, 375);
}

void you_1_6(int a,int b,int c,int d) {
  mytone(a, 563); // 微調整区間 750ms
  mytone(a, 187); //
  mytone(b, 188); // 微調整区間 375ms
  mytone(c, 187); //
  mytone(d, 375);
}

void you_1() {
  you_1_1(CoDS5, CoF5, CoDS5, CoCS5); // 1
  you_1_2(CoDS5, CoGS4, CoF5, CoDS5, CoCS5);
  you_1_3(CoDS5, CoF5, CoDS5, CoCS5); // 2
  you_1_4(CoCS5, CoGS5, CoDS5);
  you_1_1(CoDS5, CoF5, CoDS5, CoCS5); // 3
  you_1_5(CoDS5, CoGS4, CoF5, CoDS5, CoCS5);
  you_1_6(CoDS5, CoF5, CoDS5, CoCS5); // 4
  mytone(CoCS5, 1500);
}

void you_2() {
  int arr[8] = {CoF5, CoCS5, CoDS5, CoCS5, CoF5, CoCS5, CoGS5, CoCS5};
  for (int i = 0; i < 8; i++) {
    mytone(arr[i], 1500);
  }
}

void play_you() {
  you_1(); // 1
  you_2(); // 5
  mydelay(12000); // 9
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
  value = map(value, 0, 1023, 0, 4);

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
    else if (value == 3) {
      u8x8.setCursor(2, 3);
      u8x8.print("    you    ");
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
    else if (value == 3) {
      u8x8.setCursor(2, 2);
      u8x8.print("    you    ");
      u8x8.setCursor(7, 5);
      u8x8.print("/?:??");
      play_you();
    }
    min = 0;
    sec = 0;
  }

  beforevalue = value;
}
