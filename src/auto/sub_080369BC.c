extern int sub_08017400(int a, int b);

unsigned char sub_080369BC(unsigned char *p)
{
    unsigned int r = sub_08017400(0, 99);
    int i = 0;
    if (r >= p[1]) {
        unsigned char *q = p + 1;
        do {
            r -= *q;
            q += 2;
            i++;
        } while (r >= *q);
    }
    return p[i + i];
}
