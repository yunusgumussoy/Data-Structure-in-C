#ifndef veriyapilaristack
#define veriyapilaristack
//header dosyas�nda de�i�ken tan�mlam�yoruz
//sadece d�ng�leri yaz�yoruz
struct s{
	int boyut;
	int tepe;
	int *dizi;
};
typedef s stack;
stack *tanim();
int pop(stack *);
void push(int,stack *);
void bastir(stack *);
#endif
