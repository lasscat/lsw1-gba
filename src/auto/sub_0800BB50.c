struct unk {
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[4];
    void (*unk60)(struct unk *);
};

extern unsigned char gUnknown_0300332C[];
extern void sub_080020FC(struct unk *obj, int val);
extern void sub_0800FF74(struct unk *obj);

void sub_0800BB50(void)
{
    unsigned char index = gUnknown_0300332C[0xb9];
    struct unk *obj = *(struct unk **)(gUnknown_0300332C + index * 0x7c);

    sub_080020FC(obj, 2);
    obj->unk60 = sub_0800FF74;
    obj->flags |= 0x204;
}
