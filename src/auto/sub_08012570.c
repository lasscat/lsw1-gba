extern int *gUnknown_030034A4;
extern void sub_08012A3C(void);

void sub_08012570(void *a0)
{
    if (a0 == 0)
        gUnknown_030034A4[1] = (int)sub_08012A3C;
    else
        gUnknown_030034A4[1] = (int)a0;
}
