extern unsigned char gUnknown_030033EC[];

unsigned int sub_0800FE70(void)
{
    unsigned char count = 0;
    unsigned char i = 0;

    do
    {
        if (gUnknown_030033EC[i] != 0x69)
            count++;
        i++;
    } while (i <= 3);
    return count;
}
