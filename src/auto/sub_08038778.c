void sub_08037FF8(void *arg);
void sub_08035EC0(void *arg);
void sub_0802AB1C(void *arg, unsigned int value);

void sub_08038778(void *arg)
{
    sub_08037FF8(arg);
    if ((*(unsigned short *)(arg + 0xF2) & 0x20) == 0)
        sub_08035EC0(arg);
    *(unsigned char *)(arg + 0x112) = 1;
    sub_0802AB1C(arg, 0x118);
}
