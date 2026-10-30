struct Unknown
{
    unsigned char unk00[0xde];
    short unkde;
};

extern int sub_08013254(int, int, int, int);
extern int sub_08012F1C(int, int);

void sub_08000FA4(int *arg0, int arg1, int arg2, int arg3)
{
    int v;

    arg0[0x34 / 4] = arg1;
    arg0[0x38 / 4] = arg2;
    // FAKE: volatile on the two reloads; the ROM re-reads the fields it just stored and no plain C form stops agbcc from forwarding the store
    v = sub_08012F1C(sub_08013254(arg0[0xc / 4], arg0[0x10 / 4], *(volatile int *)(arg0 + 0x34 / 4), *(volatile int *)(arg0 + 0x38 / 4)) >> 8, arg3) >> 8;
    if (v <= 0)
        v = 1;
    ((struct Unknown *)arg0)->unkde = v + 1;
}
