extern void *gUnknown_03007014;

void sub_080013F4(void *arg0, unsigned int arg1, unsigned char arg2, void *arg3);
void sub_0802A758(void *arg0, int arg1);
void sub_08037548(void *arg0, int arg1, void *arg2, int arg3);

void sub_08038B1C(void *arg0)
{
    void *r4 = arg0;
    if (*(unsigned short *)(r4 + 0xf2) & 0x40)
    {
        sub_0802A758(r4, 2);
    }
    else
    {
        sub_0802A758(r4, 1);
    }
    sub_080013F4(r4 + 0x24, 0x80000000, *(unsigned char *)(r4 + 0x5f), *(void **)(r4 + 8));
    sub_08037548(r4, 0x13, gUnknown_03007014, 0);
}
