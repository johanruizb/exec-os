/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

int main(int argc, char *argv[])
{
  char comando[100];
  char **vector;
  int i;
  if (argc < 2)
  {
    printf("Sin argumentos\n");
  }
  else
  {
    for (int i = 1; i < argc; i++)
    {
      printf("argv %d %s\n", i, argv[i]);
      strcat(comando, argv[i]);
      strcat(comando, " ");
    }
    printf("Comando es: %s\n", comando);
    vector = de_cadena_a_vector(comando);
    execvp(vector[0], vector);
    perror("Error en el exec\n");
  }
  return 0;
}
