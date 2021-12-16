#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

char* vector[BUFSIZ];

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Uso:\t> leercadena_main <comando>\n\t> leercadena_main <comando> <-parametros>\n");
    return 0;
  }

  if (strcmp("exit", argv[1]) == 0) {
     printf("> Comando: %s", vector[0]);
     return 1;
  }

  int num = sizeof(*argv) / sizeof(char);

  for (int i = 1; i < num; i++) {
       vector[i - 1] = argv[i];
  }
 
  pid_t pid = fork();

  if (pid < 0) {
    perror("No se pudo crear el proceso\n");
    exit(1);
  } else if (pid == 0) {
    printf("> Comando: %s\n", vector[0]);
    execvp(vector[0], vector);
    perror("Return from execlp() not expected");
    exit(EXIT_FAILURE);
  } else {
    wait(NULL);
  }

  return 0;
}

