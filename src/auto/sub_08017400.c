int sub_080177BC(void);

int sub_08017400(int a, int b)
{
    int r;
    if (a == b)
        return a;
    r = sub_080177BC();
    r &= 0x7FFF;
    r = (b - a + 1) * r >> 15;
    return a + r;
}
