void sub_08021678(void *arg0, int arg1)
{
    unsigned char *obj = arg0;
    unsigned char *flagByte;
    int mask;

    *(int *)(obj + 0x58) = 0x00020001;
    *(obj + 0x5c) = (arg1 = 0);
    flagByte = obj + 0xb5;
    mask = 0xd;
    mask = -mask;
    *flagByte &= mask;
    *(obj + 0xbf) = arg1;
    mask = 0xf;
    *flagByte &= mask;
    *(int *)(obj + 0x24) = arg1;
    *(int *)(obj + 0x28) = arg1;
    *(int *)(obj + 0x34) = arg1;
    *(int *)(obj + 0x38) = arg1;
    *(short *)(obj + 0xde) = arg1;
}
