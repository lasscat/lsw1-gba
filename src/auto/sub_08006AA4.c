struct S08006AA4 {
    char pad0[28];
    int f1C;
    char pad20[4];
    int f24;
    char pad28[28];
    unsigned short f44;
    char pad46[30];
};

extern struct S08006AA4 gUnknown_03002C50[];

void sub_08006AA4(int a, int b)
{
    gUnknown_03002C50[a].f24 = b;
    gUnknown_03002C50[a].f1C = b;
    gUnknown_03002C50[a].f44 |= 0x8000;
}
