int sub_08017830(void);

short sub_08017544(unsigned short a)
{
    unsigned int r = sub_08017830() & 0x7FFF;
    int s = (short)a;
    return (short)(((r * (s * 2 + 1)) >> 15) - s);
}
