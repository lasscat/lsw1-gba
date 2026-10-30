extern int sub_08008948(void *arg0, void *arg1);
extern void sub_08010BE4(void *arg0, int arg1, int arg2);
extern void sub_08037BCC(void *arg0, int arg1, int arg2);

void sub_080093B8(void *arg0, void *arg1)
{
    void *r4 = arg0;
    void *r5 = arg1;

    if (*(void **)((char *)r4 + 0x68) == r5)
        goto epilogue;

    if (*(unsigned char *)((char *)r5 + 0x5c) == 1) {
        if ((*(unsigned short *)((char *)r4 + 0xf0) & 0x1000) == 0)
            goto epilogue;

        if (sub_08008948(r4, r5) != 0)
            goto epilogue;

        if (*(unsigned char *)((char *)r4 + 0xe0) == 0x43) {
            sub_08010BE4(r5, *(unsigned char *)((char *)r4 + 0x114), 6);
        } else if (*(unsigned char *)((char *)r4 + 0xe0) == 0x4a) {
            sub_08010BE4(r5, *(unsigned char *)((char *)r4 + 0x114), 0xa);
        } else {
            sub_08010BE4(r5, *(unsigned char *)((char *)r4 + 0x114), 1);
        }
    } else if (*(unsigned char *)((char *)r5 + 0x5c) == 0xc) {
        if ((*(unsigned short *)((char *)r4 + 0xf0) & 0x1000) == 0)
            goto epilogue;

        if (sub_08008948(r4, r5) != 0)
            goto epilogue;

        if (*(unsigned char *)((char *)r4 + 0xe0) == 0x4a) {
            sub_08037BCC(r5, *(unsigned char *)((char *)r4 + 0x114), 0xa);
        } else {
            sub_08037BCC(r5, *(unsigned char *)((char *)r4 + 0x114), 1);
        }
    }

epilogue:
    return;
}
