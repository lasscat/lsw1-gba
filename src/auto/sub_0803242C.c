struct unk {
    unsigned char unk00[0x0c];
    int unk0C;
    int unk10;
    unsigned char unk14[0x2c];
    int unk40;
    int unk44;
    unsigned char unk48[0x10];
    unsigned int flags;
    unsigned char unk5C[0x86];
    unsigned char unkE2;
    unsigned char unkE3;
};

extern void sub_080020FC(struct unk *obj, int val);
extern int sub_0801419C(int x, int y);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_0803ABE0(struct unk *obj);

void sub_0803242C(struct unk *arg0)
{
    struct unk *r4 = arg0;
    unsigned int state;
    int v;

    if (r4->unkE2 == 0)
        sub_080020FC(r4, 11);
    state = r4->unkE2;
    switch (state) {
    case 11:
        if (r4->flags & 0x40000)
            sub_080020FC(r4, 12);
        break;
    case 12:
        if (r4->unk44 > 0)
            break;
        sub_080020FC(r4, 13);
        break;
    case 13:
        v = sub_0801419C(r4->unk0C, r4->unk10);
        if (r4->unk40 > v)
            break;
        sub_080020FC(r4, 10);
        break;
    case 10:
        state = 2;
        break;
    default:
        sub_0803ABE0(r4);
        break;
    }
    if (state == 2)
        sub_08036AF0((unsigned int)r4, 0);
}
