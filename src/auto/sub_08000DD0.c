
void sub_08000DD0(void *arg0, int arg1, int arg2)
{
    *(int *)((char *)arg0 + 0x24) = arg1;
    *(int *)((char *)arg0 + 0x28) = arg2;
}
