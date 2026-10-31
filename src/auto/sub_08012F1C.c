int sub_08043C3C_from_thumb(int a, int b);

int sub_08012F1C(int r0, int r1)
{
    r0 <<= 6;
    if (r1 < 0) {
        r1 += 63;
    }
    r1 >>= 6;
    r0 = sub_08043C3C_from_thumb(r0, r1);
    r0 <<= 4;
    return r0;
}
