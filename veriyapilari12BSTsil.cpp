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
	/*node * iter = agac;//1.y?ntem
	if(iter->data<x){
		if(iter->sag!=NULL)
			return ekle(agac->sag,x);
		if(iter->sol!=NULL)	
			ekle(agac->sol,x);
	}*/
	if(agac->data<x){//2.y?ntem yaz?m
		agac->sag=ekle(agac->sag,x);
		return agac;
	}
	agac->sol=ekle(agac->sol,x);
	return agac;
}
/*void dolas(node *agac){//Left-Node-Right(LNR) K???kten b?y??e s?ralama i?in
	if(agac==NULL)
		return;
	dolas(agac->sol);
	printf("%d ",agac->data);
	dolas(agac->sag);
}
*/
void dolas(node *agac){//Right-Node-Left(RNL) B?y?kten K????e s?ralama i?in
	if(agac==NULL)
		return;
	dolas(agac->sag);
	printf("%d ",agac->data);
	dolas(agac->sol);
}

int bul (node * agac,int aranan){
	if(agac==NULL)
		return -1;
	if(agac->data==aranan)
		return 1;
	if(bul(agac->sag,aranan)==1)
		return 1;
	if(bul(agac->sol,aranan)==1)
		return 1;
	return -1;
}
int max(node *agac){
	while(agac->sag!=NULL)
		agac=agac->sag;
	return agac->data;
}

int min(node *agac){
	while(agac->sol!=NULL)
		agac=agac->sol;
	return agac->data;
}

node * sil(node *agac, int x){
	if(agac==NULL)
		return NULL;
	if(agac->data==x){
		if(agac->sol==NULL && agac->sag==NULL)
			return NULL;
		if(agac->sag!=NULL){
			agac->data=min(agac->sag);
			agac->sag=sil(agac->sag,min(agac->sag));
			return agac;
		}
		agac->data=max(agac->sol);
		agac->sol=sil(agac->sol,min(agac->sol));
		return agac;		
	}
	if(agac->data<x){
		agac->sag=sil(agac->sag,x);
		return agac;
	}
	agac->sol=sil(agac->sol,x);
	return agac;
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
	printf("arama sonucu: %d",bul(agac,24));
	printf("arama sonucu: %d",bul(agac,100));
	printf("max= %d min= %d ",max(agac),min(agac));
	agac=sil(agac,190);
	dolas(agac);
}

