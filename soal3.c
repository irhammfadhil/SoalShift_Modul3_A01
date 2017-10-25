#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
 
int lohan = 100;
int kepiting = 100;
int dec, sum;
int choose;
//int status = 0;

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;

void* menu(void *arg);
void* dec_lohan(void *arg);
void* dec_kepiting(void *arg);

int main()
{
    printf("Simulasi Kolam Aidil\n");
    printf("Terdapat Lohan dan Kepiting\n\n");

    pthread_create(&(tid1), NULL, &menu, (void*)&choose);
    pthread_create(&(tid2), NULL, &dec_lohan, NULL);
    pthread_create(&(tid3), NULL, &dec_kepiting, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    
    return 0;
}

void* menu(void *arg)
{
    int *choose=arg;
    while(lohan<=0 || kepiting <=0 || lohan>100 || kepiting>100)
    {
        printf("Apa yang mau kamu lakukan ?\n");
        printf("1. Tampilkan status\n");
        printf("2. Beri makan lohan\n");
        printf("3. Beri makan Kepiting\n");
        printf("pilih salah satu : "); scanf("%d", choose);

        if(*choose == 1)
        {
        printf("Status saat ini :\n");
        printf("Lohan : %d\n", lohan);
        printf("kepiting : %d\n", kepiting);
        } else
            if (*choose == 2)
            {
                lohan = lohan + 10;
            } else
                if (*choose == 3)
                {
                    kepiting = kepiting + 10;
                } else 
                    {
                        printf ("Input salah\n");
                    }
        //status = 1;
    }
}

void* dec_lohan(void *arg)
{
    while(lohan<=0 || kepiting <=0 || lohan>100 || kepiting>100)
    {
        //if(status==1);
        
        lohan = lohan - 15;
        
        sleep(10);
    }    
}


void* dec_kepiting(void *arg)
{
    while(lohan<=0 || kepiting <=0 || lohan>100 || kepiting>100)
    {
        //if(status==1);
        
        kepiting = kepiting - 10;
        
        sleep(20);
    }    
}