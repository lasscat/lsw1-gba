typedef unsigned int u32;

extern u32 gUnknown_030036A4;

void sub_08013DEC(u32 arg0, u32 arg1, u32 arg2)
{
    u32 *ptr = &gUnknown_030036A4;
    ptr[0] = arg0 | 0x80;
    ptr[1] = arg1;
    ptr[2] = arg2;
    ptr[3] = 0;
    ptr[4] = 0;
    ptr[5] = 0;
}
