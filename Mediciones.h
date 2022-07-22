#include "datosMediciones.h"

void medirTemperaturaVapor() {
  temperaturaVapor = termometroVapor.readCelsius();
  Serial.println("Temp | Vapor: ");
  Serial.println(temperaturaVapor);
}
void medirTemperaturaSoda() {
  temperaturaSoda  =  termometroSoda.readCelsius();
  Serial.println("Temp | Soda: ");
  Serial.println(temperaturaSoda);
  temperaturaPantSoda.setValue(temperaturaSoda);
}
void medirConductividadSoda() {
  conductividad = analogRead(0);
  soda = (conductividad / 100) * 10;
  Serial.println("Conductividad | Soda: ");
  Serial.println(soda);
  conductividadSoda.setValue(conductividad);
}
void mediciones() {
  if (millis() - tiempoViejo > 5000)
  {
    tiempoViejo = millis();                                 // Obtengo el tiempo de funcionamiento actual
    medirTemperaturaVapor();
    medirTemperaturaSoda();
    medirConductividadSoda();
  }
}
