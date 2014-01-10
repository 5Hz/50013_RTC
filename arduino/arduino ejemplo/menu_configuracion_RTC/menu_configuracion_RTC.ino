#include "Wire.h"
extern "C" { 
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}

#define DS1307      0xD0 >> 1
//#define R_SECS      0
//#define R_MINS      1
//#define R_HRS       2
//#define R_WKDAY     3
//#define R_DATE      4
//#define R_MONTH     5
//#define R_YEAR      6
//#define R_SQW       7

int entrada;
int opcion = 0;

byte second = 0x00;  // default to 01 JAN 2007, midnight
byte minute = 0x06;
byte hour =   0x12;
byte wkDay =  0x06;
byte day =    0x27;
byte month =  0x01;
byte year =   0x12;
byte ctrl =   0x10;

byte R_SECS = 0;
byte R_MINS = 1;
byte R_HRS = 2;
byte R_WKDAY = 3;
byte R_DATE = 4;
byte R_MONTH = 5;
byte R_YEAR = 6;
byte R_SQW = 7;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  menu();
}

void loop(){
  delay(1000);
    if (opcion == 2)  // indica que se seleccionó una opción válida
      getClock();
      //Serial.println(" ");
  else
    menu();
  if (Serial.available()){
    entrada=Serial.read();
    if(entrada=='*'){
      menu();
    }    
  }
}

void menu(){
  int entradaMenu;
  Serial.println("-------------------5HZ ELECTRONICA---------------------------");
  Serial.println("");
  Serial.println("                     PRESENTA");
  Serial.println("");
  Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("      BIEVENIDO AL PROGRAMA DE PRUEBAS DEL RTC");
  Serial.println("");
Serial.println("");
    Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("MENU PRINCIPAL");
  Serial.println("1-Escanear I2C");
  Serial.println("2-Get clock");
  Serial.println("3-Set clock");
  Serial.println("4-Led disable");
  Serial.println("5-Led enable");
  Serial.println("6-Led Control");


  do{
  }while(Serial.available()==0);
      entradaMenu=Serial.read();
    switch(entradaMenu){
   
    case '1':
       Serial.println("");
      Serial.println("I2C Scan");
      delay(1000);
      StartScan();
      opcion = 1;
      break;
      
    case '2':
      Serial.println("");
      Serial.println("Get Clock");
      getClock();
      delay(1000);
      opcion = 2;
      break;
      
    case '3':
      Serial.println("");
      Serial.println("Set Clock");
      setClock();
      getClock();
      opcion = 3;
      break;

    case '4':
      Serial.println("");
      Serial.println("Led enable");
      ctrl =   B1010000;
      setClock();
      opcion = 4;
      break;

    case '5':
      Serial.println("");
      Serial.println("Led disable");
      ctrl =   B1000000;
      setClock();  
      opcion = 5;
      break;
      
    case '6':
      Serial.println("");
      Serial.println("Led control");
      getClock_sinPrint();
      delay(100);
      ledControl();
      break;

    default:
      Serial.println("Solo hay 6 opciones, intenta de nuevo ");
      opcion = 0;
      break;
    }
    
    if (opcion == 1)
    Serial.println("Hola soy la TERMINAL DE 5Hz (presiona '*' para ir al menu) ");

}
