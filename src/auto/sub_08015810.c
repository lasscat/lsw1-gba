typedef unsigned short u16;
typedef unsigned char u8;

extern void sub_08015740(void *arg0, void *arg1);
extern void sub_080156D8(void *arg0, void *arg1);

void sub_08015810(void *arg0)
{
    void *q = *(void **)((u8 *)arg0 + 0xac);
    if (q != 0) {
        if (*(u16 *)((u8 *)arg0 + 0xbc) & 1) {
            sub_08015740(arg0, q);
        } else {
            sub_080156D8(arg0, q);
        }
        *(void **)((u8 *)arg0 + 0xac) = 0;
        *(u16 *)((u8 *)arg0 + 0xbc) &= 0xFDFF;
    }
}
