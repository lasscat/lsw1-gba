struct Item {
    struct Item *next;
    unsigned char pad[88];
    unsigned char unk5c;
    unsigned char pad2[11];
    void *unk68;
    unsigned char pad3[116];
    unsigned char unkE0;
};

extern struct Item *gUnknown_030024EC;

struct Item *sub_080017D0(void *arg)
{
    struct Item *cur = gUnknown_030024EC;
    while (cur != 0) {
        struct Item *next = cur->next;
        if (cur->unk5c == 0x14) {
            if (cur->unkE0 == 0x1b || cur->unkE0 == 0x19) {
                if (cur->unk68 == arg)
                    return cur;
            }
        }
        cur = next;
    }
    return 0;
}
