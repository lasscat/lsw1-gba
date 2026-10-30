extern void sub_08037548(void *arg0, int arg1, unsigned int arg2, int arg3);

extern unsigned int gUnknown_03007014;

void sub_080392B4(void *arg0)
{
    sub_08037548(arg0, 0x19, gUnknown_03007014, 1);
    ((unsigned int *)arg0)[0x58 / 4] &= 0xFFFBFFFF;
}
