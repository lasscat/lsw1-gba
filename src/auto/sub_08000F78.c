void sub_08000F78(int *arg0, int arg1, int arg2, int arg3)
{
    arg0[0x34 / 4] = arg1;
    arg0[0x38 / 4] = arg2;
    arg3 += 1;
    *(short *)((int)arg0 + 0xde) = arg3;
}
