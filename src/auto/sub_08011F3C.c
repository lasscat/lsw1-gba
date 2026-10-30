extern unsigned short gUnknown_03003430[];

int sub_08011EC4(int *counter, unsigned int limit, unsigned int value, unsigned int flag,
                unsigned int mask0, unsigned int mask1, unsigned int mask2);

int sub_08011F3C(int *counter, unsigned int limit, unsigned int value, unsigned int flag, int index)
{
    unsigned short *table = gUnknown_03003430;
    int offset = index * 2;
    unsigned short *p = (unsigned short *)((char *)table + 0xA);

    return sub_08011EC4(counter, limit, value, flag, *(unsigned short *)((char *)p + offset), 64, 128);
}
