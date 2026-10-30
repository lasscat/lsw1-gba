void sub_0801530C(void *p, unsigned int r1)
{
    unsigned short *sp = (unsigned short *)p;
    r1 = r1 << 16;
    sp[1] = (sp[1] & 0xC1FF) | (r1 >> 7);
}
