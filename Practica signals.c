#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void f_signalPadre(void) ;
void f_signalHijo(void) ;
int main(void){
    pid_t pid ;  pid = fork(); //crea el hijo
    if (pid == 0 ){ //Si es hijo
      sigset_t seth ; //Conjunto de señales
      sigfillset(&seth); //Inicializa lleno el conjunto de señales si queres que sea vacio es sigemptyset(&seth)
      sigdelset(&seth,SIGUSR2); //Elimina la señal SIGUSR2 del conjunto de señales
      signal(SIGUSR2,(void *)f_signalHijo) ; //SIGUSR2 la va amanejar el handle de f_signalHijo
      sigprocmask(SIG_BLOCK,&seth,NULL); //Blockea todas las señales del conjunto

      while(1){
        sleep(1);
        kill(getppid(),SIGUSR1); //Ejecuta la señal SIGUSR1 para el padre (con getppid())
        pause(); //Espera que la señal que envio actue
        }

    }  else{
          sigset_t setp ; //Conjunto de señales
          sigfillset(&setp); //Inicializa el conjunto de señales pero lleno (con todas las señales)
          sigdelset(&setp,SIGUSR1); //Le quita la señal SIGUSR1
          signal(SIGUSR1,(void *)f_signalPadre) ; //La señal SIGUSR1 la maneja el handle f_signalPadre
          sigprocmask(SIG_BLOCK,&setp,NULL); //Bloquea todas las señales del conjunto

          while(1){
            pause();
            kill(pid,SIGUSR2); //Ejecuta la señal SIGUSR2
            sleep(1);
          }
    }
exit(0);
}
//Se crean funciones para hacer de handles de las señales
void f_signalPadre(void){
  printf("Soy el Padre \n");}


void f_signalHijo(void){
  printf("Soy el Hijo \n");}
