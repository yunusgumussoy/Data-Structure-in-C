#ifndef veriyapilaristack
#define veriyapilaristack
//header dosyasında değişken tanımlamıyoruz
//sadece döngüleri yazıyoruz
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
