<p align="left">
  <img src="https://upchvirtual.edu.pe/ued/images/logo-upch.png" width="200">

# _INFORME 03: Tiny Machine Learning con Edge Impulse📑_

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

### 1. Introducción:
El aprendizaje automático (ML) ha tenido un impacto significativo en varios campos, incluidos la visión, el lenguaje y el audio, puesto que permite ejecutar modelos avanzados de inteligencia artificial en dispositivos embebidos y de bajo consumo energético [1]. Con Edge Impulse, una plataforma que facilita la creación y despliegue de estos modelos, podemos entrenar sistemas para realizar tareas complejas, integrándose en el hardware más simple.
En el presente proyecto, utilizaremos un Arduino Nano 33 BLE Sense para identificar comandos de gestos. Aprovechando los algoritmos optimizados por Edge Impulse, donde podremos capturar y procesar gestos en tiempo real, ejecutando acciones con 2 movimientos . Este pequeño dispositivo será capaz de comprender el entorno y reaccionar de manera inteligente, todo gracias a la potencia de TinyML y la flexibilidad de Edge Impulse [4].<br>

La integración de este modelo en el Arduino Nano 33 BLE Sense se basa en tres condiciones específicas:

- **LED Rojo:** Se enciende al dibujar un círculo.
- **LED Azul:** Se activa al representar el número 3.
- **LED Verde:** Se ilumina al trazar el número 1.

Cada una de estas acciones desencadena una respuesta luminosa en el dispositivo, creando una interacción única y visualmente atractiva.
A lo largo de este informe se detallarán los procedimientos de desarrollo, desde la recolección de datos hasta la implementación del modelo en el hardware, así como los resultados obtenidos y las conclusiones alcanzadas. 



### 2. Metodología:
En este apartado, explicaremos a detalle el proceso que seguimos para cumplir con el reto planteado. 

#### 2.1 Obtención y preparación de los datos:
- Dispositivos usados: Se utilizó un Arduino Nano 33 BLE Sense, que tiene sensores como el acelerómetro (acc), el giroscopio (gyr) y el magnetómetro (mag), para capturar los movimientos que se asocian a los gestos de dibujo (círculo, número 1 y  número 3).
<table>
  <tr>
    <th width="50%"><img src="" width="340" height="500"></th>
    <th width="50%" align="justify" >El Arduino Nano 33 BLE es una placa compacta y potente ideal para proyectos de Internet de las Cosas (IoT). Con un microcontrolador y conectividad Bluetooth, lo que permite una comunicación eficiente. Este incluye sensores como un acelerómetro y un giroscopio. Su fácil programación en el entorno de Arduino lo hace accesible. En este caso lo emplearemos para reconocimiento de señales y recibiremos una interacción luminosa.</th>
  </tr>
</table>


### 3. Ejecución del modelo:
### 3. Resultados:
### 4. Discusión:
### 5. Bibliografía:
1. Capogrosso, L., Cunico, F., Cheng, DS, Fummi, F. y Cristani, M. (2024). Una encuesta orientada al aprendizaje automático sobre el aprendizaje automático en miniatura. IEEE Access . 
2. Cebollo, R. A., & del Brío, B. M. Reconocimiento de gestos y voz mediante inteligencia artificial incorporada en un microcontrolador.
3. Prasanna, R., Kakarla, P. C., PJ, V. S., & Mohan, N. (2022). Implementation of tiny machine learning models on arduino 33 ble for gesture and speech recognition. arXiv preprint arXiv:2207.12866.
4. B. V. Nived, K. Jamal, G. Mahesh and R. M. Kumar, "Design of Custom Keyword Recognition using Edge Impulse on Arduino Nano 33 BLE Sense," 2023 2nd International Conference on Applied Artificial Intelligence and Computing (ICAAIC), Salem, India, 2023, pp. 1522-1529, doi: 10.1109/ICAAIC56838.2023.10140757. keywords: {Microcontrollers;Neural networks;Random access memory;Speech recognition;Feature extraction;Hardware;Data models;Voice Recognition;Sampling and Framing;MFCC;Classification;Neural Networks;Edge Impulse},

