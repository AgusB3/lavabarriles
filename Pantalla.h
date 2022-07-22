#include "funcionesNumeroPantalla.h"
#include "funcionesTextoPantalla.h"

class Pantalla {

  public:
   
    void attachPops() {
      nexInit();
      btnConfirmarCambios.attachPop(btnConfirmarCambiosPop, &btnConfirmarCambios);
      btnalcalinoSanitizante.attachPop(btnalcalinoSanitizantePop, &btnalcalinoSanitizante);
      btnalcalinoVapor.attachPop(btnalcalinoVaporPop, &btnalcalinoVapor);
      btnalcalinoVaporSanitizante.attachPop(btnalcalinoVaporSanitizantePop, &btnalcalinoVaporSanitizante);
      btnalcalinoAcido.attachPop(btnalcalinoAcidoPop, &btnalcalinoAcido);
      btnsoloAlcalino.attachPop(btnsoloAlcalinoPop, &btnsoloAlcalino);
      btnsoloSanitizante.attachPop(btnsoloSanitizantePop, &btnsoloSanitizante);
      btnGuardarEleccionLavado.attachPop(btnGuardarEleccionLavadoPop, &btnGuardarEleccionLavado);
      volverInicio.attachPop(volverInicioPop, &volverInicio);
      dbSerialPrintln("Setup Pantalla");
    }
};
