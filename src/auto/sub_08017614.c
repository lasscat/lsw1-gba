extern unsigned int gUnknown_03004964;
extern unsigned int gUnknown_0300496C;

void sub_08017614(unsigned int arg0)
{
    unsigned int r2;
    unsigned int *r3;
    unsigned int r0;
    unsigned int r1;
    r2 = arg0 | 1;
    r3 = *(unsigned int **)(&gUnknown_03004964);
    gUnknown_0300496C = 0;
    *r3++ = r2;
    r0 = 0x26F;
    r1 = 0x10DCD;
    do {
        r2 = r2 * r1;
        *r3++ = r2;
        r0--;
    } while (r0 != 0);
}
