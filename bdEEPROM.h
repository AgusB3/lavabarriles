long dato,
     tiBomba,
     tiPreBomba,
     tiAire,
     tiPurgaFinal,
     tiVapor,
     tiCo2,
     total,
     pantRepeticiones,
     dataso,
     lavElegido;

void cargarDatosLong() {
  tiPreBomba       = long(EEPROM.get(0,  dato));
  tiBomba          = long(EEPROM.get(10, dato));
  tiAire           = long(EEPROM.get(20, dato));
  tiPurgaFinal     = long(EEPROM.get(30, dato));
  pantRepeticiones = long(EEPROM.get(40, dato));
  tiVapor          = long(EEPROM.get(50, dato));
  tiCo2            = long(EEPROM.get(60, dato));
  total = tiPreBomba + tiBomba + tiPurgaFinal + tiAire + tiCo2;
  dbSerialPrintln(total);
}

void cargarLavado() {
  lavElegido = EEPROM.get(100, dataso);
  dbSerialPrintln(lavElegido);
  switch (lavElegido) {
    case 1:
      mostrarTipoLavado.setText("Alcalino + Sanitizante");
      break;
    case 2:
      mostrarTipoLavado.setText("Alcalino + Vapor");
      break;
    case 3:
      mostrarTipoLavado.setText("Alcalino + Vapor + Sanitizante");
      break;
    case 4:
      mostrarTipoLavado.setText("Alcalino + Acido");
      break;
    case 5:
      mostrarTipoLavado.setText("Solo Alcalino");
      break;
    case 6:
      mostrarTipoLavado.setText("Solo Sanitizante");
      break;
    default:
      mostrarTipoLavado.setText("Alcalino + Sanitizante");
      break;

  }
}
