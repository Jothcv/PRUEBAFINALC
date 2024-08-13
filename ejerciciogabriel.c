#include <stdio.h>
#include <string.h>


struct Amigo {
    char nombre[50];
    int dia_cumpleaños;
    int mes_cumpleaños;
    int año_cumpleaños;
    char departamento[50];
}Amigo[5];
void agregarAmigo(struct Amigo amigos[], int *numAmigos);
void buscarAmigo(struct Amigo amigos[], int numAmigos);
void mostrarAmigos(struct Amigo amigos[], int numAmigos);
int main() {
    struct Amigo amigos[5];
    int Numero_Amigos = 0;
    char opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Agregar amigo\n");
        printf("2. Mostrar amigos\n");
        printf("3. Buscar amigo por nombre\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                agregarAmigo(amigos, &Numero_Amigos);
                break;
            case '2':
                mostrarAmigos(amigos, Numero_Amigos);
                break;
            case '3':
                buscarAmigo(amigos, Numero_Amigos);
                break;
            case '4':
                printf("Usted salio del programa\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != '4');

    return 0;
}

void agregarAmigo(struct Amigo amigos[], int *numAmigos) {
    if (*numAmigos < 6) {
        printf("Ingrese el nombre del amigo: ");
        scanf(" %[^\n]s", amigos[*numAmigos].nombre);
        printf("Ingrese la fecha de cumpleaños (dia mes año): ");
        scanf("%d %d %d", &amigos[*numAmigos].dia_cumpleaños, &amigos[*numAmigos].mes_cumpleaños, &amigos[*numAmigos].año_cumpleaños);
        printf("Ingrese el departamento donde vive: ");
        scanf(" %[^\n]s", amigos[*numAmigos].departamento);

        (*numAmigos)++;
        printf("Amigo agregado correctamente.\n");
    } else {
        printf("No se pueden agregar mas amigos.\n");
    }
}

void mostrarAmigos(struct Amigo amigos[], int numAmigos) {
    if (numAmigos > 0) {
        printf("\nLista de Amigos:\n");
        for (int i = 0; i < numAmigos; i++) {
            printf("Amigo %d:\n", i + 1);
            printf("Nombre: %s\n", amigos[i].nombre);
            printf("Fecha de Cumpleaños: %d/%d/%d\n", amigos[i].dia_cumpleaños, amigos[i].mes_cumpleaños, amigos[i].año_cumpleaños);
            printf("Departamento: %s\n", amigos[i].departamento);
            printf("\n");
        }
    } else {
        printf("No hay amigos almacenados.\n");
    }
}

void buscarAmigo(struct Amigo amigos[], int numAmigos) {
    char nombreBuscar[50];
    printf("Ingrese el nombre del amigo a buscar: ");
    scanf(" %[^\n]s", nombreBuscar);

    int encontrado = 0;
    for (int i = 0; i < numAmigos; i++) {
        if (strcmp(amigos[i].nombre, nombreBuscar) == 0) {
            printf("\nAmigo encontrado:\n");
            printf("Nombre: %s\n", amigos[i].nombre);
            printf("Fecha de Cumpleaños: %d/%d/%d\n", amigos[i].dia_cumpleaños, amigos[i].mes_cumpleaños, amigos[i].año_cumpleaños);
            printf("Departamento: %s\n", amigos[i].departamento);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontro al amigo\n");
    }
}