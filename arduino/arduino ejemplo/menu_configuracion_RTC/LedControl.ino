void ledControl(){
  Serial.println("1-Led apagado");
  Serial.println("2-Led 1Hz");
  Serial.println("3-Led 4.096Hz");
  Serial.println("4-Led 8.192Hz");
  Serial.println("5-Led 32.768Hz");
  
  do{
  }while(Serial.available()<1);
  int ledOpcion=Serial.read();
  switch(ledOpcion){
  
    case '1':
      ctrl =   B1000000;
    break;
    
    case '2':
      ctrl =   B1010000;
    break;
    
    case '3':
     ctrl =   B10010001;
    break;
    
    case '4':
     ctrl =   B10010010;
    break;
    
    case '5':
     ctrl =   B10010011;
    break;
    
    default:
    Serial.print("Opcion erronea LED APAGADO");
    ctrl =   B1000000;
    break;
    
  }
  
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

