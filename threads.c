#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_THREADS 8

void* threadFuntion(void* id ){
    long thid = (long)id;
    printf("\tThread %ld: Starting work! \n",thid);
    sleep(5);
    printf("\tThread %ld: Done!\n", thid);
}


int main(){
    pthread_t th[MAX_THREADS];
    printf("Main: Initiating threads\n");
    for (int i=0; i < MAX_THREADS; i++) {
        pthread_create(&th[i], NULL, threadFuntion, (void*)i);
    }
    usleep(100);
    printf("Main: Sleep for 3 seconds...\n");
    sleep(3);
    printf("Main: Done. Waiting for all threads to finish...\n");
    for (int i=0; i < MAX_THREADS; i++) {
       pthread_join(th[i],NULL);
    }
    printf("Main: All threads finished. Exiting...\n");
    return 0;
}