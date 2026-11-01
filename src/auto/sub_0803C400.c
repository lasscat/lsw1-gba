extern void *sub_08004A14(unsigned char, unsigned char);
extern void *sub_0803C430(void *);

void *sub_0803C400(unsigned char a, unsigned char b)
{
    void *ret = sub_08004A14(a, b);
    return sub_0803C430(ret);
}
