void sub_08015A70(void *arg0, unsigned int arg1, unsigned int arg2)
{
    unsigned short *r0;
    *(unsigned int *)((unsigned char *)arg0 + 0xac) = arg1;
    r0 = (unsigned short *)((unsigned char *)arg0 + 0xbc);
    *r0 = (*r0 & 0xFDFF) | (unsigned short)arg2;
}
