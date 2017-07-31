#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

FILE * dosya;
struct para
{
    char cins[15];
    int miktar
};

struct musteriler
{
    char ad[15];
    char soyad[15];
    int hesap_no;
    int sifre;
    struct para money;
} musteri;

void sifre_degistir();
void para_yatirma();
void para_cekme();
void hesap_ozeti();
void kayit_ekle();
void giris_yap();
void sil();

int main()
{

    char menu();//fonksiyonlar tanýmlanýyor
    printf("Yapmak Istediginiz Islemi Seciniz \n");
    int dogrumu=0,sayac=0;

    char secim;
    char secim2;
    // do
    //{
    secim=menu();
    switch(secim)
    {
    case '1':
        kayit_ekle();
        break;

    case '2':

        printf("Sifrenizi Giriniz :   ");
        int girilen;
        scanf("%d",&girilen);
        dosya=fopen("musteri.txt","r");

        while(!feof(dosya))
        {
            fscanf(dosya,"%s %s %d %d",musteri.ad,musteri.soyad,&musteri.hesap_no,&musteri.sifre);
            if(musteri.sifre==girilen)
            {
                dogrumu=1;
                printf("Giris Basarili\n");
            }
        }
        fclose(dosya);
        while(dogrumu==1)
        {
            system("CLS");
            printf("Yapmak Istediginiz Islemi Seciniz : \n");
            printf("A-Sifre Degistir\nB-Para Yatirma\nC-Para Cekme\nD-Cikis\n\n");
            scanf("%c",&secim2);

            if(secim2=='A')
            {
                system("CLS");
                sifre_degistir();
                dogrumu=0;
            }
            if(secim2=='B')
            {
                system("CLS");
                para_yatirma(musteri);
            }
            if(secim2=='C')
            {
                system("CLS");
            }
            if(secim2=='D')
            {
                break;
            }
        }
        dogrumu=1;
        //YANLIÞ ÞÝFRE
        if(dogrumu==0)
        {
            printf("Yanlis Sifre! Tekrar Giris Yapiniz\n");
            printf("Sifrenizi Giriniz :   ");
            scanf("%d",&girilen);
            while(!feof(dosya))
            {
                fscanf(dosya,"%s %s %d %d",musteri.ad,musteri.soyad,&musteri.hesap_no,&musteri.sifre);
                if(musteri.sifre==girilen)
                {
                    dogrumu=1;

                }
            }
            if(dogrumu==1)
            {
                printf("Giris Basarili\n");
            }
            if(dogrumu==0)
            {
                printf("Yanlis Sifre! Tekrar Giris Yapiniz\n");
                printf("Sifrenizi Giriniz :   ");
                scanf("%d",&girilen);
                while(!feof(dosya))
                {
                    fscanf(dosya,"%s %s %d %d",musteri.ad,musteri.soyad,&musteri.hesap_no,&musteri.sifre);
                    if(musteri.sifre==girilen)
                    {
                        dogrumu=1;

                    }
                }
                if(dogrumu==1)
                {
                    printf("Giris Basarili\n");
                }
                if(dogrumu==0)
                {
                    printf("Hesabiniz Bloke Olmustur\n");
                }
            }

        }
        break;
    }

    fclose(dosya);



    //}
    // while(secim<='2' && secim>='1');


    return 0;
}



char menu()
{
    char tus;
    printf("1-Yeni Hesap\n2-Sifre Ile Giris\n\n");
    tus=getch();
    return tus;
}
void kayit_ekle()
{
    dosya=fopen("musteri.txt","a+");
    int rastgele_sifre=0,rastgele_hesap=0;
    char ad[15];
    char soyad[15];
    printf("Ad    : ");
    scanf("%s",ad);
    printf("Soyad : ");
    scanf("%s",soyad);
    //system("CLS");
    srand(time(NULL));
    rastgele_sifre=1000+rand()%9999;
    rastgele_hesap=1000+rand()%9999;
    strcpy(musteri.ad, ad );
    strcpy(musteri.soyad, soyad );
    musteri.hesap_no=rastgele_hesap;
    musteri.sifre=rastgele_sifre;
    printf("Gecici Hesap Numaraniz : %d\n",musteri.hesap_no);
    printf("Gecici Hesap Sifreniz  : %d\n",musteri.sifre);
    fprintf(dosya,"%s %s %d %d\n",musteri.ad,musteri.soyad,musteri.hesap_no,musteri.sifre);
    fclose(dosya);
}



void sifre_degistir()
{
    int aranan,yeni_sifre,hesap_no,sifre,bulundu=0,satir=0,sayac=0;
    char ad[15];
    char soyad[15];
    char ch;


    printf("Sifrenizi girin :  ");
    scanf("%d",&aranan);

    dosya=fopen("musteri.txt","r");

    while(!feof(dosya))
    {
        ch=getc(dosya);
        if(ch=='\n')
        {
            satir++;
        }
    }

    struct musteriler dizi[satir];

    fclose(dosya);
    dosya=fopen("musteri.txt","r");



    while(!feof(dosya))
    {
        fscanf(dosya,"%s %s %d %d",ad,soyad,&hesap_no,&sifre);
        if(sifre==aranan)
        {
            bulundu=1;
            printf("Yeni Sifrenizi Giriniz \n");
            scanf("%d",&yeni_sifre);
            sifre=yeni_sifre;
            printf("YENI SIFRE %d \n",sifre);
            dizi[sayac].sifre=sifre;
        }
        else
        {
            dizi[sayac].sifre=sifre;
        }
        strcpy(dizi[sayac].ad,ad);
        strcpy(dizi[sayac].soyad,soyad);
        dizi[sayac].hesap_no=hesap_no;
        sayac++;
        //printf("%d sayac\n",sayac);
    }
    sayac--;

    int i=0;
   /* for(i=0;i<(sayac);i++)
    {
        printf("%s \n",dizi[i].ad);
        printf("%s \n",dizi[i].soyad);
        printf("%d \n",dizi[i].sifre);
    }
*/
    if(bulundu==0)
    {
        printf("Kayit Bulunamadi!\n");
    }
    fclose(dosya);
    sil();

    dosya=fopen("musteri.txt","w");

    for(i=0;i<(sayac);i++)
    {
        fprintf(dosya,"%s %s %d %d \n",dizi[i].ad,dizi[i].soyad,dizi[i].hesap_no,dizi[i].sifre);
    }
    fclose(dosya);

}

void sil()
{

    int ret;
    ret=remove("musteri.txt");
    {
        if(ret==0)
        printf("dosya silindi \n");
    }
}

void para_yatirma(struct musteri *a)
{
    char ad[15];
    char soyad[15];
    int hesap_no;
    int sifre;
    int toplam_para=0;

    dosya=fopen("musteri.txt","r");

    int miktar;
    printf("Yatirmak istediginiz miktari giriniz : ");
    scanf("&d",&miktar);

    toplam_para+=miktar;

    while(!feof(dosya))
    {
        fscanf(dosya,"%s %s %d %d",musteri.ad,musteri.soyad,&musteri.hesap_no,&musteri.sifre);
        if(musteri.sifre==sifre)
        {
            fprintf(dosya,"%s %s %d %d %d\n",musteri.ad,musteri.soyad,musteri.hesap_no,musteri.sifre,toplam_para);
        }
        else
        {
        }

    }
}



