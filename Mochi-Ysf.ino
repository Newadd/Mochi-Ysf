#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Fungsi melukis animasi garis membentuk pola hati (Heart Line Tracing)
void playHeartLineAnimation() {
  display.clearDisplay();
  
  int cx = SCREEN_WIDTH / 2; // Pusat X (64)
  int cy = 28;                // Pusat Y
  float scale = 1.35;         // Skala ukuran bentuk hati

  int prevX = -1;
  int prevY = -1;

  // Menghitung & menggambar garis dari t = 0 hingga 2*PI secara bertahap
  for (float t = 0.0; t <= 2 * PI + 0.05; t += 0.08) {
    // Rumus kurva parametrik bentuk hati
    float x_raw = 16 * pow(sin(t), 3);
    float y_raw = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);

    // Konversi ke koordinat OLED
    int x = cx + (int)(x_raw * scale);
    int y = cy - (int)(y_raw * scale);

    // Hubungkan titik sebelumnya ke titik baru menggunakan garis
    if (prevX != -1 && prevY != -1) {
      display.drawLine(prevX, prevY, x, y, SSD1306_WHITE);
      display.display();
      delay(25); // Kecepatan jalannya garis (ms)
    }

    prevX = x;
    prevY = y;
  }

  delay(700); // Jeda setelah bentuk hati utuh
}

// Fungsi menampilkan nama dengan efek ngetik (typing effect)
void displayName(String name) {
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  // Menghitung posisi agar teks tepat di tengah layar
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(name, 0, 0, &x1, &y1, &w, &h);
  int startX = (SCREEN_WIDTH - w) / 2;
  int startY = (SCREEN_HEIGHT - h) / 2;

  String currentText = "";
  for (int i = 0; i < name.length(); i++) {
    currentText += name[i];
    display.clearDisplay();
    display.setCursor(startX, startY);
    display.print(currentText);
    display.display();
    delay(150); // Kecepatan muncul karakter
  }
}

void setup() {
  Wire.begin(21, 22); // Pin I2C ESP32 (SDA=21, SCL=22)

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;);
  }

  // 1. Jalankan animasi garis melukis hati
  playHeartLineAnimation();

  // 2. Tampilkan teks nama (Ganti "ALEXA" dengan nama pilihanmu)
  displayName("ALEXA");
}

void loop() {
  // Tampilan nama tetap bertahan di layar
}
