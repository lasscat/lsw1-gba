struct unk {
    unsigned char pad00[0x58];
    unsigned int flags;
    unsigned char pad5c[0x80];
    unsigned short unk0dc;
    unsigned char pad0de[4];
    unsigned char unk0e2;
    unsigned char pad0e3[5];
    struct unk *slots[4];
    unsigned char pad0f8[6];
    unsigned short unk0fe;
    unsigned char pad100[4];
    unsigned char unk104;
};

void sub_0803D38C(struct unk *obj)
{
    int i = 3;
    unsigned char *counter = (unsigned char *)obj + 0x104;

    for (; i >= 0; i--) {
        struct unk *p = obj->slots[i];

        if (p != 0 && (p->flags & 2) != 0) {
            obj->slots[i] = 0;
            *counter = *counter + 1;
            if (obj->unk0e2 != 0x10) {
                obj->unk0e2 = 0x10;
                obj->unk0dc = obj->unk0fe;
            }
        }
    }
}
