#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

typedef long long ll;

pthread_t thread[100];
int wc(char* file_path, char* word){
    FILE *fp;
    int count = 0;
    int ch, len;

    if(NULL==(fp=fopen(file_path, "r")))
        return -1;
    len = strlen(word);
    for(;;){
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *word) continue;
        for(i=1;i<len;++i){
            if(EOF==(ch = fgetc(fp))) goto end;
            if((char)ch != word[i]){
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }
        ++count;
        next: ;
    }
end:
    fclose(fp);
    return count;
}

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
