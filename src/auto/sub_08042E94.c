void *sub_08000234(void *);
void sub_08000BF4(void *, void *);
extern void sub_08042F00(void);
extern unsigned char gUnknown_030001B8[];

void sub_08042E94(void *r4)
{
    void *ret = sub_08000234(r4);
    ((unsigned char *)ret)[0x5c] = 0x14;
    *(unsigned int *)((unsigned char *)ret + 0x58) = 0x01004209;
    *(unsigned int *)((unsigned char *)ret + 0xc) = *(unsigned int *)((unsigned char *)r4 + 0xc);
    *(unsigned int *)((unsigned char *)ret + 0x10) = *(unsigned int *)((unsigned char *)r4 + 0x10);
    *(unsigned int *)((unsigned char *)ret + 0x40) = *(unsigned int *)((unsigned char *)r4 + 0x40);
    *(unsigned int *)((unsigned char *)ret + 0x68) = (unsigned int)r4;
    *(void **)((unsigned char *)ret + 0x60) = sub_08042F00;
    {
        unsigned char *r3 = (unsigned char *)ret + 0xb5;
        unsigned int r1 = 0xd;
        r1 = -r1;
        r1 &= *r3;
        r1 |= 4;
        *r3 = r1;
    }
    sub_08000BF4(ret, (void *)gUnknown_030001B8);
}
