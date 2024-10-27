#include <stdio.h>

typedef struct {
    int arrInt[10];
    int arrSize;
    int arrAdd;
} arrayLength_t;

// Inicializa el array
int initArray(arrayLength_t* arr) {
    for (int i = 0; i < 10; i++) {
        arr->arrInt[i] = -1;
    }
    arr->arrSize = 0;
    arr->arrAdd = 0;
    return 0;
}

// Imprime el array
void printArr(arrayLength_t* arr) {
    printf("{[");
    for (int i = 0; i < 10; i++) {
        if (i < arr->arrSize) {
            printf("%d", arr->arrInt[i]);
        } else {
            printf("-1");
        }
        if (i < 9) {
            printf(", ");
        }
    }
    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd);
}

// Añade un elemento
int addElement(arrayLength_t* arr, int value) {
    if (value < 0 || arr->arrSize >= 10) {
        return -1;
    }
    arr->arrInt[arr->arrSize] = value;
    arr->arrSize++;
    arr->arrAdd += value;
    return 0;
}

// Devuelve el tamaño del array
int getArrSize(arrayLength_t* arr) {
    return arr->arrSize;
}

// Devuelve la suma de los elementos
int getArrAdd(arrayLength_t* arr) {
    return arr->arrAdd;
}

// Obtiene un elemento por posición
int getElement(arrayLength_t* arr, int pos) {
    if (pos < 0 || pos >= 10 || arr->arrInt[pos] < 0) {
        return -1;
    }
    return arr->arrInt[pos];
}

// Establece un elemento por posición
int setElement(arrayLength_t* arr, int pos, int value) {
    if (pos < 0 || pos >= 10 || arr->arrInt[pos] < 0 || value < 0) {
        return -1;
    }
    arr->arrAdd += (value - arr->arrInt[pos]);
    arr->arrInt[pos] = value;
    return 0;
}

// Resetea el array
void resetArr(arrayLength_t* arr) {
    for (int i = 0; i < 10; i++) {
        arr->arrInt[i] = -1;
    }
    arr->arrSize = 0;
    arr->arrAdd = 0;
}

// Función principal
int main() {
    arrayLength_t al1, al2;

    initArray(&al1);
    for (int i = 0; i < 10; i++) {
        addElement(&al1, i * 10);
    }

    printf("Estructura al1:\n");
    printArr(&al1);

    for (int i = 1; i < 10; i += 2) {
        setElement(&al1, i, i);
    }

    printf("Estructura al1 después de actualizar posiciones impares:\n");
    printArr(&al1);

    initArray(&al2);
    for (int i = 0; i < al1.arrSize; i += 2) {
        addElement(&al2, al1.arrInt[i]);
    }

    for (int i = al2.arrSize; i < 10; i++) {
        addElement(&al2, i - al2.arrSize);
    }

    printf("Estructura al2:\n");
    printArr(&al2);

    return 0;
}
