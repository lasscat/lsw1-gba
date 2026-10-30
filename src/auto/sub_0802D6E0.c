extern unsigned char gUnknown_03006B1C[];

void sub_08040C90(void);
int sub_08040D24(void);

void sub_0802D6E0(void)
{
    unsigned char *base = gUnknown_03006B1C;
    int v = base[0x28E];
    switch (v) {
    case 0:
        if (base[0x28C] != base[0x28B]) {
            base[0x28E] = 1;
            sub_08040C90();
        }
        break;
    case 1:
        if (sub_08040D24() != 0)
            base[0x28D] = v;
        break;
    }
}
