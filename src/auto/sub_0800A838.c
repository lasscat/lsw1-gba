extern void CpuFastSet(const void *src, void *dest, unsigned int count);
extern void *gUnknown_03003190;

void sub_0800A838(void *arg)
{
    CpuFastSet(gUnknown_03003190, arg, 0x80);
}
