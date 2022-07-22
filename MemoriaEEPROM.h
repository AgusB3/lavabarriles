 #include <EEPROM.h>

class MemoriaEEPROM {
  public:

    void guardarDatoLong (int direccionEnMemoria, long datoAGuardar) {
      EEPROM.put(direccionEnMemoria, datoAGuardar);
      Serial.println("Dato almacenado...");
    }
//    void cargarDatoLong(int direccionEnMemoria, long datoObtenido, long variableTiempo) {
//      EEPROM.get(direccionEnMemoria, datoObtenido);
//      variableTiempo = datoObtenido;
//      return variableTiempo;
//    }
    void guardarDatoString(int direccionEnMemoria, String datoAGuardar) {
      EEPROM.put(direccionEnMemoria, datoAGuardar);
      Serial.println("Dato almacenado...");
    }
    void cargarDatoString(int direccionEnMemoria, String datoObtenido) {
      EEPROM.get(direccionEnMemoria, datoObtenido);
      Serial.println(datoObtenido);
    }

};
