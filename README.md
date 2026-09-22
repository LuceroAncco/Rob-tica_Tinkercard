# Proyectos de Robótica - Tinkercad

Ejercicios de simulación de circuitos con Arduino en Tinkercad Circuits.

## Autor
Mirian Lucero Ancco Ancalla - Ingeniería de Software

---

## Ejercicio 1: Prender y apagar un LED (con pantalla LCD)

Muestra el texto "hello world" en una pantalla LCD y hace parpadear el LED
integrado de la placa cada 1 segundo.

- **Proyecto en Tinkercad:** https://www.tinkercad.com/things/7MyyloQWJTt-prender-y-apagar-un-led/editel?sharecode=oC8l8lmMZIOnPgjjz1EwVZ_L40kLGXqHcROYUAv2csM
- **Código fuente:** [`ejercicio1_prender_apagar_led/prender_apagar_led.ino`](./ejercicio1_prender_apagar_led/prender_apagar_led.ino)

---

## Ejercicio 2: Semáforo americano

Simula un semáforo de vehículos con la secuencia: rojo (5 s) → rojo + amarillo
(2 s) → verde (5 s) → amarillo (2 s) → regresa a rojo (5 s). El semáforo de
peatones permanece apagado durante toda la simulación.

- **Proyecto en Tinkercad:** https://www.tinkercad.com/things/glbzpSlWe1Q/editel?sharecode=9Zz6FWu2WpKPqlmjhHB0SxtrOiLFay7H7GmgLwaDqDE
- **Código fuente:** [`ejercicio2_semaforo_americano/semaforo_americano.ino`](./ejercicio2_semaforo_americano/semaforo_americano.ino)

---

## Ejercicio 3: Semáforo para carros y personas

Semáforo cíclico (automático, sin botón) que alterna entre el paso de
vehículos y el paso de peatones siguiendo una secuencia fija de tiempos:
vehículos verde (5 s) → vehículos amarillo (2 s) → vehículos rojo / peatones
verde (5 s) → peatones rojo (1 s) → vuelve a empezar.

- **Proyecto en Tinkercad:** https://www.tinkercad.com/things/ikZb2XAKF64/editel?sharecode=6LSkzyaRpbPplnNV0f1UI8aBN_LK_YJ9s7Tt9Q1qBKU
- **Código fuente:** [`ejercicio3_semaforo_carros_personas/semaforo_vehiculos_peatones.ino`](./ejercicio3_semaforo_carros_personas/semaforo_vehiculos_peatones.ino)

---

## Ejercicio 4: Semáforo con botón peatonal

El semáforo de vehículos permanece en verde hasta que un peatón presiona un
botón. Al presionarlo, se ejecuta la secuencia de cambio (aviso → amarillo →
rojo para vehículos, verde para peatones con cuenta regresiva en la pantalla
LCD) y luego vuelve al estado normal.

- **Proyecto en Tinkercad:** https://www.tinkercad.com/things/1ixYeGiYq99-simular-el-funcionamiento-con-boton-peatonal/editel?sharecode=wunYcHVP5fBI0KEQXn519iEl91OXKQhlu6ADRQro_kA
- **Código fuente:** [`ejercicio4_boton_peatonal/simular_boton_peatonal.ino`](./ejercicio4_boton_peatonal/simular_boton_peatonal.ino)
