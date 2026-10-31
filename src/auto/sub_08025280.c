int sub_08017400(int a, int b);
int sub_0803D654(int a, int b);
extern int gUnknown_0300340C;

int sub_08025280(int a, int b, int c)
{
    int v = 0;
    int r = sub_08017400(0, 2);
    switch (r) {
    case 0:
        v = a;
        break;
    case 1:
        v = b;
        break;
    case 2:
        v = c;
        break;
    default:
        break;
    }
    return sub_0803D654(v, gUnknown_0300340C);
}
