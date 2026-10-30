extern unsigned char gUnknown_03006B1C[];

void sub_08040C90(void)
{
    unsigned char *p;
    unsigned char *end;
    unsigned char r3 = 3;

    p = gUnknown_03006B1C;
    end = p + 0x210;
    do {
        if (p[0x1a] != 0) {
            p[0x18] = r3;
        }
        p += 0x58;
    } while (p <= end);
}
