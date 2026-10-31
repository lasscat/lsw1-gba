struct S1731C {
    int unk0[7];
    int unk1C;
};

extern int gUnknown_0300496C;
extern int gUnknown_03004974;
extern int gUnknown_0300497C;
extern int gUnknown_03004978;
extern struct S1731C *gUnknown_030034A4;
extern unsigned short gUnknown_03003430[];

int sub_080177BC(void);
unsigned int sub_08047C5C(unsigned int a, unsigned int b);
void sub_08017614(unsigned int arg0);

void sub_0801731C(void)
{
    gUnknown_0300496C = -1;
    gUnknown_03004974 = -1;
    gUnknown_0300497C += (gUnknown_030034A4->unk1C << 4) + (gUnknown_03003430[0] << 2);
    if (gUnknown_0300497C == 0)
        gUnknown_0300497C = sub_08047C5C(sub_080177BC(), 0xFFF1F) + 1;
    gUnknown_03004978 += 1;
    gUnknown_0300497C = (gUnknown_0300497C << 8) + (gUnknown_030034A4->unk1C << 6) + (gUnknown_03004978 << 4) | gUnknown_03003430[0];
    sub_08017614(gUnknown_0300497C);
}
