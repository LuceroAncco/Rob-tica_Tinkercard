// ==========================================
// EJERCICIO 3
// SEMÁFORO PARA VEHÍCULOS Y PEATONES
// ==========================================
// Semáforo cíclico (sin botón) que alterna automáticamente entre el
// paso de vehículos y el paso de peatones, siguiendo una secuencia
// fija de tiempos.

// ==========================================
// SEMÁFORO DE VEHÍCULOS
// ==========================================
int rojoVehiculos = 13;
int amarilloVehiculos = 12;
int verdeVehiculos = 11;

// ==========================================
// SEMÁFORO DE PEATONES
// ==========================================
int rojoPeatones = 10;
int verdePeatones = 9;


void setup()
{
  // LEDs de vehículos como salida
  pinMode(rojoVehiculos, OUTPUT);
  pinMode(amarilloVehiculos, OUTPUT);
  pinMode(verdeVehiculos, OUTPUT);

  // LEDs de peatones como salida
  pinMode(rojoPeatones, OUTPUT);
  pinMode(verdePeatones, OUTPUT);
}


void loop()
{
  // ==========================================
  // 1. VEHÍCULOS: VERDE / PEATONES: ROJO
  // Los vehículos avanzan, los peatones deben esperar. (5 s)
  // ==========================================

  digitalWrite(verdeVehiculos, HIGH);
  digitalWrite(amarilloVehiculos, LOW);
  digitalWrite(rojoVehiculos, LOW);

  digitalWrite(rojoPeatones, HIGH);
  digitalWrite(verdePeatones, LOW);

  delay(5000);


  // ==========================================
  // 2. VEHÍCULOS: AMARILLO / PEATONES: ROJO
  // Aviso de que los vehículos van a detenerse. (2 s)
  // ==========================================

  digitalWrite(verdeVehiculos, LOW);
  digitalWrite(amarilloVehiculos, HIGH);

  digitalWrite(rojoPeatones, HIGH);
  digitalWrite(verdePeatones, LOW);

  delay(2000);


  // ==========================================
  // 3. VEHÍCULOS: ROJO / PEATONES: VERDE
  // Los vehículos se detienen y los peatones pueden cruzar. (5 s)
  // ==========================================

  digitalWrite(amarilloVehiculos, LOW);
  digitalWrite(rojoVehiculos, HIGH);

  digitalWrite(rojoPeatones, LOW);
  digitalWrite(verdePeatones, HIGH);

  delay(5000);


  // ==========================================
  // 4. PEATONES: ROJO / VEHÍCULOS: ROJO
  // Se corta el paso peatonal antes de reiniciar el ciclo. (1 s)
  // ==========================================

  digitalWrite(verdePeatones, LOW);
  digitalWrite(rojoPeatones, HIGH);

  delay(1000);

  // Después vuelve al inicio del ciclo:
  // VEHÍCULOS VERDE / PEATONES ROJO
}
