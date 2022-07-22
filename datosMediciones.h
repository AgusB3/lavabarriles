  #include "max6675.h"

#define CSVapor 32
#define CSSoda  33
// Pines en común
#define SCK     34
#define SO      35

float
temperaturaVapor,
temperaturaSoda;

MAX6675 termometroVapor(SCK, CSVapor, SO);
MAX6675 termometroSoda(SCK, CSSoda, SO);

int
conductividad,
soda,
valorMinimoSoda = 50,
valorMaximoSoda = 60;

long
tiempoViejo;
