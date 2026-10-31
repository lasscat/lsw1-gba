struct unk {
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x86];
    unsigned char unkE2;
    unsigned char unkE3;
};

extern void sub_080020FC(struct unk *obj, int val);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_0803ABE0(struct unk *obj);

void sub_080324D0(struct unk *arg0)
{
    struct unk *r4 = arg0;
    unsigned int state;

    if (r4->unkE2 == 0)
        sub_080020FC(r4, 0x1c);
    state = r4->unkE2;
    if (state == 0x1c) {
        if (r4->flags & 0x8000)
            r4->flags &= 0xFFFF7FFF;
        if (r4->flags & 0x40000)
            state = 2;
    } else {
        sub_0803ABE0(r4);
    }
    if (state == 2)
        sub_08036AF0((unsigned int)r4, 0);
}
