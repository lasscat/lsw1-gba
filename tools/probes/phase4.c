/* Phase 4 compiler probes: small leaf functions of the game, rewritten as plain C.
   Check one with: python tools/probe_compiler.py tools/probes/phase4.c sub_08000494 0x08000494
   Names and struct layouts are placeholders until the real ones are known. */

#define NULL ((void *)0)

struct Node
{
    struct Node *next;
    unsigned char unk04[0x54];
    unsigned int flags;
};

struct Slot
{
    unsigned char flags;
    unsigned char unk01[11];
};

struct Owner
{
    unsigned char unk00[0xC4];
    struct Slot slots[8];
};

extern struct Node *gNodeList;

/* One of several empty stubs (0x0800C364, 0x0800C9AC, ...). */
void sub_0800C364(void)
{
}

void sub_08000494(struct Node *node)
{
    node->flags |= 2;
    node->flags &= ~1;
}

void sub_080005BC(unsigned int bits)
{
    struct Node *node;

    for (node = gNodeList; node != NULL; node = node->next)
        node->flags |= bits;
}

void sub_08000A74(struct Owner *owner, int i)
{
    owner->slots[i].flags |= 1;
}
