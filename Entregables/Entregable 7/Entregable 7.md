<p align="left">
  <img src="https://upchvirtual.edu.pe/ued/images/logo-upch.png" width="200">

# _INFORME 07: Esquema Electrónico y PCB_

## Docentes:👨‍🏫
- Mg Umbert Lewis De La Cruz
- Mg. Paulo Camilo Vela Antón
- Mg. Moises Stevend Meza Rodriguez
- Dr. Harry Anderson Rivera Tito
- Ing. Juan Manuel Zuñiga Mamani
- Ing. Renzo José Chan Ríos
## Integrantes📊
- Flores Huaman, Meyli 
- Huarca Astete, Iory Estefani
- Mendoza Canaza, Marco Antonio
- Orosco Taype, Mayerly Nicole
- Villarreal Zapata, Liz 

## 1. Componentes Electrónicos Empleados
<table>
  <tr>
    <th width="50%"><img src="https://github.com/user-attachments/assets/4d382980-4555-4c73-9bdf-3d0320352a79" width="280" height="280"> <br> ESP32-WROOM-W2D </th>
    <th width="50%" align="justify"> 
      <b>Descripción:</b> Microcontrolador con conectividad WiFi y Bluetooth, ideal para proyectos IoT.<br><br>
      <b>Características importantes:</b>
      <ul>
        <li>Procesador dual-core Xtensa de 32 bits a 240 MHz.</li>
        <li>Memoria: 520 KB de RAM y 4 MB de flash.</li>
        <li>Conectividad: WiFi 802.11 b/g/n y Bluetooth v4.2.</li>
      </ul>
      <b>Contribución al proyecto:</b> El ESP32 será el cerebro del sistema, recolectando los datos de los sensores y transmitiéndolos en tiempo real a una base de datos a través de WiFi. Su capacidad para manejar múltiples conexiones y procesar datos en tiempo real es crucial para asegurar que las alertas sean rápidas y precisas.
    </th>
  </tr>
</table>

<table>
  <tr>
    <th width="50%"><img src="https://github.com/user-attachments/assets/dc6a8a06-5e19-4b9e-b778-d7e51096c5b7" width="280" height="280"> <br> DHT22 (Sensor de Temperatura y Humedad) </th>
    <th width="50%" align="justify"> 
      <b>Descripción:</b> Sensor digital que mide temperatura y humedad del ambiente.<br><br>
      <b>Características importantes:</b>
      <ul>
        <li>Rango de temperatura: -40°C a +80°C.</li>
        <li>Precisión: ±0.5°C (temperatura), ±2-5% (humedad)</li>
        <li>Comunicación: Protocolo digital de una sola línea.</li>
      </ul>
      <b>Contribución al proyecto:</b> El DHT22 monitoreará las condiciones ambientales alrededor del lago. Un aumento de la temperatura podría correlacionarse con la aceleración de la deglaciación, y el monitoreo de la humedad proporciona datos para interpretar el ambiente local.
    </th>
  </tr>
</table>

<table>
  <tr>
    <th width="50%"><img src="https://github.com/user-attachments/assets/3f2e861f-82e8-4185-85f7-46b0cb70eba4" width="280" height="280"> <br> Módulo GPS NEO-6M </th>
    <th width="50%" align="justify"> 
      <b>Descripción:</b> Receptor GPS que proporciona coordenadas de localización y velocidad.<br><br>
      <b>Características importantes:</b>
      <ul>
        <li>Precisión de posición: ~2.5 metros.</li>
        <li>Sensibilidad: -161 dBm</li>
        <li>Soporte para hasta 22 satélites simultáneos.</li>
      </ul>
      <b>Contribución al proyecto:</b> Este módulo permitirá obtener la localización precisa del sistema de monitoreo. Podrás asociar las lecturas de los sensores con la ubicación exacta, asegurando que las alertas provengan del área monitoreada del lago.
    </th>
  </tr>
</table>

<table>
  <tr>
    <th width="50%"><img src="https://github.com/user-attachments/assets/d9b95893-d1ff-4658-bb25-2f756f9ba7d4" width="280" height="280"> <br> MS5611 (Sensor de Presión Barométrica y Altitud)</th>
    <th width="50%" align="justify"> 
      <b>Descripción:</b> Sensor de alta precisión para medir presión atmosférica y altitud.<br><br>
      <b>Características importantes:</b>
      <ul>
        <li>Rango de presión: 10 a 1200 mbar</li>
        <li>Precisión: ±1 mbar (equivalente a 8.3 metros de altitud)</li>
        <li>Interfaz: I2C o SPI.</li>
      </ul>
      <b>Contribución al proyecto:</b> Este sensor se usará para medir cambios en la presión atmosférica que pueden correlacionarse con cambios en el nivel del agua. Detectar variaciones en la altitud del sistema por cambios de presión atmosférica es clave para monitorear posibles riesgos de inundación.
    </th>
  </tr>
