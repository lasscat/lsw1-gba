struct S08000560
{
    unsigned int w0;
    unsigned int w1;
    unsigned short h0;
    unsigned short h1;
};

extern struct S08000560 gUnknown_030024E0;
extern struct S08000560 gUnknown_030024EC;
extern unsigned char *gUnknown_03002BBC;

void sub_080005F4(unsigned int mask);
void *sub_08047910(void *dest, unsigned char val, unsigned int len);

void sub_08000560(void)
{
    struct S08000560 *dst = &gUnknown_030024EC;
    struct S08000560 *src = &gUnknown_030024E0;

    dst->w0 = src->w0;
    dst->w1 = src->w1;
    src->w0 = 0;
    src->w1 = 0;
    dst->h0 = src->h0;
    dst->h1 = src->h1;
    sub_080005F4(0x80000);
    sub_08047910(gUnknown_03002BBC, 0, 0x34);
}
