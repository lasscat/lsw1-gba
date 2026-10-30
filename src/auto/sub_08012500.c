extern void **gUnknown_030034A4;
extern void sub_08012A3C(void);

void sub_08012500(void *arg)
{
    if (arg == 0)
        *gUnknown_030034A4 = (void *)sub_08012A3C;
    else
        *gUnknown_030034A4 = arg;
}
