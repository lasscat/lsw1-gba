extern unsigned char gUnknown_03002EC4[];
extern unsigned short gUnknown_03002FA0[];
void sub_0800AC6C(void *);
void sub_0800AF10(void *);
void sub_0800AAD4(void)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i <= 11; i++)
    {
        unsigned char *p = &gUnknown_03002EC4[i * 8];
        if (*p & 1)
            sub_0800AC6C(p);
    }
    for (j = 0; j <= 11; j++)
    {
        unsigned short *q = &gUnknown_03002FA0[j * 10];
        if (*q & 1)
            sub_0800AF10(q);
    }
}
