<p align="left">
  <img src="https://upchvirtual.edu.pe/ued/images/logo-upch.png" width="200">

# _INFORME 05: Implementación del Internet de las Cosas (IoT)_

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
## 1. INTRODUCCIÓN

En la antigüedad los objetos  se comunicaban principalmente de manera manual y a través de sistemas más básicos con la finalidad de dar información de sus sensores. Desde el año 1999 el británico Kevin Ashton acuñó el término de Internet de las Cosas (Internet of Things (IoT)  mientras trabajaba para Procter & Gamble (P&G), este término hace referencia a la red de artefactos electrónicos de uso cotidiano (celulares, tablets, refrigeradoras, computadoras, etc.), los cuales se encuentren interconectados entre sí o con internet y gracias a ello en la actualidad estos  tienen la capacidad de interactuar entre ellos por medio del intercambio de información y tomando decisiones de acuerdo a la información recibida [1].

El internet de las cosas (IoT) toma gran importancia en la humanidad que vive un momento de transición para su desarrollo, es por ello que se considera como una de las tecnologías de mayor impacto a 2025 y se estima que millones de elementos físicos serán equipados con diferentes tipos de sensores conectados a la red en tiempo real, generando una gran cantidad de flujo de datos, los cuales deben ser almacenados y procesados de manera interpretable. Es aquí en donde la integración de IoT y Cloud Computing permiten el alojamiento de estos datos en internet [1]. 

En el presente informe se dará a conocer la implementación del Arduino Explore IoT Kit junto a la plataforma Arduino Cloud con la finalidad de comprender mejor el fundamento de IoT por medio de la Conversión del MKR IoT Carrier en un dispositivo agrícola urbano, usando los sensores del carrier y un sensor de humedad con el fin de analizar el ambiente para una planta, además usando luz artificial e introduciendo relés para activar dispositivos de alta potencia y centrándonos en configurar un panel de control en Arduino Cloud, donde podremos leer datos y controlar distintos componentes. También se mostrarán los resultados obtenidos de las diferentes actividades propuestas utilizando el microcontrolador ESP32, por ejemplo, lectura de un potenciómetro, uso de la Biblioteca WiFi.h y aplicaciones, Scanner WIFI  y mostrar en tiempo real la variación del potenciómetro conectado a las plataformas de IoT: Arduino Cloud, ThingSpeak y Ubidots.

## 2. METODOLOGÍA
El Arduino Explore IoT Kit es un conjunto educativo diseñado para aprender y crear proyectos de Internet de las Cosas (IoT) de manera sencilla y práctica. Incluye una variedad de sensores y componentes, como la placa Arduino MKR WiFi 1010 y el MKR IoT Carrier, que permiten la recolección, procesamiento y visualización de datos en tiempo real. El kit se integra con la plataforma Arduino Cloud, que facilita el control remoto de dispositivos conectados y la gestión de datos de manera eficiente. Esta herramienta resulta ideal para desarrollar aplicaciones IoT en áreas como sostenibilidad, automatización y conectividad.

1. Configuración Inicial del Hardware

Componentes utilizados:

- Arduino MKR WiFi 1010
- MKR IoT Carrier
- Sensor de humedad
- Otros sensores disponibles (temperatura, presión, luz, proximidad, etc.)
- Cables plug-and-play
- Cable micro USB

<p align="center"> <img src="https://github.com/user-attachments/assets/b13e9a4a-7c99-4f86-92f3-ba6c4e85888f">

1. Pasos:

a) Conectar la Placa: Coloca la placa Arduino MKR WiFi 1010 sobre el MKR IoT Carrier, asegurando que esté correctamente alineada con los pines del portador.

b) Conectar Sensores: Conecta el sensor de humedad (u otros sensores como temperatura o luz) a los puertos dedicados en el MKR IoT Carrier.

c) Conectar a la PC: Conecta el Arduino a tu computadora utilizando el cable micro USB.

