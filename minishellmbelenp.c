#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

/*Partenzi Maria Belen*/

/*Shell con ejecucion en foreground y background, comandos con argumentos separados
por uno o mas espacios y eliminacion de procesos zombies */

//memes
void ingreso_cmd(char *);
void parseo(char *, char *[]);
void mata_zombies(int);

int comando_background(char *);
void quitar_ampersand(char *);

pid_t ultimo_pid = 0;

int main(int argc, char **argv[]) {
	signal(SIGCHLD,mata_zombies); //
	char comando[512];
	char *comando_argv[50];
	int retorno;

	ingreso_cmd(comando);
	while(strncmp(comando,"exit",4)) {
		pid_t pid = fork();
		//Proceso hijo
		if (pid == 0) {
			if (comando_background(comando)) quitar_ampersand(comando);
			parseo(comando, comando_argv);
			execvp(comando_argv[0],comando_argv);
			printf("El comando [%s] de proceso %d es erroneo\n",comando,getpid());
			exit(127);
		}
		//Proceso padre
		else {
			ultimo_pid = pid;
			if (!comando_background(comando)) {
				pid = waitpid(pid,&retorno,0);
				if (WEXITSTATUS(retorno) != 127)
				printf("Proceso %d finalizo finalizo con status =%d\n",pid,WEXITSTATUS(retorno));
			}
		}
		ingreso_cmd(comando);

	}

mata_zombies(0);
printf("THE END\n");
return 0;
}




//Verifica si el comando es en background
int comando_background(char *cmd) {
	int n = strlen(cmd)-1;
	while(n >= 0 && cmd[n] == ' ') {
		cmd[n] = '\0';
		n--;
	}
	return ( n >= 0 && cmd[n] == '&');
}

//Quita el ampersand
void quitar_ampersand(char *cmd) {
	cmd[strlen(cmd)-1]='\0';
}

//Ingresa comando por teclado
void ingreso_cmd(char *cmd) {
	printf("MY PROMPT ~ \n");
	memset(cmd,0,512);
	printf("%%");
	fgets(cmd,512,stdin);
	cmd[strlen(cmd)-1] = '\0';
}

/*Toma la linea de comando y carga cada parametro en un vector argv
y en la ultima posicion agrega el valor NULL
*/
void parseo(char *cmd,char *argv[]) {
	char *token;
	int n = 0;
	token = strtok(cmd," ");
	while (token != NULL) {
		argv[n] = token;
		//printf("%s\n", token);
		token = strtok(NULL, " ");
		n++;
	}
	argv[n] = NULL;
}

//Recupera los hijos terminados
void mata_zombies(int signo) {
	while(waitpid(0,0,WNOHANG) > 0);
}
