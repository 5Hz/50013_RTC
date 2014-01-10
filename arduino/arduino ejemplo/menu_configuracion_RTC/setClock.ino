void setClock()
{
  Serial.print("Segundos=");
  do{
  }while(Serial.available()<2);
  second=Serial.read();
  second=second-48;
  second=second<<4;
  second=second+(Serial.read()-48);
  Serial.println(second,HEX);
  
  Serial.print("Minutos= ");
  do{
  }while(Serial.available()<2);
  minute=Serial.read();
  minute=minute-48;
  minute=minute<<4;
  minute=minute+(Serial.read()-48);
  Serial.println(minute,HEX);
  
  Serial.print("Hora= ");
  do{
  }while(Serial.available()<2);
  hour=Serial.read();
  hour=hour-48;
  hour=hour<<4;
  hour=hour+(Serial.read()-48);
  Serial.println(hour,HEX);
  
  Serial.println("1- Dom  2- Lun 3-Mar 4-Mier 5-Jue 6-Vie 7-Sab");
  Serial.print("Dia de la semana=  ");
  do{
  }while(Serial.available()<1);
  wkDay=Serial.read();
  wkDay=wkDay-48;
  printDayName(bcd2Dec(wkDay));
  Serial.println("");
  
  Serial.print("Dia del mes= ");
  do{
  }while(Serial.available()<2);
  day=Serial.read();
  day=day-48;
  day=day<<4;
  day=day+(Serial.read()-48);
  Serial.println(day,HEX);

  Serial.print("Mes= ");
  do{
  }while(Serial.available()<2);
  month=Serial.read();
  month=month-48;
  month=month<<4;
  month=month+(Serial.read()-48);
  Serial.println(month,HEX);
 
  Serial.print("Ano= ");
  do{
  }while(Serial.available()<2);
  year=Serial.read();
  year=year-48;
  year=year<<4;
  year=year+(Serial.read()-48);
  Serial.println(year,HEX);
  
  Wire.beginTransmission(DS1307);
  Wire.write(R_SECS);
  Wire.write(second);
  Wire.write(minute);
  Wire.write(hour);
  Wire.write(wkDay);
  Wire.write(day);
  Wire.write(month);
  Wire.write(year);
  Wire.write(ctrl);
  Wire.endTransmission();
}
