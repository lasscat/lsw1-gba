struct Obj {
    unsigned char unk00[0x0c];
    unsigned int unk0c;
    unsigned int unk10;
    unsigned char unk14[0x44];
    unsigned int unk58;
    unsigned char unk5c[0x0c];
    struct Obj *unk68;
};

void sub_08033B20(struct Obj *a)
{
    struct Obj *b = a->unk68;
    if (b != 0) {
        a->unk0c = b->unk0c;
        a->unk10 = b->unk10;
        if ((b->unk58 & 2) != 0) {
            a->unk68 = 0;
        }
    }
    if ((a->unk58 & 0x40000) != 0) {
        a->unk58 |= 2;
    }
}
