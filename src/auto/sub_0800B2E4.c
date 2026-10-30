int sub_08004A5C(int, int);
void sub_0801C6AC(void);

void sub_0800B2E4(void *arg)
{
    unsigned char *p = (unsigned char *)arg;
    if (sub_08004A5C(p[4], p[5]) != 0) {
        sub_0801C6AC();
    }
}
