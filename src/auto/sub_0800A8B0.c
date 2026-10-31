extern unsigned int gUnknown_03003190[];
void sub_08013828(void *, int, int);
void sub_0800A680(void *, void *, int);

void sub_0800A8B0(void *a)
{
    if (gUnknown_03003190[0xC] == (unsigned int)a)
        return;
    if (gUnknown_03003190[0xC] != 0 && gUnknown_03003190[0xC] != 0x080481E4) {
        sub_08013828(&gUnknown_03003190[4], 0x08048224, 32);
        sub_0800A680((void *)0x05000000, (void *)0x05000000, 1024);
        sub_0800A680((void *)gUnknown_03003190[0], (void *)gUnknown_03003190[0], 512);
        sub_0800A680((void *)gUnknown_03003190[2], (void *)gUnknown_03003190[2], 512);
    }
    gUnknown_03003190[0xC] = (unsigned int)a;
    sub_08013828(&gUnknown_03003190[4], (int)a, 32);
    if (a == (void *)0x080481E4)
        return;
    sub_0800A680((void *)0x05000000, (void *)0x05000000, 1024);
    sub_0800A680((void *)gUnknown_03003190[0], (void *)gUnknown_03003190[0], 512);
    sub_0800A680((void *)gUnknown_03003190[2], (void *)gUnknown_03003190[2], 512);
}
