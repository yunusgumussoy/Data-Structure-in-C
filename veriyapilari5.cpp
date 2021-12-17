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
	bastir(root); //buraya kadar d�ng�m�z 500,0,10,20,30,40
	//20 ile 30 aras�na 100 eklemek i�in a�a��dakileri yap�yoruz;
	node * iter=root; // root u g�steren yeni bir d���m
	for(i=0;i<3;i++)
	iter=iter->next;
	node * temp=(node*)malloc(sizeof(node)); //100 de�erini verece�imiz yeni d���m
	temp->next=iter->next; //bu ba�lant�y� kurmazsak dizi k�r�l�r 
	iter->next=temp;//dizinin aras�na d���m ekliyoruz
	temp->x=100;//100 de�eri verdi�imiz d���m
	bastir(root); // �imdi 500,0,10,20,100,30,40
}
