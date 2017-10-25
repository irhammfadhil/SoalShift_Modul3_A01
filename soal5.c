#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <stdlib.h>
pthread_t thread[100];
void* freq (void *word) {
    FILE *fp;
    int count=0,ch,len;
    char *w=(char*) word;
    if(NULL==(fp=fopen("Novel.txt", "r"))) printf("-1\n");
    len=strlen(word);
    for (;;) {
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *w) continue;
    	for(i=1;i<len;++i){
    	if(EOF==(ch = fgetc(fp))) goto end;
    	if((char)ch != w[i]){
        	fseek(fp, 1-i, SEEK_CUR);
        	goto next;
    	}
    }
    ++count;
    next: ;
    }
end:
    fclose(fp);
    printf("%s : %d\n",w,count);
    return NULL;
}
int main(int argc, char* argv[]) {
    int j=1,err;
    while(j<argc) {
        err=pthread_create(&(thread[j]),NULL,freq,(void*)argv[j]);//membuat thread
        pthread_join(thread[j],NULL);
        j++;        
    }
}
