extern unsigned int gUnknown_03004E10[];

typedef struct {
    unsigned int a;
    unsigned int b;
} Unk0801B070;

void sub_0801B070(Unk0801B070 *arg)
{
    gUnknown_03004E10[1] = arg->a;
    gUnknown_03004E10[2] = arg->b;
}
