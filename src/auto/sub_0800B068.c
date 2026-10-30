extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800B068(unsigned char *a)
{
    unsigned int p = sub_08004A5C(a[4], a[5]);
    if (p != 0) {
        if (a[6] > 31) {
            *(unsigned int *)(p + 0xd4) &= ~(1u << (a[6] - 32));
        } else {
            *(unsigned int *)(p + 0x58) &= ~(1u << a[6]);
        }
    }
}
