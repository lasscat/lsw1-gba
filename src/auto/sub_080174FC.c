int sub_080177BC(void);

short sub_080174FC(unsigned short x)
{
    unsigned int r = sub_080177BC() & 0x7FFF;
    int s = (short)x;
    return (short)((r * (s * 2 + 1) >> 15) - s);
}
