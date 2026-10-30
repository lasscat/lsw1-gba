typedef unsigned int u32;
typedef unsigned char u8;

extern u32 gUnknown_03006698;

void sub_0801C19C(unsigned int arg);

void sub_0801C6AC(unsigned int arg)
{
    unsigned int i = 0;
    u32 *p = &gUnknown_03006698;
    while (i <= 5) {
        if (*p == arg) {
            *p = 0;
            if (p[1] != 0) {
                sub_0801C19C(p[1]);
                p[1] = 0;
            }
        }
        p = (u32 *)((u8 *)p + 0x14);
        i++;
    }
}
