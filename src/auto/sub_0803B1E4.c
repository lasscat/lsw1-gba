extern void sub_080020FC(void *obj, int val);
extern int sub_08004B18(int val);
extern void sub_0802AB84(void *arg0);
extern void sub_0803ABE0(void *obj);
extern void sub_0803AF10(void *obj);
extern int sub_0803AFA4(void *obj);
extern void sub_0803B148(void *obj, int a, int b);

void sub_0803B1E4(void *arg)
{
    unsigned char *obj = arg;
    unsigned int state;
    if (obj[0xE2] == 0)
        sub_0803AF10(obj);
    state = obj[0xE2];
    switch (state) {
    case 3:
    case 0x23:
    case 0x2c: {
        int v = sub_0803AFA4(obj);
        if (v == 0x100 || state == 0x23) {
            unsigned int a = obj[0x121];
            unsigned int c = obj[0x122] + 1;
            if (c >= (unsigned char)sub_08004B18(a))
                c = 0;
            sub_0803B148(obj, a, c);
            sub_0802AB84(obj);
        } else if (v != obj[0x5F]) {
            sub_0802AB84(obj);
        }
        break;
    }
    case 2:
        sub_080020FC(obj, 3);
        break;
    default:
        sub_0803ABE0(obj);
        break;
    }
}
