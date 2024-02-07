//โมดูล MP3
const uint8_t ARDUINO_RX = 7; //ขารับสัญญาณโมดูล MP3
const uint8_t ARDUINO_TX = 6; //ขาส่งสัญญาณโมดูล MP3

//เงื่อนไขตัวแปลข้อมูลแบบ Serial
#ifndef USE_SOFTWARESERIAL
#define USE_SOFTWARESERIAL 1
#endif

//ประกาศใช้งาน Libralies โมดูล MP3
#include <MD_YX5300.h>

//ประกาศใช้งาน Libralies โมดูล ประมวลผล MP3
#include <MD_cmdProcessor.h>

//ประกาศเงื่อนไขการใช้ตัวแปร
#if USE_SOFTWARESERIAL

//ประกาศใช้งาน Libralies ซอฟแวร์ซีเรียล
#include <SoftwareSerial.h>

//ประกาศให้ซอฟแวร์ซีเรียลเป็น MP3
SoftwareSerial  MP3Stream(ARDUINO_RX, ARDUINO_TX);
#define Console Serial
#else
#define MP3Stream Serial2
#define Console   Serial
#endif
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
MD_YX5300 mp3(MP3Stream);

 
void setup() {
  //ให้โมดูล MP3 เริ่มทำงาน
  MP3Stream.begin(MD_YX5300::SERIAL_BPS); 
  mp3.begin();
  
  //เริ่มใช้คำสั่งแบบซีเรียล
  Serial.begin(9600);
}
 
void loop() {
  mp3.check(); //ให้โมดูล MP3 เช็คสถานะ
 
}