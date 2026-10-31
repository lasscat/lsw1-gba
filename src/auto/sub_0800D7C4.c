extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800D7C4(void *arg)
{
    unsigned char *p = arg;
    unsigned int r0 = sub_08004A5C(p[4], p[5]);
    *(unsigned char *)(r0 + 0xE2) = 0x14;
}
