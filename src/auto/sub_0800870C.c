extern unsigned char gUnknown_03002E70;
extern unsigned char gUnknown_03002E74[];

void sub_0800870C(void)
{
    unsigned char i = 0;

    while (i < gUnknown_03002E70) {
        gUnknown_03002E74[i * 16] &= 0xFD;
        i++;
    }
}
