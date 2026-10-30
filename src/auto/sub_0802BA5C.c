void sub_0802BA5C(void *arg0)
{
    unsigned int **r3 = (unsigned int **)((char *)arg0 + 0x10C);
    unsigned int *r2 = *r3;
    if (r2 != 0) {
        r2[0x16] = r2[0x16] | 2; /* r2[0x58/4] */
        *r3 = 0;
    }
}
