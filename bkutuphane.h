#ifndef bkutuphane
#define bkutuphane
struct n{
    int x;
    n * next;
    n * prev;// �ift y�nl� ba�l� liste
    			// geri d�n�� oldu�u i�in istedi�imiz yerde durabiliyoruz
};
typedef n node;
void bastir(node*r);
node * sil(node *r, int x);
node * ekleSirali(node*r,int x);

#endif
