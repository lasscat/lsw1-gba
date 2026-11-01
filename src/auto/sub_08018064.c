extern unsigned int gUnknown_03004980[];

void sub_08013828(void *, const void *, int);
int sub_08018028(const unsigned short *, int);
int sub_08018198(int, int, int);

int sub_08018064(void)
{
    sub_08013828(gUnknown_03004980, (void *)0x0804BF40, 0x10);
    {
        unsigned short sum = sub_08018028((unsigned short *)gUnknown_03004980, 0x10);
        ((unsigned short *)gUnknown_03004980)[7] = -sum;
    }
    return sub_08018198(0, 2, (int)gUnknown_03004980);
}
