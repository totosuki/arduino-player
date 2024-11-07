#include <U8x8lib.h>
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

enum Notes { CoA0 = 27, CoAS0 = 29, CoB0 = 31, CoC1 = 33, CoCS1 = 35, CoD1 = 37, CoDS1 = 39, CoE1 = 41, CoF1 = 44, CoFS1 = 46, CoG1 = 49, CoGS1 = 52, CoA1 = 55, CoAS1 = 58, CoB1 = 62, CoC2 = 65, CoCS2 = 69, CoD2 = 73, CoDS2 = 78, CoE2 = 82, CoF2 = 87, CoFS2 = 92, CoG2 = 98, CoGS2 = 104, CoA2 = 110, CoAS2 = 117, CoB2 = 123, CoC3 = 131, CoCS3 = 139, CoD3 = 147, CoDS3 = 156, CoE3 = 165, CoF3 = 175, CoFS3 = 185, CoG3 = 196, CoGS3 = 208, CoA3 = 220, CoAS3 = 233, CoB3 = 247, CoC4 = 262, CoCS4 = 277, CoD4 = 294, CoDS4 = 311, CoE4 = 330, CoF4 = 349, CoFS4 = 370, CoG4 = 392, CoGS4 = 415, CoA4 = 440, CoAS4 = 466, CoB4 = 494, CoC5 = 523, CoCS5 = 554, CoD5 = 587, CoDS5 = 622, CoE5 = 659, CoF5 = 698, CoFS5 = 740, CoG5 = 784, CoGS5 = 831, CoA5 = 880, CoAS5 = 932, CoB5 = 988, CoC6 = 1047, CoCS6 = 1109, CoD6 = 1175, CoDS6 = 1244, CoE6 = 1319, CoF6 = 1397, CoFS6 = 1480, CoG6 = 1568, CoGS6 = 1661, CoA6 = 1760, CoAS6 = 1865, CoB6 = 1976, CoC7 = 2093, CoCS7 = 2217, CoD7 = 2349, CoDS7 = 2489, CoE7 = 2637, CoF7 = 2794, CoFS7 = 2960, CoG7 = 3136, CoGS7 = 3322, CoA7 = 3520, CoAS7 = 3730, CoB7 = 3951, CoC8 = 4186, CoCS8 = 4435, CoD8 = 4699, CoDS8 = 4978 };

struct Chart {
  int y;
  unsigned long time;
};

// 見た目関係
uint8_t clear[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t block[8] = {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00};
uint8_t note[8]  = {0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00};

// 譜面関係
unsigned long stack[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}}; // [x, y, 出現したmillis]
Chart prologue_chart[50] = { // [y, time]
  {1, 0},
  {4, 375},
  {5, 500},
  {3, 1000},
  {1, 1500},
  {3, 2000},
  {5, 2500},
  {2, 3000},
  {4, 3500},
  {2, 4000},
  {5, 5000},
  {1, 5375},
  {3, 5500},
  {5, 6000},
  {4, 6250},
  {2, 7500},
  {4, 7750},
  {5, 8250},
  {3, 8750},
  {1, 10000},
  {2, 10750},
  {4, 11250},
  {1, 12000},
  {5, 12500},
  {3, 13000},
  {4, 13500},
  {2, 14500},
  {3, 15000},
  {5, 16000},
  {1, 16500},
  {4, 17000},
  {2, 17500},
  {3, 18250},
  {5, 19000},
  {1, 19750},
  {2, 20500},
  {3, 21000},
  {4, 22500},
  {2, 23500},
  {5, 24500},
  {3, 25500},
  {1, 27000},
  {4, 27500},
  {2, 28500},
  {5, 30000},
  {3, 31000},
  {1, 32000},
  {2, 33000},
  {4, 34000},
  {5, 35000}
};

int now_bar_pos;
int last_bar_pos;
int now_button;
int last_button;
// ノート関係
int now_notex;
int next_chart;

unsigned long music_st;
unsigned long music_nt;

void fall_note() {
  for (int i = 0; i < 3; i++) {
    if (stack[i][0] == -1) {
      continue;
    }

    now_notex = map(millis() - stack[i][2], 0, 1000, 0, 17);

    if (now_notex == 16) {
      u8x8.drawTile(15, stack[i][1], 1, clear);
      stack[i][0] = -1;
      stack[i][1] = -1;
      stack[i][2] = -1;
    }
    else if (now_notex != stack[i][0]) {
      u8x8.drawTile(now_notex, stack[i][1], 1, note);
      u8x8.drawTile(stack[i][0], stack[i][1], 1, clear);
      stack[i][0] = now_notex;
    }
  }
}

void mydelay(int dist) {
  unsigned long st = millis();

  while (millis() - st < dist) {
    music_nt = millis();

    now_bar_pos = analogRead(0);
    now_button = digitalRead(6);
    now_bar_pos = map(now_bar_pos, 0, 1024, 0, 8);

    // バーを動かす
    if (now_bar_pos != last_bar_pos) {
      u8x8.drawTile(15, now_bar_pos, 1, block);
      u8x8.drawTile(15, last_bar_pos, 1, clear);
    }

    if (music_nt - music_st >= prologue_chart[next_chart].time) {
      for (int i = 0; i < 3; i++) {
        if (stack[i][0] == -1) {
          stack[i][0] = 0;
          stack[i][1] = prologue_chart[i].y;
          stack[i][2] = millis();
          next_chart++;
          break;
        }
      }
    }

    fall_note();

    last_bar_pos = now_bar_pos;
    last_button = now_button;
  }
}

void mytone(int freq, int dist) {
  tone(5, freq * 4, dist - 10);
  mydelay(dist);
}

void play_prologue() {
  mydelay(1000);
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
  pinMode(0, 0);
  pinMode(6, 0);

  now_button = 0;
  last_button = 0;
  now_notex = 0;
  next_chart = 0;
}

void loop() {
  now_button = digitalRead(6);

  if (now_button == 1 && last_button == 0) {
    music_st = millis();
    play_prologue();
  }

  last_button = now_button;
}