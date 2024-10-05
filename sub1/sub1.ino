int buzzerPin = 5;

enum Notes { CoA0 = 27, CoAS0 = 29, CoB0 = 31, CoC1 = 33, CoCS1 = 35, CoD1 = 37, CoDS1 = 39, CoE1 = 41, CoF1 = 44, CoFS1 = 46, CoG1 = 49, CoGS1 = 52, CoA1 = 55, CoAS1 = 58, CoB1 = 62, CoC2 = 65, CoCS2 = 69, CoD2 = 73, CoDS2 = 78, CoE2 = 82, CoF2 = 87, CoFS2 = 92, CoG2 = 98, CoGS2 = 104, CoA2 = 110, CoAS2 = 117, CoB2 = 123, CoC3 = 131, CoCS3 = 139, CoD3 = 147, CoDS3 = 156, CoE3 = 165, CoF3 = 175, CoFS3 = 185, CoG3 = 196, CoGS3 = 208, CoA3 = 220, CoAS3 = 233, CoB3 = 247, CoC4 = 262, CoCS4 = 277, CoD4 = 294, CoDS4 = 311, CoE4 = 330, CoF4 = 349, CoFS4 = 370, CoG4 = 392, CoGS4 = 415, CoA4 = 440, CoAS4 = 466, CoB4 = 494, CoC5 = 523, CoCS5 = 554, CoD5 = 587, CoDS5 = 622, CoE5 = 659, CoF5 = 698, CoFS5 = 740, CoG5 = 784, CoGS5 = 831, CoA5 = 880, CoAS5 = 932, CoB5 = 988, CoC6 = 1047, CoCS6 = 1109, CoD6 = 1175, CoDS6 = 1244, CoE6 = 1319, CoF6 = 1397, CoFS6 = 1480, CoG6 = 1568, CoGS6 = 1661, CoA6 = 1760, CoAS6 = 1865, CoB6 = 1976, CoC7 = 2093, CoCS7 = 2217, CoD7 = 2349, CoDS7 = 2489, CoE7 = 2637, CoF7 = 2794, CoFS7 = 2960, CoG7 = 3136, CoGS7 = 3322, CoA7 = 3520, CoAS7 = 3730, CoB7 = 3951, CoC8 = 4186, CoCS8 = 4435, CoD8 = 4699, CoDS8 = 4978 };

void mytone(int freq, int dist) {
  tone(5, freq * 4, dist-37.5);
  delay(dist);
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void one_X(int a,int b,int c){
  mytone(a, 150);
  delay(300);
  mytone(b, 150);
  delay(300);
  mytone(c, 150);
  delay(150);
}

void two_A(int a,int b,int c){
  mytone(a, 450);
  mytone(b, 450);
  mytone(c, 300);
}

void two_B(int a,int b, int c){
  mytone(a, 450);
  mytone(b,150);
  delay(300);
  mytone(c,150);
  delay(150);
}

void threeLOOP(int a,int b, int c){
  for(int three = 0; three < 3; three++){
      one_X(a,b,c);
    }
}


void FSTLOOP(int i){
  for(int ni = 0; ni < i; ni++){
    one_X(CoCS3,CoCS3,CoCS3);
    one_X(CoFS2,CoFS2,CoFS2);
    one_X(CoA2,CoA2,CoA2);
    one_X(CoB2,CoB2,CoB2);
  }
}

void SNDLOOP(int i){
  for(int nj = 0; nj < i; nj++){
    threeLOOP(CoCS3,CoE3,CoCS3);
    one_X(CoDS3,CoCS3,CoB2);
  }
}

void TRDLOOP_A(int i){
  for(int nk = 0; nk < i; nk++){
    two_A(CoCS2,CoCS3,CoCS3);
    two_A(CoFS2,CoFS3,CoFS3);
    two_A(CoA2,CoA3,CoA3);
    two_A(CoB2,CoB3,CoB3);
  }
}

void TRDLOOP_B(int i){
  for(int nl = 0; nl < i; nl++){
    one_X(CoCS2,CoCS3,CoCS3);
    one_X(CoFS2,CoFS3,CoFS3);
    one_X(CoA2,CoA3,CoA3);
    one_X(CoB2,CoB3,CoB3);
  }
}

void TRDLOOP_C(int i){
  for(int nm = 0; nm < i; nm++){
    two_A(CoCS2,CoCS3,CoCS3);
    two_B(CoFS2,CoFS3,CoFS3);
    two_A(CoA2,CoA3,CoA3);
    two_B(CoB2,CoB3,CoB3);
  }
}

void FTHLOOP(){
  one_X(CoCS2,CoCS3,CoCS3);
  one_X(CoFS2,CoFS3,CoFS3);
  one_X(CoA2,CoA3,CoA3);
}
void loop() {
  FSTLOOP(2);                 // 1 ~ 4.4
  SNDLOOP(3);                 // 5 ~ 10.4
  threeLOOP(CoCS3,CoE3,CoCS3);      // 11 ~ 12.2
  mytone(CoDS3, 150);           // 12.3
  delay(1050);
  SNDLOOP(3);                 // 13 ~ 18.4
  threeLOOP(CoCS3,CoE3,CoCS3);      // 19 ~ 20.2
  mytone(CoDS3,150);            // 20.3
  delay(150);
  mytone(CoGS2,300);            
  mytone(CoB2,300);             // 20.4
  mytone(CoCS3,300);
  SNDLOOP(4);                 // 21 ~ 28.4
  TRDLOOP_A(4);               // 29 ~ 36.4
  TRDLOOP_B(3);               // 37 ~ 42.4
  FTHLOOP();                  // 44 ~ 44.2
  mytone(CoB2, 150);            // 44.3
  delay(1050);
  TRDLOOP_C(3);               // 45 ~ 50.4
  two_A(CoCS2,CoCS3,CoCS3);         // 51 ~ 51.2
  two_A(CoFS2,CoFS3,CoFS3);         // 51.3 ~ 51.4
  mytone(CoA2, 450);
  mytone(CoA3, 450);
  mytone(CoA3, 600);
  mytone(CoGS2,300);
  mytone(CoB2,300);
  mytone(CoCS3,300);
  TRDLOOP_C(8);
  mytone(CoCS3,2400);

  delay(10000);
}
