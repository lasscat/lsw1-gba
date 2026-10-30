extern unsigned char gUnknown_03006B1C[];

unsigned int sub_0802CC4C(int arg0);

int sub_0804297C(void)
{
    if (gUnknown_03006B1C[0x293] != 0x2c) {
        return 0;
    }
    if (!sub_0802CC4C(0)) {
        return 0;
    }
    if (!sub_0802CC4C(1)) {
        return 0;
    }
    if (!sub_0802CC4C(2)) {
        return 0;
    }
    return 1;
}
