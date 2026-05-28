/*
========================================
TALLER UNIDAD 5
Métodos de Ordenamiento y Búsqueda Binaria
Autores:
- Tu nombre aquí
========================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 30

// VARIABLES GLOBALES
int pesos[MAX_CONTENEDORES];
int cantidad = 0;
int ordenado = 0;

// FUNCIONES
void registrarManual();
void generarAleatorios();
void mostrarContenedores();

void burbuja();
void seleccion();
void insercion();

int busquedaBinaria(int valor);

int main() {

    int opcion;
    srand(time(NULL));

    do {

        printf("\n========================================\n");
        printf("SISTEMA DE ORGANIZACION DE CONTENEDORES\n");
        printf("MUELLE DE CARGA\n");
        printf("========================================\n");

        printf("1. Registrar peso manualmente\n");
        printf("2. Generar pesos aleatorios\n");
        printf("3. Mostrar contenedores\n");
        printf("4. Ordenar Metodo Burbuja\n");
        printf("5. Ordenar Metodo Seleccion\n");
        printf("6. Ordenar Metodo Insercion\n");
        printf("7. Buscar contenedor\n");
        printf("8. Salir\n");

        printf("========================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                registrarManual();
                break;

            case 2:
                generarAleatorios();
                break;

            case 3:
                mostrarContenedores();
                break;

            case 4:
                burbuja();
                break;

            case 5:
                seleccion();
                break;

            case 6:
                insercion();
                break;

            case 7: {

                if(cantidad == 0) {
                    printf("No hay contenedores registrados\n");
                    break;
                }

                if(ordenado == 0) {
                    printf("Debe ordenar el arreglo primero\n");
                    break;
                }

                int buscar;

                printf("Ingrese el peso a buscar: ");
                scanf("%d", &buscar);

                int posicion = busquedaBinaria(buscar);

                if(posicion != -1) {
                    printf("Contenedor encontrado en posicion %d\n", posicion);
                } else {
                    printf("Contenedor no encontrado\n");
                }

                break;
            }

            case 8:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 8);

    return 0;
}

// REGISTRO MANUAL
void registrarManual() {

    printf("Cuantos contenedores desea registrar? ");
    scanf("%d", &cantidad);

    if(cantidad > MAX_CONTENEDORES) {
        printf("Maximo permitido: 30\n");
        cantidad = MAX_CONTENEDORES;
    }

    for(int i = 0; i < cantidad; i++) {

        printf("Ingrese peso del contenedor %d: ", i + 1);
        scanf("%d", &pesos[i]);
    }

    ordenado = 0;

    printf("Contenedores registrados correctamente\n");
}

// GENERAR ALEATORIOS
void generarAleatorios() {

    printf("Cuantos contenedores desea generar? ");
    scanf("%d", &cantidad);

    if(cantidad > MAX_CONTENEDORES) {
        printf("Maximo permitido: 30\n");
        cantidad = MAX_CONTENEDORES;
    }

    for(int i = 0; i < cantidad; i++) {

        pesos[i] = rand() % 30001 + 1000;
    }

    ordenado = 0;

    printf("Pesos generados correctamente\n");
}

// MOSTRAR
void mostrarContenedores() {

    if(cantidad == 0) {
        printf("No hay contenedores registrados\n");
        return;
    }

    printf("\nLISTA DE CONTENEDORES\n");

    for(int i = 0; i < cantidad; i++) {

        printf("[%d] %d kg\n", i, pesos[i]);
    }
}

// METODO BURBUJA
void burbuja() {

    int aux;

    for(int i = 0; i < cantidad - 1; i++) {

        for(int j = 0; j < cantidad - 1 - i; j++) {

            if(pesos[j] > pesos[j + 1]) {

                aux = pesos[j];
                pesos[j] = pesos[j + 1];
                pesos[j + 1] = aux;
            }
        }
    }

    ordenado = 1;

    printf("Ordenado por metodo Burbuja\n");
}

// METODO SELECCION
void seleccion() {

    int menor, aux;

    for(int i = 0; i < cantidad - 1; i++) {

        menor = i;

        for(int j = i + 1; j < cantidad; j++) {

            if(pesos[j] < pesos[menor]) {

                menor = j;
            }
        }

        aux = pesos[i];
        pesos[i] = pesos[menor];
        pesos[menor] = aux;
    }

    ordenado = 1;

    printf("Ordenado por metodo Seleccion\n");
}

// METODO INSERCION
void insercion() {

    int actual;
    int j;

    for(int i = 1; i < cantidad; i++) {

        actual = pesos[i];
        j = i - 1;

        while(j >= 0 && pesos[j] > actual) {

            pesos[j + 1] = pesos[j];
            j--;
        }

        pesos[j + 1] = actual;
    }

    ordenado = 1;

    printf("Ordenado por metodo Insercion\n");
}

// BUSQUEDA BINARIA
int busquedaBinaria(int valor) {

    int inicio = 0;
    int fin = cantidad - 1;
    int medio;

    while(inicio <= fin) {

        medio = (inicio + fin) / 2;

        if(pesos[medio] == valor) {

            return medio;

        } else if(valor < pesos[medio]) {

            fin = medio - 1;

        } else {

            inicio = medio + 1;
        }
    }

    return -1;
}