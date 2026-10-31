void sub_080239DC(void *arg0);
void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
void sub_08023B64(void *arg0);

typedef struct
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char pad14[0x44];
    int flag58;
    int unk5C;
    void (*cb60)(void *);
} Elem;

typedef struct
{
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    Elem *a28[3];
    char pad34[0x18];
    Elem *f4C;
    Elem *f50;
    Elem *a54[3];
} Base;

extern Base *gUnknown_030069FC;

void sub_08023A1C(void)
{
    unsigned int i;

    sub_080239DC(gUnknown_030069FC->f00);
    sub_080239DC(gUnknown_030069FC->f08);
    sub_080239DC(gUnknown_030069FC->f04);
    sub_080239DC(gUnknown_030069FC->f0C);
    sub_080239DC(gUnknown_030069FC->f10);
    sub_080239DC(gUnknown_030069FC->f14);
    sub_080239DC(gUnknown_030069FC->f1C);
    sub_080239DC(gUnknown_030069FC->f18);
    sub_080239DC(gUnknown_030069FC->f20);
    sub_080239DC(gUnknown_030069FC->f24);
    i = 0;
    do
    {
        sub_08000F78((int *)gUnknown_030069FC->a54[i], gUnknown_030069FC->a54[i]->unk0C, gUnknown_030069FC->a54[i]->unk10 + 0xFF600000, 0x14);
        if (gUnknown_030069FC->a54[i]->flag58 & 1)
            gUnknown_030069FC->a54[i]->cb60 = sub_08023B64;
        i++;
    } while (i <= 2);
    i = 0;
    do
    {
        sub_08000F78((int *)gUnknown_030069FC->a28[i], gUnknown_030069FC->a28[i]->unk0C, gUnknown_030069FC->a28[i]->unk10 + 0xFF600000, 0x14);
        gUnknown_030069FC->a28[i]->cb60 = sub_08023B64;
        i++;
    } while (i <= 2);
    sub_08000F78((int *)gUnknown_030069FC->f4C, 0xF0000, gUnknown_030069FC->f4C->unk10, 0x14);
    sub_08000F78((int *)gUnknown_030069FC->f50, 0xE10000, gUnknown_030069FC->f50->unk10, 0x14);
}
