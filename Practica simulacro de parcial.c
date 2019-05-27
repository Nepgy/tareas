/*
Escriba un código en lenguaje C que genere una cadena de n procesos, y cada proceso
escribe en pantalla un carácter de la frase “Hola Querido Mundo 2012”,
Considerando que empieza escribiendo el primer proceso creado.
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

int main(void){
  char frase[24] = "Hola Querido Mundo 2019\0";
  pid_t manuel;
  int i;

  for(i = 0 ; i < 23 ; i ++ ){
    manuel = fork();

    if (manuel > 0) {
        printf(" %c \n", frase[i]); // con \n funciona
        break;
    }

  }
  wait(0);
  exit(0);
}
/*
romer codes:

int main(void)
{
 char frase[24] = "Hola Querido Mundo 2012\0";
 pid_t pid;
 int i ;
 for(i = 0 ; i < 23 ; i ++)
 {
 pid = fork();
 if (pid > 0)
 {
 printf("%d = %c\n",getpid(),frase[i]);
 break;
}
}
exit(0);
}
 */
