extern unsigned char gUnknown_03006B1C[];

int sub_08040D24(void)
{
    unsigned char *p;
    unsigned char *end;

    p = gUnknown_03006B1C;
    end = p + 0x210;
    do {
        if (p[0x1a] != 0) {
            if (p[0x18] != 5) {
                return 0;
            }
        }
        p += 0x58;
    } while (p <= end);
    return 1;
}
