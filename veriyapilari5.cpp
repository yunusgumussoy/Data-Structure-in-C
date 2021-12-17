#include <stdio.h>
#include <stdlib.h>
struct n{
    int x;
    n * next;
};
typedef n node;

void bastir(node*r){
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
int main(){
    node * root;
    root= (node*)malloc(sizeof(node));
    root->next=NULL;
    root->x=500;
    int i=0;
	for (i=0;i<5;i++){
		ekle(root,i*10);
	}
	bastir(root); //buraya kadar döngümüz 500,0,10,20,30,40
	//20 ile 30 arasýna 100 eklemek için aþaðýdakileri yapýyoruz;
	node * iter=root; // root u gösteren yeni bir düðüm
	for(i=0;i<3;i++)
	iter=iter->next;
	node * temp=(node*)malloc(sizeof(node)); //100 deðerini vereceðimiz yeni düðüm
	temp->next=iter->next; //bu baðlantýyý kurmazsak dizi kýrýlýr 
	iter->next=temp;//dizinin arasýna düðüm ekliyoruz
	temp->x=100;//100 deðeri verdiðimiz düðüm
	bastir(root); // þimdi 500,0,10,20,100,30,40
}
