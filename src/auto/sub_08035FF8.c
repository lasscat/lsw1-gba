struct unk {
    unsigned char unk00[0x34];
    unsigned int unk34;
    unsigned char unk38[0xA9];
    unsigned char unkE1;
    unsigned char unkE2;
    unsigned char unkE3;
    unsigned char unkE4[0x38];
    unsigned short unk11C;
    unsigned char unk11E;
};

extern void sub_080020FC(void *obj, int val);

void sub_08035FF8(struct unk *obj, long long val)
{
    int zero;
    obj->unkE1 = 0x20;
    zero = 0;
    sub_080020FC(obj, 0);
    obj->unk11E = zero;
    obj->unk11C = 0x258;
    obj->unk34 = val;
}
