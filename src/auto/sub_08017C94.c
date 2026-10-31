extern int gUnknown_03004980[];
void sub_08013828(void *arg0, int arg1, int arg2);

void sub_08017C94(void *src, int len)
{
    if (gUnknown_03004980[16] > 0) {
        *(unsigned char *)gUnknown_03004980[15] &= 0xFF >> (8 - gUnknown_03004980[16]);
        gUnknown_03004980[15]++;
        gUnknown_03004980[16] = 0;
    }
    sub_08013828((void *)gUnknown_03004980[15], src, len);
    gUnknown_03004980[15] += len;
}
