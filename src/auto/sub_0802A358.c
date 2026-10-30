void sub_0802A358(void *arg0, void *arg1)
{
    unsigned char *r2 = *(unsigned char **)((char *)arg0 + 4);
    *(unsigned int *)arg1 = (unsigned char)r2[0];
    *(unsigned int *)((char *)arg1 + 4) = (unsigned char)r2[1];
}
