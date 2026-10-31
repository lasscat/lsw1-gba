void sub_0801E658(unsigned short a, unsigned int b, unsigned char c);

struct Item080008C4 {
    unsigned short a;
    unsigned short b;
    unsigned int c;
    unsigned int d;
};

struct unk080008C4 {
    unsigned char unk00[0xB1];
    unsigned char unkB1;
    unsigned char unkB2[10];
    unsigned short unkBC;
    unsigned char unkBE[10];
    struct Item080008C4 items[2];
};

void sub_080008C4(struct unk080008C4 *p)
{
    if (p->unkBC & 0x40) {
        int i = 0;
        unsigned char *b = &p->unkB1;
        unsigned int val = 0;
        do {
            sub_0801E658(p->items[i].b, p->items[i].a, ((unsigned int)*b << 26) >> 31);
            p->items[i].b = 0xFFFF;
            p->items[i].a = val;
            p->items[i].c = val;
            i++;
        } while (i == 0);
    }
    p->unkBC &= ~0x40;
}
