extern void sub_0802F130(void *);

typedef void (*ObjCb)(void *);

typedef struct {
    unsigned char pad00[12];
    int f0C;
    int f10;
    int f14;
    int f18;
    unsigned char pad1C[8];
    int f24;
    int f28;
    unsigned char pad2C[44];
    unsigned int f58;
    unsigned char pad5C[4];
    ObjCb f60;
    unsigned char pad64[81];
    unsigned char fB5;
    unsigned char padB6[40];
    unsigned short fDE;
    unsigned char padE0;
    unsigned char fE1;
    unsigned char padE2[6];
    int fE8;
    int fEC;
    unsigned char fF0;
    unsigned char fF1;
} Obj;

void sub_0802F08C(Obj *o)
{
    unsigned char *p;
    unsigned int mask;
    unsigned int flags;
    int *q;
    int v0;
    int v1;

    o->f14 += o->f24;
    o->f18 += o->f28;
    p = (unsigned char *)o + 0xB5;
    mask = 13;
    mask = -mask;
    *p = (*p & mask) | 4;
    if (o->fDE == 0) {
        p += 0x3B;
        if (*p != 0 && o->fE1 != 1) {
            flags = o->f58;
            flags &= 0xFFFDFFFF;
            o->f58 = (flags & ~1) | 8;
            q = (int *)((unsigned char *)o + 0xE8);
            v1 = q[1];
            v0 = q[0];
            o->f0C = v0;
            o->f10 = v1;
            o->f60 = sub_0802F130;
            o->fF1 = *p;
        } else {
            o->f58 = (o->f58 | 2) & ~1;
        }
    }
}
