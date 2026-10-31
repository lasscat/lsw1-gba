extern unsigned int gUnknown_03004980[];

unsigned short sub_08018028(const unsigned short *arr, int count);
int sub_0801811C(int index, int count, void *ptr);
int sub_08018198(int, int, int);

int sub_08017FA8(void)
{
    unsigned int buf[4];
    int r;
    unsigned int *p;
    unsigned int *q;
    int n;

    r = sub_0801811C(0, 2, buf);
    if (r == 0)
        return 0;
    p = gUnknown_03004980;
    ((unsigned short *)p)[7] = 0;
    ((unsigned short *)p)[7] = -sub_08018028((const unsigned short *)p, 0x10);
    q = buf;
    for (n = 4; n != 0 && *p == *q; p++, q++, n--)
        ;
    if (n != 0)
        r = sub_08018198(0, 2, (int)gUnknown_03004980);
    return r;
}
