extern unsigned char gUnknown_0300332C[];

void sub_08042F94(int arg0, int arg1, int arg2, int arg3)
{
    int r2 = arg2;
    if (r2 == 0) {
        r2 = arg3;
    }
    gUnknown_0300332C[0xb6] = arg1;
    *(unsigned short *)(gUnknown_0300332C + 0xb4) = r2;
}
