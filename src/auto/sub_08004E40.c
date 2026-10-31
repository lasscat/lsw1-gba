extern unsigned short gUnknown_03002BD8;
extern unsigned int gUnknown_03002BFC;
unsigned short sub_08005290(unsigned short x);
unsigned int sub_08004F2C(unsigned char *a, unsigned int b, unsigned char c);

unsigned int sub_08004E40(unsigned char *a0, unsigned char *a1, unsigned int a2)
{
    unsigned int cur = a2;
    unsigned char *p = 0;
    unsigned char c = 0;
    unsigned short *f = &gUnknown_03002BD8;
    unsigned int one = 1;
    unsigned char i;
    unsigned char *q;

    if (*f & one) {
        p = a0 + *(unsigned short *)a0;
        c = *p;
    }
    q = a1 + *(unsigned short *)a1;
    c += *q;
    *(unsigned short *)gUnknown_03002BFC = c;
    cur += sub_08005290(c + 1);
    if (*f & one) {
        for (i = 0; i < *(unsigned short *)p; i++) {
            unsigned int b = gUnknown_03002BFC;
            unsigned int d = cur - b;
            unsigned int k = i * 2;
            unsigned int t = b + 2;
            t += k;
            *(unsigned short *)t = d;
            cur = sub_08004F2C(p, cur, i);
        }
        c = *p;
    } else {
        c = 0;
    }
    for (i = 0; i < *(unsigned short *)q; i++) {
        unsigned int b = gUnknown_03002BFC;
        unsigned int d = cur - b;
        unsigned int k = (i + c) * 2;
        unsigned int t = b + 2;
        t += k;
        *(unsigned short *)t = d;
        cur = sub_08004F2C(q, cur, i);
    }
    return cur;
}
