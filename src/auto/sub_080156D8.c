extern unsigned int sub_08015930(unsigned int a);
extern unsigned int sub_0801597C(unsigned int a);
extern unsigned int sub_080159C8(unsigned int a);
extern void sub_080158B4(unsigned int a, void *b, void *c);

unsigned int sub_080156D8(void *arg0, void *arg1)
{
    unsigned int r4;

    r4 = sub_08015930((unsigned int)arg1);
    if (r4 != 0xff) {
        sub_080158B4(r4, arg0, 0);
    } else {
        r4 = sub_0801597C((unsigned int)arg1);
        if (r4 != 0xff) {
            sub_080158B4(r4, arg0, arg1);
        } else {
            r4 = sub_080159C8((unsigned int)arg1);
            if (r4 != 0xff) {
                sub_080158B4(r4, arg0, arg1);
            }
        }
    }
    return r4;
}
