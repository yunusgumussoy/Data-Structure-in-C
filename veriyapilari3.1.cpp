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

void ekle(node*r,int x){ //ekleme kodu, art�k tek tek d���m eklemek zorunda de�iliz
	while(r->next!=NULL){ //liste sona gelmeden ekleme yapmak i�in
		r=r->next;//liste sona gelinceye kadar ekleme yap
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;//listenin sonunda NULL olacak
}
int main(){
    node * root;
    root= (node*)malloc(sizeof(node));//ilk kutuyu manuel yazd�k
    root->next=NULL; // ilk kutunun sonras� NULL
    root->x=500; //ilk d���me root dedik ve de�eri 500 verdik
    int i=0;
    for (i=0;i<5;i++){
    	ekle(root,i*10); //yukarda yazd���m�z ekle d�ng�s�
    	// ekle d�ng�s� sayesinde a�a��daki kodlara gerek kalmad�
    	/*
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		iter->x = i*10;// 0,10,20,30,40
		iter->next=NULL; //sona gelmeden durmak i�in
		// e�er iter NULL � g�sterirse sona geldi�inden ekleme yapamay�z 
		*/
	}
	bastir(root);
	
}
