void *sub_080001F8(int arg0);
void sub_08000BF4(void *arg0, unsigned int arg1);
void sub_08000D7C(void *arg0, int arg1, int arg2);

void *sub_0802D28C(int arg0, int arg1, int arg2, int arg3)
{
    void *obj;
    unsigned char *flagByte;
    unsigned char *statusByte;
    int mask;
    int temp;

    obj = sub_080001F8(0x2e);
    *(int *)((char *)obj + 0x58) = 0x00020001;
    if (arg2 != 0) {
        sub_08000BF4(obj, (unsigned int)arg2);
    }
    statusByte = (unsigned char *)obj + 0xb1;
    mask = -13;
    temp = 0x21;
    *statusByte &= mask;
    *statusByte &= -temp;
    flagByte = (unsigned char *)obj + 0xb5;
    *flagByte &= mask;
    *((unsigned char *)obj + 0xbf) = 3;
    sub_08000D7C(obj, arg0 << 16, arg1 << 16);
    temp = arg3 << 4;
    *flagByte &= 0x0F;
    *flagByte |= temp;
    return obj;
}
