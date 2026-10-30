extern unsigned int gUnknown_0300340C;

void sub_0802ABAC(void *a0, void *a1, void *a2);

void sub_0802AF4C(void *arg0)
{
    void *r3 = arg0;
    void *r0 = *(void **)((char *)r3 + 0x64);
    if (r0) {
        void *r1 = *(void **)((char *)r0 + 0xc);
        void *r2 = *(void **)((char *)r0 + 0x10);
        sub_0802ABAC(r3, r1, r2);
        return;
    }
    r0 = *(void **)&gUnknown_0300340C;
    {
        void *r1 = *(void **)((char *)r0 + 0xc);
        void *r2 = *(void **)((char *)r0 + 0x10);
        sub_0802ABAC(r3, r1, r2);
    }
}
