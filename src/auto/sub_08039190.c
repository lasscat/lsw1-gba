extern unsigned int gUnknown_03007014;

void sub_08037548(void *arg0, int arg1, unsigned int arg2, int arg3);
void sub_0802A758(void *arg0, int arg1);
void sub_080013F4(void *arg0, unsigned int arg1, unsigned char arg2, int arg3);
void sub_08037AB0(void *arg0, int arg1, int arg2);

void sub_08039190(void *arg0)
{
    void *r4 = arg0;
    sub_08037548(r4, 5, gUnknown_03007014, 1);
    *(unsigned int *)(r4 + 0x58) &= 0xFFFBFFFF;
    sub_0802A758(r4, 4);
    *(int *)(r4 + 8) = -*(int *)(r4 + 8) * 5;
    sub_080013F4(r4 + 0x24, 0x80000000, *(unsigned char *)(r4 + 0x5f), *(int *)(r4 + 8));
    if (*(short *)(r4 + 0xd8) <= 0)
        sub_08037AB0(r4, 0x19, 0);
}
