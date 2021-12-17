#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n * sol;
	n * sag;
};

typedef n node;
node * ekle (node *agac, int x){
	if(agac==NULL){
		node *root=(node*)malloc(sizeof(node));
		root->sol=NULL;
		root->sag=NULL;
		root->data=x;
		return root;
	}
	/*node * iter = agac;//1.yöntem
	if(iter->data<x){
		if(iter->sag!=NULL)
			return ekle(agac->sag,x);
		if(iter->sol!=NULL)	
			ekle(agac->sol,x);
	}*/
	if(agac->data<x){//2.yöntem yazým
		agac->sag=ekle(agac->sag,x);
		return agac;
	}
	agac->sol=ekle(agac->sol,x);
	return agac;
}
/*void dolas(node *agac){//Left-Node-Right(LNR) Küçükten büyüðe sýralama için
	if(agac==NULL)
		return;
	dolas(agac->sol);
	printf("%d ",agac->data);
	dolas(agac->sag);
}
*/
void dolas(node *agac){//Right-Node-Left(RNL) Büyükten Küçüðe sýralama için
	if(agac==NULL)
		return;
	dolas(agac->sag);
	printf("%d ",agac->data);
	dolas(agac->sol);
}
int main(){
	node * agac=NULL;
	agac=ekle(agac,12);
	agac=ekle(agac,200);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,56);
	agac=ekle(agac,24);
	agac=ekle(agac,18);
	agac=ekle(agac,27);
	agac=ekle(agac,28);
	dolas(agac);
}
