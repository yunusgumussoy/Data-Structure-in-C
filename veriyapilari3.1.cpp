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

void ekle(node*r,int x){ //ekleme kodu, artýk tek tek düðüm eklemek zorunda deðiliz
	while(r->next!=NULL){ //liste sona gelmeden ekleme yapmak için
		r=r->next;//liste sona gelinceye kadar ekleme yap
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;//listenin sonunda NULL olacak
}
int main(){
    node * root;
    root= (node*)malloc(sizeof(node));//ilk kutuyu manuel yazdýk
    root->next=NULL; // ilk kutunun sonrasý NULL
    root->x=500; //ilk düðüme root dedik ve deðeri 500 verdik
    int i=0;
    for (i=0;i<5;i++){
    	ekle(root,i*10); //yukarda yazdýðýmýz ekle döngüsü
    	// ekle döngüsü sayesinde aþaðýdaki kodlara gerek kalmadý
    	/*
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		iter->x = i*10;// 0,10,20,30,40
		iter->next=NULL; //sona gelmeden durmak için
		// eðer iter NULL ý gösterirse sona geldiðinden ekleme yapamayýz 
		*/
	}
	bastir(root);
	
}
