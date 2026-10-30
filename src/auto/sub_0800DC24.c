struct Sub0800DC24Node {
    struct Sub0800DC24Node *next;
    unsigned char unk_04[84];
    unsigned int unk_58;
    unsigned char unk_5C;
    unsigned char unk_5D;
    unsigned char unk_5E[130];
    unsigned char unk_E0;
};

extern struct Sub0800DC24Node *gUnknown_030024EC;

void sub_0800DC24(void)
{
    struct Sub0800DC24Node *p;
    struct Sub0800DC24Node *next;
    for (p = gUnknown_030024EC; p != 0; p = next)
    {
        next = p->next;
        if ((((p->unk_5C == 0xD) || (p->unk_5C == 0x12)) && (p->unk_5D == 0xFF) && (p->unk_E0 == 0x12)) || ((p->unk_5C == 0x14) && (p->unk_E0 == 0x38)))
            p->unk_58 |= 2;
    }
}
