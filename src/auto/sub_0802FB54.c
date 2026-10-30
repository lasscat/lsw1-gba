extern int sub_0802FB0C(void);
extern void sub_0802E098(void *arg0, int arg1);

void sub_0802FB54(void *arg0)
{
    unsigned char *r4 = arg0;
    unsigned int r6;
    unsigned char *r5;
    unsigned int r0;
    
    r0 = sub_0802FB0C();
    r6 = r0 << 2;
    r5 = r4 + 0xfd;
    r0 = *r5;
    if (r6 != r0) {
        sub_0802E098(r4, 0);
        *(unsigned int *)(r4 + 0xe8) = 0;
    }
    *r5 = r6;
}
