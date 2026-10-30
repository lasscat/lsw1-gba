struct unk {
    unsigned char unk00[0x24];
    unsigned int unk24;
    unsigned int unk28;
};

extern unsigned char gUnknown_0300332C[];
extern void sub_080020FC(struct unk *obj, int val);

void sub_0800BB08(void)
{
    unsigned char index = gUnknown_0300332C[0xb9];
    struct unk *obj = *(struct unk **)(gUnknown_0300332C + index * 0x7c);

    sub_080020FC(obj, 1);
    obj->unk24 = 0;
    obj->unk28 = 0;
}
