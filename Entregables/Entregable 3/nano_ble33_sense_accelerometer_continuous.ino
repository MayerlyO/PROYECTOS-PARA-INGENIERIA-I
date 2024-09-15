#include <Arduino.h>
#include <Arduino_LSM9DS1.h>    // Librería para el IMU (acelerómetro)
#include <LAB_3_inferencing.h>  // Librería del modelo Edge Impulse

// Pines para los LEDs del ARDUINO NANO 33 BLE SENSE
#define RED_LED   LEDR
#define GREEN_LED LEDG
#define BLUE_LED  LEDB

// Configura el tamaño del buffer y otras variables globales
#define EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW (EI_CLASSIFIER_RAW_SAMPLE_COUNT / EI_CLASSIFIER_SLICE_SIZE)

float buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE] = { 0 };
int buffer_ix = 0;

void setup() {
    // Inicializa los LEDs
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    // Apaga todos los LEDs al inicio
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    // Inicializa el IMU
    if (!IMU.begin()) {
        ei_printf("Error al inicializar el IMU\n");
        while (1); // Detener ejecución si no se inicializa el IMU
    }

    ei_printf("Edge Impulse inferencing with accelerometer data\n");
}

void loop() {
    // Variables para almacenar los datos del acelerómetro
    float ax, ay, az;

    // Leer los datos del acelerómetro
    if (IMU.accelerationAvailable()) {
        IMU.readAcceleration(ax, ay, az);

        // Llenar el buffer con los datos del acelerómetro
        buffer[buffer_ix++] = ax;
        buffer[buffer_ix++] = ay;
        buffer[buffer_ix++] = az;

        // Ejecutar la inferencia una vez que el buffer esté lleno
        if (buffer_ix == EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
            buffer_ix = 0;
            ei_impulse_result_t result;
            signal_t signal;
            signal.total_length = EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE;
            signal.get_data = [](size_t offset, size_t length, float *out_ptr) {
                memcpy(out_ptr, buffer + offset, length * sizeof(float));
                return EIDSP_OK;
            };

            EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false);
            if (res != EI_IMPULSE_OK) {
                ei_printf("Error en la inferencia (%d)\n", res);
                return;
            }

            // Apagar todos los LEDs
            digitalWrite(RED_LED, LOW);
            digitalWrite(GREEN_LED, LOW);
            digitalWrite(BLUE_LED, LOW);

            // Mostrar el resultado de la inferencia y encender el LED correspondiente
            ei_printf("Resultados de la inferencia:\n");
            for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
                ei_printf("    %s: %.5f\n", result.classification[ix].label, result.classification[ix].value);
            }

            // Encender el LED correspondiente en función de la clasificación
            if (result.classification[0].value > 0.8) {  // Círculo "O"
                digitalWrite(RED_LED, HIGH);
                ei_printf("Reconocido: Círculo\n");
            } else if (result.classification[1].value > 0.8) {  // Número 3
                digitalWrite(BLUE_LED, HIGH);
                ei_printf("Reconocido: Número 3\n");
            } else if (result.classification[2].value > 0.8) {  // Número 1
                digitalWrite(GREEN_LED, HIGH);
                ei_printf("Reconocido: Número 1\n");
            }
        }
    }
}
