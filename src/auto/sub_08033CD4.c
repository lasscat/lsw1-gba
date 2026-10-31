struct Node
{
    unsigned char unk00[0x0c];
    unsigned int unk0c;
    unsigned int unk10;
    unsigned char unk14[0x2c];
    unsigned int unk40;
    unsigned char unk44[0x24];
    struct Node *unk68;
    unsigned char unk6c[0x49];
    unsigned char unkB5;
    unsigned char unkB6[0x2c];
    unsigned char unkE2;
};

void sub_08000494(struct Node *node);
void sub_08000D00(void *arg0, int arg1);
extern int sub_0801419C(int x, int y);

void sub_08033CD4(struct Node *a)
{
    int m = 13;
    int t;
    int v;

    {
        unsigned char *s = (unsigned char *)a->unk68 + 0xb5;
        unsigned char *d = (unsigned char *)a + 0xb5;
        unsigned int u = *s & 0xc;
        *d = (*d & -m) | u;
    }

    a->unk0c = a->unk68->unk0c;
    a->unk10 = a->unk68->unk10;

    if ((unsigned char)(a->unk68->unkE2 - 2) <= 1) {
        sub_08000494(a);
    }

    t = (a->unk68->unk40 - a->unk40) * 7;
    if (t < 0) {
        t += 63;
    }
    v = t >> 22;
    if (v > 5) {
        v = 5;
    } else if (v < 0) {
        v = 0;
    }

    a->unk40 = sub_0801419C(a->unk68->unk0c, a->unk68->unk10);

    {
        unsigned char *s = (unsigned char *)a->unk68 + 0xb5;
        unsigned char *d = (unsigned char *)a + 0xb5;
        unsigned int u = *s & 0xc;
        *d = (*d & -m) | u;
    }

    sub_08000D00(a, v);
}
