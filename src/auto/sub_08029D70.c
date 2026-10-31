struct S6AFC {
    int unk0;
    int unk1;
    unsigned short unk8;
    unsigned short unkA;
};

extern struct S6AFC gUnknown_03006AFC;
extern void sub_080062F8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);

void sub_08029D70(void)
{
    int sum;

    if (gUnknown_03006AFC.unk1 == 0)
        return;
    sum = gUnknown_03006AFC.unk8 + gUnknown_03006AFC.unkA;
    gUnknown_03006AFC.unkA = sum;
    if ((sum << 16) > 0x27FF0000)
        gUnknown_03006AFC.unkA = sum - 0x2800;
    sub_080062F8(3, gUnknown_03006AFC.unk0, 0, 0, 0, (((short)gUnknown_03006AFC.unkA >> 8)) * 20, 0, 0, 30, 20);
}
