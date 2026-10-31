extern void *gUnknown_03003190[];
void sub_08013828(void *, int, int);
extern void CpuFastSet(void *src, void *dst, unsigned int mode);
void sub_08009ED8(char *a)
{
    sub_08013828(gUnknown_03003190[0], (int)a, 512);
    CpuFastSet(gUnknown_03003190[1], a, 256);
    a += 512;
    sub_08013828(gUnknown_03003190[2], (int)a, 512);
    CpuFastSet(gUnknown_03003190[3], a, 256);
}
