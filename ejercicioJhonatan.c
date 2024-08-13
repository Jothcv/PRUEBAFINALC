#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Estudiante {
    int id;
    char nombre[50];
    char apellido[50];
    char grado[10];
    char seccion[10];
    int edad;
};

struct Producto {
    int codigo;
    float precioCosto;
    float precioVenta;
    int cantidad;
};

struct Contacto {
    char nombre[50];
    char apellido[50];
    char direccion[100];
    char telefono[15];
    char tipoSangre[5];
    int edad;
};

void leerEstudiantes(struct Estudiante *estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese datos del estudiante %d:\n", i + 1);
        printf("ID: "); 
        scanf("%d", &estudiantes[i].id);
        printf("Nombre: "); 
        scanf("%s", estudiantes[i].nombre);
        printf("Apellido: "); 
        scanf("%s", estudiantes[i].apellido);
        printf("Grado: "); 
        scanf("%s", estudiantes[i].grado);
        printf("Seccion: "); 
        scanf("%s", estudiantes[i].seccion);
        printf("Edad: "); 
        scanf("%d", &estudiantes[i].edad);
    }
}
void encontrarExtremosEdad(struct Estudiante *estudiantes, int n) {
    int maxEdad = estudiantes[0].edad, minEdad = estudiantes[0].edad;
    int idxMax = 0, idxMin = 0;

    for (int i = 1; i < n; i++) {
        if (estudiantes[i].edad > maxEdad) 
        { maxEdad = estudiantes[i].edad;idxMax = i; }
        if (estudiantes[i].edad < minEdad) 
        { minEdad = estudiantes[i].edad; idxMin = i; }
    }

    printf("El mas grande es::\n");
    printf("Nombre: %s %s, Edad: %d\n", estudiantes[idxMax].nombre, estudiantes[idxMax].apellido, estudiantes[idxMax].edad);
    printf("el mas pequeño es;:\n");
    printf("Nombre: %s %s, Edad: %d\n", estudiantes[idxMin].nombre, estudiantes[idxMin].apellido, estudiantes[idxMin].edad);
}

float calcularGanancias(struct Producto *productos, int n) {
    float totalGanancias = 0.0;
    for (int i = 0; i < n; i++)
    { totalGanancias += 
    (productos[i].precioVenta - productos[i].precioCosto) * productos[i].cantidad; }
    return totalGanancias;
}

void leerProductos(struct Producto *productos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese datos del producto %d:\n", i + 1);
        printf("Codigo: "); scanf("%d", &productos[i].codigo);
        printf("Precio de Costo: "); scanf("%f", &productos[i].precioCosto);
        printf("Precio de Venta: "); scanf("%f", &productos[i].precioVenta);
        printf("Cantidad: "); scanf("%d", &productos[i].cantidad);
    }
}

void ordenarAscendente(int *vector, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

void ordenarDescendente(int *vector, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vector[j] < vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

void ingresarYOrdenarVectores() {
    int m, n;
    printf("Ingrese la cantidad de datos para el primer vector: ");
    scanf("%d", &m);
    int vector1[m];
    for (int i = 0; i < m; i++) { printf("Ingrese el dato %d para el primer vector: ", i + 1); scanf("%d", &vector1[i]); }
    printf("Ingrese la cantidad de datos para el segundo vector: ");
    scanf("%d", &n);
    int vector2[n];
    for (int i = 0; i < n; i++) { printf("Ingrese el dato %d para el segundo vector: ", i + 1); scanf("%d", &vector2[i]); }
    ordenarAscendente(vector1, m);
    ordenarDescendente(vector2, n);
    printf("Primer vector ordenado para arriba\n");
    for (int i = 0; i < m; i++) { printf("%d ", vector1[i]); }
    printf("\n");
    printf("Segundo vector ordenado para anakp\n");
    for (int i = 0; i < n; i++) { printf("%d ", vector2[i]); }
    printf("\n");
}

void leerContactos(struct Contacto *agenda, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese datos del contacto %d:\n", i + 1);
        printf("Nombre: "); scanf("%s", agenda[i].nombre);
        printf("Apellido: "); scanf("%s", agenda[i].apellido);
        printf("Dirección: "); scanf("%s", agenda[i].direccion);
        printf("Teléfono: "); scanf("%s", agenda[i].telefono);
        printf("Tipo de Sangre: "); scanf("%s", agenda[i].tipoSangre);
        printf("Edad: "); scanf("%d", &agenda[i].edad);
    }
}

void mostrarAgenda(struct Contacto *agenda, int n) {
    printf("Agenda de contactos:\n");
    for (int i = 0; i < n; i++) {
        printf("Contacto %d:\n", i + 1);
        printf("Nombre: %s %s\n", agenda[i].nombre, agenda[i].apellido);
        printf("Dirección: %s\n", agenda[i].direccion);
        printf("Teléfono: %s\n", agenda[i].telefono);
        printf("Tipo de Sangre: %s\n", agenda[i].tipoSangre);
        printf("Edad: %d\n", agenda[i].edad);
        printf("\n");
    }
}

int main() {
    int opcion, n;
    do {
        printf("\nMenu:\n1. Colegio\n2. Tienda\n3. Vectores\n4. Agenda\n5. Salir\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: {
                printf("Ingrese el numero de estudiantes: ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Numero de estudiantes no valido Intente nuevamente.\n");
                    break;
                }
                struct Estudiante estudiantes[n];
                leerEstudiantes(estudiantes, n);
                encontrarExtremosEdad(estudiantes, n);
                break;
            }
            case 2: {
                printf("Ingrese la cantidad de productos: ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Cantidad de productos no válida. Intente nuevamente.\n");
                    break;
                }
                struct Producto productos[n];
                leerProductos(productos, n);
                printf("Las ganancias totales son: %.2f\n", calcularGanancias(productos, n));
                break;
            }
            case 3:
                ingresarYOrdenarVectores();
                break;
            case 4: {
                printf("Ingrese la cantidad de contactos a agregar: ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Cantidad de contactos no valida Intente nuevamente.\n");
                    break;
                }
                struct Contacto agenda[n];
                leerContactos(agenda, n);
                mostrarAgenda(agenda, n);
                break;
            }
            case 5:
                printf("good buye nfjab\n");
                break;
            default:
                printf("loco esa opcion no esta disponible\n");
                break;
        }
    } while (opcion != 5);
    return 0;
}
