

Türkçe :
Bu proje, RFID (MFRC522) modülü ve bir servo motor kullanarak basit bir erişim kontrol sistemi oluşturmayı amaçlar. Projede, RFID kartları veya etiketleri ile kimlik doğrulaması yapılır ve doğru kart okutulduğunda servo motor harekete geçirilir (örneğin, bir kapıyı açmak için).

Özellikler ✨
RFID Okuma: MFRC522 RFID modülü ile UID (benzersiz kimlik) okuma.
Kimlik Doğrulama: Tanımlanan kart UID'leri ile karşılaştırma.
Servo Kontrolü: Geçerli bir kart okutulduğunda servo motor belirli bir açıya hareket eder.
Hızlı Entegrasyon: Arduino ve diğer mikrokontrolcü platformlarında kolayca çalıştırılabilir.
Gereksinimler 🛠️
Donanım:

MFRC522 RFID modülü
Servo motor
Arduino veya uyumlu bir mikrokontrolcü
Bağlantı kabloları
Breadboard (isteğe bağlı)
Yazılım:

Arduino IDE
MFRC522 Kütüphanesi
Servo Kütüphanesi
Nasıl Çalışır? ⚙️
Projeye uygun bağlantıları yapın (devre şeması aşağıda verilmiştir).
Arduino IDE'yi açın ve gerekli kütüphaneleri yükleyin.
Depoda verilen kodu yükleyin.
RFID modülü üzerinden kart okutulduğunda UID okunur.
UID, kodda tanımlı geçerli kart UID'leri ile karşılaştırılır:
Geçerli kart ise: Servo motor hareket eder.
Geçersiz kart ise: Bir uyarı veya işlem yapılmaz.

Bağlantı Şeması 🔌
RFID Pinleri	Arduino Pinleri
SDA	D10
SCK	D13
MOSI	D11
MISO	D12
IRQ	-
GND	GND
RST	D9
3.3V	3.3V
Servo Motor	Arduino Pinleri
Sinyal	D3
VCC	5V
GND	GND

RFID UID değerini öğrenmek istiyorsanız şu dosyaya göz atın: uiddeger.ino.


English :

This project demonstrates how to create a simple access control system using an RFID (MFRC522) module and a servo motor. The system reads RFID cards or tags, verifies their unique ID (UID), and triggers the servo motor to move (e.g., to unlock a door) when a valid card is scanned.

Features ✨
RFID Reading: Read UID from RFID cards using the MFRC522 module.
Authentication: Compare the UID with pre-defined valid IDs.
Servo Motor Control: Move the servo motor to a specific angle upon valid authentication.
Easy Integration: Compatible with Arduino and other microcontroller platforms.
Requirements 🛠️
Hardware:

MFRC522 RFID module
Servo motor
Arduino or compatible microcontroller
Jumper wires
Breadboard (optional)
Software:

Arduino IDE
MFRC522 Library
Servo Library
How It Works ⚙️
Connect the components as shown in the circuit diagram below.
Open Arduino IDE and install the required libraries.
Upload the provided code to your Arduino board.
When an RFID card is scanned:
The UID is read by the module.
The UID is compared with pre-defined valid IDs in the code.
If the UID matches:
The servo motor moves to the desired position.
If the UID doesn’t match:
No action is taken, or an alert is generated.



Circuit Diagram 🔌
RFID Pins	Arduino Pins
SDA	D10
SCK	D13
MOSI	D11
MISO	D12
IRQ	-
GND	GND
RST	D9
3.3V	3.3V

Servo Motor	Arduino Pins
Signal	D3
VCC	5V
GND	GND
If you want to learn the RFID UID value, check out this file: uiddeger.ino.
