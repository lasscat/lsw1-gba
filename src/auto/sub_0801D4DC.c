extern void sub_08000D7C(void *arg0, int arg1, int arg2);

void sub_0801D4DC(void *arg0, int arg1, int arg2)
{
    arg1 = (int)(short)arg1 - ((*(unsigned char *)((char *)arg0 + 0x96)) >> 1);
    sub_08000D7C(arg0, (int)((short)arg1 << 16), (int)(arg2 << 16));
}
