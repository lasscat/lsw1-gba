void sub_080136AC(void *arg);

void sub_0801DD0C(void *arg)
{
    unsigned int i = 0;

    if (i >= ((unsigned char *)arg)[0x32] || (*(void ***)((unsigned char *)arg + 0x44))[i] == 0)
        goto end;
loop:
    sub_080136AC((*(void ***)((unsigned char *)arg + 0x44))[i]);
    i++;
    if (i < ((unsigned char *)arg)[0x32] && (*(void ***)((unsigned char *)arg + 0x44))[i] != 0)
        goto loop;
end:
    sub_080136AC(*(void ***)((unsigned char *)arg + 0x44));
}
