#include <stdio.h>
#include <stdlib.h>
#include "bkutuphane.h"

void bastir(node*r){// r sabit bir deðer deðil, hareketli
	node *iter=r; //dairesel baðlý liste için 
	printf("%d", iter->x);//dairesel listede ilk deðeri kendimiz bastýrdýk
	iter=iter->next;
	while(iter!=r){
		printf("\n%d",iter->x);
		iter=iter->next;
	}
	printf("\n");
}

node* ekleSirali(node*r,int x){ // listeye sýralý ekleme yapmak için 
	if(r==NULL){//baðlý liste boþsa
		r=(node*)malloc(sizeof(node));//kutu yap içine deðer koy
		r->next=NULL;//tek elemanlý, kendinden sonra yine kendini gösteriyor
		r->prev=NULL;
		r->x=x;
		return r;
	}
	if(r->x > x){//liste boþ deðil ve yeni eleman ilk elemandan küçükse durumu
	//root deðiþiyor yeni kutu yapýyor artýk root bu yeni kutu oluyor
			node * temp=(node*)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
			r->prev=temp;
			return temp;
	}
	node*iter=r;
	while(iter->next!=NULL && iter->next->x < x){//liste boþ deðilse
	// ve yeni eleman son elemandan büyük olduðu için baþa deðil sona geldiði sürece
		iter=iter->next;
	}
	node*temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->prev=iter;
	if(temp->next!=NULL)//Null a giderse null ýn prev i olmadýðýndan dönemeyiz
	temp->next->prev=temp;
	temp->x=x;
	return r;
	
	/*
	else if(r->next==NULL){ //r nin nexti null ise yani liste tek elemanlýysa
	
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
node * sil(node *r, int x){//silme döngüsü
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
	iter->next->prev=iter;//sildiðimiz deðerden dönerken sorun olmamasý için
	return r;
}

