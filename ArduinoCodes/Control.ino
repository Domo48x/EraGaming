#include <LiquidCrystal.h>
#include <Servo.h>

Servo base;
Servo hombro;
Servo codo;
Servo muneca;
Servo gripper;

const int sbasepin = A0;
const int shombropin = A1;
const int scodopin = A2;
const int smunecapin = A3;

const int funcionpin = 2;

float vbase = 0;
float vhombro = 0;
float vcodo = 0;
float vmuneca = 0;

float gbase = 0;
float ghombro = 0;
float gcodo = 0;
float gmuneca = 0;

float abase = 25;
float ahombro = 35;
float acodo = 45;
float amuneca = 55;
float agripper = 65;

int funcion;

LiquidCrystal lcd(0 , 4 , 7 , 8 , 12 , 13);
#define COLUMNAS 16
#define FILAS 2
#define VELOCIDAD 300
#define ARRAYTXT 2
int indice;

const int bpinverde = 23;
const int bpinrojo = 24;
const int hpinverde = 25;
const int hpinrojo = 26;
const int cpinverde = 27;
const int cpinrojo = 28;
const int mpinverde = 29;
const int mpinrojo = 30;

const int botonbs = 32;
const int botonbr = 33;
const int botonhs = 34;
const int botonhr = 35;
const int botoncs = 36;
const int botoncr = 37;
const int botonms = 38;
const int botonmr = 39;

 int estadobs = 0;
 int estadobr = 0;
  int estadohs = 0;
 int estadohr = 0;
  int estadocs = 0;
 int estadocr = 0;
  int estadoms = 0;
 int estadomr = 0;

 int angulob = 0;
 int anguloh = 0;
 int anguloc = 0;
 int angulom = 0;

void setup() {
  
  Serial.begin(9600);
  
  base.attach(3);
  hombro.attach(5);
  codo.attach(6);
  muneca.attach(9);
  gripper.attach(10);

  pinMode(funcionpin , INPUT);

  lcd.begin(COLUMNAS,FILAS);

  pinMode(bpinverde,OUTPUT);
  pinMode(bpinrojo,OUTPUT);
  pinMode(hpinverde,OUTPUT);
  pinMode(hpinrojo,OUTPUT);
  pinMode(cpinverde,OUTPUT);
  pinMode(cpinrojo,OUTPUT);
  pinMode(mpinverde,OUTPUT);
  pinMode(mpinrojo,OUTPUT);

  pinMode(botonbs,INPUT);
  pinMode(botonbr,INPUT);
  pinMode(botonhs,INPUT);
  pinMode(botonhr,INPUT);
  pinMode(botoncs,INPUT);
  pinMode(botoncr,INPUT);
  pinMode(botonms,INPUT);
  pinMode(botonmr,INPUT);

  

}

