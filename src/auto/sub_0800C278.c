extern unsigned char gUnknown_03006B1C[];

extern int sub_08017400(int, int);

struct Sub0800C278 {
    char _0[4];
    short s4;
    short s6;
    unsigned char b8;
};

void sub_0800C278(struct Sub0800C278 *p)
{
    int r = sub_08017400(p->s4, p->s6);
    unsigned char *q = gUnknown_03006B1C;
    q += 0x2AA;
    q[p->b8] = r;
}
