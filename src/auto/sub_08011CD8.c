extern unsigned short gUnknown_03003430[];

void sub_08011CD8(void)
{
    gUnknown_03003430[4] = 0;
    {
        int r0 = 0;
        unsigned short *r1;
        unsigned short r2 = 0;
        r1 = (unsigned short *)( (char *)gUnknown_03003430 + 0x12 );
        do {
            *r1 = r2;
            r1--;
            r0--;
        } while (r0 >= 0);
    }
}
