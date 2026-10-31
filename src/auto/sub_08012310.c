int sub_08011FC4(int *counter, unsigned int limit, unsigned int value, unsigned int flag, int index);

extern unsigned int gUnknown_03003430[];

unsigned int sub_08012310(unsigned int arg0, int arg1)
{
    unsigned int r4 = gUnknown_03003430[11];
    if (r4 != 0) {
        unsigned int b = gUnknown_03003430[12];
        if (r4 <= b) {
            sub_08011FC4((int *)&gUnknown_03003430[10], 0, r4 - 1, arg0, arg1);
        } else {
            unsigned int t1 = gUnknown_03003430[6] + gUnknown_03003430[7];
            unsigned int t2 = gUnknown_03003430[5] - 1;
            if (t1 < t2) {
                sub_08011FC4((int *)&gUnknown_03003430[10], 0, b - 1, arg0, arg1);
            } else {
                unsigned int v = r4 - t1 * b;
                sub_08011FC4((int *)&gUnknown_03003430[10], 0, v - 1, arg0, arg1);
            }
        }
    }
    return gUnknown_03003430[10];
}
