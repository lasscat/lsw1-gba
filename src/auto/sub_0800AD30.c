extern unsigned int gUnknown_03002F9C;
extern unsigned char gUnknown_03002FA0[];

void sub_0800AD94(void *);

void sub_0800AD30(void)
{
    unsigned char n;
    unsigned int i;
    unsigned char *p;

    n = 0;
    i = 0;
    if (n > gUnknown_03002F9C)
        return;
    do {
        p = gUnknown_03002FA0 + i * 20;
        if (*(unsigned short *)p & 1) {
            sub_0800AD94(p);
            n++;
        }
        i++;
    } while (i <= 11 && n <= gUnknown_03002F9C);
}
