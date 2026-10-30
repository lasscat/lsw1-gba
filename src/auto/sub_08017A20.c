extern int gUnknown_03004980[];
void sub_08013828(void *arg0, int arg1, int arg2);

void sub_08017A20(void *src, int len)
{
    if (gUnknown_03004980[16] > 0) {
        gUnknown_03004980[15]++;
        gUnknown_03004980[16] = 0;
    }
    sub_08013828(src, gUnknown_03004980[15], len);
    gUnknown_03004980[15] += len;
}
