struct unk {
    unsigned char unk00[0xE2];
    unsigned char unkE2;
    unsigned char unkE3[0x39];
    unsigned short unk11C;
};

extern void sub_080020FC(struct unk *obj, int val);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_0803ABE0(struct unk *obj);

void sub_0803223C(struct unk *obj)
{
    unsigned int state;

    if (obj->unkE2 == 0)
        sub_080020FC(obj, 3);
    state = obj->unkE2;
    if (state == 3) {
        if (obj->unk11C == 0)
            state = 2;
        obj->unk11C--;
    } else {
        sub_0803ABE0(obj);
    }
    if (state == 2)
        sub_08036AF0((unsigned int)obj, 0);
}
