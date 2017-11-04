#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
 
int lohan = 100;
int kepiting = 100;
int choose;
int status = 0;

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
pthread_mutex_t lock;

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
    while(1)
    {
        if(lohan<=0 || kepiting <=0 || lohan>100 || kepiting>100 == 1)
        {
            printf("\n\nSimulasi Selesai\n");
            break;
        }
        
        status = 1;
        
        printf("Apa yang mau kamu lakukan ?\n");
        printf("1. Tampilkan status\n");
        printf("2. Beri makan Lohan\n");
        printf("3. Beri makan Kepiting\n");
        printf("pilih salah satu : "); scanf("%d", choose);

        if(*choose == 1)
        {
            printf("\n\nStatus saat ini :\n");
            printf("Lohan    : %d\n", lohan);
            printf("kepiting : %d\n\n", kepiting);
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
                        printf ("\nInput salah\n\n");
                    }
        
    }
    exit(EXIT_SUCCESS);
}

void* dec_lohan(void *arg)
{
    while(1)
    {
        while(status==0);
        
        sleep(10);
        
        lohan = lohan - 15;
        
        if(lohan<=0 || kepiting <=0 || lohan>100 || kepiting>100 == 1)
        {
            printf("\n\nSimulasi Selesai\n");
            break;
        }
    }   
    exit(EXIT_SUCCESS);
}

void* dec_kepiting(void *arg)
{
    while(1)
    {
        while(status==0);
        
        sleep(20);
        
        kepiting = kepiting - 10;
        
        if(lohan<=0 || kepiting <=0 || lohan>100 || kepiting>100 == 1)
        {
            printf("\n\nSimulasi Selesai\n");
            break;
        }
    }    
    exit(EXIT_SUCCESS);
}