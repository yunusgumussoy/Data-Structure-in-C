#include <stdio.h>
#include <stdlib.h>
#include "stackll.h"
void bastir(node * root){
	while(root!=NULL){
		printf("%d ->", root->data);
		root = root ->next;
	}
}
int pop(node *root){
	if(root==NULL){
		printf("stack bos");
		return -1;
	}
	if(root->next==NULL){
		int rvalue=root->data;
		free(root);
		return rvalue;
	}
	node * iter = root;
	while (iter->next->next != NULL)
		iter = iter->next;
	node * temp = iter->next;
	int rvalue = temp ->data;//temp in tuttuðu veriyi baþka bi deðiþkene baðladýk
	iter->next=NULL;
	free(temp);//kutuyu ram den sildik
	return rvalue;
}
node* push(node * root, int a){
	if(root == NULL){
		root=(node*) malloc (sizeof(node));
		root -> data = a;
		root -> next = NULL;
		return root;
	}
	node * iter = root;
	while(iter->next!=NULL)
		iter = iter -> next;
	node * temp = (node*) malloc (sizeof(node));
	temp -> data=a;
	temp -> next=NULL;
	iter -> next=temp;
	return root;
}
int main(){
	node * s=NULL;
	s = push(s,10);
	s = push(s,20);
	printf("%d -> ",pop(s));
	//bastir(s);
	//fflush(stdout);//
	//perror("gecti");//kodun buraya kadar gelip gelmediðini anlamak için debugging kodu
	s = push(s,30);
	printf("%d -> ",pop(s));
	printf("%d -> ",pop(s));
}
