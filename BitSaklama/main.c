#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

    int N;
    srand(time(NULL));
    N=5+rand()%5;

    int i;
    int dizi[N];

    printf("Uretilen sayi : ");
    for(i=0; i<N; i++)
    {
        int rastgele;
        rastgele=rand()%2;
        dizi[i]=rastgele;
        printf("%d",rastgele);
    }

    int hak=0;
    int eslesme=0,komple_esit=1;
    while(hak<10)
    {
    printf("\nkalan hakkiniz :%d\n",(10-hak));
    int tahmin;
    printf("\nTahmininiz :  ");
    scanf("%d",&tahmin);

    int x,y;
    int dizi2[10];
    int sayac=0;

    if(tahmin<=0)
    {
        return tahmin;
    }
    while(tahmin>0)
    {
        x=tahmin%2;
        // printf("*** %d\n",x);
        dizi2[sayac]=x;
        sayac++;
        tahmin=tahmin-x;
        tahmin=tahmin/2;
    }
    //printf("sayac = %d\n",sayac);
    int duz_dizi[sayac];
    int b=0;

    for(i=(sayac-1); i>=0; i--)
    {
        duz_dizi[b]=dizi2[i];
        //printf("%d",duz_dizi[b]);
        b++;
    }

    int yeni_sayac;
    if(N<sayac)
    {
        yeni_sayac=N;
    }
    else
    {
        yeni_sayac=sayac;
    }


    for(i=0; i<yeni_sayac; i++)
    {
        if(duz_dizi[i]==dizi[i])
        {
            if(duz_dizi[i]==1)
                eslesme++;
                komple_esit++;
        }
    }
    if(N==sayac || sayac==komple_esit)
    {
        printf("\nTebrikler,dogru tahminde bulundunuz\n");
        break;
    }
    else
        {
            printf("eslesme %d",eslesme);
    hak++;
        }

    }





    return 0;
}
