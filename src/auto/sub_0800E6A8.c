extern void sub_080137A0(void *, int, int);
extern void *gUnknown_030031D0;
extern unsigned int gUnknown_030031D4;

void sub_0800E6A8(void)
{
    unsigned int i = 0;
    if (i < gUnknown_030031D4) {
        do {
            sub_080137A0(gUnknown_030031D0, 0, 8);
            i = i + 1;
        } while (i < gUnknown_030031D4);
    }
    gUnknown_030031D4 = 0;
}
