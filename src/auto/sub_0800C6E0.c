unsigned int sub_08004A5C(unsigned char a, unsigned char b);
void sub_0802E2CC(void);
void sub_08000F50(void *);
void sub_08002138(void *, unsigned int);
void sub_0801C19C(unsigned int);

extern unsigned int gUnknown_0300332C[];

void sub_0800C6E0(void *arg0)
{
    unsigned char v1;
    unsigned char v2;
    void *v4;
    unsigned int *r4;
    unsigned int *r5;
    unsigned char *p;
    unsigned int r6;

    v1 = *(unsigned char *)((char *)arg0 + 4);
    v2 = *(unsigned char *)((char *)arg0 + 5);
    v4 = (void *)sub_08004A5C(v1, v2);
    if (!v4)
        return;
    sub_0802E2CC();
    sub_08000F50(v4);
    p = (unsigned char *)((char *)v4 + 0x94);
    r6 = 0;
    *p = r6;
    if (*(unsigned int *)((char *)v4 + 0x68))
    {
        p = (unsigned char *)((char *)(*(unsigned int *)((char *)v4 + 0x68)) + 0x94);
        *p = r6;
    }
    sub_08002138(v4, 3);
    *(unsigned int *)((char *)v4 + 0xd4) |= 4;
    r4 = gUnknown_0300332C;
    r5 = (unsigned int *)((char *)r4 + 0xa0);
    sub_0801C19C(*r5);
    *r5 = r6;
    r4 = (unsigned int *)((char *)r4 + 0xa4);
    sub_0801C19C(*r4);
    *r4 = r6;
}
