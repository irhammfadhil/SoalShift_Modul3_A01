#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
 
int lohan = 100;
int kepiting = 100;
int dec, sum;
int choose;
int status;

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;

void* menu(void *arg);
void* dec_lohan(int *dec);
void* dec_kepiting(int *sum);

int main()
{
    printf("Simulasi Kolam Aidil\n");
    printf("Terdapat Lohan dan Kepiting\n\n");

    p
}

void* menu(void *arg)
{
    while(lohan<=0 || kepiting <=0 || lohan>100 || kepiting>100)
    {
        printf("Apa yang mau kamu lakukan ?\n");
        printf("1. Tampilkan status\n");
        printf("2. Beri makan lohan\n");
        printf("3. Beri makan Kepiting\n");
        printf("pilih salah satu : "); scanf("%d", &choose);

        if(choose == 1)
        {
        printf("Status saat ini :\n");
        printf("Lohan : %d\n", lohan);
        printf("kepiting : %d\n" kepiting);
        } else
            if (choose == 2)
            {
                lohan = lohan + 10;
            } else
                if (choose == 3)
                {
                    kepiting = kepiting + 10;
                } else 
                    {
                        printf ("Input salah\n");
                        menu();
                    }
        status = 1;
    }
}