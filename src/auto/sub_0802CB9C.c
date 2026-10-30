extern unsigned char gUnknown_03006B1C[];

int sub_0802CB9C(int a)
{
    unsigned char *base = gUnknown_03006B1C;
    unsigned int *p = (unsigned int *)(base + 0x440);
    return (*p) & (1 << a);
}
