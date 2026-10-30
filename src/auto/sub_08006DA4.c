typedef struct {
    unsigned char _00[0x28];
    int unk28;
    int unk2c;
    unsigned char _30[0x14];
    unsigned short unk44;
    unsigned char _46[30];
} S_6DA4;
extern S_6DA4 gUnknown_03002C50[];

void sub_08006DA4(int a0, int a1, int a2)
{
    gUnknown_03002C50[a0].unk28 = a1;
    gUnknown_03002C50[a0].unk2c = a2;
    gUnknown_03002C50[a0].unk44 |= 1;
}
