struct Copy { unsigned int a, b, c; };

void sub_08003E04(void *r0, void *r1)
{
    struct Copy *r2 = (struct Copy *)((char *)r0 + 0x4c);
    *r2 = *(struct Copy *)r1;
    ((unsigned int *)((char *)r0 + 0xd4))[0] |= 0x40;
}
