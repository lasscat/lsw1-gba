typedef unsigned short u16;
typedef unsigned char u8;

extern void sub_0800E0AC(void *, void *);
extern unsigned char gUnknown_06010000[];

void sub_0801E5B0(void *arg0, void *arg1)
{
    u16 idx = *(u16 *)((u8 *)arg0 + 0xba);
    void *tile = (void *)(gUnknown_06010000 + (idx << 5));
    sub_0800E0AC(arg1, tile);
}
