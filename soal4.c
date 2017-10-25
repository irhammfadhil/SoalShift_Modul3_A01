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
}

int main(int argc, char* argv[]) {
	int i;j=1;
	int err;
	int  num[argc-1];
    for (i=1;i<argc;i++) num[i]=atoi[i];
    while(j<argc)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[j]),NULL,fact,(void*)num[j]);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        pthread_join(tid[j],NULL);
        j++;
    }
	
	
}
