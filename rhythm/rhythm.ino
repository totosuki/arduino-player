#include <U8x8lib.h>
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

uint8_t clear[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t block[8] = {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00};
uint8_t note[8]  = {0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00};

int stack[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}}; // [x, y, 出現したmillis]

int now_bar_pos;
int last_bar_pos;
int now_button;
int last_button;
// ノート関係
int now_notex;

void fall() {
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
}

void loop() {
  now_bar_pos = analogRead(0);
  now_button = digitalRead(6);
  now_bar_pos = map(now_bar_pos, 0, 1024, 0, 8);

  // バーを動かす
  if (now_bar_pos != last_bar_pos) {
    u8x8.drawTile(15, now_bar_pos, 1, block);
    u8x8.drawTile(15, last_bar_pos, 1, clear);
  }

  // ノート生成（テスト）
  if (now_button == 1 && last_button == 0) {
    for (int i = 0; i < 3; i++) {
      if (stack[i][0] == -1) {
        stack[i][0] = 0;
        stack[i][1] = now_bar_pos;
        stack[i][2] = millis();
        break;
      }
    }
  }

  fall();

  last_bar_pos = now_bar_pos;
  last_button = now_button;

  delay(20);
}