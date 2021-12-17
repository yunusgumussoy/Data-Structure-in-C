#include <stdio.h>
#include <stdlib.h>
struct n{
    int x;
    n * next;
};
typedef n node;

void bastir(node*r){// r sabit bir deðer deðil, hareketli
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
node* ekleSirali(node*r,int x){ // listeye sýralý ekleme yapmak için 
	if(r==NULL){//baðlý liste boþsa
		r=(node*)malloc(sizeof(node));//kutu yap içine deðer koy
		r->next=NULL;
		r->x=x;
		return r;
	}
	if(r->x > x){//liste boþ deðil ve yeni eleman ilk elemandan küçükse durumu
	//root deðiþiyor yeni kutu yapýyor artýk root bu yeni kutu oluyor
			node * temp=(node*)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
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
