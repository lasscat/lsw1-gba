void sub_08000F50(void *arg);

void sub_08038FE0(void *arg0)
{
    ((unsigned int *)arg0)[0x58 / 4] &= -0x11;
    sub_08000F50(arg0);
}
