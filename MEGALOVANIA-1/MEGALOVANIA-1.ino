#include <U8x8lib.h>

int buzzerPin = 5;
int value = 0;

enum Notes { CoA0 = 27, CoAS0 = 29, CoB0 = 31, CoC1 = 33, CoCS1 = 35, CoD1 = 37, CoDS1 = 39, CoE1 = 41, CoF1 = 44, CoFS1 = 46, CoG1 = 49, CoGS1 = 52, CoA1 = 55, CoAS1 = 58, CoB1 = 62, CoC2 = 65, CoCS2 = 69, CoD2 = 73, CoDS2 = 78, CoE2 = 82, CoF2 = 87, CoFS2 = 92, CoG2 = 98, CoGS2 = 104, CoA2 = 110, CoAS2 = 117, CoB2 = 123, CoC3 = 131, CoCS3 = 139, CoD3 = 147, CoDS3 = 156, CoE3 = 165, CoF3 = 175, CoFS3 = 185, CoG3 = 196, CoGS3 = 208, CoA3 = 220, CoAS3 = 233, CoB3 = 247, CoC4 = 262, CoCS4 = 277, CoD4 = 294, CoDS4 = 311, CoE4 = 330, CoF4 = 349, CoFS4 = 370, CoG4 = 392, CoGS4 = 415, CoA4 = 440, CoAS4 = 466, CoB4 = 494, CoC5 = 523, CoCS5 = 554, CoD5 = 587, CoDS5 = 622, CoE5 = 659, CoF5 = 698, CoFS5 = 740, CoG5 = 784, CoGS5 = 831, CoA5 = 880, CoAS5 = 932, CoB5 = 988, CoC6 = 1047, CoCS6 = 1109, CoD6 = 1175, CoDS6 = 1244, CoE6 = 1319, CoF6 = 1397, CoFS6 = 1480, CoG6 = 1568, CoGS6 = 1661, CoA6 = 1760, CoAS6 = 1865, CoB6 = 1976, CoC7 = 2093, CoCS7 = 2217, CoD7 = 2349, CoDS7 = 2489, CoE7 = 2637, CoF7 = 2794, CoFS7 = 2960, CoG7 = 3136, CoGS7 = 3322, CoA7 = 3520, CoAS7 = 3730, CoB7 = 3951, CoC8 = 4186, CoCS8 = 4435, CoD8 = 4699, CoDS8 = 4978 };

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

void mytone(int freq, int dist) {
  tone(5, freq * 4, dist - 10);
  delay(dist);
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_8x13B_1x2_f);
}

void ONELOOP(int i) {
  mytone(i, 125);
  mytone(i, 125);
  mytone(CoD5, 250);

  mytone(CoA4, 375);
  mytone(CoGS4, 187.5);
  delay(62.5);
  mytone(CoG4, 250);
  mytone(CoF4, 250);
  mytone(CoD4, 125);
  mytone(CoF4, 125);
  mytone(CoG4, 125);
}

void TWOLOOP(int j,int k) {
  mytone(j,250);
  mytone(j,250);
  delay(125);
  mytone(j,250);
  mytone(k,250);
  mytone(k,250);
  delay(375);
  mytone(k,250);
}

void FSTLOOP(int l) {
  for(int nl = 0; nl < l; nl++){
    ONELOOP(CoD4);
    ONELOOP(CoC4);
    ONELOOP(CoB3);
    ONELOOP(CoAS3);
  }
}

