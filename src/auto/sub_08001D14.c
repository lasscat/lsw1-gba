void sub_08001D14(int a, int b, int *out)
{
    int c = (int)((unsigned int)a >> 31);
    c = c + a;
    c = c >> 1;
    c = c + b;
    out[0] = c;
    out[1] = c - a;
}
