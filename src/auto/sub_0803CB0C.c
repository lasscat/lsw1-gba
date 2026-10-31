void *sub_08000234(void);
extern void sub_08002138(void *arg0, unsigned int arg1);
extern void sub_080020FC(void *obj, int val);
extern void sub_0800966C(void);
extern unsigned char gUnknown_05000009[];
extern unsigned char gUnknown_0500000C[];

struct Node
{
    unsigned char unk00[0x58];
    void *unk58;
    unsigned char unk5C[0x30];
    void (*unk8C)(void);
    unsigned char unk90[0x25];
    unsigned char unkB5;
    unsigned char unkB6[9];
    unsigned char unkBF;
    unsigned char unkC0[0x20];
    unsigned char unkE0;
    unsigned char unkE1;
    unsigned char unkE2;
    unsigned char unkE3;
    unsigned char unkE4[4];
    struct Node *unkE8;
    unsigned char unkEC[4];
    unsigned char unkF0;
    unsigned char unkF1;
    unsigned char unkF2;
    unsigned char unkF3;
    unsigned char unkF4;
    unsigned char unkF5;
    unsigned char unkF6;
    unsigned char unkF7[9];
    unsigned char unk100;
    unsigned char unk101[2];
    unsigned char unk103;
};

struct Node *sub_0803CB0C(void)
{
    struct Node *a;
    unsigned int u;

    a = sub_08000234();
    a->unk58 = gUnknown_05000009;
    a->unkBF = 0x80;
    sub_08002138(a, 3);
    sub_080020FC(a, 0);
    a->unkF3 = 0;
    a->unkF0 = 0;
    a->unkF2 = 0;
    a->unk103 = 0;
    a->unkF1 = 0;
    a->unk100 = 0;
    a->unkF6 = 3;
    a->unkE8 = sub_08000234();
    a->unkE8->unkE0 = 100;
    a->unkE8->unk58 = gUnknown_0500000C;
    u = a->unkE8->unkB5 & -13;
    a->unkE8->unkB5 = u | 4;
    a->unkE8->unkBF = 0x80;
    a->unkE8->unk8C = sub_0800966C;
    a->unkF5 = 0;
    return a;
}
