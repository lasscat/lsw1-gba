void sub_08001DD4(void *arg0, void *arg1)
{
    unsigned char *p0 = (unsigned char *)arg0;
    signed int *p1 = (signed int *)arg1;
    
    p1[1] = (signed char)p0[0x72];
    p1[3] = (signed char)p0[0x73];
    p1[0] = (signed char)p0[0x70];
    p1[2] = (signed char)p0[0x71];
}
