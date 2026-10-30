int sub_0801E530(int, int, int);

void sub_0800070C(void *arg0, int arg1)
{
    unsigned int *r4 = (unsigned int *)arg0;
    int r0 = arg1;
    unsigned short r1;
    unsigned int r2;

    r1 = *(unsigned short *)((char *)r4 + 0xb8);
    r2 = *(unsigned char *)((char *)r4 + 0xb1);
    r2 = (r2 << 0x1a);
    r2 = r2 >> 0x1f;
    r0 = sub_0801E530(r0, r1, r2);
    *(unsigned short *)((char *)r4 + 0xba) = (unsigned short)r0;
}
