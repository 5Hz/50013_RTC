/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por:                                                          **
** Basado en el código de:                                       **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el Real Time Clock DS1307                        **
** lee la fecha (hh:mm:ss dd/mm/yyyy) y                          **
** la imprime en el puerto serial                                **
*******************************************************************

Conexiones para la comunicacion i2c usando el breakout de 5Hz con un Arduino Uno / Duemilanove:
Arduino <-> Breakout board
Gnd      -  GND
3.3v     -  VCC
3.3v     -  CS
Analog 4 -  SDA
Analog 5 -  SCL

Conexiones para la comunicacion i2c usando el breakout de 5Hz con un Arduino Mega / Mega ADK:
Arduino <-> Breakout board
Gnd      -  GND
3.3v     -  VCC
3.3v     -  CS
20       -  SDA
21       -  SLC
*/


#include <Wire.h>


//-----------------------------------------------------------definiciones
#define DS1307      0xD0 >> 1 //direccion I2C del reloj

//--------------------------------------------------definiciones de pines


//-------------------------------------definiciones de variables globales
byte second = 0x00;                       
byte minute = 0x00;
byte hour =   0x00;
byte wkDay =  0x00;
byte day =    0x00;
byte month =  0x00;
byte year =   0x00;
byte ctrl =   0x00;

byte R_SECS = 0;
byte R_MINS = 1;
byte R_HRS = 2;
byte R_WKDAY = 3;
byte R_DATE = 4;
byte R_MONTH = 5;
byte R_YEAR = 6;
byte R_SQW = 7;

//------------------------------------------------prototipos de funciones
void getClock();
void printHour();
void printHex2(byte hexVal);
void printMonthName(byte m);
void printDayName(byte d);
byte bcd2Dec(byte bcdVal);

//----------------------------------------------------------configuracion
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("*****************************************************");
  Serial.println("***********  Electronica 5Hz presenta:  *************");
  Serial.println("****** Leyendo la hora con nuestro amigo DS1338/DS1307  ****");
  Serial.println("*****************************************************");
}

//#########################################################ciclo principal
void loop()
{
  getClock();
  delay(1000);
}
//##################################################fin del ciclo principal


//-----------------------------------------------------------------funciones
void getClock()
{
  Wire.beginTransmission(DS1307);
  Wire.write(R_SECS);
  Wire.endTransmission();
  Wire.requestFrom(DS1307, 8);
  second = Wire.read();
  minute = Wire.read();
  hour   = Wire.read();
  wkDay  = Wire.read();
  day    = Wire.read();
  month  = Wire.read();
  year   = Wire.read();
  ctrl   = Wire.read();
  
  printHour();
}

void printHour()
{
  printHex2(hour);
  Serial.print(":");
  printHex2(minute);
  Serial.print(":");
  printHex2(second);

  Serial.print("  ");
  printDayName(bcd2Dec(wkDay));
  Serial.print("  ");

  printHex2(day);
  Serial.print(" ");
  printMonthName(bcd2Dec(month));
  Serial.print(" 20");
  printHex2(year);
  Serial.println(); 
}

void printHex2(byte hexVal)
{
  if (hexVal < 0x10)
    Serial.print("0");
  Serial.print(hexVal, HEX);
}

void printMonthName(byte m)
{
  switch (m) {
  case 1:
    Serial.print("JAN");
    break;
  case 2:
    Serial.print("FEB");
    break;
  case 3:
    Serial.print("MAR");
    break;
  case 4:
    Serial.print("APR");
    break;
  case 5:
    Serial.print("MAY");
    break;
  case 6:
    Serial.print("JUN");
    break;
  case 7:
    Serial.print("JUL");
    break;
  case 8:
    Serial.print("AUG");
    break;
  case 9:
    Serial.print("SEP");
    break;
  case 10:
    Serial.print("OCT");
    break;
  case 11:
    Serial.print("NOV");
    break;
  case 12:
    Serial.print("DEC");
    break;
  default:
    Serial.print("???");
  }
}

void printDayName(byte d)
{
  switch (d) {
  case 1:
    Serial.print("SUN");
    break;
  case 2:
    Serial.print("MON");
    break;
  case 3:
    Serial.print("TUE");
    break;
  case 4:
    Serial.print("WED");
    break;
  case 5:
    Serial.print("THU");
    break;
  case 6:
    Serial.print("FRI");
    break;
  case 7:
    Serial.print("SAT");
    break;
  default:
    Serial.print("???");
  }
}

byte bcd2Dec(byte bcdVal)
{
  return bcdVal / 16 * 10 + bcdVal % 16;
}
