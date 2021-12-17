#include <stdio.h>
#include <stdlib.h>
int *dizi=NULL;
int sira=0,sirabasi=0,boyut=2;
int deque(){//s�ran�n ba��ndan ba�layarak siler
	if(sira==sirabasi){
		printf("\nsira bos");
		return -1;
	}
	if(sira-sirabasi<=boyut/4){//sira-sirabasi ifadesi bize s�radaki eleman say�s�n� verir
		int * dizi2=(int*)malloc(sizeof(int)*boyut/2);
		for(int i=0;i<sira-sirabasi;i++){
			dizi2[i]=dizi[sirabasi+i];
		}
		sira-=sirabasi;
		sirabasi=0;
		free(dizi);
		boyut /=2;
		dizi=dizi2;
	}
	return dizi[sirabasi++];
}
void toparla(){//s�ran�n ba��ndan silinen de�erler yerine s�radaki de�erleri s�rayla kayd�r�r
	if(sirabasi==0)
		return ;
	for(int i=0;i<boyut;i++){
		dizi[i]=dizi[i+sirabasi];
	}
	sira -=sirabasi;//s�raba�� ne kadar kayd�ysa s�ra da kayacak
	sirabasi=0;
}
void enque(int a){//s�raya kald��� yerden de�er ekler
	if(dizi==NULL){
		dizi=(int*)malloc(sizeof(int)*2);
	}
	if(sira >= boyut){
		boyut *=2;
		int *dizi2 = (int *)malloc(sizeof(int)*boyut);
		for(int i=0;i<boyut/2;i++)
			dizi2[i]=dizi[i];
		free(dizi);
		dizi=dizi2;
	}
	dizi[sira++]=a;
}
int main(){
	for(int i=0;i<20;i++){
		enque(i*10);
	}
	printf("\ndurum: boyut: %d sira: %d sirabasi: %d",boyut,sira,sirabasi);
	for(int i=0;i<13;i++){
		printf("\n%d",deque());
	}
	toparla();
	printf("\ndurum: boyut: %d sira: %d sirabasi: %d",boyut,sira,sirabasi);
	for(int i=0;i<20;i++){
		enque(i*10);
	}
	printf("\ndurum: boyut: %d sira: %d sirabasi: %d",boyut,sira,sirabasi);
	for(int i=0;i<30;i++){
		printf("\n%d",deque());
	}
	printf("\ndurum: boyut: %d sira: %d sirabasi: %d",boyut,sira,sirabasi);	
}
