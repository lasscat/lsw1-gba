void sub_0802178C(void *arg0)
{
    if (*(int *)((char *)arg0 + 0xc) > 0x00EAFFFF) {
        *(unsigned int *)((char *)arg0 + 0x58) &= ~1;
    }
}
