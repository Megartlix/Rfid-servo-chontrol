#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 3

MFRC522 rfid(SS_PIN, RST_PIN);
Servo motor;
int okutmaSayisi = 0;
byte yetkiliKart[4] = {0x63, 0xE6, 0xF4, 0x11}; // Sizin kartınızın ID'si

void setup() {
  Serial.begin(9600);
  while (!Serial);    // Serial port hazır olana kadar bekle
  
  SPI.begin();        // SPI başlat
  rfid.PCD_Init();    // RFID başlat
  
  motor.attach(SERVO_PIN);  // Servo başlat
  motor.write(0);     // Başlangıç pozisyonu
  
  Serial.println("Test başladı - Kartınızı okutun");
}

void loop() {
  // Kart kontrolü
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    
    // Kart ID'sini yazdır
    Serial.print("Okunan Kart ID: ");
    for (byte i = 0; i < 4; i++) {
      Serial.print(rfid.uid.uidByte[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    
    // Yetkili kart kontrolü
    if (kartKontrol(rfid.uid.uidByte)) {
      okutmaSayisi++;
      Serial.print("Okutma sayısı: ");
      Serial.println(okutmaSayisi);
      
      if (okutmaSayisi % 2 == 1) {
        Serial.println("GİRİŞ - Kapı açılıyor");
      } else {
        Serial.println("ÇIKIŞ - Kapı açılıyor");
      }
      
      // Servo hareketi
      motor.write(90);
      delay(3000);
      motor.write(0);
      
    } else {
      Serial.println("YETKİSİZ KART!");
    }
    
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
  
  delay(100);
}

boolean kartKontrol(byte *id) {
  for (byte i = 0; i < 4; i++) {
    if (id[i] != yetkiliKart[i]) {
      return false;
    }
  }
  return true;
}