void sub_080023D8(void *arg0);

void sub_08000D00(void *arg0, int arg1)
{
    unsigned char v;
    if (*(unsigned char *)((char *)arg0 + 0x97) != arg1 || (*(unsigned int *)((char *)arg0 + 0x58) & 0x80) != 0) {
        *(unsigned char *)((char *)arg0 + 0x97) = arg1;
        v = *(unsigned char *)((char *)arg0 + 0x95);
        *(unsigned char *)((char *)arg0 + 0x94) = v;
        sub_080023D8(arg0);
    }
    *(unsigned int *)((char *)arg0 + 0x58) &= 0xFFFBFFFF;
}
