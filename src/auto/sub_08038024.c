void sub_080020FC(void *obj, unsigned int val);
void sub_08036AF0(void *obj, unsigned int val);

void sub_08038024(void *arg)
{
    unsigned char *obj = arg;
    unsigned char *p;
    int v;
    unsigned char a;
    unsigned char b;

    if (obj[0x10E] != 0) {
        p = obj + 0xE1;
        *p = obj[0x10E];
        sub_080020FC(arg, 0);
        v = *p;
        switch (v) {
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 14:
                *(unsigned int *)(obj + 0x58) |= 8;
                a = obj[0x10F];
                obj[0x122] = a;
                b = obj[0x110];
                obj[0x121] = b;
                sub_080020FC(arg, 0x23);
                break;
        }
    } else {
        sub_08036AF0(arg, 0);
    }
}
