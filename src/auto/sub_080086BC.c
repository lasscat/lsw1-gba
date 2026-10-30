extern unsigned char gUnknown_03002E70;
extern struct {
    unsigned char unk0;
    unsigned char unk1[15];
} gUnknown_03002E74[];

void sub_080086BC(void)
{
    unsigned char i;

    for (i = 0; i < gUnknown_03002E70; i++)
        gUnknown_03002E74[i].unk0 |= 1;
}
