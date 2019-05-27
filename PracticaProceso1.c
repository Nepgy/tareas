/*El siguiente código intenta representar la solución a la siguiente problemática:
Un proceso crea un conjunto de procesos hijos al mismo nivel y le asigna a cada unouna tarea determinada,
cada proceso hijo debe indicar a su proceso padre un estado definalización de la tarea, estado 1 tarea resuelta con éxito,
estado 0 tarea no resuelta.Suponemos que el fork() no falla.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int tarea(int); //funcion tarea
int main(int  argc , char *argv[]) {
  pid_t pid , pidTer; //pid_t inicializados
  int status  = 0 ; //Iniciar la variable con un valor
  int np = atoi(argv[1]); //Ingresa un valor por teclado, cuantos fork queres hacer y suponemos que no es codigo basura

  while(np){
    pid = fork(); //Hijo
    np -- ; //le resta a NP

    if (pid == 0 )exit(tarea(getpid()));} //asigna la tarea al nene

      while((pidter = wait(&status)) != -1 ){ //Espera un status y se fija si tira error, (!= 1) es para que sea distinto a error
        printf("Hijo %d termino  ",pidter) ;
        printf("retorno %d\n",status/256); //porque queremos los ultimos 4 digitos
      }
  }

exit(0);
}


int tarea(int num) {
    sleep(1);
    printf("tarea %d \n",num);
    return num % 2;
}
