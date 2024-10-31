#include <U8x8lib.h>
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

uint8_t clear[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t block[8] = {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00};
uint8_t note[8]  = {0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00};

int nowpos;
int lastpos;
int nowbutton;
int lastbutton;
// ノート関係
int isfall;
int starttime;
int nownotex;
int lastnotex;

void fallnote() {
  nownotex = map(millis() - starttime, 0, 1000, 0, 17);

  if (nownotex == 16) {
    u8x8.drawTile(15, 3, 1, clear);
    isfall = 0;
    nownotex = 0;
    lastnotex = 0;
  }
  else if (nownotex != lastnotex) {
    u8x8.drawTile(nownotex, 3, 1, note);
    u8x8.drawTile(lastnotex, 3, 1, clear);
  }
}

void setup() {
  Serial.begin(9600);
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_8x13B_1x2_f);
  pinMode(0, 0);
  pinMode(6, 0);

  nowbutton = 0;
  lastbutton = 0;
  nownotex = 0;
  lastnotex = 0;
}

void loop() {
  nowpos = analogRead(0);
  nowbutton = digitalRead(6);
  nowpos = map(nowpos, 0, 1024, 0, 8);

  // バーを動かす
  if (nowpos != lastpos) {
    u8x8.drawTile(15, nowpos, 1, block);
    u8x8.drawTile(15, lastpos, 1, clear);
  }

  // ノート生成（テスト）
  if (nowbutton != lastbutton) {
    isfall = 1;
    starttime = millis();
  }

  if (isfall == 1) {
    fallnote();
  }

  lastpos = nowpos;
  lastbutton = nowbutton;
  lastnotex = nownotex;
}