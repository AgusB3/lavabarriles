#include "bdEEPROM.h"

#define DESCARTE 2
#define CO2 11
#define AIRE 10
#define H2O 3
#define VAPOR 9
#define SALIDAT1 5
#define SALIDAT2 6
#define RETORNOT1 7
#define RETORNOT2 8
#define BOMBA 23
#define PISTON 4
#define RESISTENCIA 21

#define MARCHA 20

void pinMoode() {
  pinMode(DESCARTE, OUTPUT);
  pinMode(CO2, OUTPUT);
  pinMode(AIRE, OUTPUT);
  pinMode(H2O, OUTPUT);
  pinMode(VAPOR, OUTPUT);
  pinMode(SALIDAT1, OUTPUT);
  pinMode(SALIDAT2, OUTPUT);
  pinMode(RETORNOT1, OUTPUT);
  pinMode(RETORNOT2, OUTPUT);
  pinMode(BOMBA, OUTPUT);
  pinMode(PISTON, OUTPUT);
  pinMode(RESISTENCIA, OUTPUT);

  pinMode(MARCHA, INPUT_PULLUP);
}

class Secuencia {
  private:
    long
    viejoTiempo,
    tiempoEspera,
    accion;
    byte
    valvula,
    valvula2,
    secuencia,
    _repeticiones,
    _estado;
    bool interruptor,
         interruptor2;
  public:
    void soloEsperar(long tiempoEspera) {
      viejoTiempo = millis();
      while (millis() <= viejoTiempo + tiempoEspera) {
        /*Poner verificacion de resistencia aca????*/
        temporizador(tiempoEspera);
        if (temperaturaSoda > valorMinimoSoda) {
          digitalWrite(RESISTENCIA, LOW);
        }
      }
    }
    void esperarConUnaValvula(byte valvula, bool interruptor, long tiempoEspera) {
      Serial.println(valvula);
      Serial.println(interruptor);
      digitalWrite(valvula, interruptor);
      soloEsperar(tiempoEspera);
    }
    void esperarConDosValvulas(byte valvula, byte valvula2, bool interruptor, bool interruptor2, long tiempoEspera) {
      Serial.println(valvula);
      Serial.println(interruptor);
      Serial.println(valvula2);
      Serial.println(interruptor2);
      digitalWrite(valvula, interruptor);
      digitalWrite(valvula2, interruptor2);
      soloEsperar(tiempoEspera);
    }
    //      /* Millis con multiples digitalwrite (pensarlo...) */

    void mostrarTiempos(long accion, int secuencia) {
      Serial.println("******************************************************");
      Serial.print("# Tiempo que duro esta acción: ");
      Serial.print(accion / 1000);
      Serial.println(" segundos");
      Serial.println("******************************************************");
      Serial.print("# Tiempo que lleva funcionando la maquina: ");
      Serial.print(millis() / 1000);
      Serial.println(" segundos");
      Serial.print("####################");
      Serial.print("    (");
      Serial.print(secuencia);
      Serial.print("/25");
      Serial.print(")   ");
      Serial.println("####################");
      Serial.println("");
    }

    void acumular(int _repeticiones, byte valvula, bool interruptor, bool interruptor1, long tiempoEspera, int secuencia) {
      Serial.println("Comenzando acumulación de aire en los barriles");
      for (int i = 0; i < _repeticiones; i++)
      {
        Serial.println("******************************************************");
        Serial.println("[Repitiendo Secuencia]");
        Serial.println("");
        Serial.print("[LOW] Descarte");
        Serial.println("");
        estoyHaciendo.setText("Acumulando aire en los barriles...");
        esperarConUnaValvula(valvula, interruptor, tiempoEspera);
        Serial.println("###");
        Serial.print("[HIGH] descarte");
        Serial.println("");
        estoyHaciendo.setText("Liberando aire de los barriles...");
        esperarConUnaValvula(valvula, interruptor1, tiempoEspera);
      }
      mostrarTiempos(tiempoEspera * _repeticiones, secuencia);
    }
};
