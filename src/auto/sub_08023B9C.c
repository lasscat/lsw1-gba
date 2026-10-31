void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
void sub_08023B24(int *arg0);
void sub_08023C84(void);

typedef struct
{
    int *unk00;
    int *unk04;
    int *unk08;
    int *unk0C;
    int *unk10;
    int *unk14;
    int *unk18;
    int *unk1C;
    int *unk20;
    int *unk24;
    int *unk28[3];
    int *unk34[6];
    int *unk4C;
    int *unk50;
    int *unk54;
    int *unk58;
    int *unk5C;
} S_030069FC;
extern S_030069FC *gUnknown_030069FC;

void sub_08023B9C(void)
{
    unsigned int i;
    int *q;

    sub_08023B24(gUnknown_030069FC->unk00);
    sub_08023B24(gUnknown_030069FC->unk08);
    sub_08023B24(gUnknown_030069FC->unk04);
    sub_08023B24(gUnknown_030069FC->unk0C);
    sub_08023B24(gUnknown_030069FC->unk10);
    sub_08023B24(gUnknown_030069FC->unk14);
    sub_08023B24(gUnknown_030069FC->unk1C);
    sub_08023B24(gUnknown_030069FC->unk18);
    sub_08023B24(gUnknown_030069FC->unk20);
    sub_08023B24(gUnknown_030069FC->unk24);
    sub_08023B24(gUnknown_030069FC->unk54);
    sub_08023B24(gUnknown_030069FC->unk58);
    sub_08023B24(gUnknown_030069FC->unk5C);
    i = 0;
    do
    {
        sub_08000F78(gUnknown_030069FC->unk28[i],
            ((int *)gUnknown_030069FC->unk28[i])[3],
            ((int *)gUnknown_030069FC->unk28[i])[4] + 0x00A00000, 0x14);
        ((int *)gUnknown_030069FC->unk28[i])[0x60 / 4] = (int)sub_08023C84;
        i++;
    } while (i <= 2);
    q = gUnknown_030069FC->unk4C;
    sub_08000F78(q, 0xFFEC0000, q[4], 0x14);
    q = gUnknown_030069FC->unk50;
    sub_08000F78(q, 0x1040000, q[4], 0x14);
}
