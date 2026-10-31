extern unsigned char gUnknown_03006B1C[];
void sub_08040C90(void);
int sub_08040D24(void);

void sub_0802D978(void)
{
    switch (gUnknown_03006B1C[0x28E]) {
    case 0:
        if (gUnknown_03006B1C[0x28C] != gUnknown_03006B1C[0x28B]) {
            gUnknown_03006B1C[0x28E] = 1;
            sub_08040C90();
        }
        break;
    case 1:
        if (sub_08040D24() != 0)
            gUnknown_03006B1C[0x28D] = 1;
        break;
    }
}
