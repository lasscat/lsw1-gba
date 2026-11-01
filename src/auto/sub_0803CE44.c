struct Entry {
    unsigned char pad0[0x16];
    unsigned char f16;
    unsigned char f17;
    unsigned char pad18[0x2c - 0x18];
    unsigned char f2c;
    unsigned char pad2d[3];
};

struct Obj {
    unsigned char pad0[0xc];
    int f0c;
    int f10;
    unsigned char pad14[0x60 - 0x14];
    void *f60;
    unsigned char pad64[0xd4 - 0x64];
    unsigned int fd4;
    unsigned char padd8[0xdc - 0xd8];
    unsigned short fdc;
    unsigned char padde[2];
    unsigned char fe0;
    unsigned char fe1;
    unsigned char fe2;
    unsigned char pade3[0xf0 - 0xe3];
    unsigned char ff0;
    unsigned char ff1;
    unsigned char padf2;
    unsigned char ff3;
    unsigned char padf4;
    unsigned char ff5;
    unsigned char padf6[0x103 - 0xf6];
    unsigned char f103;
    unsigned char f104;
    unsigned char f105;
};

extern struct Entry gUnknown_0805171C[];
extern unsigned char gUnknown_0300332C[];
extern int sub_0801BEB8(int);
extern unsigned short gUnknown_03003430;

extern void sub_08000D00(void *, int);
extern void sub_08000F78(int *, int, int, int);
extern void sub_080020FC(void *, int);
extern void sub_08004458(unsigned char, unsigned char);
extern int sub_0801BEB8(int);
extern void sub_0802B450(unsigned char *);
extern void sub_0802B4B8(void *);
extern void sub_0802B604(unsigned char *);
extern void sub_0802B7C8(void);
extern int sub_0802B814(void *);
extern void sub_0802B88C(void *);
extern void sub_0802B99C(void *);
extern void sub_0802BA5C(void *);
extern void *sub_0803C330(void *);
extern void sub_0803D098(void *);

void sub_0803CE44(struct Obj *p)
{
    switch (p->fe1) {
    case 3:
    switch (p->fe2) {
    case 0:
        if (sub_0802B814(p)) {
            sub_0802BA5C(p);
            p->fdc = 0x19;
            { int r = sub_0801BEB8(gUnknown_0805171C[p->fe0].f2c); unsigned char *q = gUnknown_0300332C; q += 0xa8; *(int *)q = r; }
            sub_080020FC(p, 0x14);
        } else {
            sub_0802B88C(p);
        }
        break;
    case 0x14:
        if (p->fdc == 0) {
            p->ff0 = 1;
            sub_080020FC(p, 2);
            return;
        }
        if ((p->fdc % 2) == 0) {
            if (!(gUnknown_03003430 & 0x200) && !(p->fd4 & 8)) {
                p->ff0 = 0;
                sub_080020FC(p, 0);
                sub_0802B7C8();
                return;
            }
            if (gUnknown_0805171C[p->fe0].f16 != 0) {
                int base;
                unsigned char v;
                if (p->ff3 != 0)
                    base = p->f0c + (int)0xFFFC0000;
                else
                    base = p->f0c + 0x40000;
                v = 0;
                if (p->ff3 == 0)
                    v = 1;
                p->ff3 = v;
                sub_08000F78((int *)p, base, p->f10, 2);
            }
        }
        p->fdc--;
        break;
    case 2:
        if (!(gUnknown_03003430 & 0x200) && !(p->fd4 & 8)) {
            p->f60 = (void *)sub_0803D098;
            return;
        }
        if (p->ff0 == 0)
            sub_080020FC(p, 0x49);
        break;
    case 0x49:
        sub_0802B7C8();
        if (p->ff5 == 0) {
            sub_0802B450((unsigned char *)p);
            if (p->ff5 == 0)
                sub_08004458(p->f105, p->f104);
        }
        sub_0802B4B8(p);
        if (gUnknown_0805171C[p->fe0].f17 != 0) {
            sub_080020FC(p, 0);
            p->ff1 = 0;
            sub_08000D00(p, 0);
            p->f103 = 0;
            sub_0801BEB8(0x24);
        } else {
            sub_080020FC(p, 1);
            sub_0801BEB8(0x25);
        }
        if (p->fe0 == 0x14) {
            sub_0803C330(p);
            sub_0802B99C(p);
        }
        break;
    }
    if (p->ff0 != 0)
        sub_0802B604((unsigned char *)p);
    break;
    case 1:
        sub_0802B99C(p);
        break;
    }
}
