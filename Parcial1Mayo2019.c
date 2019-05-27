#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int main(){
  pid_t pid;

  pid = fork();

  if (pid == 0){
    pid = fork();

    if (pid == 0){
      pid = fork();

      if (pid == 0){
        pid = fork();

        if (pid == 0){
          prinf("Soy 4, estoy re duro");
        }
      }
    }
  }

wait(0);
exit(0);
}

//OR

int main(int argc, char ** argv){
  pid_t carla;
  int i, status = 0;

  for (i = 0; i < 4; i++){ //crea hijos en cadena
    carla = fork();
    if (carla > 0) break;
  }
  wait(&status);
  exit(0);
}
