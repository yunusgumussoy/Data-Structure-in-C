#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    n * next;
};
typedef n node;

int main(){
    node * root;
    root= (node*)malloc(sizeof(node));
    root->x=10;
    root->next=(node *)malloc (sizeof(node));
    root->next->x=20;
    root->next->next=(node*)malloc(sizeof(node));
    root->next->next->x=30;
    root->next->next->next = NULL;//döngünün sonu
    node * iter;
    iter=root;
    printf("%d", iter->x);
    iter=iter->next;
    printf("%d", iter->x);
    iter=iter->next;
    printf("%d", iter->x);
    iter=root;
    int i=0;
    while (iter!=NULL){ //döngünün sona geldiðini gösterir
    i++;
    	printf("\n%dinci eleman : %d \n",i,iter->x);
    	iter=iter->next;
	}
}
