extern void sub_08004228(void);
extern unsigned char gUnknown_03002BC8[];

void sub_080040F0(void)
{
    sub_08004228();
    if (gUnknown_03002BC8[15]) {
        ((unsigned short *)gUnknown_03002BC8)[5] |= 8;
    }
}
