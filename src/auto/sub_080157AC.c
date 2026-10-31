typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct E { u32 a; u32 b; };
extern struct E gUnknown_030048A0[];
extern void sub_08015874(int);
static inline u16 ident16(u16 x) { return x; }
void sub_080157AC(void *arg0)
{
    u32 v1 = *(u32 *)((u8 *)arg0 + 0x58);
    if ((v1 & 0x200000) != 0) {
        unsigned int v = *(u8 *)((u8 *)arg0 + 0xB5) >> 4;
        *(u32 *)((u8 *)arg0 + 0x58) = v1 & 0xFFDFFFFF;
        *(void **)((u8 *)arg0 + 0xAC) = (void *)gUnknown_030048A0[v].a;
        *(u16 *)((u8 *)arg0 + 0xBC) = ident16(*(u16 *)((u8 *)arg0 + 0xBC));
        sub_08015874(v);
    }
}
