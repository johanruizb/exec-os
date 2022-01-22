/*
 * Durante la clase se llevó a cabo la construcción de un shell muy 
 * básico el cual permitía ejecutar comandos de manera interactiva. 
 * Se han hecho los ajustes necesarios en el código leercadena_main.c
 * para tener un comportamiento deseado.
 * 
 * Codigo fuente: https://github.com/josanabr/so_80/tree/master/05/dummy_shell
 * 
 * Modificado por: Johan Ruiz - johan.andres.ruiz@correounivalle.edu.co
 * Fecha: 19/12/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

/**
 * Recibe comandos y parametros como argumentos al ejecutarse el programa.
 * Uso: leercadena_main <comando>
        leercadena_main <comando> <-parametros>
 * 
 * @param[in] argc cantidad de argumentos
 * @param[in] argv vector que contiene los argumentos
 * @param[out] int retorna 0, en caso de una ejecucion correcta
*/

int main(int argc, char *argv[])
{
  char *vector[BUFSIZ];

  if (argc < 2)
  {
    printf("Uso:\t> leercadena_johan <comando>\n\t> leercadena_johan <comando> <-parametros>\n");
    return 0;
  }

  if (strcmp("exit", argv[1]) == 0)
  {
    printf("> Comando: %s", vector[0]);
    return 0;
  }

  // Recortar y guardar 'argv' en 'vector'
  for (int i = 1; i < argc; i++)
  {
    vector[i - 1] = argv[i];
  }

  pid_t pid = fork();

  if (pid < 0)
  {
    perror("No se pudo crear el proceso\n");
    exit(1);
  }
  else if (pid == 0)
  {
    printf("> Comando: %s\n", vector[0]);
    execvp(vector[0], vector);
    perror("Error inesperado de execvp()");
    exit(EXIT_FAILURE);
  }
  else
  {
    wait(NULL);
  }

  return 0;
}