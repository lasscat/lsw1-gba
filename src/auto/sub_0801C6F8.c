typedef unsigned int u32;
typedef unsigned char u8;

extern u32 gUnknown_03006698;

int sub_0801C6F8(void)
{
    int i = 0;
    u32 *p = &gUnknown_03006698;
    while (i <= 5) {
        u32 v = *p;
        p = (u32 *)((u8 *)p + 0x14);
        if (v == 0) {
            return i;
        }
        i++;
    }
    return 6;
}
