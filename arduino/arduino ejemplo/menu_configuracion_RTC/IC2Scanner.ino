

void scanI2CBus(byte from_addr, byte to_addr, 
                void(*callback)(byte address, byte result) ) 
{
  byte rc;
  byte data = 0; // not used, just an address to feed to twi_writeTo()
  for( byte addr = from_addr; addr <= to_addr; addr++ ) {
    //rc = twi_writeTo(addr, &data, 0, 1);
    rc = twi_writeTo(addr, &data, 1, 1, 1);
    callback( addr, rc );
  }
}

void scanFunc( byte addr, byte result ) {
  Serial.print("addr: ");
  if(addr<10)
  Serial.print("0");
  if(addr<100)
  Serial.print("0");
  Serial.print(addr,DEC);
  Serial.print( (result==0) ? " found!":"       ");
  Serial.print( (addr%4) ? "\t":"\n");
}


  byte start_address = 1;
byte end_address = 200;

void StartScan(){
  

     Serial.println("\nI2CScanner ready!");
    Serial.print("starting scanning of I2C bus from ");
    Serial.print(start_address,DEC);
    Serial.print(" to ");
    Serial.print(end_address,DEC);
    Serial.println("...");

    // start the scan, will call "scanFunc()" on result from each address
    scanI2CBus( start_address, end_address, scanFunc );

    Serial.println("\ndone"); 
}
