extern const unsigned char gUnknown_0805714C[];

unsigned int sub_080393C4(void);
void sub_0801C19C(void);

void sub_0802DA20(void *r5, int r4)
{
    unsigned int r6;
    unsigned int *r4_2;
    const unsigned char *r0;

    if (r4 == 0) {
        return;
    }
    r6 = sub_080393C4();
    r0 = gUnknown_0805714C;
    if ((r0[r4 * 4 + 3] & 1) == 0) {
        return;
    }
    r4_2 = (unsigned int *)((unsigned int)r5 + 0x11C);
    if (*r4_2 != 0) {
        sub_0801C19C();
        *r4_2 = 0;
    }
    *r4_2 = r6;
}
