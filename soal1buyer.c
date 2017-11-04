#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main()
{
    key_t key = 1234;
    int *jumlah;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    jumlah = shmat(shmid, NULL, 0);
    
    int input;
    char namasenjata[20];
    const char* nama[] = {"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};
    
    printf("Menu:\n 1. Lihat stok senjata\n 2. Beli senjata\n");
    scanf("%d", &input);
    
    while(1)
    {
        if(input==1) 
        {
            int i;
        	for (i=0;i<6;i++) 
            {
                printf("%s %d\n", nama[i],jumlah[i]);
            }
        } else
            if(input==2)
            {
                printf("Barang yang dapat dibeli yaitu:\n");
				printf("MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, dan MINE\n");
				printf("Format input: Produk Item yang ingin dibeli\n");
				int value;
				scanf("%s%d", namasenjata, &value);
				
                if (strcmp(namasenjata,"MP4A1")==0) 
                {
				    if (jumlah[0]-value<0) 
                    {
                       printf("Anda membeli %d %s. Stok tidak cukup. Stok yang tersedia adalah %d\n", value,namasenjata,jumlah[0]);
                    } else 
                        {
						  jumlah[0]-=value;
						  printf("Anda membeli %d %s. Stok barang menjadi %d.\n", value, namasenjata,jumlah[0]);
                        }
				} else
                    if (strcmp(namasenjata,"PM2-V1")==0)
                    {
					    if (jumlah[1]-value<0) printf("Anda membeli %d %s. Stok tidak cukup. Stok yang tersedia adalah %d\n", value,namasenjata,jumlah[1]);
					else {
						jumlah[1]-=value;
						printf("Anda membeli %d %s. Stok barang menjadi %d.\n", value, namasenjata,jumlah[1]);
					}
				}
				else if (strcmp(namasenjata,"SPR-3")==0) {
					if (jumlah[2]-value<0) printf("Anda membeli %d %s. Stok tidak cukup. Stok yang tersedia adalah %d\n", value,namasenjata,jumlah[2]);
					else {
						jumlah[2]-=value;
						printf("Anda membeli %d %s. Stok barang menjadi %d.\n", value, namasenjata,jumlah[2]);
					}
				}
				else if (strcmp(namasenjata,"SS2-V5")==0) {
					if (jumlah[3]-value<0) printf("Anda membeli %d %s. Stok tidak cukup. Stok yang tersedia adalah %d\n", value,namasenjata,jumlah[3]);
					else {
						jumlah[3]-=value;
						printf("Anda membeli %d %s. Stok barang menjadi %d.\n", value, namasenjata,jumlah[3]);
					}
				}
				else if (strcmp(namasenjata,"SPG1-V3")==0) {
					if (jumlah[4]-value<0) printf("Anda membeli %d %s. Stok tidak cukup. Stok yang tersedia adalah %d\n", value,namasenjata,jumlah[4]);
					else {
						jumlah[4]-=value;
						printf("Anda membeli %d %s. Stok barang menjadi %d.\n", value, namasenjata,jumlah[4]);
					}
				}
				else if (strcmp(namasenjata,"MINE")==0) {
					if (jumlah[5]-value<0) printf("Anda membeli %d %s. Stok tidak cukup. Stok yang tersedia adalah %d\n", value,namasenjata,jumlah[5]);
					else {
						jumlah[5]-=value;
						printf("Anda membeli %d %s. Stok barang menjadi %d.\n", value, namasenjata,jumlah[5]);
					}
				}
			}
			printf("Menu:\n 1. Lihat stok senjata\n 2. Beli senjata\n");
			scanf("%d", &input);
		}
 
    shmdt(jumlah);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}