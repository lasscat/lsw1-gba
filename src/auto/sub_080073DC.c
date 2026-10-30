extern unsigned char gUnknown_03002C54[];

struct Unk {
    int a, b, c;
};

void sub_080073DC(int idx, struct Unk *src)
{
    unsigned char *base = gUnknown_03002C54 + idx * 100;
    struct Unk *dst = (struct Unk *)(base + 0x58);
    *dst = *src;
    *(unsigned short *)(base + 0x40) |= 8;
}
