

#include <SPI.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(9);

#include <lwthread.h>

lwthread t1,t2,t3, t4, t5;

SLWT scheduler;

byte zero[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};


byte one[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};

byte two[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

byte three[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
};

byte four[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
};

byte five[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};


void acendeLed(){
	digitalWrite(4, HIGH);
	t1.Stop();
	t2.Start();
	
}

void apagaLed(){
	digitalWrite(4, LOW);
	t2.Stop();
	t1.Start();
	
	
}

void acendeLed2(){
	digitalWrite(3, HIGH);
	t4.Stop();
	t5.Start();
	
}

void apagaLed2(){
	digitalWrite(3, LOW);
	t5.Stop();
	t4.Start();
	
	
}

void printLCDinfo();

void printLCDbar(String incName, byte percentage);

void setup() {
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	Serial.begin(115200);
	lcd.begin(16, 2);

	lcd.createChar(0,zero);
	lcd.createChar(1,one);
	lcd.createChar(2,two);
	lcd.createChar(3,three);
	lcd.createChar(4,four);
	lcd.createChar(5,five);
  
	t1.init(acendeLed, 1500, &scheduler);
	t1.Start();
  
	t2.init(apagaLed, 80, &scheduler);
  
	t3.init(printLCDinfo, 50, &scheduler);
	t3.Start();
	
	t4.init(acendeLed2, 500, &scheduler);
	t4.Start();
	
	t5.init(apagaLed2, 500, &scheduler);
	
  
 
}

void loop() {
	

	scheduler.handle_run();

 }
 
 void printLCDinfo(){
	 int value = analogRead(A0);
	 float value2 = value * (100.0/1024);
	 printLCDbar("A0", (int)value2);
 }


void printLCDbar(String incName, byte percentage){
  lcd.clear();
  lcd.print(incName);
  lcd.print("   ");
  lcd.print(percentage);
  lcd.print("%");
  int bar = (percentage*16/100);
  int minibar = (percentage*16%100) *5/100;
  lcd.setCursor(0,1);
  
  for(int i=0; i<=bar; i++){
    lcd.write(byte(5));
    } 
  switch(minibar){
    case 0 : lcd.write(byte(0));
             break;
    case 1 : lcd.write(byte(1));
             break;
    case 2 : lcd.write(byte(2));
             break;
    case 3 : lcd.write(byte(3));
             break;
    case 4 : lcd.write(byte(4));
             break;
    case 5 : lcd.write(byte(5));
             break;    
    default: Serial.println("error on switch");     
    }
}
