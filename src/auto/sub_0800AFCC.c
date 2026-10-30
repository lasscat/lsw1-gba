extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800AFCC(void *arg)
{
    unsigned char *p = arg;
    unsigned char *obj = (unsigned char *)sub_08004A5C(p[4], p[5]);
    if (obj != 0) {
        unsigned short h = *(unsigned short *)(p + 6);
        obj[0x118] = h;
        obj[0xE3] |= 8;
    }
}
