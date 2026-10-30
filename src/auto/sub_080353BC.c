void sub_080353BC(void *arg)
{
    unsigned int *a = arg;
    unsigned int *b = *(unsigned int **)((unsigned char *)arg + 0x68);
    unsigned int x = b[3];
    unsigned int y = b[4];
    int m = 13;
    a[3] = x;
    a[4] = y;
    a[5] = x;
    a[6] = y;
    a[16] = b[16];
    {
        unsigned char *s = (unsigned char *)b + 0xb5;
        unsigned char *d = (unsigned char *)arg + 0xb5;
        unsigned int t = *s & 0xc;
        *d = (*d & -m) | t;
    }
}
