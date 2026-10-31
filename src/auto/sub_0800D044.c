extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800D044(unsigned char *a)
{
    unsigned int b = sub_08004A5C(a[4], a[5]);
    if (b != 0) {
        if (*(unsigned int *)(b + 0xD0) != 0) {
            *(unsigned int *)(*(unsigned int *)(b + 0xD0) + 0x58) |= 2;
            *(unsigned int *)(*(unsigned int *)(*(unsigned int *)(b + 0xD0) + 0xF4) + 0x58) |= 2;
            *(unsigned int *)(*(unsigned int *)(b + 0xD0) + 0xF4) = 0;
            *(unsigned int *)(b + 0xD0) = 0;
            *(unsigned char *)(b + 0x10A) = 0x83;
        }
    }
}
