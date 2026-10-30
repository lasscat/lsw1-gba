struct Ent {
    char pad00[24];
    int f18;
    char pad1C[4];
    int f20;
    char pad24[32];
    unsigned short f44;
    char pad46[30];
};
extern struct Ent gUnknown_03002C50[];

void sub_08006A58(int index, int value)
{
    gUnknown_03002C50[index].f20 = value;
    gUnknown_03002C50[index].f18 = value;
    gUnknown_03002C50[index].f44 |= 0x8000;
}
