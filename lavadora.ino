 //#include <EEPROM.h>
#include "Pantalla.h"
#include "tiempoRestante.h"
#include "alcalinoSanitizante.h"

Pantalla pantalla;

void setup(void) {
  Serial.begin(9600);
  pantalla.attachPops();
  pinMoode();
  cargarDatosLong();
  cargarLavado();
}

void loop(void) {
  nexLoop(Nex_listen_list);
  mediciones();
  lavadora();
}
