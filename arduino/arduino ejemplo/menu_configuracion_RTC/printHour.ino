void printHour(){
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
