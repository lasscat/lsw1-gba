extern unsigned int gUnknown_03007014;

int sub_08017400(int a, int b);
void sub_08037548(void *arg0, int arg1, unsigned int arg2, int arg3);
void sub_08037798(void *obj, int val);
void sub_08000F50(void *arg0);

typedef struct {
    unsigned char _00[0x58];
    unsigned int _58;
} Obj38;

void sub_08038DC4(Obj38 *obj)
{
    if (sub_08017400(0, 100) <= 2)
        sub_08037798(obj, 0);
    sub_08037548(obj, 7, gUnknown_03007014, 1);
    obj->_58 &= 0xFFFBFFFF;
    sub_08000F50(obj);
}
