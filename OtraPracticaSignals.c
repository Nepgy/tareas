#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
int pulsaciones = 0;
void terminar ();
void contar ();

int main (void){
  signal(SIGINT,contar);
  signal(SIGALRM,terminar);
  printf("Pulsa varias veces CTRL-C durante 15 segundos.\n");
  alarm (15);
  while(1);
  return 0;
}

void terminar (){
  printf("¡Alarma!\n");
  printf("Has pulsado CTRL+C %d veces.\n",num_pulsaciones); // ctrl c manda una señal para cortar el program
}

void contar (){
  signal(SIGINT,SIG_DFL);
  pulsaciones++;
}
/* Lo que hace es contar 1 ctrl c si es que se aplica
Si se toca 2 veces termina el programa por el handle de SIG_DFL*/
