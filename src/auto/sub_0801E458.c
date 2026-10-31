void *sub_08047910(void *dest, unsigned char val, unsigned int len);
extern unsigned char gUnknown_03006824[];
extern unsigned char gUnknown_030068A4[];

void sub_0801E458(unsigned char a)
{
    if (a == 3 || a == 4 || a == 5) {
        unsigned char *p = gUnknown_03006824;
        sub_08047910(p, 0xFF, 0x40);
        sub_08047910(p + 0x40, 0, 0x40);
    } else {
        sub_08047910(gUnknown_03006824, 0, 0x80);
        sub_08047910(gUnknown_030068A4, 0xFF, 0x80);
    }
}
