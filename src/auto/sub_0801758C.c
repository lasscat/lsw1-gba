int sub_080177BC(void);

int sub_0801758C(unsigned short a)
{
    unsigned int v = sub_080177BC();
    unsigned int r = ((v & 0x7FFF) * 101) >> 15;
    if (a < r)
        return 0;
    return 1;
}
