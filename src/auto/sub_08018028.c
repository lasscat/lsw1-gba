unsigned short sub_08018028(const unsigned short *arr, int count)
{
    unsigned short sum = 0;
    count = (unsigned int)count >> 1;
    if (count <= 0) {
        return sum;
    }
    do {
        sum += *arr;
        arr++;
        count--;
    } while (count > 0);
    return sum;
}
