<p align="left">
  <img src="https://upchvirtual.edu.pe/ued/images/logo-upch.png" width="200">

  # <h1 align="center">*Entregable N° 1: Regresión Lineal*

## *Introducción*

Los materiales particulados, como el PM2.5 (partículas con un diámetro menor a 2.5 micrómetros, µm), son un factor clave para evaluar la calidad del aire en una zona específica. Estas partículas afectan la salud debido a sus características toxicológicas, las cuales varían según su origen y composición química [1]. Investigaciones han demostrado que la exposición prolongada a partículas en suspensión (PM) en el aire puede estar relacionada con la mortalidad infantil posneonatal, especialmente en casos de problemas respiratorios y el síndrome de muerte súbita del lactante (SMSL) en California [2]. Por esta razón, diversos estudios se centran en implementar y evaluar estrategias para reducir los elevados niveles de material particulado (PM2.5) en el centro de California [3].

Frente a esta problemática nuestro equipo de trabajo realizó una regresión lineal para examinar cómo las fluctuaciones en los niveles de PM2.5 influyen en el AQI en California. Esta herramienta estadística facilita el modelado de la relación entre variables, permitiendo cuantificar la influencia directa del PM2.5 sobre el AQI. La aplicación de la regresión lineal ayudará a identificar tendencias y patrones, proporcionando una visión clara de cómo varía la calidad del aire con las concentraciones de PM2.5. Además, el desarrollo de modelos predictivos permitirá anticipar cómo podría evolucionar la calidad del aire, un aspecto crucial en un entorno tan dinámico como el de California.


## *Metodología*
### *1. Importación de Librerías*

- Para llevar a cabo la regresión lineal, se importaron varias librerías esenciales, incluyendo:

***a) Numpy***, es una librería fundamental para realizar cálculos numéricos en Python. Se utiliza principalmente para manejar arrays multidimensionales y realizar operaciones matemáticas de manera eficiente. Es esencial para cualquier tipo de cálculo científico o matemático en Python.

***b) Pandas***, se usó para la manipulación y análisis de datos. Ofrece estructuras de datos de alto rendimiento como DataFrames, que son esenciales para manejar datos tabulares de manera similar a las hojas de cálculo de Excel.

***c) Seaborn***, para la visualización de datos construida sobre matplotlib; debido a que ofrece gráficos estadísticos atractivos y fáciles de interpretar, lo que facilita la exploración y comprensión de los datos.

***d) Train_test_split (función de scikit-learn)*** para dividir datos en subconjuntos, en un 80% para entrenamiento y un 20% para pruebas, así evaluar el rendimiento de un modelo en datos no vistos durante el entrenamiento.

***e) LinearRegression (clase de scikit-learn)*** se usó para implementar el modelo de regresión lineal para predecir el AQI en función de la concentración de PM2.

***Entre otras.***

### *2. Carga de Datos*
***-Datos de 2022 y 2023:*** Se cargaron dos conjuntos de datos correspondientes a las mediciones diarias de PM2.5 y AQI en California para los años 2022 y 2023. Estos datos se leyeron desde archivos CSV mediante la función `pd.read_csv()` de “pandas”.

***-Selección de Variables:*** Del conjunto de datos original, se seleccionaron las columnas más importantes “Daily Mean PM2.5 Concentration” (concentración diaria de PM2.5) y “Daily AQI Value” (valor diario del AQI).

### *3. Pre procesamiento de los Datos*
***-Conversión de Fechas:*** Se transformaron las columnas de fechas en formato “datetime” para facilitar el manejo temporal de los datos.

***- Separación de Conjuntos de Entrenamiento y Prueba:*** Se utilizaron `train_test_split` de `sklearn` para dividir los datos en conjuntos de entrenamiento y prueba. Esto permitió evaluar el rendimiento del modelo de manera independiente.

### *4. Construcción del Modelo de Regresión Lineal* 
Se creó una instancia del modelo `LinearRegression` de `sklearn` para iniciar el modelo, luego se ajustó el modelo a los datos de entrenamiento utilizando el método “fit()”, que permitió encontrar la mejor línea que minimiza el error cuadrático medio entre las predicciones y los valores reales del AQI.

