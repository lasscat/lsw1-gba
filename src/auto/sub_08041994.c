extern unsigned char gUnknown_0300332C[];
extern unsigned int gUnknown_0300340C;
extern unsigned int gUnknown_080715B4[];
extern int sub_08047BE4(int arg0, int arg1);
extern void sub_0803F544(void *arg0, unsigned int arg1, unsigned int arg2);

struct Sub08041994 {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    void *ptr;
    unsigned short unk8;
};

void sub_08041994(struct Sub08041994 *arg)
{
    unsigned char v;
    unsigned int base;
    unsigned short a;
    unsigned short b;
    unsigned int idx;

    v = gUnknown_0300332C[0xCE];
    base = gUnknown_0300340C;
    a = *(unsigned short *)(base + 0xEC);
    b = *(unsigned short *)(base + 0xEE);
    if (a == b)
        idx = v - 1;
    else
        idx = (unsigned int)(v * sub_08047BE4(a << 16, b)) >> 16;
    sub_0803F544(arg->ptr, gUnknown_080715B4[idx], 2);
    arg->unk8 = *(unsigned short *)(gUnknown_0300340C + 0xEC);
}
