struct Node
{
    char unk0[8];
    struct Node *next;
    struct Node *prev;
};

struct Slot
{
    struct Node *head;
    char pad[12];
};

struct Tbl
{
    int unk0;
    struct Slot slots[8];
};

extern struct Tbl gUnknown_03003678;

void sub_08013ADC(struct Node *a, int b)
{
    if (a->prev != 0)
    {
        a->prev->next = a->next;
    }
    else
    {
        gUnknown_03003678.slots[b].head = a->next;
    }
    if (a->next != 0)
    {
        a->next->prev = a->prev;
    }
}
