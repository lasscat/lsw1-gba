struct unk48 {
    unsigned char unk00[0x26];
    unsigned char unk26;
    unsigned char unk27[9];
};

struct sub11C {
    unsigned char unk00[0xA];
    unsigned char unk0A;
};

struct unk {
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x84];
    unsigned char unkE0;
    unsigned char unkE1;
    unsigned char unkE2;
    unsigned char unkE3[0x39];
    struct sub11C unk11C;
};

extern void sub_080020FC(struct unk *obj, int val);
extern void sub_0802DED0(struct unk *obj);
extern void sub_0803ABE0(struct unk *obj);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern struct unk48 gUnknown_0804FB00[];

void sub_08031D78(struct unk *arg0)
{
    unsigned int state;

    if (arg0->unkE2 == 0) {
        sub_080020FC(arg0, 4);
        arg0->flags &= 0xFFFBFFFF;
        arg0->flags &= 0xFFFF7FFF;
    }
    state = arg0->unkE2;
    if (state == 4) {
        if (arg0->flags & 0x8000) {
            struct sub11C *p = &arg0->unk11C;
            p->unk0A = gUnknown_0804FB00[arg0->unkE0].unk26;
            sub_0802DED0(arg0);
            arg0->flags &= 0xFFFF7FFF;
        }
        if (arg0->flags & 0x40000)
            state = 2;
    } else {
        sub_0803ABE0(arg0);
    }
    if (state == 2)
        sub_08036AF0((unsigned int)arg0, 0);
}
