extern void sub_08036DA0(void *);

void sub_08036E74(void *arg)
{
    sub_08036DA0(arg);
    *(unsigned short *)((unsigned char *)arg + 0xf2) |= 0x40;
}
