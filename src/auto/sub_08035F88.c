struct Obj {
    unsigned char pad00[0x64];
    int field64;
    unsigned char pad68[0x78];
    unsigned char byteE0;
    unsigned char byteE1;
};

extern void sub_080020FC(void *obj, int val);
extern void sub_08035F20(void *obj);
extern void sub_080393C4(int obj, unsigned char val);

void sub_08035F88(struct Obj *obj)
{
    switch (obj->byteE0) {
    case 0x63:
        if (obj->field64 == 0) {
            sub_08035F20(obj);
        } else {
            obj->byteE1 = 0x39;
            sub_080020FC(obj, 0);
            sub_080393C4((int)obj, 0x38);
        }
        break;
    case 0x67:
    case 0x68:
        obj->byteE1 = 0x36;
        sub_080020FC(obj, 0);
        break;
    }
}
