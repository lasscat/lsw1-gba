int sub_080133A0(short a)
{
    int r = (a << 8) & 0x7FFFFF;
    if (a < 0)
        r = -r;
    return r;
}
