#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
 
int lohan = 100;
int kepiting = 100;
int dec, sum;

void* menu(void *arg);
void* decstat(int *dec);
void* feed(int *sum);

int main(){


}
