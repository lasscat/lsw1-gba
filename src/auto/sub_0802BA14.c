extern unsigned int gUnknown_0300340C;

int sub_0802BA14(void *arg0)
{
    int r = 0;
    unsigned int *r2 = *(unsigned int **)&gUnknown_0300340C;
    unsigned char *r1 = *(unsigned char **)((char *)arg0 + 0xE8);
    unsigned int r0 = *(unsigned int *)((char *)arg0 + 0x40) + ((unsigned int)r1[0x78] << 16);
    if (r2[0x10] == r0)
        r = 1;
    return r;
}
