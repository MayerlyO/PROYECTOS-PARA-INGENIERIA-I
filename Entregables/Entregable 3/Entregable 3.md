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
    <th width="50%"><img src="https://github.com/MayerlyO/PROYECTOS-PARA-INGENIERIA-I/blob/main/Entregables/Entregable%203/Im%C3%A1genes/arduino_nano_33_ble.jpg" width="280" height="280"> <br> Arduino NANO 33 BLE Sense [Fotografía]. (s.f.)</th>
    <th width="50%" align="justify" >El Arduino Nano 33 BLE es una placa compacta y potente ideal para proyectos de Internet de las Cosas (IoT). Con un microcontrolador y conectividad Bluetooth, lo que permite una comunicación eficiente. Este incluye sensores como un acelerómetro y un giroscopio. Su fácil programación en el entorno de Arduino lo hace accesible. En este caso lo emplearemos para reconocimiento de señales y recibiremos una interacción luminosa.</th>
  </tr>
</table><br>

- Serie de tiempo: Como se observa en la sigueinte imagen, los datos de la serie de tiempo capturados incluyen 9 ejes de datos (accX, accY, accZ, gyrX, gyrY, gyrZ, magX, magY, magZ), que miden diferentes aspectos del movimiento y la orientación del dispositivo.De igual modo se puede observar una sección  donde se logró definir el tamaño de ventana de 3010 ms con un incremento de ventana de 200 ms. Esto significa que los datos se recogen en intervalos de 3 segundos con una frecuencia de muestreo de 100 Hz.
<p align="center">
  <img src="https://github.com/MayerlyO/PROYECTOS-PARA-INGENIERIA-I/blob/main/Entregables/Entregable%203/Im%C3%A1genes/E3_1.jpg"width="750"> <br><br>
  
#### 2.2  Comportamiento espectral (Procesamiento de datos):
El análisis espectral nos permitió extraer características útiles de los datos en bruto. Al marcar todas las entradas disponibles, utilizando información tanto del acelerómetro como del giroscopio y el magnetómetro. Estos datos transformados en características espectrales ayudan a que el modelo capture patrones repetitivos en los gestos para luego emitir un color de acuerdo al gesto realizado.
<p align="center">
  <img src="https://github.com/MayerlyO/PROYECTOS-PARA-INGENIERIA-I/blob/main/Entregables/Entregable%203/Im%C3%A1genes/E3_2.jpg"width="750"> <br><br>

#### 2.3 Clasificación de gestos:
- El modelo tiene tres salidas: un círculo ("O"), el número 3 y el número 1. Este clasificador utiliza las características espectrales de las señales para identificar qué gesto se está realizando y emitir un color.
- Como muestra la segunda imagen, la división de datos entre entrenamiento y prueba es del 80% para entrenar el modelo y el 20% para evaluarlo, asegurando que el modelo tenga datos suficientes para aprender sin sobre ajustarse.
<p align="center">
  <img src="https://github.com/MayerlyO/PROYECTOS-PARA-INGENIERIA-I/blob/main/Entregables/Entregable%203/Im%C3%A1genes/E3_3.jpg"width="750"> <br><br>

#### 2.4 Entrenamiento y pruebas:
- En el segundo conjunto de imágenes, se puede ver cómo se etiquetaron y organizaron los datos para entrenamiento y prueba. Cada gesto capturado (círculo, 1, 3) está representado por muestras etiquetadas (como el ejemplo "1.57bq53rd") que contienen las series de datos de los sensores. 
- Las series de tiempo capturadas se muestran gráficamente para cada una de las etiquetas, lo que permite visualizar los patrones de movimiento característicos de cada gesto. <br><br>

#### 2.5 Implementación en Arduino (TinyML):
- Una vez que el modelo ha sido entrenado y validado, se exporta el modelo optimizado para que se ejecute en el Arduino Nano 33 BLE Sense. Este paso implica compilar el modelo para un entorno TinyML y cargar el código resultante en el microcontrolador.
<p align="center">
  <img src="https://github.com/MayerlyO/PROYECTOS-PARA-INGENIERIA-I/blob/main/Entregables/Entregable%203/Im%C3%A1genes/E3_4.jpg"width="450"> <br><br>

