/* Realizar un proceso que reciba desde línea de comando una secuencia de
comandos a ejecutar y que cree un hijo por cada comando a ejecutar (crea un hijo
ejecuta el comando, crea otro hijo ejecuta el comando, crea otro hijo ejecuta el
comando, mientras existan comandos). NO USAR system.
Los comandos no tienen modificadores. El padre espera la terminación de cada
hijo. Ejemplo de la línea de comandos $./a.out ps ls cal who */


#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char * argv[]){ //argc contiene el número de argumentos que se han introducido.

 pid_t pid ;
 int i ;

 for(i = 1 ; i < argc ; i++)
 {
   pid = fork() ;
   if ( pid == 0 ){
    execlp(argv[i],argv[i],0); //execlp va ejectuando los comandos 1 por 1 mientras avanza la variable i
  }else{
      wait(0);}
 }


 exit(0);
}
