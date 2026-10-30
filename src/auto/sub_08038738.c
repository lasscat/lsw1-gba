// Declarations for unmatched callees
void sub_08038024(void *arg);
void sub_0802AB1C(void *arg, unsigned int value);

void sub_08038738(void *arg)
{
    void *r4 = arg;
    unsigned int r5 = 0;
    
    *(unsigned int *)(r4 + 0x64) = 0;
    sub_08038024(arg);
    sub_0802AB1C(r4, 0x100);
    *(unsigned char *)(r4 + 0x112) = r5;
}
