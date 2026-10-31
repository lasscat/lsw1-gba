extern unsigned char gUnknown_0805714C[];
extern void sub_080388A4(void *arg0, int arg1, int arg2);

struct S394B8
{
    struct S394B8 *next;
};

extern struct S394B8 *gUnknown_030024EC;

void sub_080394B8(int arg0, int arg1, int arg2, void *arg3)
{
    void *ex = arg3;
    int v1 = 0;
    int v5 = 0;
    struct S394B8 *node;
    struct S394B8 *next;

    if (gUnknown_0805714C[arg2 * 4] == 0xFF)
        v5 = 1;
    else
        v1 = gUnknown_0805714C[arg2 * 4] << 7;
    if (v1 != 0 || v5 != 0)
    {
        node = gUnknown_030024EC;
        while (node != 0)
        {
            next = node->next;
            if (((*(unsigned short *)((unsigned char *)node + 0xF2) & 0x80) != 0) && (node != ex) && (v5 != 0))
                sub_080388A4(node, 0, 0);
            node = next;
        }
    }
}
