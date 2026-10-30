extern unsigned char gUnknown_030049F0;

void sub_0801A83C(unsigned int *arg0)
{
    unsigned char *q = &gUnknown_030049F0;
    arg0[0] = *(unsigned short *)(q + 0x32C) << 3;
    arg0[1] = *(unsigned short *)(q + 0x32E) << 3;
}
