typedef struct Inner {
    unsigned char f_00[0x5C];
    unsigned char unk_5C;
    unsigned char f_5D[0x58];
    unsigned char unk_B5;
} Inner;

typedef struct Outer {
    unsigned char f_00[0x58];
    unsigned int unk_58;
    unsigned char f_5C[0x0C];
    Inner *unk_68;
    unsigned char f_6C[0x49];
    unsigned char unk_B5;
    unsigned char f_B6[0x09];
    unsigned char unk_BF;
    unsigned char f_C0[0x1C];
    unsigned short unk_DC;
} Outer;


void sub_08034E48(Outer *p)
{
    unsigned char *qb;
    unsigned char *pb;
    int qv;
    int pv;
    p->unk_BF = 0x80;
    qb = (unsigned char *)p->unk_68 + 0xB5;
    pb = (unsigned char *)p + 0xB5;
    qv = *qb & 0xC;
    pv = *pb & ~0xC;
    *pb = pv | qv;
    p->unk_58 &= ~1;
    p->unk_DC = 10;
    if (p->unk_68->unk_5C == 1)
        *pb = (*pb & 0xF) | 0x10;
}
