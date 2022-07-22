#include "Mediciones.h"

void temporizador(long tiempoLavado) {
  long tiempoRestante =  tiempoLavado / 1000,
       oldt;

  while (tiempoRestante > 0) {
    oldt = millis();
    tiempoRestante--;
    mostrarTiempoRestante.setValue(tiempoRestante);
    pantSoda.setValue(temperaturaSoda);
    pantVapor.setValue(temperaturaVapor);
    while (millis() <= oldt + 1000) {
      mediciones();
    }
  }
}
