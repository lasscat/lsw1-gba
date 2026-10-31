void sub_08037FF8(void *arg);
void sub_0802AB1C(void *arg, unsigned int value);
extern void sub_08037798(void *obj, int val);
extern void sub_08036AF0(unsigned int obj, unsigned int val);

void sub_08038830(void *arg0, void *arg1)
{
    sub_08037FF8(arg0);
    *(void **)(arg0 + 0x64) = arg1;
    *(unsigned char *)(arg0 + 0x112) = 3;
    sub_0802AB1C(arg0, 0x200);
    if ((*(unsigned int *)(arg0 + 0xD4) & 0x400) == 0) {
        sub_08037798(arg0, 1);
        *(unsigned int *)(arg0 + 0xD4) |= 0x400;
    }
    if ((*(unsigned short *)(arg0 + 0xF2) & 0x20) == 0)
        sub_08036AF0((unsigned int)arg0, 0);
}
