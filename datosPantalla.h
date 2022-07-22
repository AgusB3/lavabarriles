#include "Nextion.h"

/* pantalla Tiempo Restante */
NexPage pantaTiempoRestante          = NexPage(4, 0, "enMarcha");
NexText estoyHaciendo                = NexText(4, 1, "t100");
NexNumber mostrarTiempoRestante      = NexNumber(4, 2, "n79");
NexNumber mostrarTiempoRestanteTotal = NexNumber(4, 3, "n80");
NexNumber pantSoda                   = NexNumber(4, 4, "n81");
NexNumber pantVapor                  = NexNumber(4, 5, "n82");

/* pantalla inicio */
NexPage pantaInicio                 = NexPage(0, 0, "inicio");

/* Medidas */
NexNumber conductividadSoda         = NexNumber(0, 3, "n0");
/* Datos Mostrados en pantalla */
NexNumber temperaturaPantSoda       = NexNumber(0, 4, "n2t");
NexText mostrarTipoLavado           = NexText(0, 7, "t3");
NexButton volverInicio              = NexButton(1, 3, "b2");

/** Tiempos **/
//1 Enjuague
NexNumber enj1purga      = NexNumber(3, 1, "nt1");
NexNumber enj1bomba      = NexNumber(3, 9, "nt2");
NexNumber enj1aire       = NexNumber(3, 10, "nt3");
//Tacho 1
NexNumber tacho1purga    = NexNumber(3, 4, "nt4");
NexNumber tacho1bomba    = NexNumber(3, 6, "nt5");
NexNumber tacho1aire     = NexNumber(3, 7, "nt6");
//Enjuague 2
NexNumber enj2purga      = NexNumber(3, 5, "nt7");
NexNumber enj2bomba      = NexNumber(3, 8, "nt8");
NexNumber enj2aire       = NexNumber(3, 11, "nt9");
//Tacho 2
NexNumber tacho2purga    = NexNumber(3, 14, "nt10");
NexNumber tacho2bomba    = NexNumber(3, 13, "nt11");
NexNumber tacho2aire     = NexNumber(3, 12, "nt12");
//Tacho 2
NexNumber co2presur      = NexNumber(3, 15, "nt13");
/* Repetición */
NexNumber enj1repe       = NexNumber(3, 17, "nt14");
NexNumber tacho1repe     = NexNumber(3, 18, "nt15");
NexNumber enj2repe       = NexNumber(3, 20, "nt16");
NexNumber tacho2repe     = NexNumber(3, 19, "nt17");
/* Vapor */
//NexNumber vapor        = NexNumber(3, 17, "n1");
/* Btn confirmar*/
NexButton btnConfirmarCambios = NexButton(3, 2, "bt1");
NexButton btnConfigAvanzada   = NexButton(3, 16, "bt0");
NexButton btnVolver           = NexButton(3, 3, "bt2");

/** Lavados **/
NexNumber numeroLavadoEscondido     = NexNumber(2, 11, "n200");
NexText btnalcalinoSanitizante      = NexText(2, 1, "t0");
NexText btnalcalinoVapor            = NexText(2, 2, "t1");
NexText btnalcalinoVaporSanitizante = NexText(2, 3, "t2");
NexText btnalcalinoAcido            = NexText(2, 4, "t3");
NexText btnsoloAlcalino             = NexText(2, 5, "t4");
NexText btnsoloSanitizante          = NexText(2, 6, "t5");
NexText lavadoElegido               = NexText(2, 8, "t6");
NexButton btnGuardarEleccionLavado  = NexButton(2, 7, "b0");
