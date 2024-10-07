<p align="left">
  <img src="https://upchvirtual.edu.pe/ued/images/logo-upch.png" width="200">

# _INFORME 05: VDI Módulo Mecánico_

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
Muchos proyectos de ingeniería suelen estar compuestos por distintos tipos de módulos que se agrupan según la función específica que cumplen dentro del sistema general, por ejemplo, módulos mecánicos, eléctricos, electrónicos, térmicos, etc. El diseño mecánico o también denominado diseño de ingeniería, es el proceso de diseñar componentes, piezas, productos y sistemas que son inherentemente de naturaleza mecánica [1]; dentro de estos componentes es importante tener en cuenta los esfuerzos mecánicos (tracción, compresión, flexión, torsión y cortante) que actúan sobre una pieza u objeto para evitar o disminuir las fallas mecánicas que se podrían presentar.<br>

Existen plataformas en línea que permiten simular y realizar análisis detallados de diferentes tipos de fenómenos físicos y mecánicos para optimizar el diseño y desempeño de productos, estructuras y sistemas. Uno de estas plataformas es SimScale la cual ofrece una gama de herramientas y capacidades en un entorno basado en la nube que integra a la perfección todo lo necesario para un flujo de trabajo de simulación de ingeniería de extremo a extremo y permite acceder a las simulaciones desde cualquier dispositivo con conexión a internet convirtiéndola en una opción técnica y económicamente viable para cualquier organización [2].

## 2. METODOLOGÍA
![Q Y F (2)](https://github.com/user-attachments/assets/4aa2d08a-3f00-4670-89d4-549609f204c4)


## 3. RESULTADOS
### 3.1 Asignación de valores:  peso del case general parte delantera y  fuerza del viento
![WhatsApp Image 2024-10-06 at 23 08 08](https://github.com/user-attachments/assets/bec06427-8655-4a11-a84d-d7c44b7a5290) <br><br>
En la simulación consideramos el case general de nuestro prototipo inicial con un peso de 98 N y una fuerza de viento de 2500 N, el cual muestra un fenómeno de flexión. A continuación se detalla el proceso de deformación bajo flexión y cómo las fuerzas aplicadas influyen en la estructura.<br>

### 3.2 Descripción de las fuerzas aplicadas
![WhatsApp Image 2024-10-06 at 23 08 35](https://github.com/user-attachments/assets/c5b3e58c-e3d3-4aa5-9d1b-18ce0a4d9a0d) <br><br>
* Peso de la caja (98 N): Esta fuerza actúa verticalmente hacia abajo, generando una pequeña compresión en la estructura. 
* Fuerza del viento (2500 N): Esta fuerza es aplicada lateralmente, lo que significa que el viento empuja la estructura, generando un momento de flexión que deforma el tubo (poste del case general). <br>

### 3.3 Mallado (meshing)
![WhatsApp Image 2024-10-06 at 23 08 55](https://github.com/user-attachments/assets/a16e2d6d-2279-45e5-a8f3-d4b328dda318) <br>
![WhatsApp Image 2024-10-06 at 23 09 07](https://github.com/user-attachments/assets/fef83f69-d642-4e8f-9f3a-d59e9ef4a9f1) <br><br>
Posee una finura de 9. <br>

### 3.4 Deformación observada
![WhatsApp Image 2024-10-06 at 23 09 23](https://github.com/user-attachments/assets/954c7a9a-1dfa-4ed1-9105-7b0dd615f869) <br><br>
* Distribución de colores: La imagen muestra un tubo (poste del case general) con una deformación evidente hacia una de sus zonas extremas, donde los colores varían desde el azul en las zonas menos deformadas hasta tonos más cálidos (verde, amarillo, y rojo) en las zonas con mayor concentración de tensiones.
* Concentración de esfuerzos: Los colores rojos indican que hay una alta concentración de tensiones en esa zona, lo que sugiere una deformación significativa. En cambio, las zonas azules en los extremos sugieren áreas de baja tensión y mínima deformación.
* Tipo de carga dominante: La deformación y el tipo de colores sugieren que el objeto está sometido a un momento de flexión debido a la fuerza lateral (fuerza del viento). Esta carga causa que el tubo se doble, generando compresión en un lado y tracción en el otro.

#### Efecto de las fuerzas aplicadas
* Peso del case general (98 N): Esta fuerza actúa hacia abajo, pero es relativamente pequeña en comparación con la fuerza del viento. El impacto del peso en la deformación parece ser mínimo, dado que la mayor deformación ocurre en una de sus zonas extremas, y no en sus extremos donde se aplicaría la carga del peso. Esto sugiere que la deformación visible está principalmente influenciada por la fuerza del viento.
* Fuerza del viento (2500 N): La deformación y distribución de tensiones observadas concuerdan con una fuerza lateral significativa. Esta fuerza, aplicada a lo largo de la estructura, provoca que las tensiones más grandes se acumulen en la zona donde el material se deforma visiblemente. El momento de flexión genera tracción en la parte superior y compresión en la parte inferior de la barra, lo que explica la alta concentración de tensiones en el centro.

## 4. DISCUSIÓN DE RESULTADOS

De acuerdo a los resultados obtenidos, se observa una deformación significativa en una de sus zonas extremas del tubo (poste del case general), con un gradiente de colores que va del azul (bajas tensiones) al rojo (altas tensiones), lo que sugiere la acción de un momento de flexión causado por la fuerza lateral del viento (2500 N), la cual genera compresión en un lado y tracción en el otro. El peso de la caja (98 N) tiene un impacto mínimo en la deformación total, dado que la mayor concentración de tensiones se encuentra lejos del centro. En resumen, la fuerza del viento es la principal responsable de la deformación observada, mientras que el peso de la caja tiene un efecto secundario. <br>

La representación visual de las tensiones, mediante el uso de colores, facilita la identificación de las áreas críticas donde el material está sometido a mayores esfuerzos, lo cual es clave para un análisis detallado y medidas correctivas, además, es importante destacar que la zona de mayor concentración de tensiones (área roja) podría ser un punto crítico para la fatiga del material, lo que podría requerir refuerzos o una revisión del diseño estructural para prevenir fallos, por lo tanto, sería recomendable realizar un análisis de fatiga o ciclos de carga, para prever posibles fallos a largo plazo. Asimismo, el comportamiento de las zonas menos deformadas (áreas azules) indica que, si bien estas no están sometidas a grandes tensiones, deben considerarse para evitar problemas futuros de acumulación de esfuerzos.<br>

## 5. CONCLUSIÓN

La deformación del tubo (poste del case general) está dominada por la fuerza lateral del viento (2500 N), que provoca una flexión significativa en el centro del tubo, donde las tensiones se concentran. El peso del case general (98 N) tiene un efecto menor sobre la deformación observada, ya que su magnitud es pequeña en comparación con la fuerza del viento. Los colores de la imagen ayudan a visualizar las áreas de mayor y menor deformación, confirmando que las zonas más tensas se encuentran en el centro, donde el material está más comprometido estructuralmente debido al momento de flexión.<br>

## 6. BIBLIOGRAFÍA

1. Los beneficios de la 3DEXPERIENCE en el Diseño Mecánico – CIIA BAJÍO [Internet]. 2023  Disponible en: https://www.ciiabajio.mx/los-beneficios-de-la-3dexperience-en-el-diseno-mecanico/
2. SimScale [Internet]. Simulation Features and Benefits | Cloud-Based CAE. Disponible en: https://www.simscale.com/product/simulation-features/














