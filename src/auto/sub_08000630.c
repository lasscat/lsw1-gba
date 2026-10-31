typedef struct {
    unsigned short unk0;
    unsigned short unk2;
    unsigned char pad[8];
} Item12;

typedef struct Node0630 {
    struct Node0630 *next;
    unsigned char pad1[180];
    unsigned short fldB8;
    unsigned short fldBA;
    unsigned short fldBC;
    unsigned char pad2[10];
    Item12 items[1];
} Node0630;

extern Node0630 *gUnknown_030024EC;

void sub_08000630(void)
{
    Node0630 *p = gUnknown_030024EC;
    unsigned char i;

    while (p != 0) {
        p->fldBA |= 0xFFFF;
        p->fldB8 = 0;
        if (p->fldBC & 0x40) {
            i = 0;
            do {
                p->items[i].unk2 |= 0xFFFF;
                p->items[i].unk0 = 0;
                i++;
            } while (i == 0);
        }
        p = p->next;
    }
}
