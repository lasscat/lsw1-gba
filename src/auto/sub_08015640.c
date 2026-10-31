extern unsigned char gUnknown_030048A0[];

void sub_08015640(int arg0)
{
    unsigned char *ptr = gUnknown_030048A0;
    ptr[arg0 * 8 + 6] &= 0xFD;
}
