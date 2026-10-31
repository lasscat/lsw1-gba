struct Ent
{
    int f0;
    int f4;
    int f8;
    int fc;
};

extern struct Ent gUnknown_03003678[];
extern int gUnknown_03003688;

void sub_0801395C(int arg0, void *arg1, void *arg2)
{
    int p = (int)((char *)arg1 + 0x10);
    int len = (char *)arg2 - (char *)arg1 - 0x10;
    gUnknown_03003678[arg0].f0 = p;
    gUnknown_03003678[arg0].f4 = p;
    gUnknown_03003678[arg0].f8 = len;
    gUnknown_03003678[arg0].fc = (int)arg2;
    *(int *)gUnknown_03003678[arg0].f0 = 0;
    *((int *)gUnknown_03003678[arg0].f0 + 1) = 0;
    *((int *)gUnknown_03003678[arg0].f0 + 2) = 0;
    *((int *)gUnknown_03003678[arg0].f0 + 3) = 0;
    gUnknown_03003688++;
}
