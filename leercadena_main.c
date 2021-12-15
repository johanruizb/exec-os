#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "leercadena.h"

char **vector;
int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Indique el programa que desea se ejecute\n");
    return 0;
  }

  if (strcmp("exit", argv[1]) == 0) {
     return 1;
  }

  //printf("argv[1] = %s\n", argv[1]);

  int num = sizeof(*argv) / sizeof(char);

  for (int i = 1; i < num; i++) {
    vector[i - 1] = argv[i];
  }
  vector[num] = NULL;
  
  printf("vector[0] = %s\n", vector[0]);

  pid_t pid = fork();

  if (pid < 0) {
    perror("No se pudo crear el proceso\n");
    exit(1);
  } else if (pid == 0) {

    printf("%s\n", "test create");

    printf("tamaño argv = %d\n", num);

    execvp(vector[0], vector);
    perror("Return from execlp() not expected");
    exit(EXIT_FAILURE);

  } else {
    wait(NULL);
  }

  return 0;
}

