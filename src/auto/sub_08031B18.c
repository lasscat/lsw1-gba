struct unk {
    unsigned char pad0[0xe2];
    unsigned char unkE2;
    unsigned char padE3[0x39];
    unsigned short unk11C;
};

void sub_080020FC(struct unk *obj, int val);
void sub_08036AF0(unsigned int obj, unsigned int val);
void sub_0803ABE0(struct unk *obj);

void sub_08031B18(struct unk *p)
{
    unsigned int state;
    if (p->unkE2 == 0)
        sub_080020FC(p, 3);
    state = p->unkE2;
    if (state == 3) {
        if (p->unk11C == 0)
            sub_080020FC(p, 2);
        p->unk11C--;
    } else {
        sub_0803ABE0(p);
    }
    if (state == 2)
        sub_08036AF0((unsigned int)p, 0);
}
