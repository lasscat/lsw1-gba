extern void *gUnknown_030069D8;
void *sub_08000234(void);
void sub_08020E9C(void);

void sub_08020DE0(void)
{
    *(void **)((unsigned char *)gUnknown_030069D8 + 0x5c) = sub_08000234();
    sub_08020E9C();
}
