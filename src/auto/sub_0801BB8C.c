extern unsigned char gUnknown_030049F0[];

int sub_0801BB8C(int a, int b)
{
    int n = gUnknown_030049F0[0x40E];
    int d = a - b;
    if (d < 0)
        goto neg;
    if (d > n)
        goto clamp;
    return b;
neg:
    if (b - a <= n)
        goto done;
clamp:
    if (b > a)
        b = a + gUnknown_030049F0[0x40E];
    else
        b = a - gUnknown_030049F0[0x40E];
done:
    return b;
}
