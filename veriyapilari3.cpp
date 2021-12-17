#include <stdio.h>
#include <stdlib.h>
struct n{
    int x;
    n * next;
};
typedef n node;

void bastir(node*r){ // bastirma kodu, art�k tek tek printf yazmak zorunda de�iliz
	while(r!=NULL){
		printf("\n%d",r->x);
		r=r->next;
	}
}

int main(){
    node * root;
    root= (node*)malloc(sizeof(node));
    root->x=10;
    root->next=(node *)malloc (sizeof(node));
    root->next->x=20;
    root->next->next=(node*)malloc(sizeof(node));
    root->next->next->x=30;
    root->next->next->next = NULL;//d�ng�n�n sonu
    node * iter;
    iter=root;
    printf("%d", iter->x);
    iter=iter->next;
    printf("%d", iter->x);
    iter=iter->next;
    printf("%d", iter->x);
    iter=root;
    int i=0;
    while (iter->next!=NULL){ //d�ng�n�n sona gelmeden
    i++;
    	printf("\n%dinci eleman : %d \n",i,iter->x);
    	iter=iter->next; //burada 3.eleman� yani son eleman� yazd�rmayacak
    	//��nk� son elemana gelirse liste biter 
	}
	for (i=0;i<5;i++){
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		iter->x = i*10;
		iter->next=NULL;
	}
	bastir(root);//yukarda ekledi�imiz bastir d�ng�s�
	
}
