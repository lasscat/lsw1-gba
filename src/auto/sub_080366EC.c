struct unk
{
    unsigned char unk00[0x64];
    unsigned int unk64;
    unsigned char unk68[0x6C];
    unsigned int unkD4;
    unsigned char unkD8[9];
    unsigned char unkE1;
};

extern void sub_080020FC(struct unk *obj, int val);
extern void sub_08035F20(struct unk *obj);
extern void sub_080393C4(struct unk *obj, unsigned char val);

void sub_080366EC(struct unk *p)
{
    if (p->unk64 == 0) {
        sub_08035F20(p);
    } else {
        p->unkD4 &= 0xFFFEFFFF;
        p->unkE1 = 0x38;
        sub_080020FC(p, 0);
        sub_080393C4(p, 0x39);
    }
}
