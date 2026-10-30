unsigned short sub_08005290(unsigned short x)
{
    if (x & 1) {
        x = x + 1;
    }
    x = x << 1;
    return x;
}
