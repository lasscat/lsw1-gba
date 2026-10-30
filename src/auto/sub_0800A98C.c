extern unsigned char gUnknown_03002EC4[];
extern unsigned int gUnknown_03002F28;
void sub_0800A9D0(void *);

void sub_0800A98C(void)
{
    unsigned int i;
    unsigned char *p;

    gUnknown_03002F28 = 0;
    for (i = 0, p = gUnknown_03002EC4; i <= 11; i++) {
        sub_0800A9D0(p);
        p += 8;
    }
}
