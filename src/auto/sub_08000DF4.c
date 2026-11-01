void sub_08000DF4(unsigned char *p, int arg1)
{
    if ((signed char)(p[0xb3] << 3) < 0) {
        arg1 = -arg1;
    }
    *(int *)(p + 0x24) = arg1;
}
