extern unsigned int gUnknown_030031C4;
extern unsigned char gUnknown_03002DEC[];
extern unsigned char gUnknown_0300332C[];
extern int gUnknown_0804B704[];
extern unsigned char gUnknown_030049F0[];
extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_08007908(void *a, int b, int c, int d);
extern void sub_08007868(int a, int b);
extern void sub_080078C4(int a, int b, int c, int d);

struct Obj_0800C17C
{
    int unk00[3];
    int unk0C;
    int unk10;
    int unk14[11];
    int unk40;
};

void sub_0800C17C(unsigned char *p)
{
    struct Obj_0800C17C *obj = (struct Obj_0800C17C *)sub_08004A5C(p[4], p[5]);

    if (obj == 0)
        return;
    if (gUnknown_030031C4 == 1)
        gUnknown_030031C4 = 2;
    if (gUnknown_030031C4 == 2) {
        int base = (int)gUnknown_03002DEC;
        *(unsigned char *)(base + gUnknown_0300332C[0xb9] * 40 + 0x25) = 1;
    }
    sub_08007908(obj, gUnknown_0804B704[0], gUnknown_0804B704[1], 0);
    sub_08007868(4, 0);
    sub_080078C4(obj->unk0C, obj->unk10, 0, obj->unk40);
    gUnknown_030049F0[0x2a2] = 1;
}
