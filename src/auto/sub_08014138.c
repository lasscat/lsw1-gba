void sub_08014138(char *r3, int *r1)
{
    int r2;

    r2 = *(short *)(r3 + 0x1a);
    r1[2] = r2 + *(signed char *)(r3 + 0x72);
    r2 = r2 + *(signed char *)(r3 + 0x73);
    r1[3] = r2;

    r2 = *(short *)(r3 + 0x16);
    r1[1] = r2 + *(signed char *)(r3 + 0x71);
    r2 = r2 + *(signed char *)(r3 + 0x70);
    r1[0] = r2;
}
