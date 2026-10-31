typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void sub_080156D8(void *arg0, void *arg1);
extern void sub_080157AC(void *arg0, void *arg1);
extern void sub_08015810(void *arg0);

void sub_08015A14(void *arg0, void *arg1)
{
    sub_080157AC(arg0, arg1);
    *(void **)((u8 *)arg0 + 0xac) = 0;
    *(u16 *)((u8 *)arg0 + 0xbc) &= 0xFDFF;
    sub_080156D8(arg0, arg1);
    if (*(u32 *)((u8 *)arg0 + 0x58) & 0x400) {
        sub_08015810(arg0);
    }
}
