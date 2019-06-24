#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define sonsuz 999

void dij(int dugumSayisi,int baslangicDugumu,int matris[20][20],int maliyet[])
{
    int i,u,sayac,w,bayrak[20],min;
    for(i=1; i<=dugumSayisi; i++)
        bayrak[i]=0,maliyet[i]=matris[baslangicDugumu][i];
    sayac=2;
    while(sayac<=dugumSayisi)
    {
        min=99;
        for(w=1; w<=dugumSayisi; w++)
            if(maliyet[w]<min && !bayrak[w])
                min=maliyet[w],u=w;
        bayrak[u]=1;
        sayac++;
        for(w=1; w<=dugumSayisi; w++)
            if((maliyet[u]+matris[u][w]<maliyet[w]) && !bayrak[w])
                maliyet[w]=maliyet[u]+matris[u][w];
    }
}

void main()
{
    int toplam=0,dugumSayisi,baslangicDugumu,i,j,matris[20][20],maliyet[20];
    //clrscr();
    printf("\n Dugum sayisini giriniz : ");
    scanf("%d",&dugumSayisi);
    printf("\n Komsuluk matrisini olusturunuz :\n");
    for(i=1; i<=dugumSayisi; i++)
        for(j=1; j<=dugumSayisi; j++)
        {
            scanf("%d",&matris[i][j]);
            if(matris[i][j]==0)
                matris[i][j]=sonsuz;
        }
    printf("\n Baslangic dugumu:");
    scanf("%d",&baslangicDugumu);
    dij(dugumSayisi,baslangicDugumu,matris,maliyet);
    printf("\n En kisa yol:\n");
    for(i=1; i<=dugumSayisi; i++)
        if(i!=baslangicDugumu)
        {
            printf("%d->%d,maliyet=%d\n",baslangicDugumu,i,maliyet[i]);
            toplam = toplam + maliyet[i];
        }
    printf("Toplam maliyet: %d ",toplam);
    getch();
}
