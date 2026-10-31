extern unsigned char gUnknown_03002C50[];

unsigned char sub_08007668(int a)
{
    unsigned int base = (unsigned int)gUnknown_03002C50;
    return *(unsigned char *)(base + (unsigned int)a * 100 + 4) >> 7;
}
