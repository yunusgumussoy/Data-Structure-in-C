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
    root->x=500; //ilk düðüm, bundan sonrakiler bunun sonuna eklenecek
    int i=0;
	for (i=0;i<5;i++){
		ekle(root,i*10);
		/*iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		iter->x = i*10;// 0,10,20,30,40
		iter->next=NULL; //sona gelmeden durmak için
		// eðer iter NULL ý gösterirse sona geldiðinden ekleme yapamayýz 
		*/
	}
	bastir(root);
	
}
