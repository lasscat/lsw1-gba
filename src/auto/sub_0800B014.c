extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800B014(void *p)
{
    unsigned int *q = (unsigned int *)sub_08004A5C(((unsigned char *)p)[4], ((unsigned char *)p)[5]);

    if (q == 0)
        return;
    if (((unsigned char *)p)[6] > 0x1f) {
        q[0xD4 / 4] |= 1 << (((unsigned char *)p)[6] - 0x20);
    } else {
        q[0x58 / 4] |= 1 << ((unsigned char *)p)[6];
    }
}
