typedef unsigned char u8;
typedef unsigned int u32;

struct ListEntry
{
    struct ListEntry *next;
};

extern struct ListEntry *gUnknown_030024EC;

void sub_08001E98(void)
{
    struct ListEntry *p = gUnknown_030024EC;

    while (p != 0) {
        if ((*(u32 *)((u8 *)p + 0x58) & 0x20000) == 0) {
            *(u32 *)((u8 *)p + 0xd4) |= 0x20000000;
        }
        p = p->next;
    }
}
