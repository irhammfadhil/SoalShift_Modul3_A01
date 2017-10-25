#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

typedef long long ll;

pthread_t thread[100];

void* fact (void* num) {
    int i;
    ll res=1;
    int a=(int)num;
    if (a==0 || a==1) res=1;
    else {
        for (i=2;i<=a;i++) {
            res=res*i;
        }
    }
    printf("Hasil %d! = %lld\n", a,res);
    return NULL;
}

int main(int argc, char* argv[]) {
	int i;int j=1;
	int err;
	int  num[argc];
    for (i=1;i<argc;i++) num[i]=atoi(argv[i]);
    while(j<argc)//looping membuat thread 2x
    {
        err=pthread_create(&(thread[j]),NULL,fact,(void*)num[j]);//membuat thread
        pthread_join(thread[j],NULL);
        j++;
    }
	
	
}