2. Instalación y Configuración de Arduino Cloud
Crear una cuenta en Arduino Cloud: Dirígete al sitio web de Arduino Cloud y crea una cuenta, inicia sesión para comenzar a gestionar tus dispositivos IoT.
Instalar Arduino Create Agent: Descarga e instala Arduino Create Agent para que tu computadora reconozca los dispositivos Arduino conectados por USB.

3. Programación y Creación de Bocetos (Sketches)
Código Base:
Abre el IDE de Arduino o utiliza la plataforma en línea para crear un nuevo boceto.
Carga las librerías necesarias (Arduino_MKRIoTCarrier.h, thingProperties.h) para manejar los sensores y conectar la placa a Arduino Cloud.
Programa la lógica de control de los relés y la lectura de sensores.
Subir el código a la placa: Asegúrate de que el boceto funcione correctamente y sube el código a tu placa.

4. Integración de Dispositivos y Gestión en Arduino Cloud
Conectar Dispositivos: En Arduino Cloud, selecciona tu placa conectada y habilita la comunicación con la nube, verifica que el dispositivo esté correctamente configurado y conectado a internet.
Agregar Bocetos y Cosas: Crea nuevos bocetos o conecta "cosas" específicas a tu dispositivo (sensores o actuadores) para controlarlas desde la nube.
Panel de Control (Dashboard): Organiza un panel de control visual para monitorear en tiempo real los datos de los sensores y el estado de los relés.


## 3. RESULTADOS
### a) MKR WIFI 1010

<p align="center"> <img src="https://github.com/user-attachments/assets/7ae0bc0c-b35b-45e5-a3a3-19df7c4960a4" width="750">

#### Creación del DashBoard en Arduino Cloud
<p align="center"> <img src="https://github.com/user-attachments/assets/2d944c56-d834-403b-a038-52af72f1a2e9" width="750">

Como se puede visualizar, en el dashboard estarán todas las "things" que se crearon anteriormente. Desde el dashboard podemos controlar el apagado y encendido del RELAY, así como también la intensidad luminosa de los led. Además, permite observar en tiempo real datos tomados por los sensores de Temperatura, Humedad y Luz.

