extern void sub_08035F20(void *obj);
extern void sub_0802AF4C(void *arg0);
extern void sub_080020FC(void *obj, int val);

struct Obj36944 {
    unsigned char unk_00[220];
    unsigned short unk_DC;
    unsigned short unk_DE;
    unsigned char unk_E0;
    unsigned char unk_E1;
    unsigned char unk_E2[14];
    unsigned short unk_F0;
};

void sub_08036944(struct Obj36944 *obj)
{
    unsigned char *p = &obj->unk_E0;

    if (*p == 0x2c)
        return;
    if (obj->unk_F0 & 0x4000)
        return;
    if (obj->unk_F0 & 0x10) {
        sub_08035F20(obj);
        return;
    }
    sub_0802AF4C(obj);
    obj->unk_DC = 10;
    if (*p == 0x65)
        obj->unk_DC = 2;
    obj->unk_E1 = 0;
    sub_080020FC(obj, 0x20);
}
