extern unsigned int gUnknown_03002F24;
void sub_0800A200(unsigned char, unsigned char, unsigned char, unsigned char);

void sub_0800A258(unsigned short *p)
{
    int i = 0;
    if (i < p[0]) {
        unsigned int *pg = &gUnknown_03002F24;
        unsigned char *q = (unsigned char *)p + 4;
        do {
            sub_0800A200(q[0], q[1], q[2], q[3]);
            *pg |= 1 << i;
            q += 4;
            i++;
        } while (i < p[0]);
    }
}
