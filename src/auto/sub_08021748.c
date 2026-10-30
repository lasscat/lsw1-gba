extern unsigned char gUnknown_030069EC;
extern int gUnknown_030069DC;

void sub_08021748(void *arg0)
{
    if (gUnknown_030069EC == 1 && gUnknown_030069DC < 0) {
        *(unsigned int *)((char *)arg0 + 0x58) &= ~1;
    }
}
