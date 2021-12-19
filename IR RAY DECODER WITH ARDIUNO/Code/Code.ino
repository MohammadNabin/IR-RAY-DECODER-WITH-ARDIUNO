//TheTechMortal-https://www.youtube.com/thetechmortal//
//MohammadNabin-https://www.facebook.com/mohammadnabin99//
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

int RECV_PIN = 11;
LiquidCrystal_I2C lcd(0x27, 16, 2);
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
pinMode(13,OUTPUT); //power supply to ir reciver
pinMode(12,OUTPUT);
pinMode(11,INPUT);
digitalWrite(13, HIGH);
digitalWrite(12,LOW);

lcd.init();
lcd.backlight();

  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); //Start the receiver
  Serial.println("Enabled IRin");
  lcd.setCursor(0,0);
  lcd.print("IR Remote Decode");
  lcd.setCursor(1,1);
  lcd.print("MOHAMMAD NABIN");
}  
void loop() 

{   
  if (irrecv.decode(&results)) 
    {
      lcd.clear();
      Serial.println(results.value, HEX);
      Serial.println(results.value, DEC);

      lcd.setCursor(0,0);
      lcd.print(results.value, HEX);
      lcd.setCursor(12,0);
      lcd.print("HEX");
      lcd.setCursor(0,1);
      lcd.print(results.value, DEC);
      lcd.setCursor(12,1);
      lcd.print("DEC"); 
      irrecv.resume();   // Receive the next value
    }
    delay(100);
}
