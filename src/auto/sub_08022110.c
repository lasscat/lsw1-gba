extern void sub_0800EABC(int, int, int, int);
extern void sub_0801D4A8(int, int);

struct S069F0 {
    int unk0;
    signed char unk4;
    unsigned char pad[3];
    int arr[3];
};
extern struct S069F0 *gUnknown_030069F0;

void sub_08022110(void)
{
    unsigned int i = 0;
    do {
        int v = gUnknown_030069F0->unk4;
        int a = 13;
        if (i == (unsigned int)v)
            a = 9;
        sub_0800EABC(0, a, 0, 0);
        sub_0801D4A8(gUnknown_030069F0->arr[i], i + 22);
        i++;
    } while (i <= 2);
}
