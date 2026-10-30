extern int sub_08011850(const char *a, const char *b, int c);
extern char *gUnknown_03006714;

void *sub_0801D0AC(const char *a)
{
    if (sub_08011850(a, gUnknown_03006714, 0x400) == 0) {
        return gUnknown_03006714;
    }
    return 0;
}
