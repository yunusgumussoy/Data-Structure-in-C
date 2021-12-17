#include <stdio.h>
#include <stdlib.h>
struct n{
    int x;
    n * next;
};
typedef n node;

void bastir(node*r){// r sabit bir de�er de�il, hareketli
	while(r!=NULL){
		printf("\n%d",r->x);
		r=r->next;
	}
}

void ekle(node*r,int x){
	while(r->next!=NULL){
		r=r->next;
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;
}
node* ekleSirali(node*r,int x){ // listeye s�ral� ekleme yapmak i�in 
	if(r==NULL){//ba�l� liste bo�sa
		r=(node*)malloc(sizeof(node));//kutu yap i�ine de�er koy
		r->next=NULL;
		r->x=x;
		return r;
	}
	if(r->x > x){//liste bo� de�il ve yeni eleman ilk elemandan k���kse durumu
	//root de�i�iyor yeni kutu yap�yor art�k root bu yeni kutu oluyor
			node * temp=(node*)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
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

int main(){
    node * root;
    root= NULL;
    root=ekleSirali(root,400);
    root=ekleSirali(root,40);
    root=ekleSirali(root,4);
    root=ekleSirali(root,450);
    root=ekleSirali(root,50);
	bastir(root);
}
