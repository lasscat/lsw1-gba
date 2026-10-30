struct unk {
    unsigned char pad0[0xe2];
    unsigned char unk0e2;
    unsigned char unk0e3;
};

extern unsigned int sub_08004A5C(unsigned char, unsigned char);
void sub_080020FC(struct unk *obj, int val);
void sub_08000F50(void *arg);

void sub_0800D584(void *arg)
{
    unsigned char a;
    unsigned char b;
    unsigned int ret;
    unsigned int z;
    unsigned int *pd0;
    unsigned int r2;
    unsigned int *f;
    unsigned int v;
    unsigned char *pe1;
    a = ((unsigned char *)arg)[4];
    b = ((unsigned char *)arg)[5];
    ret = sub_08004A5C(a, b);
    if (ret == 0)
        return;
    pd0 = (unsigned int *)(ret + 0xd0);
    r2 = *pd0;
    if (r2 != 0) {
        f = (unsigned int *)(r2 + 0x58);
        *f |= 2;
        *pd0 = 0;
    }
    pe1 = (unsigned char *)ret + 0xe1;
    z = 0;
    *pe1 = 2;
    sub_080020FC((struct unk *)ret, 0x52);
    *(unsigned short *)((unsigned char *)ret + 0xf2) = z;
    *(unsigned short *)((unsigned char *)ret + 0xd8) = z;
    v = *(unsigned int *)((unsigned char *)ret + 0x58);
    v |= 0x30;
    v &= 0xFFFBFFFB;
    *(unsigned int *)((unsigned char *)ret + 0x58) = v;
    *(unsigned int *)((unsigned char *)ret + 0x8c) = z;
    *(unsigned int *)((unsigned char *)ret + 0x90) = z;
    *((unsigned char *)ret + 0x111) = 0;
    sub_08000F50((void *)ret);
}
