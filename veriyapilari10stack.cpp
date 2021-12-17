#include <stdio.h>
#include <stdlib.h>
#include "veriyapilaristack.h"
//Stack array
//int dizi[2];// 2 elemanlý dizi- statik kullaným ama bize dinamik lazým
stack * tanim(){
	stack *s =(stack*)malloc(sizeof(stack));
	s->dizi=NULL;//diziyi dinamik kullanmak için
	s->boyut=2;
	s->tepe=0;
	return s;
}
int pop(stack *s){//diziden deðer çýkarmak için
	if(s->tepe<=0 || s->dizi==NULL){
		printf("dizi bos");
		return -1;
	}
	if(s->tepe<=s->boyut/4 && s->boyut>2){//diziden deðer çýkardýkça dizinin boyutunu küçültmek için
		int *dizi2=(int*)malloc(sizeof(int)*s->boyut/2);
		for(int i=0;i<s->tepe;i++)
			dizi2[i]=s->dizi[i];
		free(s->dizi);
		s->dizi=dizi2;
		s->boyut /=2;//boyutu yarýya düþürecek
	}
	return s->dizi[--s->tepe];
}
void push(int a,stack *s){//diziye deðer eklemek için
	if(s->dizi==NULL){
		s->dizi=(int*)malloc(sizeof(int)*2);
	}
	if(s->tepe>=s->boyut-1){//iki deðer koyduktan sonra dizi dolduðu için yeni dizi oluþturuyoruz
		int *dizi2=(int*)malloc(sizeof(int)*s->boyut*2);//dizi doldukca boyutunu 2 katý artýracak
		for(int i=0;i<s->boyut;i++)//yeni oluþturduðumuz diziye ilk dizinin deðerlerini veriyoruz
			dizi2[i]=s->dizi[i];
		int * temp=s->dizi;
		s->dizi=dizi2;//dizi doldu dizi2 oluþturuldu, dizi2, dizi nin yerini aldý
		//int dizi2[boyut*2];//dizi tanýmýnda deðiþken kullanamayacaðýmýz için yukarda pointer ile kullanacaðýz
		free(temp);//eski dizinin içeriðini temizlemek için
		s->boyut*=2;//boyutu 2 katýna çýkarýyor
	}
	s->dizi[s->tepe++]=a;
}
void bastir(stack *s){
	printf("\nboyut: %d ",s->boyut);
	for(int i=0;i<s->tepe;i++){
		printf("\n%d",s->dizi[i]);
	}
}

