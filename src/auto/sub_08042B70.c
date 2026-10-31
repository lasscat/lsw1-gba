extern unsigned int gUnknown_0300340C;

void sub_08042BE8(void *arg0);
void sub_08042C80(void);
void sub_08042D08(void);

void sub_08042B70(void *r0)
{
    void *r2 = r0;
    unsigned short *r1;
    r1 = (unsigned short *)((char *)r2 + 0xdc);
    if (*r1 == 0) {
        return;
    }
    (*r1)--;
    if (*r1 != 0) {
        return;
    }
    *(unsigned char *)((char *)r2 + 0x94) = 2;
    *(unsigned char *)((char *)r2 + 0x95) = 2;
    if (*(unsigned int *)((char *)r2 + 0x68) == *(unsigned int *)&gUnknown_0300340C) {
        *(void **)((char *)r2 + 0x8c) = (void *)sub_08042C80;
    } else {
        *(void **)((char *)r2 + 0x8c) = (void *)sub_08042D08;
    }
    *(void **)((char *)r2 + 0x60) = (void *)sub_08042BE8;
    *(unsigned short *)((char *)r2 + 0xdc) = 200;
}
