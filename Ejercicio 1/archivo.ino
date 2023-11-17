const int PULSADOR1 = 2;
const int PULSADOR2 = 3;
const int PULSADOR3 = 4;
const int LED1 = 9;
const int LED2 = 10;

enum Estado {
  ESPERANDO,
  INCREMENTANDO,
  ATENUANDO
};

Estado estado = ESPERANDO;
int brilloActual = 0;
int paso = 5; // Ajusta el paso de incremento/atenuacion
int ledActual = LED1;

void setup() {
  pinMode(PULSADOR1, INPUT_PULLUP);
  pinMode(PULSADOR2, INPUT_PULLUP);
  pinMode(PULSADOR3, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  
  if (digitalRead(PULSADOR1) == LOW) {
    estado = INCREMENTANDO;
  } else if (digitalRead(PULSADOR2) == LOW) {
    if (brilloActual == 0) {
      
      brilloActual = 255;
      estado = ATENUANDO;
    } else {
      
      estado = ATENUANDO;
    }
  } else if (digitalRead(PULSADOR3) == LOW) {
   
    ledActual = (ledActual == LED1) ? LED2 : LED1;
    estado = ESPERANDO;
  }

 
  switch (estado) {
    case ESPERANDO:
     
      break;
    case INCREMENTANDO:
      incrementarBrillo();
      break;
    case ATENUANDO:
      atenuarBrillo();
      break;
  }
}

void incrementarBrillo() {
  if (brilloActual < 255) {
    brilloActual += paso;
  }
  analogWrite(ledActual, brilloActual);
  delay(50);  // Modificar valor para cambial la velocidad de incremento
}

void atenuarBrillo() {
  if (brilloActual > 0) {
    brilloActual -= paso;
  }
  analogWrite(ledActual, brilloActual);
  delay(50);  // Modificar valor para cambial la velocidad de atenuacion
}
