extern unsigned char gUnknown_08056D70[];
extern void sub_08038128(void *, unsigned int, unsigned char);

void sub_080388A4(void *arg0, unsigned int arg1, unsigned int arg2)
{
    unsigned char *p;

    if ((*(unsigned short *)(arg0 + 0xF2) & 8) == 0)
        return;
    if (*(unsigned int *)(arg0 + 0x64) == 0)
        *(unsigned int *)(arg0 + 0x64) = arg1;
    p = &gUnknown_08056D70[*(unsigned char *)(arg0 + 0x119) * 24];
    if (p[arg2] <= (*(unsigned short *)(arg0 + 0xF2) & 7))
        return;
    sub_08038128(arg0, arg1, p[arg2]);
}
