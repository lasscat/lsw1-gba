extern unsigned int sub_08004A5C(unsigned char, unsigned char);

unsigned int sub_08005350(unsigned int r0, unsigned int r1)
{
    if (r0 != 0 || r1 != 0) {
        unsigned char c0 = (unsigned char)r0;
        unsigned char c1 = (unsigned char)r1;
        return sub_08004A5C(c0, c1);
    }
    return 0;
}
