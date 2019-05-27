/*
void *hilo1();
void *hilo2();

int fin1=0,fin2=0;

int main(int argc,char **argv) {
	pthread_t h1,h2;
	printf("main(): lanzo hilo1!\n");
	pthread_create(&h1,NULL,hilo1,NULL);
	printf("main(): lanzo hilo2!\n");
	pthread_create(&h2,NULL,hilo2,NULL);
	printf("main(): espera por fin de hilo1 y hilo2!\n");
	while(!(fin1 && fin2)) sleep(1);
	printf("main(): fin!\n");
	return 0;
}

void *hilo1() {
	int n=5;
	while(n) {
		printf("hilo1(): n=%d\n",n);
		n--;
		sleep(1);
	}
	printf("hilo1(): fin!\n");
	fin1=1;
	pthread_exit(0);
}

void *hilo2() {
	int n=10;
	while(n) {
		printf("hilo2(): n=%d\n",n);
		n--;
		sleep(1);
	}
	printf("hilo2(): fin!\n");
	fin2=1;
	pthread_exit(0);
}
*/

//La version copada


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*
Ejemplo simple de procesos livianos (threads) hilos
Ejemplo simple de sincronizacion usando join
main() no requiere de variables globales para sincronizar
hilo1() e hilo2() , sino que utiliza join() para bloquear
el hilo del proceso pesado hasta la finalizacion de los
hilos
compilar como:
cc -Wall -o thr1 thr1.c -lpthread
*/

void *hilo1(); //Pre hilo anunciado
void *hilo2();//same hilo2

int main(int argc,char **argv) {
	pthread_t h1,h2; //Creamos los hilos, del tipo hilo
	printf("main(): lanzo hilo1!\n");
	pthread_create(&h1,NULL,hilo1,NULL); //Acá se crea el hilo h1 y comienza a trabajar como hilo1 apenas se crea
	printf("main(): lanzo hilo2!\n");
	pthread_create(&h2,NULL,hilo2,NULL); // Acá se crea el hilo h2 y labura tambien desde acá como hilo2
	printf("main(): espera por fin de hilo1 y hilo2!\n");
	pthread_join(h1,NULL);  // esperando por la finalizacion de hilo1() h1 //es como el wait pero para threads
	pthread_join(h2,NULL);  // esperando por la finalizacion de hilo2() h2
	printf("main(): fin!\n");
	return 0;
}

void *hilo1() {
	int n=5;
	while(n) {
		printf("hilo1(): n=%d\n",n);
		n--;
		sleep(1);
	}
	printf("hilo1(): fin!\n");
	pthread_exit(0); //el hilo finaliza
}

void *hilo2() {
	int n=10;
	while(n) {
		printf("hilo2(): n=%d\n",n);
		n--;
		sleep(1);
	}
	printf("hilo2(): fin!\n");
	pthread_exit(0);
}
