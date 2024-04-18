#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

int main() {
    char *data; // Puntero para almacenar datos ingresados por el usuario
    FILE *archivo;
    char nombre_archivo[] = "prueba_1.txt"; // Nombre del archivo
    int longitud;

    // Abrir el archivo en modo escritura
    archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Solicitar al usuario ingresar datos
    printf("Ingrese los datos (presione Ctrl + D para terminar):\n");

    // Reservar memoria dinámicamente para almacenar los datos
    data = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    if (data == NULL) {
        printf("Error de asignación de memoria.\n");
        return 1;
    }

    // Leer datos desde la entrada estándar y escribirlos en el archivo
    while (fgets(data, MAX_STRING_LENGTH, stdin) != NULL) {
        fputs(data, archivo);
    }

    // Liberar la memoria asignada
    free(data);

    // Cerrar el archivo
    fclose(archivo);

    printf("Datos guardados en el archivo \"%s\".\n", nombre_archivo);

    return 0;
}
