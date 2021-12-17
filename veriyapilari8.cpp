#include <stdio.h>
#include <stdlib.h>
struct n{
    int x;
    n * next;
};
typedef n node;//dairesel ba�l� liste

void bastir(node*r){// r sabit bir de�er de�il, hareketli
	node *iter=r; //dairesel ba�l� liste i�in 
	printf("%d", iter->x);//dairesel listede ilk de�eri kendimiz bast�rd�k
	iter=iter->next;
	while(iter!=r){
		printf("\n%d",iter->x);
		iter=iter->next;
	}
	printf("\n");
}

void ekle(node*r,int x){
	node*iter=r;
	while(iter->next!=r){
		iter=iter->next;
	}
	iter->next=(node*)malloc(sizeof(node));
	iter->next->x=x;
	iter->next->next=r;
}
node* ekleSirali(node*r,int x){ // listeye s�ral� ekleme yapmak i�in 
	if(r==NULL){//ba�l� liste bo�sa
		r=(node*)malloc(sizeof(node));//kutu yap i�ine de�er koy
		r->next=r;//tek elemanl�, kendinden sonra yine kendini g�steriyor
		r->x=x;
		return r;
	}
	if(r->x > x){//liste bo� de�il ve yeni eleman ilk elemandan k���kse durumu
	//root de�i�iyor yeni kutu yap�yor art�k root bu yeni kutu oluyor
			node * temp=(node*)malloc(sizeof(node));
			temp->x=x;
			temp->next=r;
			node*iter=r;
			while (iter->next!=r)
				iter=iter->next;
				iter->next=temp;
			return temp;
	}
	node*iter=r;
	while(iter->next!=r && iter->next->x < x){//liste bo� de�ilse
	// ve yeni eleman son elemandan b�y�k oldu�u i�in ba�a de�il sona geldi�i s�rece
		iter=iter->next;
	}
	node*temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	return r;
	
	/*
	else if(r->next==NULL){ //r nin nexti null ise yani liste tek elemanl�ysa
	
		}
		else{
			node* temp=(node*)malloc(sizeof(node));
			temp->x=x;
			temp->next=NULL;
			r->next=temp;
			return r;
		}
	} */
}
node * sil(node *r, int x){//silme d�ng�s�
	node*temp;
	node*iter=r;
	if(r->x==x){
		while(iter->next!=r){
			iter=iter->next;
		}
		iter->next=r->next;
		free(r);//silme komutu
		return iter->next;
	}
	while(iter->next!=r && iter->next->x!=x){
		iter=iter->next;
	}
	if(iter->next==r){
		printf("sayi bulunamadi\n");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	return r;
}

int main(){
    node * root;
    root= NULL;
    root=ekleSirali(root,400);
    root=ekleSirali(root,40);
    root=ekleSirali(root,4);
    root=ekleSirali(root,450);
    root=ekleSirali(root,50);
    bastir(root);
    root=sil(root,50);
	bastir(root);
	root=sil(root,999);
	bastir(root);
	root=sil(root,4);
	bastir(root);
	root=sil(root,450);
	bastir(root);
}