### *5. Evaluación del Modelo*
Se realizaron predicciones sobre los datos de prueba utilizando el método “predict()”, posteriormente  se calcularon métricas clave como el Error Absoluto Medio (MAE), el Error Cuadrático Medio (MSE), y el Coeficiente de Determinación (R²) para evaluar la precisión del modelo.

### *6. Visualización de Resultados*
Se utilizaron “matplotlib” y “seaborn” para generar gráficos que ilustran la relación entre las predicciones del modelo y los valores reales del AQI, permitiendo una visualización clara de la efectividad del modelo.

Una vez que el modelo fue entrenado y evaluado, se usó para predecir los valores del AQI para 2024, basado en las concentraciones de PM2.5 esperadas o proyectadas para ese año y finalmente se utilizó “joblib” para guardar el modelo entrenado, permitiendo su reutilización para futuras predicciones sin necesidad de entrenarlo nuevamente.

## *Resultados*
[Colab_ Regresión Lineal_ GRUPO 9](https://colab.research.google.com/drive/10S0VaYjtLfpBDIcDJ3DkEwyBSqU3xMDu?usp=sharing)

*Error absoluto medio (MAE):  1.42*

*Error cuadrático medio (MSE):  3.09*

*Puntaje R²:  0.98*

*Precisión del modelo: 86.67%*

## *Discusión*

Este análisis evaluó la calidad del aire en California mediante el estudio de las concentraciones de PM 2.5, comparando datos de 2022 y 2023, y utilizando un modelo de regresión lineal para predecir el Índice de Calidad del Aire (AQI). Se emplearon gráficos de dispersión para visualizar la relación entre PM 2.5 y AQI, confirmando una correlación positiva entre estas variables, lo cual es coherente con la teoría, ya que el AQI refleja la calidad del aire en función de contaminantes como el PM 2.5. Para el modelado y las predicciones, se entrenó un modelo de regresión lineal con los datos de 2022, considerando la concentración media diaria de PM 2.5 (Daily Mean PM2.5 Concentration) como variable independiente y el valor diario del AQI (Daily AQI Value) como dependiente. Asimismo, el modelo mostró un buen ajuste con un coeficiente de determinación (R²) de 0.98.

Los resultados confirmaron la esperada correlación positiva entre la concentración de PM 2.5 y el AQI, validando la metodología empleada y reforzando la idea de que mayores niveles de PM 2.5 están asociados con una peor calidad del aire. El modelo de regresión lineal presentó un rendimiento adecuado con un R² (0.98) que indica un buen ajuste a los datos de 2022. No obstante, al evaluar con los datos de 2023, se evidenció que la capacidad predictiva del modelo puede variar de un año a otro, lo que sugiere la presencia de patrones no completamente capturados por un modelo lineal sencillo. Al aplicar el modelo de 2022 a los datos de 2023, se observó que su capacidad predictiva fue moderada; aunque mostró consistencia general. Además, otros factores podrían estar influyendo en las mediciones del AQI, requiriendo posiblemente un modelo más complejo o la inclusión de variables adicionales para mejorar la precisión.

## *Referencias*

[1] Meza, L. M., Quintero, M., García, R., & Ramírez, J. (2010). Estimación de factores de emisión de PM10 y PM2. 5, en vías urbanas en Mexicali, Baja California, México. Información tecnológica, 21(4), 45-56.

[2] Woodruff, T. J., Parker, J. D., & Schoendorf, K. C. (2006). Fine particulate matter (PM2. 5) air pollution and selected causes of postneonatal infant mortality in California. Environmental health perspectives, 114(5), 786-790.

[3] Chow, J. C., Chen, L. W. A., Watson, J. G., Lowenthal, D. H., Magliano, K. A., Turkiewicz, K., & Lehrman, D. E. (2006). PM2. 5 chemical composition and spatiotemporal variability during the California Regional PM10/PM2. 5 Air Quality Study (CRPAQS). Journal of Geophysical Research: Atmospheres, 111(D10).


