#include <stdio.h>

typedef struct {
    int arrInt[10];
    int arrSize;
    int arrAdd;
} arrayLength_t;

// Inicializa el array y otros campos de la estructura
int initArray(arrayLength_t *array) {
    if (array == NULL) return -1;

    for (int i = 0; i < 10; i++) {
        array->arrInt[i] = -1;
    }
    array->arrSize = 0;
    array->arrAdd = 0;

    return 0;
}

// Muestra el contenido de la estructura
void printArr(const arrayLength_t *array) {
    printf("{[");
    for (int i = 0; i < 10; i++) {
        printf("%d", array->arrInt[i]);
        if (i < 9) printf(", ");
    }
    printf("], %d, %d}\n", array->arrSize, array->arrAdd);
}

// Añade un elemento al array
int addElement(arrayLength_t *array, int newValue) {
    if (array == NULL || newValue <= 0) return -1; // Verifica si el puntero es NULL y si el valor es positivo

    if (array->arrSize < 10) { // Comprueba si hay espacio en el array
        array->arrInt[array->arrSize] = newValue; // Añade el nuevo valor
        array->arrAdd += newValue; // Actualiza la suma total
        array->arrSize++; // Incrementa el número de elementos
        return 0; // Éxito
    }

    return -1; // No hay espacio
}

int main() {
    arrayLength_t arr;

    // Inicializa la estructura
    if (initArray(&arr) == 0) { // Cambiado para verificar correctamente la inicialización
        printf("Array inicializado\n");
    } else {
        printf("Error en inicialización\n");
    }

    printArr(&arr);

    // Añade elementos y verifica
    if (addElement(&arr, 22) == 0) {
        printf("Elemento añadido\n");
    } else {
        printf("Error al añadir elemento\n");
    }
    printArr(&arr);

    if (addElement(&arr, 44) == 0) {
        printf("Elemento añadido\n");
    } else {
        printf("Error al añadir elemento\n");
    }
    printArr(&arr);

    return 0;
}
