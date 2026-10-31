extern int gUnknown_0804BA04[];

void sub_08003F40(void *a)
{
    unsigned short s1;
    unsigned short s2;

    s1 = (*(unsigned short *)((char *)a + 0x4C) += *(unsigned short *)((char *)a + 0x50));
    *(int *)((char *)a + 0x14) += gUnknown_0804BA04[255 & ~(((s1 << 16) >> 24) + 64)] * *(short *)((char *)a + 0x54);
    s2 = (*(unsigned short *)((char *)a + 0x4E) += *(unsigned short *)((char *)a + 0x52));
    *(int *)((char *)a + 0x18) += gUnknown_0804BA04[255 - (((unsigned)(s2 << 16)) >> 24)] * *(short *)((char *)a + 0x56);
}
