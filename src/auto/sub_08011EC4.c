int sub_08011EC4(int *counter, unsigned int limit, unsigned int value, unsigned int flag, unsigned short mask0, unsigned short mask1, unsigned short mask2)
{
    int ret = 1;
    if (mask0 & mask1) {
        if (*counter <= limit) {
            if (flag == 0) {
                ret = 0;
            } else {
                *counter = value;
            }
        } else {
            (*counter)--;
        }
    } else {
        if ((mask0 & mask2) != 0) {
            if (*counter >= value) {
                if (flag != 0) {
                    *counter = limit;
                } else {
                    ret = 0;
                }
            } else {
                (*counter)++;
            }
        } else {
            ret = 0;
        }
    }
    return ret;
}
