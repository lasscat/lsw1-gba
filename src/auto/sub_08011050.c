extern unsigned int gUnknown_0300340C;
extern unsigned char gUnknown_0300332C[];

extern void sub_0801C6AC(unsigned int arg);
extern void sub_0801C19C(unsigned int arg);
extern void sub_0800FD8C(int arg0, int arg1);

void sub_08011050(int arg0)
{
    unsigned char *base;
    unsigned char *p;
    unsigned char *q;
    unsigned int i;

    sub_0801C6AC(gUnknown_0300340C);

    base = gUnknown_0300332C;
    sub_0801C19C(*(unsigned int *)(base + 0xa0));
    *(unsigned int *)(base + 0xa0) = 0;
    sub_0801C19C(*(unsigned int *)(base + 0xa4));
    *(unsigned int *)(base + 0xa4) = 0;
    sub_0801C19C(*(unsigned int *)(base + 0xac));
    *(unsigned int *)(base + 0xac) = 0;

    i = 0;
    q = base + 0xbf;
    p = base + 0xc0;
    do {
        if (*p++ == arg0) {
            *q = i;
            sub_0800FD8C(arg0, 1);
            break;
        }
        i++;
    } while (i < 4);
}
