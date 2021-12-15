#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "leercadena.h"

char **recortar(char* arg[], int inicio) {
  char **vector;
  size_t num = sizeof(*arg)/sizeof(char);
  for (size_t i = inicio; i < num; i++) {
     vector[i-inicio] = arg[i];
  }

  return vector;
}

int main(int argc, char *argv[]) {
//char comando[BUFSIZ];
  char **vector;
 if (argc < 2) {
 printf("Indique el programa que desea se ejecute\n");
 return 0;
 }

printf("%s\n",argv[0]);
printf("%s\n",argv[1]);

//while (1) {
  pid_t pid;
//  printf("> ");
//    leer_de_teclado(BUFSIZ,comando);

// if (strcmp("exit", argv[1]) == 0) {
//   return 1;
// }

  pid = fork();

 if (pid < 0) {
  //  printf("%s\n","test error");

    perror("No se pudo crear un proceso\n");
    exit(1);
  
} else if (pid == 0) {
/* 
   //      vector = de_cadena_a_vector(comando);
   //      vector = recortar(argv, 1);

    printf("%s\n","test create");
//    printf("%s-\n", &argv[1]);

    int num = sizeof(*argv)/sizeof(char);

printf("numero %d\n", num);
    for (int i = 1; i < num; i++) {
       vector[i-1] = argv[i];
    }

    vector[num]=NULL;

    printf("%s-",vector[0]);

*/
    execvp(argv[1], argv);
    perror("Return from execlp() not expected");
    exit(EXIT_FAILURE);

  } else {
//    printf("%s\n","test waait");
    wait(NULL);
  }

  return 0;
}
