long elegido;

void elegirLavado(NexText eleccion, int numeroLavado) {
  memset(buffer, 0, sizeof(buffer));
  eleccion.getText(buffer, sizeof(buffer));
  lavadoElegido.setText(buffer);
  numeroLavadoEscondido.setValue(numeroLavado);
  dbSerialPrintln(buffer);
  dbSerialPrintln(numeroLavado);
}

void btnalcalinoSanitizantePop(void *ptr) {
  elegirLavado(btnalcalinoSanitizante, 1);
}

void btnalcalinoVaporPop(void *ptr) {
  elegirLavado(btnalcalinoVapor, 2);
}

void btnalcalinoVaporSanitizantePop(void *ptr) {
  elegirLavado(btnalcalinoVaporSanitizante, 3);
}

void btnalcalinoAcidoPop(void *ptr) {
  elegirLavado(btnalcalinoAcido, 4);
}

void btnsoloAlcalinoPop(void *ptr) {
  elegirLavado(btnsoloAlcalino, 5);
}

void btnsoloSanitizantePop(void *ptr) {
  elegirLavado(btnsoloSanitizante, 6);
}

void btnGuardarEleccionLavadoPop(void *ptr) {
  numeroLavadoEscondido.getValue(&elegido);
  EEPROM.put(100, elegido);
}

void volverInicioPop(void *ptr) {
  int lavElegido,
      dataso;
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
