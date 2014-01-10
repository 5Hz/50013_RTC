void getClock_sinPrint()
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
}
