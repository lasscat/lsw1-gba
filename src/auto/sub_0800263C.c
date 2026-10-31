struct Node {
    struct Node *next;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char unk1C[0x58 - 0x1C];
    unsigned int flags58;
    unsigned char unk5C[0xD4 - 0x5C];
    unsigned int unkD4;
};
void sub_08001E64(void *arg0);
void sub_08002B50(void *arg0);
void sub_08003F40(void *arg0);
void sub_0800263C(struct Node **pp)
{
    struct Node *n = *pp;
    while (n != 0) {
        unsigned int a;
        unsigned int b;
        unsigned int v;
        sub_08002B50(n);
        a = n->unk14;
        b = n->unk18;
        n->unk0C = a;
        n->unk10 = b;
        if (n->flags58 & 0x2000) {
            sub_08001E64(n);
        }
        v = n->unkD4;
        if ((v & 0x40) != 0 && (n->flags58 & 0x80000) == 0 && (v & 0x20000000) == 0) {
            sub_08003F40(n);
        }
        n = n->next;
    }
}
