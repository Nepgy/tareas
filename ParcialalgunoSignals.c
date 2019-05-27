

void handler(void);
void cortarPapu(void);

int main(void) {
 int loop = 1;
 pid_t pid ;
 pid = fork(); //creamos al crio

 if (pid > 0) { //para el papu

   signal (SIGALARM, cortarPapu); //handler para la alarma
   alarm(5); //Manda la señal para parar en 5 segundos
   while(loop) handler; //Algo asco para que no pare por 5 segundos
   wait(0); //Esperar al nene

  }
 else {
   //Esta parte es para el hijo
   alarm(5); //Pones alarma para que termine junto al f_signalPadre
   pause(); //Esto es para que espere realmente
}

 exit(0);

}
void handler(void) { printf("Padre dice hola\n"); }

void cortarPapu(void){
  loop = 0; //cortar ciclos 300000a
}
