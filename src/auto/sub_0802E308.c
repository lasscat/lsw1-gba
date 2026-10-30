extern void sub_08047910(void *, void *, unsigned int);
extern void sub_0802E630(int);
extern unsigned char gUnknown_0300333C[];

void sub_0802E308(int arg)
{
    unsigned int *ptr = (unsigned int *)(gUnknown_0300333C + arg * 0x7C);
    sub_08047910(ptr, (void *)0, 0x54);
    sub_0802E630(arg);
}
