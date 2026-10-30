void sub_0801C19C(unsigned int arg);

struct Inner35D3C {
    unsigned int unk00[22];
    unsigned int unk58;
    unsigned char unk5C[128];
    unsigned short unkDC;
};

struct Outer35D3C {
    unsigned int unk00[22];
    unsigned int unk58;
    unsigned char unk5C[12];
    struct Inner35D3C *unk68;
    unsigned int unk6C[44];
    unsigned int unk11C;
};

void sub_08035D3C(struct Outer35D3C *p)
{
    struct Inner35D3C *q = p->unk68;
    if ((q->unk58 & 2) == 0) {
        if (q->unkDC > 1)
            return;
    }
    p->unk58 |= 2;
    sub_0801C19C(p->unk11C);
}