void SNDLOOP(int m){
  for(int nm = 0; nm < m; nm++){
    delay(1000);
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

void TRDLOOP_A(int n){
  for(int nn = 0; nn < n; nn++){
    TWOLOOP(CoAS3,CoAS3);
    TWOLOOP(CoC4,CoC4);
    TWOLOOP(CoD4,CoCS4);
    TWOLOOP(CoC4,CoB3);
  }
}

void TRDLOOP_B(int o){
  for(int no = 0; no < o; no++){
    TWOLOOP(CoAS3,CoAS3);
    TWOLOOP(CoC4,CoC4);
    TWOLOOP(CoD4,CoD4);
    TWOLOOP(CoD4,CoD4);
  }
}

void TRDLOOP() {
  TRDLOOP_A(1);
  TRDLOOP_B(1);
  TRDLOOP_A(1);
  TRDLOOP_B(1);
}

void MEGALOVANIA_1() {
  FSTLOOP(4);

  mytone(CoF4, 250);
  mytone(CoF4, 125);
  mytone(CoF4, 125);
  delay(125);
  mytone(CoF4, 250);
  mytone(CoF4, 250);
  mytone(CoD4, 250);
  mytone(CoD4, 500);
  delay(125);

  mytone(CoF4, 250);
  mytone(CoF4, 125);
  mytone(CoF4, 125);
  delay(125);
  mytone(CoG4, 250);
  mytone(CoGS4, 250);
  mytone(CoG4, 41);   //
  delay(1);
  mytone(CoG4, 41); //  微調整区間 125ms
  delay(1);
  mytone(CoG4, 41);   //
  mytone(CoF4, 125);
  mytone(CoD4, 125);
  mytone(CoF4, 125);
  mytone(CoG4, 125);
  delay(250);

  mytone(CoF4, 250);
  mytone(CoF4, 125);
  mytone(CoF4, 125);
  delay(125);
  mytone(CoG4, 250);
  mytone(CoGS4, 125);
  delay(125);
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
  delay(125);
  mytone(CoA5, 250);
  mytone(CoA5, 250);
  mytone(CoG5, 125);
  delay(125);
  mytone(CoG5, 625);

  mytone(CoA5, 250);
  mytone(CoA5, 125);
  mytone(CoA5, 125);
  delay(125);
  mytone(CoA5, 250);
  mytone(CoG5, 125);
  delay(125);
  mytone(CoA5, 125);
  delay(125);
  mytone(CoD6, 125);
  delay(125);
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
  delay(125);
  mytone(CoF5, 250);
  mytone(CoC6, 1125);

  SNDLOOP(2);

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
  delay(1);           //

  mytone(CoB3, 83);   //
  mytone(CoAS3, 83); //  微調整区間 250ms
  mytone(CoA3, 83);   //
  delay(1);           //

  mytone(CoGS3, 83);   //
  mytone(CoG3, 83); //  微調整区間 250ms
  mytone(CoFS3, 83);   //
  delay(1);           //

  mytone(CoF3, 83);   //
  mytone(CoE3, 83); //  微調整区間 250ms
  mytone(CoDS3, 83);   //
  delay(1);           //

  mytone(CoD3, 2000);

  mytone(CoAS3, 1500);
  mytone(CoF4, 500);

  mytone(CoE4, 1000);
  mytone(CoD4, 1000);

  mytone(CoF4, 2000);

  delay(250);
  mytone(CoF4, 125);
  delay(125);
  mytone(CoG4, 250);
  mytone(CoF4, 125);
  mytone(CoC4, 125);
  delay(125);
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
  delay(125);
  mytone(CoF4, 250);
  mytone(CoE4, 375);
  mytone(CoC4, 125);
  delay(125);
  mytone(CoE4, 250);
  mytone(CoD4, 250);
  mytone(CoG3, 125);
  mytone(CoA3, 125);
  mytone(CoC4, 125);

  delay(250);
  mytone(CoF4, 250);
  mytone(CoE4, 375);
  mytone(CoC4, 125);
  delay(125);
  mytone(CoE4, 250);
  mytone(CoD4, 250);
  mytone(CoG3, 125);
  mytone(CoA3, 125);
  mytone(CoC4, 125);

  TRDLOOP();

  ONELOOP(CoAS3);
  ONELOOP(CoC4);
  ONELOOP(CoD4);
  ONELOOP(CoD4);
  ONELOOP(CoAS3);
  ONELOOP(CoC4);
}

void clear_display() {
  for (int i=0;i<8;i++) {
    u8x8.setCursor(0, i);
    u8x8.print("                ");
  }
}



void loop() {

  value = map(value, 0, 1023, 0, 3);
  
  if(digitalRead(6) == 1){
    clear_display();
    u8x8.setCursor(0, 3);
    u8x8.print("  MEGALOVANIA  ");
    MEGALOVANIA_1();
    clear_display();
  
  
  }else if(digitalRead(6) == 0){
    u8x8.setCursor(0, 2);
    u8x8.print("  MEGALOVANIA  ");
    u8x8.setCursor(0, 4);
    u8x8.print("Press the button");
  }

}
