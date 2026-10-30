extern unsigned int gUnknown_03003678;

int sub_080139C4(void *arg0, int arg1)
{
    int r2 = (int)arg0;
    if (*(int *)arg0 != 0) {
        return *(int *)arg0 - r2 - 0x10;
    }
    {
        char *r0 = (char *)&gUnknown_03003678;
        unsigned int r1 = arg1 << 4;
        r0 += 0xc;
        r1 = r1 + (unsigned int)r0;
        return *(int *)r1 - r2 - 0x10;
    }
}
