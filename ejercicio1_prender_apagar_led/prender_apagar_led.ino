// ==========================================
// EJERCICIO 1
// PRENDER Y APAGAR UN LED
// ==========================================
// Hace parpadear un LED conectado al pin 13, encendiéndolo y
// apagándolo cada 1 segundo.

int led = 13;

void setup()
{
  // Configuramos el pin del LED como salida
  pinMode(led, OUTPUT);
}

void loop()
{
  // Encender LED
  digitalWrite(led, HIGH);
  delay(1000);

  // Apagar LED
  digitalWrite(led, LOW);
  delay(1000);
}
