int sub_0802CAE0(int arg0, int arg1);

int sub_0802CB20(int arg0)
{
    unsigned int i;
    int count = 0;
    for (i = 0; i <= 4; i++) {
        if (sub_0802CAE0(arg0, i) != 0) {
            count++;
        }
    }
    return count;
}
