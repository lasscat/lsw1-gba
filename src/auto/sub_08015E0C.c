typedef struct Node {
    struct Node *next;
    unsigned int unk04;
    unsigned int id;
    unsigned int pad0c[7];
    unsigned int flags;
} Node;

typedef struct Manager {
    Node *list;
    Node *head;
    unsigned char pad08[0x14];
    unsigned char flag1c;
    unsigned char pad1d[7];
    unsigned short count24;
} Manager;

extern Manager gUnknown_03004920;

void sub_08016144(Node *node);

void sub_08015E0C(unsigned int arg0)
{
    Node *node;
    Node *next;
    if (gUnknown_03004920.count24 != 0) {
        node = gUnknown_03004920.head;
        while (node != 0) {
            next = node->next;
            if (node->id == arg0) {
                sub_08016144(node);
                node->flags |= 0x8000;
            }
            node = next;
        }
        gUnknown_03004920.flag1c = 0;
    }
}
