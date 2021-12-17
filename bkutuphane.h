#ifndef bkutuphane
#define bkutuphane
struct n{
    int x;
    n * next;
    n * prev;// çift yönlü baðlý liste
    			// geri dönüþ olduðu için istediðimiz yerde durabiliyoruz
};
typedef n node;
void bastir(node*r);
node * sil(node *r, int x);
node * ekleSirali(node*r,int x);

#endif
