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
    arrayLength_t myArray;

    // Inicializa la estructura
    if (initArray(&myArray) == 0) { 
        printArr(&myArray); // Muestra el estado inicial

        // Añade elementos
        addElement(&myArray, 5);
        addElement(&myArray, 10);
        addElement(&myArray, 15);

        // Muestra el estado después de añadir elementos
        printArr(&myArray); // Debe mostrar: {[5, 10, 15, -1, -1, -1, -1, -1, -1, -1], 3, 30}
    } else {
        printf("Error al inicializar el array.\n");
    }

    return 0;
}
