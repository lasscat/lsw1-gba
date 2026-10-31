struct UnkStruct_0802D3AC {
    unsigned int unk0;
    unsigned int unk4;
};

struct UnkStruct_0803F544 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned short unk8;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
};

struct Sub08041674 {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    struct UnkStruct_0802D3AC *unk4[10];
    unsigned short unk2C;
};

extern struct UnkStruct_0802D3AC *sub_0802D3AC(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4);
extern void sub_0803F544(struct UnkStruct_0803F544 *arg0, unsigned int arg1, unsigned int arg2);
extern void sub_080417AC(void *arg0);

void sub_08041674(struct Sub08041674 *arg0)
{
    unsigned int v3 = 0x13;
    unsigned int v2 = 0;
    unsigned int i = 0;
    struct UnkStruct_0802D3AC *p;

    do {
        p = sub_0802D3AC(0x08070328, 2, v2, 0, v3);
        arg0->unk4[i] = p;
        sub_0803F544((struct UnkStruct_0803F544 *)p, 0x08070320, 2);
        v2 += 2;
        v3 += 4;
        i++;
    } while (i <= 9);
    arg0->unk2C = 0;
    sub_080417AC(arg0);
    arg0->unk0 = 2;
}
