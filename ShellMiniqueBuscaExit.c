#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int main(int argc, charr ** argv){
  char cmd[512];

  memset(cmd, 0, 512);
  fgets(cmd, 512, stdin);
  //cmd [ strlen(cmd) -1] = '/0';

  while (strncmp(cmd, "exit", 4)){
    p_pid pid;
    pid = fork();

    if (pid == 0){
      execl(cmd, cmd, NULL);
      return(0);
    }else{
      wait(0);
    }
    memset(cmd, 0, 512);
    fgets(cmd, 512, stdin);
    //cmd [ strlen(cmd) -1] = '/0';
  }
  exit(0);
}
