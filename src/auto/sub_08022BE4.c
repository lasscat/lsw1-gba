void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
void sub_08022C64(void);

typedef struct
{
    int *unk00;
    int *items[7];
    int *unk20;
    int *unk24;
} GStruct;
extern GStruct *gUnknown_030069F8;

void sub_08022BE4(void)
{
    unsigned int i = 0;
    int *q;

    do
    {
        sub_08000F78(gUnknown_030069F8->items[i],
            ((int *)gUnknown_030069F8->items[i])[3],
            ((int *)gUnknown_030069F8->items[i])[4] - 0xA00000, 0x14);
        ((int *)gUnknown_030069F8->items[i])[0x60 / 4] = (int)sub_08022C64;
        i++;
    } while (i <= 6);
    q = gUnknown_030069F8->unk20;
    sub_08000F78(q, 0x3C0000, q[4], 0x14);
    q = gUnknown_030069F8->unk24;
    sub_08000F78(q, 0xB40000, q[4], 0x14);
}
