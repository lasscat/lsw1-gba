int sub_0800EB7C(int);
int sub_0800EBF0(int);
void sub_08000D7C(void *, int, int);

void sub_0801D514(void *arg0, int arg1, short arg2, short arg3, int flags)
{
    if (flags & 1)
        arg2 -= (sub_0800EB7C(arg1) + 1) / 2;
    if (flags & 2)
        arg2 -= sub_0800EB7C(arg1);
    if (flags & 4)
        arg3 -= (sub_0800EBF0(arg1) + 1) / 2;
    if (flags & 8)
        arg3 -= sub_0800EBF0(arg1);
    sub_08000D7C(arg0, arg2 << 16, arg3 << 16);
}
