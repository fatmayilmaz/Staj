#include <stdio.h>
#include <stdlib.h>

/**
    A kisisi icin -->1
    B kisisi icin -->2
    C kisisi icin -->3
    .
    .
    .
    seklinde kullanilmistir
*/

int temel_konusma(int a,int dedikodu[]);
void bilen();

int main()
{
    printf("Kisi Sayisini giriniz : ");
    int kisi,i;
    scanf("%d",&kisi);
    printf("%d tane konusma yapilmali \n",(2*kisi-4));
    int dedikodu[kisi];

    for (i=0; i<kisi; i++)
    {
        dedikodu[i]=0;
    }
    dedikodu[kisi]=kisi;

    if(kisi==2)
    {
        i=kisi;
        printf("%d - %d ile konustu\n",(i-1),i);

    }
    if(kisi==3)
    {
        i=kisi;
        printf("%d - %d ile konustu\n",i-2,i-1);
        printf("%d - %d ile konustu\n",(i-1),i);
        printf("%d - %d ile konustu\n",(i-2),i);
    }

    if(kisi==4)
    {
        temel_konusma(kisi,dedikodu);
    }

    if(kisi>4)
    {
        for(i=kisi; i>0; i--)
        {
            printf("%d - %d ile konustu   : ",i,((i-1)));
            dedikodu[i-1]=(i-1);
            bilen(dedikodu,1,kisi);
            printf("\n");
            if(i==5)
            {
                i--;
                temel_konusma(i,dedikodu);
                break;
            }
        }

        for(i=4; i<kisi; i++)
        {
            printf("%d - %d ile konustu   : ",i,(i+1));
            dedikodu[i+1]=i+1;
            bilen(dedikodu,1,kisi);
            printf("\n");
            if(kisi==i)
                break;
        }
    }

    return 0;
}

int temel_konusma(int i,int dedikodu[])
{
    dedikodu[i]=i;
    printf("%d - %d ile konustu   : ",i,(i-3));
    dedikodu[i-3]=i-3;
    bilen(dedikodu,i-3,i);
    printf("\n");
    printf("%d - %d ile konustu   : ",(i-1),(i-2));
    dedikodu[i-1]=i-1;
    dedikodu[i-2]=i-2;
    bilen(dedikodu,i-2,i-1);
    printf("\n");
    printf("%d - %d ile konustu   : ",i,(i-1));
    dedikodu[i-1]=i-1;
    bilen(dedikodu,i-3,i);
    printf("\n");
    printf("%d - %d ile konustu   : ",(i-3),(i-2));
    dedikodu[i-2]=i-2;
    bilen(dedikodu,i-3,i);
    printf("\n");
    return 0;
}

void bilen(int dizi[],int a,int kisi)
{
    while((kisi+1)!=a)
    {
        if(dizi[a]!=0)
            printf("%d  ",dizi[a]);
        a++;
    }
}