void loop() {

  String textos[ARRAYTXT] = {"MODO AUTOMATICO" , "MODO MANUAL"};
  lcd.clear();

  vbase = analogRead(sbasepin);
  vhombro = analogRead(shombropin);
  vcodo = analogRead(scodopin);
  vmuneca = analogRead(smunecapin);

  vbase = (vbase*100)/1023;
  vhombro = (vhombro*100)/1023;
  vcodo = (vcodo*100)/1023;
  vmuneca = (vmuneca*100)/1023;

  gbase = map(vbase , 0 , 100 , 0 , 180);
  ghombro = map(vhombro , 0 , 100 , 0 , 180);
  gcodo = map(vcodo , 0 , 100 , 0 , 180);
  gmuneca = map(vbase , 0 , 100 , 0 , 180);

  funcion = digitalRead(funcionpin);
  if(funcion == HIGH){//HIGH=MODO AUTOMÁTICO||LOW=MODO MANUAL
    
    indice = 0;
    lcd.print(textos[indice]);
    delay(1000);
    
    base.write(abase);
    hombro.write(ahombro);
    codo.write(acodo);
    muneca.write(amuneca);
    gripper.write(agripper);

    if(abase==gbase ){
      digitalWrite(bpinverde,HIGH);
      digitalWrite(bpinrojo,LOW);
    }

   if(gbase<abase){
      digitalWrite(bpinverde,LOW);
      digitalWrite(bpinrojo,HIGH);
     float baux = 0;
     baux = abase;
    do{
     baux++;
     base.write(baux);
     vbase = analogRead(sbasepin);
     vbase = (vbase*100)/1023;
     gbase = map(vbase , 0 , 100 , 0 , 180);
     
    }while(gbase==abase);
    
    digitalWrite(bpinverde,HIGH);
    digitalWrite(bpinrojo,LOW);
   }

   if(gbase>abase){
      digitalWrite(bpinverde,LOW);
      digitalWrite(bpinrojo,HIGH);
     float baux1 = 0;
     baux1 = abase;
    do{
     baux1--;
     base.write(baux1);
     vbase = analogRead(sbasepin);
     vbase = (vbase*100)/1023;
     gbase = map(vbase , 0 , 100 , 0 , 180);
     
    }while(gbase==abase);
    
    digitalWrite(bpinverde,HIGH);
    digitalWrite(bpinrojo,LOW);
   }

   // AJUSTE HOMBRO

if(ahombro==ghombro){
  digitalWrite(hpinverde,HIGH);
  digitalWrite(hpinrojo,LOW);
}

 if(ghombro<ahombro){
      digitalWrite(hpinverde,LOW);
      digitalWrite(hpinrojo,HIGH);
     float haux = 0;
     haux = ahombro;
    do{
     haux++;
     hombro.write(haux);
     vhombro = analogRead(shombropin);
     vhombro = (vhombro*100)/1023;
     ghombro = map(vhombro , 0 , 100 , 0 , 180);
     
    }while(ghombro==ahombro);
    
    digitalWrite(hpinverde,HIGH);
    digitalWrite(hpinrojo,LOW);
   }

   if(ghombro>ahombro){
      digitalWrite(hpinverde,LOW);
      digitalWrite(hpinrojo,HIGH);
     float haux1 = 0;
     haux1 = ahombro;
    do{
     haux1--;
     hombro.write(haux1);
     vhombro = analogRead(shombropin);
     vhombro = (vhombro*100)/1023;
     ghombro = map(vhombro , 0 , 100 , 0 , 180);
     
    }while(ghombro==ahombro);
    
    digitalWrite(hpinverde,HIGH);
    digitalWrite(hpinrojo,LOW);
   }

   //AJUSTE CODO

if(acodo==gcodo){
  digitalWrite(cpinverde,HIGH);
  digitalWrite(cpinrojo,LOW);
}

if(gcodo<acodo){
      digitalWrite(cpinverde,LOW);
      digitalWrite(cpinrojo,HIGH);
     float caux = 0;
     caux = acodo;
    do{
     caux++;
     codo.write(caux);
     vcodo = analogRead(scodopin);
     vcodo = (vcodo*100)/1023;
     gcodo = map(vcodo , 0 , 100 , 0 , 180);
     
    }while(gcodo==acodo);
    
    digitalWrite(hpinverde,HIGH);
    digitalWrite(hpinrojo,LOW);
   }

   if(gcodo>acodo){
      digitalWrite(cpinverde,LOW);
      digitalWrite(cpinrojo,HIGH);
     float caux1 = 0;
     caux1 = acodo;
    do{
     caux1--;
     codo.write(caux1);
     vcodo = analogRead(scodopin);
     vcodo = (vcodo*100)/1023;
     gcodo = map(vcodo , 0 , 100 , 0 , 180);
     
    }while(gcodo==acodo);
    
    digitalWrite(hpinverde,HIGH);
    digitalWrite(hpinrojo,LOW);
   }

   //Ajuste Muñeca

if(amuneca==gmuneca){
  digitalWrite(mpinverde,HIGH);
  digitalWrite(mpinrojo,LOW);
}

if(gmuneca<amuneca){
      digitalWrite(mpinverde,LOW);
      digitalWrite(mpinrojo,HIGH);
     float maux = 0;
     maux = amuneca;
    do{
     maux++;
     muneca.write(maux);
     vmuneca = analogRead(smunecapin);
     vmuneca = (vmuneca*100)/1023;
     gmuneca = map(vmuneca , 0 , 100 , 0 , 180);
     
    }while(gmuneca==amuneca);
    
    digitalWrite(mpinverde,HIGH);
    digitalWrite(mpinrojo,LOW);
   }
   
if(gmuneca>amuneca){
      digitalWrite(mpinverde,LOW);
      digitalWrite(mpinrojo,HIGH);
     float maux1 = 0;
     maux1 = amuneca;
    do{
     maux1--;
     muneca.write(maux1);
     vmuneca = analogRead(smunecapin);
     vmuneca = (vmuneca*100)/1023;
     gmuneca = map(vmuneca , 0 , 100 , 0 , 180);
     
    }while(gmuneca==amuneca);
    
    digitalWrite(mpinverde,HIGH);
    digitalWrite(mpinrojo,LOW);
   }
    
  }
  
  else{

    indice = 1;
    lcd.print(textos[indice]);
    delay(1000);
    
    base.attach(angulob);
    hombro.attach(anguloh);
    codo.attach(anguloc);
    muneca.attach(angulom);
    gripper.attach(0);

    estadobs = digitalRead(botonbs);
    estadobr = digitalRead(botonbr);
    estadohs = digitalRead(botonhs);
    estadohr = digitalRead(botonhr);
    estadocs = digitalRead(botoncs);
    estadocr = digitalRead(botoncr);
    estadoms = digitalRead(botonms);
    estadomr = digitalRead(botonmr);

    if(estadobs == HIGH){
      angulob++;

      if(angulob>=180){
        angulob = 180;
      }
    }

if(estadobr == HIGH){
      angulob--;

      if(angulob<=0){
        angulob = 0;
      }
    }

    base.write(angulob);
    
  //HOMBRO  

  if(estadohs == HIGH){
      anguloh++;

      if(anguloh>=180){
        anguloh = 180;
      }
    }

if(estadohr == HIGH){
      anguloh--;

      if(anguloh<=0){
        anguloh = 0;
      }
    }

    base.write(anguloh);  
  
  //CODO

  if(estadocs == HIGH){
      anguloc++;

      if(anguloc>=180){
        anguloc = 180;
      }
    }

if(estadocr == HIGH){
      anguloc--;

      if(anguloc<=0){
        anguloc = 0;
      }
    }

    base.write(anguloc);  

    //MUÑECA
    if(estadoms == HIGH){
      angulom++;

      if(angulom>=180){
        angulom = 180;
      }
    }

if(estadomr == HIGH){
      angulom--;

      if(angulom<=0){
        angulom = 0;
      }
    }

    base.write(angulom);  
  } 
  
  }

  
  
