extern unsigned char gUnknown_03002E70;
extern struct {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
} gUnknown_03002E74[];

void sub_0800866C(void)
{
    unsigned char i;

    for (i = 0; i < gUnknown_03002E70; i++)
        gUnknown_03002E74[i << 2].unk0 &= 0xFE;
}
