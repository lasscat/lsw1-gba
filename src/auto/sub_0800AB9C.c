extern unsigned char gUnknown_03002EC4[];
void sub_0800ABE0(void *);

void sub_0800AB9C(void)
{
    unsigned int i;
    unsigned char *p;

    for (i = 0; i <= 11; i++) {
        p = gUnknown_03002EC4 + i * 8;
        if (p[0] & 1)
            sub_0800ABE0(p);
    }
}
