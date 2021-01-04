#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(13, 12, 8, 4, 3, 2);

Servo base;
Servo hombro;
Servo codo;
Servo muneca;
Servo act;

int const modo =A4;
int vm = 0;
int vmp = 0;

int bm = 0;
int br = 1;
int ebm;
int ebr;

const int pot = A0;
int valor=0;
int mapeo=0;

const int poth=A1;
int valorh=0;
int mapeoh=0;

const int potc=A2;
int valorc=0;
int mapeoc=0;

const int potm=A3;
int valorm=0;
int mapeom=0;

int angulo = 0;

const int cambio = 7;
int ecambio = 0;


void setup() {
  
base.attach(6);
hombro.attach(9);
codo.attach(10);
muneca.attach(11);
act.attach(5);
  

pinMode(bm,INPUT);
pinMode(br,INPUT); 
  
  
 lcd.begin(16, 2);
 
  
  pinMode(cambio , INPUT);
  
 Serial.begin(9600);
 Serial.setTimeout(50);
}

void loop() {
  
  
  vm = analogRead(modo);
  vmp = map(vm,0,1023,0,100);
  
  if(vmp > 66)
  {
    ecambio = digitalRead(cambio);
    if(ecambio == LOW)
    {
      lcd.clear();
      lcd.setCursor(0 , 0);
      lcd.print("BRAZO ROBOTICO");
      lcd.setCursor(0, 1);
  	  lcd.print("MODO 1: [A]");
      delay(1000);
    }
    if(ecambio == HIGH)
    {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("B:");
    lcd.setCursor(2, 0);
    lcd.print("180");
    lcd.setCursor(10, 0);
    lcd.print("H:");
    lcd.setCursor(12, 0);
    lcd.print("90");
    
    lcd.setCursor(0, 1);
    lcd.print("C:");
    lcd.setCursor(2, 1);
    lcd.print("45");
    lcd.setCursor(10, 1);
    lcd.print("M:");
    lcd.setCursor(12, 1);
    lcd.print("0");
    delay(1000);
    }
    
    base.write(180);
    hombro.write(90);
    codo.write(45);
    muneca.write(0);
    act.write(45);
  }
  
  if(vmp < 66)
  {
    
    base.write(angulo);
    hombro.write(mapeo);
    codo.write(mapeoh);
    muneca.write(mapeoc);
    act.write(mapeom);
    
    ebm=digitalRead(bm);
    ebr=digitalRead(br);
    
    if(ebm == HIGH){
      angulo++;

      if(angulo>=180){
        angulo = 180;
      }
    }

if(ebr == HIGH){
      angulo--;

      if(angulo<=0){
        angulo = 0;
      }
    }

    base.write(angulo);
    
    valor = analogRead(pot);
    mapeo = map(valor,0,1023,0,180);
    hombro.write(mapeo);
    
    valorh = analogRead(poth);
    mapeoh = map(valorh,0,1023,0,180);
    codo.write(mapeoh);
    
    valorc = analogRead(potc);
    mapeoc = map(valorc,0,1023,0,180);
    muneca.write(mapeoc);
    
    valorm = analogRead(potm);
    mapeom = map(valorm,0,1023,0,180);
    act.write(mapeom); 
    
    ecambio = digitalRead(cambio);
    if(ecambio == LOW)
    {
      lcd.clear();
      lcd.setCursor(0 , 0);
      lcd.print("BRAZO ROBOTICO");
      lcd.setCursor(0, 1);
  	  lcd.print("MODO 2: [M]");
      delay(1000);
    }
    if(ecambio == HIGH)
    {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("B:");
    lcd.setCursor(2, 0);
    lcd.print(mapeo);
    lcd.setCursor(10, 0);
    lcd.print("H:");
    lcd.setCursor(12, 0);
    lcd.print(mapeoh);
    
    lcd.setCursor(0, 1);
    lcd.print("C:");
    lcd.setCursor(2, 1);
    lcd.print(mapeoc);
    lcd.setCursor(10, 1);
    lcd.print("M:");
    lcd.setCursor(12, 1);
    lcd.print(mapeom);
    delay(1000);
    }
    
  }
  
}
 