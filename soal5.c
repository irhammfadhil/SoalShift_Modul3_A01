#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

typedef long long ll;

pthread_t thread[100];

void* find (void* arg) {
}

int main(int argc, char* argv[]) {
    int j=1;
    while(j<argc)//looping membuat thread 2x
    {
        err=pthread_create(&(thread[j]),NULL,fact,);//membuat thread
        pthread_join(thread[j],NULL);
        j++;
    }
	
	
}
