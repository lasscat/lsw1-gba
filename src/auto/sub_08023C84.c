void sub_08023C84(void *arg)
{
    signed int *r2 = arg;
    if (r2[4] > 0xAA0000)
    {
        r2[0x16] &= ~1;
        r2[0x18] = 0;
    }
}
