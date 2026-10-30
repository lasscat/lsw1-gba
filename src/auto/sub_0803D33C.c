struct unk {
    unsigned char pad[0xE8];
    void *slots[4];
    unsigned char pad2[0xC];
    unsigned char count;
};

void sub_0803D33C(struct unk *obj, void *val)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        if (obj->slots[i] == val) {
            obj->slots[i] = 0;
            obj->count = obj->count + 1;
            i = 4;
        }
    }
}
