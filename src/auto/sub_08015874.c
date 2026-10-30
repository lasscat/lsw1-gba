typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 gUnknown_030048A0[];

void sub_08015874(int r0)
{
    u8 *r1;
    u16 *p;
    r1 = &gUnknown_030048A0[0];
    r1 = (u8 *)((u32)r1 + (r0 << 3));
    p = (u16 *)(r1 + 4);
    if (*p != 0) {
        (*p)--;
        if (*p == 0) {
            r1[6] &= 0xFE;
        }
    }
}