#### Código usado
```cpp
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <Arduino_MKRIoTCarrier.h>

// Instancia del MKR IoT Carrier
MKRIoTCarrier carrier;
int moistPin = A5;
String relayState1 = "";

void setup() {
  // Inicialización de la comunicación serial
  Serial.begin(9600);
  
  // Inicialización de las propiedades de Arduino Cloud
  initProperties();
  
  // Conexión a la nube de Arduino
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  // Inicialización del MKR IoT Carrier y sus sensores
  CARRIER_CASE = true;
  carrier.begin();
  
  // Inicializa los sensores ambientales
  if (!carrier.Env.begin()) {
    Serial.println("Error al inicializar los sensores ambientales.");
    while (true);  // Detiene el programa si falla la inicialización
  }
  
  // Depuración de la conexión a la nube
  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
  
  // Esperar la conexión
  while (ArduinoCloud.connected() != 1) {
    ArduinoCloud.update();
    carrier.display.setTextSize(3);
    carrier.display.setCursor(20, 70);
    carrier.display.println("Waiting For");
    carrier.display.setCursor(5, 110);
    carrier.display.println("Connection...");
    delay(500);
  }
}

void loop() {
  ArduinoCloud.update();  // Actualiza los datos en la nube
  
  // Control del relay
  if (relay_1 == true) {
    carrier.Relay1.open();
    relayState1 = "ON";
  } else {
    carrier.Relay1.close();
    relayState1 = "OFF";
  }
  
  // Lectura del sensor de luz
  if (carrier.Light.colorAvailable()) {
    int none;  // Variable no utilizada
    carrier.Light.readColor(none, none, none, light);
  }
  
  // Lectura de temperatura y humedad
  float temp = carrier.Env.readTemperature();
  float hum = carrier.Env.readHumidity();
  
  if (!isnan(temp) && !isnan(hum)) {
    temperature = temp;
    humidity = hum;
  } else {
    Serial.println("Error al leer temperatura o humedad.");
  }
  
  // Lectura de humedad del suelo
  int rawMoistValue = analogRead(moistPin);
  moistValue = map(rawMoistValue, 0, 1023, 100, 0);
  
  delay(1000);  // Espera antes de la siguiente actualización
}

// Función cuando cambia el valor del relay
void onRelay1Change() {
  // No es necesario hacer nada aquí, se maneja en el loop
}

// Función cuando cambia el color del RGB
void onRgbColorChange() {
  uint8_t r, g, b;
  rgbColor.getValue().getRGB(r, g, b);
  if (rgbColor.getSwitch()) {
    carrier.leds.fill(carrier.leds.Color(g, r, b), 0, 5);
    carrier.leds.show();
  } else {
    carrier.leds.fill(0, 0, 5);
    carrier.leds.show();
  }
}

// Función para actualizar la pantalla
void onUpdateDisplayChange() {
  // Actualiza la pantalla con los valores de los sensores
  carrier.display.fillScreen(ST77XX_WHITE);
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.setTextSize(2);

  carrier.display.setCursor(20, 30);
  carrier.display.print("Temp: ");
  carrier.display.print(temperature);
  carrier.display.print(" C");

  carrier.display.setCursor(20, 50);
  carrier.display.print("Humi: ");
  carrier.display.print(humidity);
  carrier.display.print(" %");

  carrier.display.setTextColor(ST77XX_ORANGE);
  carrier.display.setCursor(20, 70);
  carrier.display.print("Light: ");
  carrier.display.print(light);

  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setCursor(20, 90);
  carrier.display.print("Moist: ");
  carrier.display.print(moistValue);
  carrier.display.print(" %");

  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setCursor(20, 120);
  carrier.display.print("R1: ");
  carrier.display.print(relayState1);

  updateDisplay = false;  // Resetea la actualización de la pantalla
}

// Funciones de cambio para cada sensor (solo para depuración)
void onHumidityChange() {
  Serial.println("Humidity has changed.");
}

void onTemperatureChange() {
  Serial.println("Temperature has changed.");
}

void onLightChange() {
  Serial.println("Light has changed.");
}

void onMoistValueChange() {
  Serial.println("Moisture value has changed.");
}

```

#### Control de LED por RELAY

https://github.com/user-attachments/assets/576ab63a-2266-4e17-b7c9-2b66a4a22580

#### Control del rgbColor

https://github.com/user-attachments/assets/72f44836-87f3-47b3-9373-e4b92916a7ed

#### Sensor de Luz, Humedad y Temperatura

https://github.com/user-attachments/assets/99fc4148-266e-4313-aeb1-b4fa8562fce3

https://github.com/user-attachments/assets/17b21164-2fa2-49b5-b5d2-1610a7e190a2

### b) ESP32
#### Ejemplo 01: Lectura de un potenciómetro con ESP32
<p align="center"> <img src="https://github.com/user-attachments/assets/bf02e2ec-9cb2-4946-88f1-85c82e2b126e" width="700">

#### Ejemplo 02: Scanner WIFI con ESP32
<p align="center"> <img src="https://github.com/user-attachments/assets/5454fa51-adbb-4b1a-93f8-0fe041e62404" width="700">
<p align="center"> <img src="https://github.com/user-attachments/assets/f24fed69-4f96-4c52-9d64-35b04a77dbc8" width="700">

#### Ejemplo 03: Enviando datos a la nube
<p align="center"> <img src="https://github.com/user-attachments/assets/8c0b7b8d-8a30-4995-b7a5-9e9e60dacfac" width="700">
<p align="center"> <img src="https://github.com/user-attachments/assets/ae209a1e-54a8-4fa6-a998-b77e6230fc4f" width="700">
<p align="center"> <img src="https://github.com/user-attachments/assets/6953b624-e970-4d72-8de4-9e0cfe5762f5" width="700">


