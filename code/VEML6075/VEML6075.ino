#include <VEML6075.h>

VEML6075 UV;

void setup()
{
Serial.begin(38400); //Begin Serial
UV.begin(); //Begin the UV module

}

void loop()
{
Serial.print("UVA = ");
Serial.print(UV.GetUVA()); //Get compensated UVA value
Serial.print(" UVB = ");
Serial.println(UV.GetUVB()); //Get compensated UVB value
delay(1000);
}
