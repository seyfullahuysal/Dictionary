#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<string.h>

void sirala(char [][25],char[][25]);
void ara(int,char [][25],char [] [25]);
void dosya_olustur(char [][25],char[][25]);
char *tr_donus(char []);
void belgeleri_temizle();
void secenekler();
void bosluk();



int main()
{
	setlocale(LC_ALL,"Turkish");
	char turkce[100][25],ingilizce[100][25];
	dosya_olustur(turkce,ingilizce);
	secenekler();
	char sec;
	

	
	while(1)
	{
	bosluk();
	printf("Seçenek Giriniz = ");
	sec=getchar();
	switch(sec)
	{
		case '0':
			system("color 3a");
			ara(0,turkce,ingilizce);
			break;
		case '1':
			system("color 5f");
			ara(1,turkce,ingilizce);
			break;
		case '2':
			system("color 4a");
			dosya_olustur(turkce,ingilizce);
			bosluk();
			printf("!!! Dosyalar Baþarýyla Oluþturuldu !!!\n");
			break;
		case '3':
			system("color fc");
			belgeleri_temizle();
			break;
			
	}
	getch();
	system("cls");
	secenekler();
}

	
	
	
	getch();
	return 0;
}






void dosya_olustur(char turkce[][25],char ingilizce[][25])
{
	
	FILE *sozluk_d,*turkce_d,*ingilizce_d;
	int i=0;
	if((sozluk_d=fopen("sozluk.txt","r"))==NULL)
	{
		printf("! Sozluk.txt Dosyasina Erisilemedi !");
		exit(0);
	}

	else
	{
		
		if((turkce_d=fopen("turkce.txt","w+"))==NULL)
		{
			printf("! turkce.txt Dosyasina Erisilemedi !");
			exit(0);
		}
		
		if((ingilizce_d=fopen("ingilizce.txt","w+"))==NULL)
		{
			printf("! ingilizce.txt Dosyasina Erisilemedi !");
			exit(0);
		}

		while(!feof(sozluk_d))
		{
			fscanf(sozluk_d,"%s%s",turkce[i],ingilizce[i]);
			i++;
			
		}
	
			sirala(turkce,ingilizce);
	}
		
	
	
	for(i=0;i<100;i++)
	{	
			fprintf(turkce_d,"%-25s\n",turkce[i]);
	}
	
		
	for(i=0;i<100;i++)
	{
			fprintf(ingilizce_d,"%-25s\n",ingilizce[i]);	
	}	
	
	
	
	
	fclose(sozluk_d);
	fclose(turkce_d);
	fclose(ingilizce_d);
	
	
	
	
}

void sirala(char turkce[][25],char ingilizce[][25])
{
	
		char gecici[25],gecici2[25];

		int i,j;
		for(i=0;i<100;i++)
		{
			for(j=i+1;j<99;j++)
			{
				strcpy(gecici,turkce[i]);
				strcpy(gecici2,turkce[j+1]);
				if(strcmp(tr_donus(gecici),tr_donus(gecici2))>0)
				{
					strcpy(gecici,turkce[i]);
					strcpy(turkce[i],turkce[j+1]);
					strcpy(turkce[j+1],gecici);
					
					
					
					strcpy(gecici,ingilizce[i]);
					strcpy(ingilizce[i],ingilizce[j+1]);
					strcpy(ingilizce[j+1],gecici);

					
				}
			}
		
		}
	
			
	
	
	
}

void ara(int yon,char turkce[][25],char ingilizce[][25])
{
	

	
	char kelime1[25],gecici[25];
	bosluk();
	printf("Aranak Kelimeyi Giriniz = ");
	scanf("%s",kelime1);
	
	int i,durum=0;
	
	if(yon==0)
	{
		for(i=0;i<=99;i++)
		{
			strcpy(gecici,turkce[i]);
			if(strcmp(tr_donus(gecici),tr_donus(kelime1))==0)
			{
				bosluk();
				printf("Aranan Kelime %d. Satýrda Bulunan %s 'dýr\n",i+1,ingilizce[i]);
				durum=1;
			}
			
			
		}
		
		
	}
	
	
	
	if(yon==1)
	{
		for(i=0;i<=99;i++)
		{
			
			if(strcmp(kelime1,ingilizce[i])==0)
			{
				bosluk();
				printf("Aranan Kelime %d. Satýrda Bulunan %s 'dýr\n",i+1,turkce[i]);
				durum=1;
			}
			
			
			
		}
	
		
	}
	
if(durum==0)
	{
		bosluk();
		printf("Aranan Kelime Bulunamadi");
	}
	
	
	
	
}
	
char *tr_donus(char a[])
{
	int i,j;
	int  c=strlen(a);
    char karakterler[]={'ç','ð','ý','ö','þ','ü',-121,-89,-115,-108,-97,-127};
    for (i=0;i<c;i++)
    {
    	for (j=0;j<12;j++)
            if (a[i]==karakterler[j])
            {
            	switch (a[i]) {
                    case 'ç': 
						 a[i]='c'; break;
                    case 'ð':
						 a[i]='g'; break;
                    case 'ý':
						 a[i]='i'; break;
                    case 'ö':
						 a[i]='o'; break;
                    case 'þ':
						 a[i]='s'; break;
                    case 'ü':
						 a[i]='u'; break;
					case -121: 
						 a[i]='c'; break;
                    case -89:
						 a[i]='g'; break;
                    case -115:
						 a[i]='i'; break;
                    case -108:
						 a[i]='o'; break;
                    case -97:
						 a[i]='s'; break;
                    case -127:
						 a[i]='u'; break;
                }
                
            }
                
    }
        return a;
}

void belgeleri_temizle()
{
	
	FILE *turkce,*ingilizce;
	turkce=fopen("turkce.txt","w");
	ingilizce=fopen("ingilizce.txt","w");
	fclose(turkce);
	fclose(ingilizce);
	bosluk();
	printf("!!! Dosyalar Baþarýyla Temizlendi !!!\n");
	
}

void secenekler()
{  	
	system("color 1F");
	printf("\n\n\n");
	bosluk();                    
	printf("                ANA MENÜ         \n");
	bosluk();
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n\n");
	bosluk();
	printf(" ( 0 )   Türkçe      --->   Ýngilizce\n\n");
	bosluk();
	printf(" ( 1 )   Ýngilizce   --->   Türkçe\n\n");
	bosluk();
	printf(" ( 2 )   Dosyalarý Oluþtur\n\n");
	bosluk();
	printf(" ( 3 )   Dosyalarý Temizle \n\n\n\n");
	bosluk();
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n\n");
	
	
}

void bosluk()
{
	int i;
	for(i=1;i<=20;i++)
	{
		printf(" ");

	}	
}	














