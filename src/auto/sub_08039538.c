extern void sub_080020FC(void *obj, int val);

void sub_08039538(void *arg)
{
    void *r6 = arg;
    unsigned int r4;
    unsigned int r5;
    unsigned char *p;
    
    p = (unsigned char *)r6 + 0xe3;
    r4 = 0;
    *p = r4 & 0xFF;
    p = (unsigned char *)r6 + 0xe1;
    *p = r4 & 0xFF;
    p = (unsigned char *)r6 + 0xd8;
    r5 = 0;
    *(unsigned short *)p = r4 & 0xFFFF;
    
    sub_080020FC(r6, 0);
    
    p = (unsigned char *)r6 + 0xe0;
    *p = r5 & 0xFF;
    *(unsigned int *)(r6 + 0x68) = r4;
}
