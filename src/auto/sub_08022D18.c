void sub_08022D18(void *arg0)
{
    int *p = (int *)arg0;
    if (p[4] > 0x00AA0000)
    {
        p[22] &= ~1;
    }
}
