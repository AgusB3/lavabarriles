#include "Secuencia.h"

Secuencia secuencia;

bool
abierta = HIGH,
cerrada = LOW;

long
repeticion,
EAcumular = 3000,
multi = 1000;
int
estado = 1,
_estado;

void comprobarRepeticiones(bool valvula) {
  if (repeticion > EAcumular)
  {
    estoyHaciendo.setText("[Repeticiones encontradas] Repitiendo Secuencia...");
    digitalWrite(valvula, cerrada);
    repeticion--;
    estado--;
  }
  else
  {
    estoyHaciendo.setText("Sin repeticiones.");
    estado++;
  }
}
void etapaUno() {
  /* Alcalino + Sanitizante */
  switch (estado)
  {
    case 1:
      digitalWrite(RESISTENCIA, abierta);
      mediciones();
      while (temperaturaSoda > valorMinimoSoda) {
        digitalWrite(RESISTENCIA, cerrada);
      }
      if (!digitalRead(MARCHA)) {
        digitalWrite(DESCARTE, abierta);
        digitalWrite(PISTON, abierta);
        pantaTiempoRestante.show();
        dbSerialPrintln(total);

        secuencia.soloEsperar(2000);
        estoyHaciendo.setText("Abrí descarte y baje pistones.");
        repeticion = pantRepeticiones;
        estado++;
      }
      break;
    case 2:
      /* [HIGH] H2O */
      estoyHaciendo.setText("LLenando de liquido la bomba...");
      secuencia.esperarConUnaValvula(H2O, abierta, tiPreBomba * multi);
      secuencia.mostrarTiempos(tiPreBomba * multi, 01);
      estoyHaciendo.setText("Prendi la bomba.");
      secuencia.esperarConUnaValvula(BOMBA, abierta, tiBomba * multi);
      secuencia.mostrarTiempos(tiBomba * multi, 02);
      estado++;
      break;
    case 3:
      estoyHaciendo.setText("Cerrando valvula del liquido y apagando la bomba...");
      secuencia.esperarConDosValvulas(H2O, BOMBA, cerrada, cerrada, 1000);
      secuencia.mostrarTiempos(1000, 03);
      estoyHaciendo.setText("Expulsando el liquido dentro de los barriles con aire.");
      secuencia.esperarConUnaValvula(AIRE, abierta, tiAire * multi);
      secuencia.mostrarTiempos(tiAire * multi, 04); /* a revisar*/
      estoyHaciendo.setText("Comprobando si hay repeticiones...");
      comprobarRepeticiones(AIRE);
      break;
    case 4:
      secuencia.acumular(3, DESCARTE, cerrada, abierta, EAcumular, 05);
      estado++;
      break;
    case 5:
      secuencia.esperarConUnaValvula(DESCARTE, abierta, 1000);
      estoyHaciendo.setText("Cerrando aire...");
      digitalWrite(AIRE, cerrada);
      secuencia.soloEsperar(1000);
      repeticion = pantRepeticiones;
      secuencia.mostrarTiempos(1000, 06);
      estado++;
      break;
  }
}
void etapaDos() {
  switch (estado) {
    case 6:
      digitalWrite(DESCARTE, cerrada);
      estoyHaciendo.setText("Acumulando liquido del tacho 1 previo a encender la bomba");
      secuencia.esperarConDosValvulas(SALIDAT1, RETORNOT1, abierta, abierta, tiPreBomba * multi);
      digitalWrite(RESISTENCIA, cerrada);
      secuencia.mostrarTiempos(tiPreBomba * multi, 07);
      estoyHaciendo.setText("Prendi la bomba.");
      secuencia.esperarConUnaValvula(BOMBA, abierta, tiBomba * multi);
      secuencia.mostrarTiempos(tiBomba * multi, 8);
      estado++;
      break;

    case 7:
      estoyHaciendo.setText("Cerrando entrada del liquido y apagando la bomba...");
      secuencia.esperarConDosValvulas(SALIDAT1, BOMBA, cerrada, cerrada, 1000);
      secuencia.mostrarTiempos(1000, 9);
      estoyHaciendo.setText("Liberando aire para expulsar restos de liquido...");
      secuencia.esperarConUnaValvula(AIRE, abierta, tiAire * multi);
      secuencia.mostrarTiempos(tiAire * multi, 10);
      comprobarRepeticiones(AIRE);
      break;

    case 8:
      secuencia.acumular(3, RETORNOT1, cerrada, abierta, EAcumular, 11);
      secuencia.esperarConDosValvulas(AIRE, RETORNOT1, cerrada, cerrada, 1000);
      digitalWrite(RESISTENCIA, abierta);
      secuencia.mostrarTiempos(1000, 12);
      digitalWrite(DESCARTE, cerrada);
      repeticion = pantRepeticiones;
      estado++;
      break;
  }
}
void etapaTres() {
  switch (estado) {
    case 9:
      estoyHaciendo.setText("Acumulando liquido previo a encender la bomba.");
      secuencia.esperarConUnaValvula(H2O, abierta, tiPreBomba * multi);
      secuencia.mostrarTiempos(tiPreBomba * multi, 13);
      estoyHaciendo.setText("Prendi la bomba.");
      secuencia.esperarConUnaValvula(BOMBA, abierta, tiBomba * multi);
      secuencia.mostrarTiempos(tiBomba * multi, 14);
      estado++;
      break;
    case 10:
      estoyHaciendo.setText("Cerrando entrada del liquido y apagando la bomba...");
      secuencia.esperarConDosValvulas(H2O, BOMBA, cerrada, cerrada, 1000);
      secuencia.mostrarTiempos(1000, 15);
      estoyHaciendo.setText("Liberando aire para expulsar restos de liquido...");
      secuencia.esperarConUnaValvula(AIRE, abierta, tiAire * multi);
      secuencia.mostrarTiempos(tiAire * multi, 16);
      comprobarRepeticiones(AIRE);
      break;
    case 11:
      secuencia.acumular(3, DESCARTE, cerrada, abierta, EAcumular, 17);
      estado++;
      break;
    case 12:
      secuencia.esperarConUnaValvula(DESCARTE, abierta, 1000);
      digitalWrite(AIRE, cerrada);
      secuencia.soloEsperar(1000);
      repeticion = pantRepeticiones;
      secuencia.mostrarTiempos(1000, 18);
      estado++;
      break;

  }
}
void etapaCuatro() {
  switch (estado) {
    case 13:
      secuencia.esperarConUnaValvula(DESCARTE, cerrada, 1000);
      secuencia.mostrarTiempos(1000, 19);
      estoyHaciendo.setText("Acumulando liquido del tacho 2 previo a encender la bomba.");
      secuencia.esperarConDosValvulas(SALIDAT2, RETORNOT2, abierta, abierta, tiPreBomba * multi);
      secuencia.mostrarTiempos(tiPreBomba * multi, 20);
      estoyHaciendo.setText("Prendi la bomba.");
      secuencia.esperarConUnaValvula(BOMBA, abierta, tiBomba * multi);
      secuencia.mostrarTiempos(tiBomba * multi, 21);
      estado++;
      break;
    case 14:
      estoyHaciendo.setText("Cerrando entrada del liquido y apagando la bomba...");
      secuencia.esperarConDosValvulas(SALIDAT2, BOMBA, cerrada, cerrada, 1000);
      secuencia.mostrarTiempos(1000, 22);
      estoyHaciendo.setText("Liberando aire para expulsar restos de liquido...");
      secuencia.esperarConUnaValvula(AIRE, abierta, tiAire * multi);
      secuencia.mostrarTiempos(tiAire * multi, 23);
      comprobarRepeticiones(AIRE);
      break;
    case 15:
      secuencia.acumular(3, RETORNOT2, cerrada, abierta, EAcumular, 24);
      secuencia.esperarConDosValvulas(AIRE, RETORNOT2, cerrada, abierta, 1000);
      secuencia.mostrarTiempos(1000, 25);
      digitalWrite(RETORNOT2, cerrada);
      repeticion = pantRepeticiones;
      estado++;
      break;
  }
}
void etapaCinco() {
  switch (estado) {
    case 16:
      estoyHaciendo.setText("Liberando CO2 para presurizar los barriles...");
      secuencia.esperarConUnaValvula(CO2, abierta, tiCo2 * multi);
      secuencia.mostrarTiempos(tiCo2 * multi, 26);
      secuencia.acumular(3, DESCARTE, cerrada, abierta, EAcumular, 27);
      estado++;
      break;
    case 17:
      estoyHaciendo.setText("Cerrando CO2...");
      secuencia.esperarConDosValvulas(CO2, DESCARTE, cerrada, cerrada, 1000);
      secuencia.mostrarTiempos(1000, 26);
      estoyHaciendo.setText("¡Lavado Finalizado!");
      estado++;
      break;
    case 18:
      /* Lavado Finalizado */
      digitalWrite(PISTON, cerrada);
      pantaInicio.show();
      estado = 1;
      break;
  }
}

void lavadora() {
  etapaUno();
  etapaDos();
  etapaTres();
  etapaCuatro();
  etapaCinco();
}
