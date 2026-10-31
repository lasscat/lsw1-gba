typedef struct S {
    unsigned char _00[0x0C];
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char _14[0x44];
    unsigned int unk58;
    unsigned char _5C[0x0C];
    struct S *unk68;
    unsigned char _6C[0x49];
    unsigned char unkB5;
    unsigned char _B6[0x3C];
    unsigned short unkF2;
} S;

void sub_08042F00(S *p)
{
    S *b;

    if (p->unk68->unk58 & 2) {
        p->unk58 |= 2;
    } else {
        p->unk0C = p->unk68->unk0C;
        p->unk10 = p->unk68->unk10;
    }

    b = p->unk68;
    if ((b->unkF2 & 7) == 0) {
        p->unkB5 = (p->unkB5 & 0x0F) | 0x30;
    } else if ((b->unkF2 & 7) == 1) {
        p->unkB5 = (p->unkB5 & 0x0F) | 0x40;
    } else if ((b->unkF2 & 7) == 2) {
        p->unkB5 = (p->unkB5 & 0x0F) | 0x10;
    } else if ((b->unkF2 & 7) == 3) {
        p->unkB5 = (p->unkB5 & 0x0F) | 0x20;
    }
}
