extern unsigned int gUnknown_0300340C;

extern void sub_08002138(void *arg0, unsigned int arg1);

void sub_08010FC8(void)
{
    unsigned int *r4 = (unsigned int *)&gUnknown_0300340C;
    sub_08002138((void *)*r4, 0x18);
    {
        unsigned int *r1 = (unsigned int *)(*r4 + 0xd4);
        *r1 = *r1 & 0xFFFFFFFB;
    }
}
