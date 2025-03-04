#include <stdio.h>
const int N=2e7+10;
int a[N];
namespace Gen
{
    unsigned z1, z2, z3, z4, b;
    unsigned rand_()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
    void srand_(int n, int v)
    {
        scanf("%u%u%u%u", &z1, &z2, &z3, &z4);
        for(int i = 1; i <= n; i++) a[i] = rand_() % v + 1;
    }
}
int n,v;
int main(){
    scanf("%d%d", &n, &v);
    Gen::srand_(n, v);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
}