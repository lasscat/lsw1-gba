extern int gUnknown_03002F9C;
extern unsigned char gUnknown_03002FA0[];

void sub_0800AA9C(void *);

void sub_0800AA58(void)
{
    unsigned int i;

    gUnknown_03002F9C = 0;
    for (i = 0; i <= 11; i++)
        sub_0800AA9C(gUnknown_03002FA0 + i * 20);
}
