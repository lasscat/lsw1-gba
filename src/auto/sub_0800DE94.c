unsigned char sub_0800DE94(unsigned char *data, int len)
{
    unsigned int crc = 0;
    unsigned int val;
    unsigned int i;
    unsigned int bit;

    len--;
    if (len != -1) {
        do {
            val = *data;
            for (i = 0; i <= 7; i++) {
                bit = (crc ^ val) & 1;
                val >>= 1;
                crc >>= 1;
                if (bit != 0)
                    crc ^= 0x8C;
            }
            data++;
            len--;
        } while (len != -1);
    }
    return crc;
}
