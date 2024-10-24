<p align="left">
  <img src="https://upchvirtual.edu.pe/ued/images/logo-upch.png" width="200">

# _INFORME 08: TRL 1 PRINCIPIOS BÁSICOS DE LOS SENSORES EN LA IMPLEMENTACION DEL PROYECTO._          
En un mundo interconectado, los sensores son herramientas esenciales para el monitoreo y la recopilación de datos en tiempo real. En el contexto de nuestro proyecto, que se centra en los principios básicos de los sensores en la implementación del monitoreo, estos dispositivos permiten medir parámetros críticos, desde la temperatura hasta la calidad del aire. Esto no solo facilita la toma de decisiones informadas, sino que también potencia soluciones innovadoras en áreas como la agricultura y la salud. Este informe explorará los fundamentos de los sensores (TRL 1) y su relevancia en nuestro proyecto, destacando su capacidad para transformar industrias y mejorar la calidad de vida.


## 1. DHT22: Sensor de Temperatura y Humedad

| DHT22: Sensor de Temperatura y Humedad                                                                                       | ![SENSOR DE T Y H](https://github.com/user-attachments/assets/f85e4d5f-ea92-43c5-acd4-f56f5bd310de)                                                                                         |
|-------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| El **DHT22** permite monitorear temperatura y humedad relativa de forma precisa y sencilla a un bajo precio. La salida suministrada es de tipo digital, no requiriéndose utilizar entradas analógicas. |                                                                                                                               |

### Funcionamiento del DHT22

1. **Medición de Humedad**:
   - Utiliza un sensor capacitivo que contiene dos placas conductoras separadas por un material dieléctrico que absorbe humedad. 
   - La capacitancia cambia con la cantidad de vapor de agua en el aire. Esta variación es medida por un microcontrolador interno, que convierte la capacitancia en un valor digital de humedad relativa (%).

2. **Medición de Temperatura**:
   - Emplea un termistor, cuyo valor de resistencia varía con la temperatura. 
   - El microcontrolador interno mide esta resistencia y la convierte en un valor digital de temperatura en grados Celsius (°C) o Fahrenheit (°F).

3. **Comunicación de Datos**:
   - El DHT22 transmite los datos de temperatura y humedad a través de un solo pin digital. 
   - Al iniciar la comunicación, el sensor envía un pulso de inicio, seguido de los datos en un formato digital que el microcontrolador receptor (como Arduino) puede interpretar.

### Características Principales

- **Voltaje de Operación**: 3V - 6V DC
- **Rango de medición de temperatura**: -40°C a 80 °C
- **Precisión de medición de temperatura**: <±0.5 °C
- **Resolución Temperatura**: 0.1°C
- **Rango de medición de humedad**: De 0 a 100% RH
- **Precisión de medición de humedad**: ± 2% RH
- **Resolución Humedad**: 0.1% RH
- **Tiempo de sensado**: 2s
- **Interfaz digital**: Single-bus (bidireccional)
- **Modelo**: AM2302
- **Dimensiones**: 20 × 15 × 8 mm
- **Peso**: 3 g
- **Carcasa**: Plástico blanco

### Aplicación en la Laguna Palcacocha

Al implementar un sistema de monitoreo basado en sensores de temperatura y humedad, puedes anticipar y mitigar el riesgo de desbordamiento de la laguna Palcacocha, protegiendo así a la comunidad y sus bienes. La clave está en la integración de datos, el análisis continuo y la comunicación efectiva.

---

## 2. MS5611: Sensor de Presión Barométrica y Altitud

| **MS5611: Sensor de Presión Barométrica y Altitud**                                                                                       | ![Sensor MS5611](https://github.com/user-attachments/assets/8180267e-f3c2-48dc-ad33-045c09405c13)                          |
|-------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| El **MS5611** se basa en la relación entre la presión atmosférica y la altitud, permitiendo convertir la presión en una medida útil para determinar la altura sobre el nivel del mar. |                                                                                                                               |


### Funcionamiento del Sensor MS5611

El MS5611 es un sensor piezoeléctrico que mide la presión utilizando un elemento capacitivo de alta precisión. Los pasos de su funcionamiento básico son los siguientes:

1. **Captación de la Presión**:
   - El sensor tiene una membrana flexible en su interior que se deforma ligeramente bajo la presión atmosférica. Esta deformación genera una señal eléctrica que puede medirse. Cuanto mayor es la presión, mayor es la deformación.

2. **Conversión Digital**:
   - La deformación de la membrana se traduce en una señal de voltaje, la cual es procesada por un ADC (convertidor analógico-digital) incorporado en el sensor. El resultado es un valor digital que corresponde a la presión medida.

3. **Cálculo de la Altitud**:
   - A partir de la presión medida, es posible calcular la altitud utilizando la ecuación barométrica. El sensor compara la presión medida con la presión de referencia al nivel del mar, utilizando esta diferencia para calcular la altitud. En la práctica, las bibliotecas de software que acompañan al sensor hacen esta conversión automáticamente.

### Especificaciones

- **Módulo**: GY-63
- **Chip**: MS5611
- **Voltaje de operación**: 3.3V - 5V DC
- **Interfaz de comunicación digital**: I2C o SPI
- **ADC interno de 24 bits**: Puede tomar 4096 mediciones analógicas de 24 bits en solo 8 ms y proporcionar el promedio de los puntos de datos al bus de datos digital.
- **Rango de medición de presión**: 10 a 1200 mBar
- **Resolución de presión**: 0.012 mbar (configurable por software)
- **Conversión rápida**: 1 ms
- **Ultra-bajo consumo de energía**: 1 µA (en espera <0.15 µA)

### Aplicación en la Laguna Palcacocha

En nuestro proyecto de la Laguna Palcacocha, el sensor MS5611 se usará para medir los cambios en la presión barométrica que ocurren naturalmente debido a la altitud y las condiciones meteorológicas. Estos cambios pueden proporcionar información valiosa sobre el entorno de la laguna, relacionados con otros factores, como la temperatura del agua y los niveles de radiación.

---

## 3. ML8511: Sensor de Radiación UV

| **ML8511: Sensor de Luz Ultravioleta**                                                                                       | ![Sensor ML8511](https://github.com/user-attachments/assets/836bd338-6148-438c-9150-23268aa9aaac)                          |
|-------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| El **ML8511** es un sensor de luz ultravioleta fácil de usar, diseñado para medir la intensidad de la radiación UV. Este sensor es especialmente útil para crear dispositivos que advierten a los usuarios sobre el riesgo de quemaduras solares o que miden el índice UV en relación con las condiciones climáticas. |                                                                                                                               |


### Funcionamiento

El ML8511 funciona emitiendo una señal analógica proporcional a la cantidad de luz ultravioleta que detecta. El rango de luz más efectivo que mide se encuentra entre **280-390 nm**, que abarca parte del espectro UVB (rayos ardientes) y la mayor parte del espectro UVA (rayos bronceadores). La salida de tensión del sensor está relacionada linealmente con la intensidad de la radiación UV medida en mW/cm².

### Características Principales

- **Voltaje de Operación**: 5V DC
- **Salida Analógica**: Proporciona una señal analógica que puede ser leída por un microcontrolador.
- **Longitud de Onda**: 280-390 nm
- **Consumo de Energía**: Muy bajo, lo que lo hace ideal para dispositivos portátiles.
- **Facilidad de Integración**: La salida de voltaje se puede conectar directamente al convertidor analógico/digital (A/D) de un microcontrolador, eliminando la necesidad de circuitos de conversión fotoeléctrica adicionales.


**:seedling: SINTESIS DE INFORMACIÓN:**

| DHT22: Sensor de Temperatura y Humedad           | MS5611: Sensor de Presión Barométrica y Altitud | ML8511: Sensor de Radiación UV                     |
|--------------------------------------------------|--------------------------------------------------|---------------------------------------------------|
| Bajo costo                                       | Alta precisión en mediciones de presión y altitud | Detección de radiación UV en tiempo real          |
| Fácil de usar y conectar                         | Consumo de energía muy bajo                       | Salida analógica que permite fácil lectura         |
| Medición precisa de temperatura y humedad        | Interfaz digital (I2C/SPI) para fácil integración | Útil para aplicaciones de salud y seguridad        |
| Salida digital simple para microcontroladores    | Ideal para aplicaciones meteorológicas            | Compacto y fácil de integrar en sistemas portátiles|
| Amplio rango de medición                         | Compacto y ligero                                 | Bajo consumo de energía                            |




**:seedling: FUENTES BIBLIOGRÁFICAS:**

Sensor Altitud Presion Barometrica y Temperatura GY-63 MS5611 I2C. (s/f). Robot Electronica. Recuperado el 24 de octubre de 2024, de https://robot.com.ve/product/sensor-altitud-presion-barometrica-y-temperatura-gy-63-ms5611-i2c/

Adafruit. (n.d.). DHT22 (AM2302) temperature-humidity sensor. https://learn.adafruit.com/dht/overview

SparkFun. (n.d.). DHT22 (AM2302) temperature and humidity sensor. https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf

MEAS. (n.d.). MS5611-01BA03 - High resolution barometric pressure sensor. https://www.meas-spec.com/documents/MS5611-01BA03.pdf

SparkFun. (n.d.). MS5611 - Barometric pressure sensor. https://learn.sparkfun.com/tutorials/ms5611-barometric-pressure-sensor-hookup-guide

SparkFun. (n.d.). ML8511 UV sensor. https://www.sparkfun.com/datasheets/Sensors/ML8511.pdf

Adafruit. (n.d.). ML8511 - UV light sensor. https://learn.adafruit.com/ml8511-uv-light-sensor/overview

Sensor de presión MS5611 - Altímetro Barómetro. (s. f.). Naylamp Mechatronics - Perú. https://naylampmechatronics.com/sensores-posicion-inerciales-gps/731-sensor-de-presion-ms5611-altimetro-barometro.html
