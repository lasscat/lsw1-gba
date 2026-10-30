void sub_08034EB8(void *arg0)
{
    unsigned char *r1 = arg0;
    unsigned char *r0 = *(unsigned char **)(r1 + 0x68);
    if (r0[0x5c] == 1) {
        r1[0xb5] = (r1[0xb5] & 0x0f) | 0x10;
    }
}
