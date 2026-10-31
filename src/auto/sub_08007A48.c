extern unsigned int gUnknown_03002E68[];

void sub_08007A48(void *r0, int r1)
{
    unsigned int *base = gUnknown_03002E68;
    unsigned int *p = base + (r1 << 1);
    unsigned int r2 = p[1];
    unsigned int r1v = p[0];
    ((unsigned int *)r0)[0] = r1v;
    ((unsigned int *)r0)[1] = r2;
}
