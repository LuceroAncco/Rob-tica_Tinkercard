// ==========================================
// EJERCICIO 2
// SEMÁFORO AMERICANO
// ==========================================
// Simula el funcionamiento de un semáforo de vehículos con las
// secuencias: rojo -> rojo+amarillo -> verde -> amarillo -> rojo,
// mientras el semáforo de peatones permanece apagado (fijo).

// ---------- Pines del semáforo de vehículos ----------
int rojoVehiculos = 13;      // LED rojo para vehículos
int amarilloVehiculos = 12;  // LED amarillo para vehículos
int verdeVehiculos = 11;     // LED verde para vehículos

// ---------- Pines del semáforo de peatones ----------
int rojoPeatones = 10;   // LED rojo para peatones
int verdePeatones = 9;   // LED verde para peatones


void setup()
{
  // Configura los LEDs de vehículos como salidas digitales
  pinMode(rojoVehiculos, OUTPUT);
  pinMode(amarilloVehiculos, OUTPUT);
  pinMode(verdeVehiculos, OUTPUT);

  // Configura los LEDs de peatones como salidas digitales
  pinMode(rojoPeatones, OUTPUT);
  pinMode(verdePeatones, OUTPUT);

  // En este ejercicio los LEDs de peatones permanecen apagados
  // durante toda la simulación (no se usan más en el loop)
  digitalWrite(rojoPeatones, LOW);
  digitalWrite(verdePeatones, LOW);
}


void loop()
{
  // ==========================================
  // 1. ROJO
  // Los vehículos deben detenerse. Se mantiene 5 segundos.
  // ==========================================

  digitalWrite(rojoVehiculos, HIGH);
  digitalWrite(amarilloVehiculos, LOW);
  digitalWrite(verdeVehiculos, LOW);

  delay(5000);


  // ==========================================
  // 2. ROJO + AMARILLO
  // Aviso de que el semáforo está por cambiar a verde.
  // Se mantiene 2 segundos.
  // ==========================================

  digitalWrite(rojoVehiculos, HIGH);
  digitalWrite(amarilloVehiculos, HIGH);
  digitalWrite(verdeVehiculos, LOW);

  delay(2000);


  // ==========================================
  // 3. VERDE
  // Los vehículos pueden avanzar. Se mantiene 5 segundos.
  // ==========================================

  digitalWrite(rojoVehiculos, LOW);
  digitalWrite(amarilloVehiculos, LOW);
  digitalWrite(verdeVehiculos, HIGH);

  delay(5000);


  // ==========================================
  // 4. AMARILLO
  // Aviso de que el semáforo está por cambiar a rojo.
  // Se mantiene 2 segundos.
  // ==========================================

  digitalWrite(verdeVehiculos, LOW);
  digitalWrite(amarilloVehiculos, HIGH);
  digitalWrite(rojoVehiculos, LOW);

  delay(2000);


  // ==========================================
  // 5. REGRESA A ROJO
  // Se cierra el ciclo y vuelve a empezar desde el paso 1.
  // Se mantiene 5 segundos.
  // ==========================================

  digitalWrite(amarilloVehiculos, LOW);
  digitalWrite(rojoVehiculos, HIGH);

  delay(5000);
}
