#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

int fact1,a;

void* facta (void *arg) {
	int i;
	if (a==0) fact1=1;
	else {
		for (i=1;i<=a;i++) {
		fact1*=i;
		}
	}
	printf("%d", fact1);
}

int main() {
	pthread_t threads[3];
	int iret[3];
	scanf("%d", &a);
	iret[0] = pthread_create( &threads[0], NULL, facta, (void*) (&a));
}
