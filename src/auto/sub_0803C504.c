void *sub_08004A14(unsigned char, unsigned char);
void *sub_0803C534(void *);

void *sub_0803C504(unsigned char r0, unsigned char r1)
{
    void *p;
    p = sub_08004A14(r0, r1);
    return sub_0803C534(p);
}
