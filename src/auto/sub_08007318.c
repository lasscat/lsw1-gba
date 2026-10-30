extern unsigned char gUnknown_03002C54[];

void sub_08007364(int);
void sub_080073A0(int);

void sub_08007318(int idx)
{
    unsigned char *base = gUnknown_03002C54 + idx * 100;
    sub_08007364(idx);
    sub_080073A0(idx);
    *(unsigned short *)(base + 0x40) &= 0xFFF7;
}
