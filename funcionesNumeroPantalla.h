#include "configDatosPantalla.h"
#include "MemoriaEEPROM.H"

MemoriaEEPROM memoria;

long
/* TIEMPOS */
TAcumular = 3000,
TPREBOMBA,
TBOMBA,
TAIRE,
TPURGAFINAL,
TVAPOR,
TCO2,
/* Ciclos */
TREPETICIONES;

void guardarDatosLong() {
  memoria.guardarDatoLong(0,  TPREBOMBA);
  memoria.guardarDatoLong(10, TBOMBA);
  memoria.guardarDatoLong(20, TAIRE);
  memoria.guardarDatoLong(30, TPURGAFINAL);
  memoria.guardarDatoLong(40, TREPETICIONES);
  memoria.guardarDatoLong(50, TVAPOR);
  memoria.guardarDatoLong(60, TCO2);
}

void btnConfirmarCambiosPop(void *ptr) {
//  preBomba.getValue(&TPREBOMBA);
//  bomba.getValue(&TBOMBA);
//  aire.getValue(&TAIRE);
//  purgaFinal.getValue(&TPURGAFINAL);
//  vapor.getValue(&TVAPOR);
//  co2.getValue(&TCO2);
//  repetici.getValue(&TREPETICIONES);
//  guardarDatosLong();
  dbSerialPrintln("Datos Guardados Exitosamente.");
}
