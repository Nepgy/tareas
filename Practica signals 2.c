#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalPapa(void);
void signalNene(void);

int main(void){
  pid_t identificadorCarla;
  identificadorCarla = fork();

  if (identificadorCarla > 0){
    sigset_t conjuntoSignalsPapi;
    sigfillset(&conjuntoSignalsPapi);
    sigdelset(&conjuntoSignalsPapi, SIGUSR2);
    signal(SIGUSR1, signalPapa);


  }else{
    sigset_t conjuntoSignalsNene;
    sigfillset(&conjuntoSignalsNene);
    sigdelset(&conjuntoSignalsNene, SIGUSR1);
    signal(SIGUSR2,signalNene);
  }
  exit(0);
}
