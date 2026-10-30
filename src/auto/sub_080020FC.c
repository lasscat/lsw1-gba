struct unk {
    unsigned char pad0[0xe2];
    unsigned char unk0e2;
    unsigned char unk0e3;
};

void sub_080020FC(struct unk *obj, int val)
{
    if (obj->unk0e2 == val)
        return;
    obj->unk0e2 = val;
    obj->unk0e3 |= 2;
}