</table>

<table>
  <tr>
    <th width="50%"><img src="https://github.com/user-attachments/assets/263ef56e-f01d-41fb-8009-4b7c7f6f0e80" width="280" height="280"> <br> ML8511 (Sensor de Radiación UV)</th>
    <th width="50%" align="justify"> 
      <b>Descripción:</b> Sensor que mide la cantidad de radiación ultravioleta (UV) en el entorno.
<br><br>
      <b>Características importantes:</b>
      <ul>
        <li>Rango de detección: 280 a 390 nm (UV-A y UV-B)</li>
        <li>Sensibilidad de voltaje de salida proporcional a la intensidad UV.</li>
      </ul>
      <b>Contribución al proyecto:</b> La radiación solar puede influir en el derretimiento de los glaciares. Al monitorear los niveles de radiación UV, puedes establecer relaciones entre la intensidad solar y el aumento del nivel del agua debido a la deglaciación.
    </th>
  </tr>
</table>
<br>

### Conexión del sistema

El ESP32 será el encargado de gestionar los datos de los sensores y subirlos a una base de datos en la nube. Esto permitirá que se monitoree en tiempo real el nivel de riesgo de inundaciones, y se pueda alertar a la población a través de una aplicación móvil basada en estos datos.

Este conjunto de sensores te permitirá monitorear el ambiente y las condiciones climáticas alrededor del lago, detectando cambios importantes que puedan conducir a una inundación debido a la deglaciación.<br><br>

## 2. Esquema Electrónico 
<img src=https://github.com/user-attachments/assets/9dc05ada-ac60-4168-ad7c-90735305fa30>

### a. ESP32-DEVKITC
- El **ESP32** es el microcontrolador central del sistema, al cual están conectados los demás sensores.
- La alimentación del ESP32 se realiza mediante un pin de **+3V3** (3.3V) y **GND**.
- También hay una entrada de **5V** conectada al pin **19** para la alimentación del ESP32.

### b. Sensor ML8511 (Sensor de Radiación UV)
- Conectado a **CN3**.
- Alimentación a través de **+3V3** (pin 1 y 3) y **GND**.
- La señal de salida **OUT** (pin 4) se conecta al ESP32, pero no se especifica un pin exacto del ESP32 en este esquema.

### c. Sensor DHT22 (Sensor de Temperatura y Humedad)
- Conectado a **CN2**.
- Alimentación a través de **+3V3** (pin 1) y **GND** (pin 3).
- La salida de datos **OUT** (pin 2) se conecta al ESP32 a través de una resistencia de **10kΩ** (R1) como pull-up, conectada a **+3V3**.

### d. MS5611 (Sensor de Presión Barométrica y Altitud)
- Conectado en el conector **H1**.
- Alimentación a través de **+3V3** (pin 1 y 7) y **GND** (pin 4).
- Comunicación mediante el bus **I2C**: 
  - **SCL** (pin 6) y **SDA** (pin 3), conectados a los pines correspondientes del ESP32 (SCL/SDA).

### e. Módulo GPS NEO-6M
- Conectado a **JP1**.
- Alimentado con **+5V** (pin 1) y **GND** (pin 2).
- Comunicación mediante los pines **TX** y **RX**, que se conectan al ESP32:
  - **TX** (pin 3) a **RX0** del ESP32.
  - **RX** (pin 4) a **TX0** del ESP32.

### f. Fuente de alimentación
- El esquema incluye una fuente de **5V** conectada a través de **P1**, que alimenta tanto al ESP32 como al GPS y otros componentes que necesitan 5V.

## 3. PCB
<img src=https://github.com/user-attachments/assets/ec506ef1-4fe8-4dbd-986e-6a1853e12fa9>
<img src=https://github.com/user-attachments/assets/54e03034-1b9d-464b-8a3c-2572ecdd16ac>
<br><br>
El diseño del PCB integra los componentes claves del proyecto, enfocándose en un sistema de sensores que pueden monitorear variables ambientales críticas como temperatura, humedad, presión atmosférica, radiación UV, y localización GPS. El ESP32 actúa como el cerebro del sistema, recopilando y transmitiendo estos datos a una base de datos a través de WiFi. El diseño del circuito está claramente organizado y es adecuado para su montaje en un sistema o caja protectora, lo que asegura la durabilidad en un entorno de campo.

