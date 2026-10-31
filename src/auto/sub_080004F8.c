struct Node
{
    struct Node *next;
    unsigned char unk04[0x54];
    unsigned int flags;
};

struct Queue
{
    struct Node *head;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0A;
};

extern struct Queue gUnknown_030024EC;
extern struct Queue gUnknown_030024E0;

void sub_08001858(struct Node *node);
void sub_08002174(struct Node *node, unsigned int bits);

void sub_080004F8(void)
{
    struct Node *node = gUnknown_030024EC.head;

    while (node != 0)
    {
        sub_08001858(node);
        sub_08002174(node, 0x80000);
        node = node->next;
    }
    gUnknown_030024E0.head = gUnknown_030024EC.head;
    gUnknown_030024E0.unk04 = gUnknown_030024EC.unk04;
    gUnknown_030024EC.head = 0;
    gUnknown_030024EC.unk04 = 0;
    gUnknown_030024E0.unk08 = gUnknown_030024EC.unk08;
    gUnknown_030024E0.unk0A = gUnknown_030024EC.unk0A;
    gUnknown_030024EC.unk08 = 0;
    gUnknown_030024EC.unk0A = 0;
}
