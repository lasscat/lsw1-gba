struct unk
{
    unsigned char unk00[0x64];
    int field64;
    unsigned char unk68[0x6C];
    unsigned int fieldD4;
    unsigned char unkD8[9];
    unsigned char fieldE1;
};

extern void sub_08035F20(struct unk *obj);
extern void sub_080020FC(struct unk *obj, int val);
extern void sub_080393C4(void *obj, unsigned char val);

void sub_08036690(struct unk *obj)
{
    if (obj->field64 == 0) {
        sub_08035F20(obj);
    } else {
        obj->fieldD4 &= 0xFFFEFFFF;
        obj->fieldE1 = 0x37;
        sub_080020FC(obj, 0);
        sub_080393C4(obj, 0x38);
    }
}
