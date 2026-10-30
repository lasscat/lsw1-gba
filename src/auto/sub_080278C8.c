struct Sub {
    unsigned char unk[0x58];
    unsigned int f58;
};

struct Main {
    unsigned int w00;
    struct Sub *w04;
    struct Sub *w08;
    unsigned int w0C;
    unsigned int w10;
    unsigned int w14;
    struct Sub *w18;
    struct Sub *w1C;
};

extern struct Main *gUnknown_03006AF0;

static inline void clr(struct Sub *p, unsigned int m)
{
    unsigned int v = p->f58;
    v &= m;
    p->f58 = v;
}

void sub_080278C8(void)
{
    struct Main *r3 = gUnknown_03006AF0;
    struct Sub *p = r3->w18;
    unsigned int r0v = p->f58;
    unsigned int r1v = 2;
    r1v = 0 - r1v;
    r0v &= r1v;
    p->f58 = r0v;
    clr(r3->w1C, r1v);
    clr(r3->w04, r1v);
    clr(r3->w08, r1v);
}
