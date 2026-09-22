// ==========================================
// EJERCICIO 1
// PRENDER Y APAGAR UN LED + PANTALLA LCD
// ==========================================
// Muestra el texto "hello world" en una pantalla LCD (I2C) y, al
// mismo tiempo, hace parpadear el LED integrado de la placa (LED_BUILTIN)
// cada 1 segundo.

#include <Adafruit_LiquidCrystal.h>

// Pantalla LCD conectada por I2C en la dirección 0
Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  // Inicializa la pantalla LCD de 16 columnas x 2 filas
  lcd_1.begin(16, 2);

  // Configura el LED integrado de la placa como salida
  pinMode(LED_BUILTIN, OUTPUT);

  // Posiciona el cursor al inicio y enciende la retroiluminación
  lcd_1.setCursor(0, 0);
  lcd_1.setBacklight(1);
  lcd_1.display();
}

void loop()
{
  // ---------- Estado: LED encendido ----------
  lcd_1.setCursor(0, 0);
  lcd_1.print("hello world");     // Muestra el texto en la LCD
  digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED
  delay(1000);                     // Espera 1 segundo

  // ---------- Estado: LED apagado ----------
  lcd_1.setCursor(0, 0);
  lcd_1.print("hello world");     // Vuelve a mostrar el texto
  lcd_1.clear();                   // Limpia la pantalla antes del siguiente ciclo
  digitalWrite(LED_BUILTIN, LOW);  // Apaga el LED
  delay(1000);                     // Espera 1 segundo
}
