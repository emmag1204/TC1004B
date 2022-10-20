#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define NUM_THREADS 10

/*ypedef struct thread_data{
    int threadId;
    char name[20];
    //..
} ThreadData;
typedef char caracter;*/

int saldo;
sem_t protectSaldo;

void * suma(void *arg){
    sem_wait(&protectSaldo); // decrementa
    printf("El saldo inicial es %d\n", saldo);
    saldo = saldo + 100;
    printf("El saldo despues es %d\n", saldo);
    sem_post(&protectSaldo); // incrementa
    pthread_exit(NULL);
}
/*void * holaMundo(void *arg){
    ThreadData *myData = (ThreadData *)arg;
    printf("Hola desde el hilo y mi id es %d\n", myData->threadId);
    pthread_exit(NULL);
}*/

int main(){
    saldo = 0;
    pthread_t threadsInfo[NUM_THREADS];
    sem_init(&protectSaldo, 0, 1);
    //Create threads
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threadsInfo[i], NULL, suma, NULL);
    }
    for (int i =  0; i < NUM_THREADS; i++){
        pthread_join(threadsInfo[i], NULL);
    }
    printf("El final es %d\n", saldo);
    pthread_exit(NULL);
    printf("NUNCA LLEGA");
}