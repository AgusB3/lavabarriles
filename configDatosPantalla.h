#include "datosPantalla.h"

void btnConfirmarCambiosPop(void *ptr);
void btnalcalinoSanitizantePop(void *ptr);
void btnalcalinoVaporPop(void *ptr);
void btnalcalinoVaporSanitizantePop(void *ptr);
void btnalcalinoAcidoPop(void *ptr);
void btnsoloAlcalinoPop(void *ptr);
void btnsoloSanitizantePop(void *ptr);

char buffer[100] = {0};

NexTouch *Nex_listen_list[] = {
  //&vapor,
  /* btn's */
  &btnConfirmarCambios,
  &btnalcalinoSanitizante,
  &btnalcalinoVapor,
  &btnalcalinoVaporSanitizante,
  &btnalcalinoAcido,
  &btnsoloAlcalino,
  &btnsoloSanitizante,
  &btnGuardarEleccionLavado,
  &conductividadSoda,
  &temperaturaPantSoda,
  &mostrarTiempoRestante,
  &mostrarTipoLavado,
  &numeroLavadoEscondido,
  &volverInicio,
  &pantaTiempoRestante,
  &estoyHaciendo,
  &pantaInicio,
  &pantSoda,
  &pantVapor,
  &mostrarTiempoRestanteTotal,
  &btnConfigAvanzada,
  &btnVolver,
  &tacho2repe,
  &enj2repe,
  &tacho1repe,
  &enj1repe,
  /* liquidos */
  &co2presur,
  &tacho2aire,
  &tacho2bomba,
  &tacho2purga,
  &enj2aire,
  &enj2bomba,
  &enj2purga,
  &tacho1aire,
  &tacho1bomba,
  &tacho1purga,
  &enj1aire,
  &enj1bomba,
  &enj1purga,
  NULL
};
