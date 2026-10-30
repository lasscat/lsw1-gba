extern unsigned int gUnknown_03006FD4;

void *sub_080317B4(unsigned int arg0)
{
    unsigned char *p = (unsigned char *)&gUnknown_03006FD4;
    arg0 = arg0 << 4;
    p = p + 0xc;
    return *(void **)(p + arg0);
}
