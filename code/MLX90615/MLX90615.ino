#include <Wire.h>
#include <mlx90615.h>

MLX90615 mlx = MLX90615();

void setup() {
Serial.begin(9600);
Serial.println("Melexis MLX90615 infra-red temperature sensor test");
mlx.begin();
Serial.print("Sensor ID number = ");
Serial.println(mlx.get_id(), HEX);
}

void loop() {
Serial.print("Ambient = ");
Serial.print(mlx.get_ambient_temp());
Serial.print(" *C\tObject = ");
Serial.print(mlx.get_object_temp());
Serial.println(" *C");

Serial.println();
delay(500);
}