## 4. DISCUSIÓN DE RESULTADOS
### 4.1 KIT IoT EXPLORE
En esta práctica, implementamos un sistema con el Arduino MKR IoT Carrier y varios sensores, explorando cómo el Internet de las Cosas (IoT) puede ser aplicado en diferentes áreas tecnológicas. A lo largo del taller, trabajamos con un sensor de humedad y un relé para controlar un LED, gestionando la recolección de datos y el control remoto a través de Arduino Cloud. Esta experiencia nos permitió comprender cómo la tecnología IoT puede optimizar procesos en campos como la automatización del hogar, el monitoreo ambiental, la gestión de infraestructuras, y la industria manufacturera. Al conectar los dispositivos a la nube, pudimos visualizar los datos en tiempo real y tomar decisiones basadas en esa información, demostrando cómo la IoT facilita la integración de sensores y actuadores en sistemas inteligentes​.

Lo que más nos llamó la atención fue la combinación de hardware y software para controlar dispositivos de manera eficiente. Aunque utilizamos el relé únicamente para encender un LED, esto me permitió entender su potencial en aplicaciones más complejas, como el control de iluminación o ventilación en casas inteligentes o industrias. La posibilidad de monitorear el entorno y automatizar respuestas ante cambios en los datos —como encender el LED cuando ciertos valores cambian— nos mostró cómo la IoT puede crear sistemas autónomos que optimizan las decisiones. Esta práctica no solo cumplió con los objetivos de aprendizaje, sino que también nos demostró el impacto que la IoT puede tener en diversas industrias, mejorando la eficiencia y la toma de decisiones en tiempo real​.

### 4.2 ESP32 

Los resultados obtenidos con el ESP32 demostraron su capacidad eficiente para conectarse a redes WiFi y transmitir datos en tiempo real a plataformas IoT en la nube. El dispositivo mostró una rápida conexión a la red, permitiendo la transmisión fluida de datos mediante protocolos ligeros como MQTT. La conexión a plataformas facilitó el almacenamiento y análisis de datos, destacando su utilidad en el monitoreo continuo y control remoto. La escalabilidad y las capacidades de automatización fueron puntos fuertes, mejorando la gestión de grandes volúmenes de información. Sin embargo, el rendimiento dependió de la calidad de la señal WiFi, lo que puede ser un factor limitante en entornos con conectividad inestable. En general, la capacidad del ESP32 para integrarse de manera eficiente en soluciones IoT y enviar datos en tiempo real representa un avance significativo para diversas aplicaciones industriales, ambientales y domésticas

## 5. CONCLUSIONES

En conclusión, el acelerado crecimiento del Internet de las Cosas (IoT) nos sitúa en una encrucijada donde la integración de lo físico y lo digital redefine sectores estratégicos como la agricultura urbana. En el presente laboratorio, la implementación del Arduino Explore IoT Kit y la plataforma Arduino Cloud permitió crear un sistema inteligente que, mediante sensores y actuadores, observamos que los relés y LEDs respondieron adecuadamente a los comandos enviados desde la nube, reflejando los estados deseados en tiempo real, logrando controlar. variables esenciales como la humedad y la iluminación, mejorando el rendimiento agrícola de manera precisa y en tiempo real desde cualquier lugar. Además, la incorporación del microcontrolador ESP32 junto a plataformas como ThingSpeak y Ubidots subraya la capacidad del IoT para gestionar eficientemente recursos a través de una conexión remota y automatizada. Este trabajo no solo cumplió con los objetivos propuestos, sino que reveló el poder transformador del IoT en la creación de soluciones sostenibles, eficientes y escalables. 

## 6. BIBLIOGRAFÍA
* Revista Ingeniería. [citado el 25 de septiembre de 2024]; Disponible en: https://revistas.udistrital.edu.co/index.php/REDES/article/view/8505/10464

