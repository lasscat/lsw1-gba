extern void sub_0800A8B0(void *);
extern unsigned int gUnknown_03003190[];

void sub_0800A868(void)
{
    unsigned int p = gUnknown_03003190[0xC];

    if (p == 0x080481E4)
        sub_0800A8B0((void *)0x08048204);
    else
        sub_0800A8B0((void *)0x080481E4);
}
