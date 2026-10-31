extern unsigned char gUnknown_03006B34[];

typedef void (*TableFunc)(unsigned char *);

void sub_08040D68(void)
{
    unsigned int i = 0;
    TableFunc *tbl = (TableFunc *)0x08071500;

    for (; i <= 6; i++) {
        unsigned char *p = &gUnknown_03006B34[i * 0x58];
        unsigned int kind = p[2];

        if (kind != 0) {
            if (p[1] != 0)
                p[1]--;
            tbl[p[0] + kind * 5](p);
        }
    }
}
