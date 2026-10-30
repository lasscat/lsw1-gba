void sub_08023B64(void *arg0)
{
    signed int *r2 = (signed int *)arg0;
    if (r2[4] <= 0x00A9FFFF)
    {
        r2[0x16] |= 1;
        r2[0x18] = 0;
    }
}
