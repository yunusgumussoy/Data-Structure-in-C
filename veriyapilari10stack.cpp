#include <stdio.h>
#include <stdlib.h>
#include "veriyapilaristack.h"
//Stack array
//int dizi[2];// 2 elemanl� dizi- statik kullan�m ama bize dinamik laz�m
stack * tanim(){
	stack *s =(stack*)malloc(sizeof(stack));
	s->dizi=NULL;//diziyi dinamik kullanmak i�in
	s->boyut=2;
	s->tepe=0;
	return s;
}
int pop(stack *s){//diziden de�er ��karmak i�in
	if(s->tepe<=0 || s->dizi==NULL){
		printf("dizi bos");
		return -1;
	}
	if(s->tepe<=s->boyut/4 && s->boyut>2){//diziden de�er ��kard�k�a dizinin boyutunu k���ltmek i�in
		int *dizi2=(int*)malloc(sizeof(int)*s->boyut/2);
		for(int i=0;i<s->tepe;i++)
			dizi2[i]=s->dizi[i];
		free(s->dizi);
		s->dizi=dizi2;
		s->boyut /=2;//boyutu yar�ya d���recek
	}
	return s->dizi[--s->tepe];
}
void push(int a,stack *s){//diziye de�er eklemek i�in
	if(s->dizi==NULL){
		s->dizi=(int*)malloc(sizeof(int)*2);
	}
	if(s->tepe>=s->boyut-1){//iki de�er koyduktan sonra dizi doldu�u i�in yeni dizi olu�turuyoruz
		int *dizi2=(int*)malloc(sizeof(int)*s->boyut*2);//dizi doldukca boyutunu 2 kat� art�racak
		for(int i=0;i<s->boyut;i++)//yeni olu�turdu�umuz diziye ilk dizinin de�erlerini veriyoruz
			dizi2[i]=s->dizi[i];
		int * temp=s->dizi;
		s->dizi=dizi2;//dizi doldu dizi2 olu�turuldu, dizi2, dizi nin yerini ald�
		//int dizi2[boyut*2];//dizi tan�m�nda de�i�ken kullanamayaca��m�z i�in yukarda pointer ile kullanaca��z
		free(temp);//eski dizinin i�eri�ini temizlemek i�in
		s->boyut*=2;//boyutu 2 kat�na ��kar�yor
	}
	s->dizi[s->tepe++]=a;
}
void bastir(stack *s){
	printf("\nboyut: %d ",s->boyut);
	for(int i=0;i<s->tepe;i++){
		printf("\n%d",s->dizi[i]);
	}
}