### 3. Resultados:
Pasamos a probar el modelo realizado en Edge Impulse para comprobar si este predice correctamente las figuras que estamos dibujando con el ARDUINO NANO 33 BLE SENSE. <br><br>
#### 3.1 Video prueba del TRES



### 4. Discusión:
En la actualidad, la inteligencia artificial se puede encontrar cada vez en un mayor número de dispositivos sin que los usuarios sean conscientes de ello, un ejemplo es el uso de una palabra o gesto para activar un dispositivo y ejecutar acciones más complejas, puesto que el aprendizaje automático ha revolucionado nuestra forma de interactuar con la tecnología, especialmente en el ámbito de los dispositivos embebidos [2]. En este reto, trabajamos con el Arduino Nano 33 BLE Sense, experimentamos de primera mano cómo esta placa puede ejecutar modelos de inteligencia artificial para reconocer comandos de gestos. Sin embargo, no todo fue un camino fácil. La recolección y preparación de datos fue un desafío significativo; tuvimos que asegurarnos de que los datos fueran representativos y bien etiquetados, lo que requirió mucho tiempo y esfuerzo en equipo. 
<br><br>
Resulta importante destacar un estudio realizado por Viswanatha V,  Ramachandra AC y otros investigadores en el año 2022, que se enfoca en el reconocimiento de gestos, puesto que nos proporciona un enfoque innovador de la comunicación no verbal ya que tiene amplias aplicaciones en la interacción hombre-máquina y en el lenguaje de señas, en la implementación del reconocimiento de gestos de la mano, el modelo Tiny ML se entrena y se implementa desde el marco Edge Impulse para el reconocimiento de gestos de la mano y, en función de los movimientos de la mano, el dispositivo Arduino Nano 33 BLE con IMU de 6 ejes puede averiguar la dirección del movimiento de la mano la integración de retroalimentación visual, como el uso de LEDs para indicar acciones, las cuales se puede poner en práctica en los diversos contextos o en la solucion de problematicas de nuestro país [3]. 
<br><br>
Esta experiencia enriqueció nuestra interacción con el Arduino, ya que ver cómo el dispositivo respondía a nuestros comandos, a pesar de algunas limitaciones, fue gratificante. Esta retroalimentación positiva nos inspiró a ajustar nuestro enfoque y a explorar nuevas técnicas, fortaleciendo nuestro compromiso con el aprendizaje y la innovación.<br><br>

### 5. Conclusión:
En conclusión, nuestra experiencia con el Arduino Nano 33 BLE Sense y el aprendizaje automático ha sido un viaje lleno de desafíos y aprendizajes significativos. La integración de retroalimentación visual no solo mejoró la interacción, sino que también nos motivó a seguir refinando nuestro enfoque. Estas experiencias nos han enseñado la importancia del trabajo en equipo, la adaptabilidad y la perseverancia. Con estas lecciones en mente, nos sentimos más preparados para enfrentar futuros retos y continuar explorando las posibilidades del aprendizaje automático en dispositivos embebidos, con la confianza de que cada obstáculo superado nos acerca más a nuestras metas.<br><br>

### 6. Bibliografía:
1. Capogrosso, L., Cunico, F., Cheng, DS, Fummi, F. y Cristani, M. (2024). Una encuesta orientada al aprendizaje automático sobre el aprendizaje automático en miniatura. IEEE Access . 
2. Cebollo, R. A., & del Brío, B. M. Reconocimiento de gestos y voz mediante inteligencia artificial incorporada en un microcontrolador.
3. Prasanna, R., Kakarla, P. C., PJ, V. S., & Mohan, N. (2022). Implementation of tiny machine learning models on arduino 33 ble for gesture and speech recognition. arXiv preprint arXiv:2207.12866.
4. B. V. Nived, K. Jamal, G. Mahesh and R. M. Kumar, "Design of Custom Keyword Recognition using Edge Impulse on Arduino Nano 33 BLE Sense," 2023 2nd International Conference on Applied Artificial Intelligence and Computing (ICAAIC), Salem, India, 2023, pp. 1522-1529, doi: 10.1109/ICAAIC56838.2023.10140757. keywords: {Microcontrollers;Neural networks;Random access memory;Speech recognition;Feature extraction;Hardware;Data models;Voice Recognition;Sampling and Framing;MFCC;Classification;Neural Networks;Edge Impulse},

