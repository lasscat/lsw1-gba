extern void sub_080188B8(void);
struct Node {
    struct Node *next;
    unsigned char pad[0xAD];
    signed char flags;
};
extern struct Node *gUnknown_030024EC;

void sub_08019D30(unsigned short mode)
{
    short a = 16;
    short b = 16;
    volatile unsigned short disp; // FAKE: target keeps the masked DISPCNT in a stack slot
    struct Node *n;

    *(volatile unsigned short *)0x04000050 = (unsigned short)(mode | 0xC0);
    disp = *(volatile unsigned short *)0x04000000 & 0xFFF8;
    if (disp & 0x100)
        *(volatile unsigned short *)0x04000008 |= 0x40;
    if (disp & 0x200)
        *(volatile unsigned short *)0x0400000A |= 0x40;
    if (disp & 0x400)
        *(volatile unsigned short *)0x0400000C |= 0x40;
    if (disp & 0x800)
        *(volatile unsigned short *)0x0400000E |= 0x40;

    if (disp & 0x1000) {
        for (n = gUnknown_030024EC; n; n = n->next) {
            signed char *f = &n->flags;
            *f |= 0x10;
        }
    }
    while (a > 0) {
        a -= 2;
        b -= 2;
        *(volatile unsigned short *)0x0400004C = (b << 12) | (a << 8) | (b << 4) | a;
        *(volatile unsigned short *)0x04000054 = a;
        sub_080188B8();
    }
    if (disp & 0x1000) {
        for (n = gUnknown_030024EC; n; n = n->next) {
            signed char *f = &n->flags;
            *f &= ~0x10;
        }
    }
}
