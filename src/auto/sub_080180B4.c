extern unsigned char gUnknown_03004980[];
extern unsigned char gUnknown_0804BF40[];
extern int sub_0801811C(int index, int count, void *ptr);
extern unsigned short sub_08018028(const unsigned short *arr, int count);

int sub_080180B4(void)
{
    unsigned char *buf = gUnknown_03004980;
    unsigned char *ref;
    unsigned char *p;
    int i;
    if (sub_0801811C(0, 2, buf) == 0)
        goto fail; // FAKE: block-order goto places the shared fail block mid-function
    if (sub_08018028((const unsigned short *)buf, 0x10) == 0)
        goto loop; // FAKE: block-order goto skips over the fail block into the loop
fail:
    return 0;
loop:
    i = 0;
    ref = gUnknown_0804BF40;
    p = buf;
    do {
        unsigned char a = *p++;
        unsigned char b = *ref++;
        if (a != b)
            goto fail; // FAKE: block-order goto reuses the mid-function fail block
        i++;
    } while (i <= 7);
    return 1;
}
