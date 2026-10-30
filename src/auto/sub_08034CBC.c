typedef unsigned int u32;
typedef unsigned char u8;

void sub_08034CBC(void *arg)
{
    u32 *p = (u32 *)((u8 *)arg + 0xd4);
    *p |= 0x80;
}
