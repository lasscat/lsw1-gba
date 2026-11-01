extern unsigned int gUnknown_03002BF0;
int sub_08004BE0(int a)
{
    unsigned int base = gUnknown_03002BF0;
    unsigned int offset = a << 1;
    unsigned char *p = (unsigned char *)(base + 2);
    unsigned short value;
    p += offset;
    value = *(unsigned short *)p;
    return *(unsigned char *)(base + value);
}
