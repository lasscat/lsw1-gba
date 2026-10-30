extern void *gUnknown_03007014;

/* Placeholder names */
struct Unknown
{
    unsigned char unk00[8];
    unsigned int unk08;
    unsigned char unk0c[0x18];
    void *unk24;
    unsigned char unk28[0x37];
    unsigned char unk5f;
};

void sub_08037548(void *arg0, int arg1, void *arg2, int arg3);
void sub_0802A758(void *arg0, int arg1);
void sub_080013F4(void *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);

void sub_08038AC8(struct Unknown *arg)
{
    void *r4 = arg;
    void *r2 = gUnknown_03007014;

    sub_08037548(r4, 1, r2, 0);
    sub_0802A758(r4, 2);
    sub_080013F4(&arg->unk24, 0x80000000, arg->unk5f, arg->unk08);
}
