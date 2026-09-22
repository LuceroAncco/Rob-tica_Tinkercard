// ==========================================
// EJERCICIO 4
// SEMÁFORO CON BOTÓN PEATONAL
// ==========================================
// Semáforo de vehículos que permanece en VERDE hasta que un peatón
// presiona un botón. Al presionarlo, se ejecuta la secuencia de cambio
// (amarillo -> rojo para vehículos, verde para peatones con cuenta
// regresiva) y luego vuelve al estado normal. Una pantalla LCD muestra
// el estado actual en todo momento.

#include <Adafruit_LiquidCrystal.h>

// ==========================================
// DISPLAY LCD (I2C, dirección 0)
// ==========================================
Adafruit_LiquidCrystal lcd(0);

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

// ==========================================
// BOTÓN PEATONAL
// ==========================================
int boton = 2;


void setup() {

  // LEDs de vehículos como salida
  pinMode(rojoVehiculos, OUTPUT);
  pinMode(amarilloVehiculos, OUTPUT);
  pinMode(verdeVehiculos, OUTPUT);

  // LEDs de peatones como salida
  pinMode(rojoPeatones, OUTPUT);
  pinMode(verdePeatones, OUTPUT);

  // Botón como entrada con resistencia pull-up interna:
  // en reposo el pin lee HIGH, y al presionar el botón pasa a LOW
  pinMode(boton, INPUT_PULLUP);

  // Inicializar LCD de 16 columnas x 2 filas
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  // ---------- Estado inicial: vehículos en verde, peatones en espera ----------
  digitalWrite(rojoVehiculos, LOW);
  digitalWrite(amarilloVehiculos, LOW);
  digitalWrite(verdeVehiculos, HIGH);

  digitalWrite(rojoPeatones, HIGH);
  digitalWrite(verdePeatones, LOW);

  // Mensaje inicial en la pantalla
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("VEHICULOS: VERDE");

  lcd.setCursor(0, 1);
  lcd.print("PEATONES: ESPERE");
}


void loop() {

  // Como se usa INPUT_PULLUP, el botón presionado se lee como LOW
  if (digitalRead(boton) == LOW) {

    // ==========================================
    // AVISO DE CAMBIO
    // Notifica que el semáforo va a cambiar de estado
    // ==========================================
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CAMBIO SEMAFORO");

    lcd.setCursor(0, 1);
    lcd.print("ESPERE...");

    delay(2000);


    // ==========================================
    // VEHÍCULOS: AMARILLO
    // Transición antes de detener a los vehículos
    // ==========================================
    digitalWrite(verdeVehiculos, LOW);
    digitalWrite(amarilloVehiculos, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VEHICULOS:");
    lcd.setCursor(0, 1);
    lcd.print("AMARILLO");

    delay(2000);


    // ==========================================
    // VEHÍCULOS: ROJO / PEATONES: VERDE
    // Los vehículos se detienen y los peatones pueden cruzar
    // ==========================================
    digitalWrite(amarilloVehiculos, LOW);
    digitalWrite(rojoVehiculos, HIGH);

    digitalWrite(rojoPeatones, LOW);
    digitalWrite(verdePeatones, HIGH);


    // ==========================================
    // CUENTA REGRESIVA PEATONAL
    // Muestra en la LCD el tiempo restante para cruzar (5 a 1)
    // ==========================================
    for (int tiempo = 5; tiempo >= 1; tiempo--) {

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("PEATONES: PASE");

      lcd.setCursor(0, 1);
      lcd.print("TIEMPO: ");
      lcd.print(tiempo);

      delay(1000);
    }


    // ==========================================
    // PEATONES: ROJO
    // Se termina el tiempo de cruce peatonal
    // ==========================================
    digitalWrite(verdePeatones, LOW);
    digitalWrite(rojoPeatones, HIGH);


    // ==========================================
    // VEHÍCULOS: VERDE
    // Se reanuda la circulación de vehículos
    // ==========================================
    digitalWrite(rojoVehiculos, LOW);
    digitalWrite(verdeVehiculos, HIGH);


    // ==========================================
    // MENSAJE NORMAL
    // Vuelve al estado de espera inicial
    // ==========================================
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VEHICULOS: VERDE");

    lcd.setCursor(0, 1);
    lcd.print("PEATONES: ESPERE");

    delay(1000);
  }
}
