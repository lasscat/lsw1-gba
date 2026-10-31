int sub_080152E4(const void *arg0);
void sub_0801530C(void *p, unsigned int r1);
void sub_0801539C(int arg0);

typedef struct {
    unsigned char unk0[0xB0];
    unsigned char unkB0;
    unsigned char st : 2;
    unsigned char hi : 6;
} Obj08003D48;

void sub_08003D48(Obj08003D48 *p)
{
    unsigned int t = p->st;
    if (t == 1 || t == 3) {
        unsigned char *q;
        unsigned short s;
        p->st = 0;
        q = (unsigned char *)p + 0xB0;
        s = sub_080152E4(q);
        sub_0801530C(q, 0);
        sub_0801539C(s);
    }
}
