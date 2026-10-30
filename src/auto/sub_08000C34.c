void sub_080021E8(void *arg0);
void sub_080023D8(void *arg0);

void sub_08000C34(void *arg0, unsigned int arg1, unsigned int arg2)
{
    *(unsigned int *)((char *)arg0 + 0xa0) = arg1;
    *(unsigned int *)((char *)arg0 + 0x9c) = arg1 + (arg2 << 1);
    if (arg1 != 0) {
        *(unsigned int *)((char *)arg0 + 0x9c) += (arg2 << 1);
        sub_080021E8(arg0);
        sub_080023D8(arg0);
    }
}
