extern unsigned int gUnknown_0300368C[];
extern unsigned int gUnknown_03002F24[];

struct S08023F70 {
    void *ptr;
    unsigned char unk4;
    unsigned char unk5;
    unsigned char unk6;
};

extern struct S08023F70 gUnknown_03006A00;

void sub_0800F8CC(void);
extern void *sub_080135D0(int);

void sub_08023F70(void)
{
    struct S08023F70 *p;

    gUnknown_0300368C[1] = 0;
    gUnknown_03002F24[0] = 0;
    p = &gUnknown_03006A00;
    p->unk6 = 0xFF;
    sub_0800F8CC();
    p->ptr = sub_080135D0(0x200);
}
