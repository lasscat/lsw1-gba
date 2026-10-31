extern unsigned int gUnknown_03003250[];

void sub_0800F548(unsigned int *dst, int n, int c)
{
    int count;

    if (gUnknown_03003250[11] == 1) {
        c = (c << 24) + (c << 16) + (c << 8) + c;
        count = n * 16;
    } else {
        c &= 15;
        c += c << 4;
        c += c << 8;
        c += c << 16;
        count = n * 8;
    }
    count--;
    while (count != -1) {
        *dst++ = c;
        count--;
    }
}
