#include <stdio.h>
#include <stdlib.h>
#include "bkutuphane.h"

void bastir(node*r){// r sabit bir de�er de�il, hareketli
	node *iter=r; //dairesel ba�l� liste i�in 
	printf("%d", iter->x);//dairesel listede ilk de�eri kendimiz bast�rd�k
	iter=iter->next;
	while(iter!=r){
		printf("\n%d",iter->x);
		iter=iter->next;
	}
	printf("\n");
}

node* ekleSirali(node*r,int x){ // listeye s�ral� ekleme yapmak i�in 
	if(r==NULL){//ba�l� liste bo�sa
		r=(node*)malloc(sizeof(node));//kutu yap i�ine de�er koy
		r->next=NULL;//tek elemanl�, kendinden sonra yine kendini g�steriyor
		r->prev=NULL;
		r->x=x;
		return r;
	}
	if(r->x > x){//liste bo� de�il ve yeni eleman ilk elemandan k���kse durumu
	//root de�i�iyor yeni kutu yap�yor art�k root bu yeni kutu oluyor
			node * temp=(node*)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
			r->prev=temp;
			return temp;
	}
	node*iter=r;
	while(iter->next!=NULL && iter->next->x < x){//liste bo� de�ilse
	// ve yeni eleman son elemandan b�y�k oldu�u i�in ba�a de�il sona geldi�i s�rece
		iter=iter->next;
	}
	node*temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->prev=iter;
	if(temp->next!=NULL)//Null a giderse null �n prev i olmad���ndan d�nemeyiz
	temp->next->prev=temp;
	temp->x=x;
	return r;
	
	/*
	else if(r->next==NULL){ //r nin nexti null ise yani liste tek elemanl�ysa
	
		}
		else{
			node* temp=(node*)malloc(sizeof(node));
			temp->x=x;
			temp->next=NULL;
			r->next=temp;
			return r;
		}
	} */
}
node * sil(node *r, int x){//silme d�ng�s�
	node*temp;
	node*iter=r;
	if(r->x==x){
		while(iter->next!=r){
			iter=iter->next;
		}
		iter->next=r->next;
		free(r);//silme komutu
		return iter->next;
	}
	while(iter->next!=NULL && iter->next->x!=x){
		iter=iter->next;
	}
	if(iter->next==NULL){
		printf("sayi bulunamadi\n");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	if(iter->next!=NULL)
	iter->next->prev=iter;//sildi�imiz de�erden d�nerken sorun olmamas� i�in
	return r;
}

