extern char gUnknown_03002E14[];

int sub_08008068(int a)
{
    char *r1 = gUnknown_03002E14;
    int r2 = 0x54;
    int r0 = a * r2;
    r1 = r1 + 0x34;
    return *(int *)(r0 + r1);
}
