
#include<LiquidCrystal_I2C.h>
#define LED_PIN1 13
#define LED_PIN2 10
#define RELAY_PIN 4
#define soil A2
#define SAD_PIN A4
#define SCL_PIN A5
#define BUZZER_PIN 9
 LiquidCrystal_I2C lcd(32,16,2);


void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN1,OUTPUT);
  pinMode(LED_PIN2,OUTPUT);
  pinMode(RELAY_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
   lcd.init();
  lcd.backlight();
}


void loop(){
  lcd.setCursor(0,0);
 int soil_moist=analogRead(A2);
 
  Serial.println(soil_moist);
  if(soil_moist<300){
    digitalWrite(LED_PIN2,HIGH);
    digitalWrite(RELAY_PIN,HIGH);
    digitalWrite(LED_PIN1,LOW);
     tone(BUZZER_PIN,200);
  
    
  lcd.print("MOTOR ON");
    delay(9000);
    lcd.clear();
   
  
    
  }
  else{
    digitalWrite(LED_PIN1,HIGH);
    digitalWrite(RELAY_PIN,LOW);
    
    digitalWrite(LED_PIN2,LOW);
    lcd.print("MOTOR OFF");
    delay(5000);
    lcd.clear();
   
   
  }
}

