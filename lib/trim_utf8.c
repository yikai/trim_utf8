#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trim_utf8.h"

unsigned char map_1b[] =
{
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0A,
    0x0B,
    0x0C,
    0x0D,
    0x0E,
    0x0F,
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16,
    0x17,
    0x18,
    0x19,
    0x1A,
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x7F,
    0x00,
};

unsigned char map_2b[] =
{
    0xC2, 0x85,
    0xC2, 0xA0,
    0xC2, 0xAD,
    0xCE, 0xAF,
    0x00, 0x00,
};

unsigned char map_3b[] =
{
    0xE2, 0x80, 0x80,
    0xE2, 0x80, 0x81,
    0xE2, 0x80, 0x82,
    0xE2, 0x80, 0x83,
    0xE2, 0x80, 0x84,
    0xE2, 0x80, 0x85,
    0xE2, 0x80, 0x86,
    0xE2, 0x80, 0x87,
    0xE2, 0x80, 0x88,
    0xE2, 0x80, 0x89,
    0xE2, 0x80, 0x8A,
    0xE2, 0x80, 0x8B,
    0xE2, 0x80, 0x8C,
    0xE2, 0x80, 0x8D,
    0xE2, 0x80, 0x91,
    0xE2, 0x80, 0xAF,
    0xE2, 0x81, 0x9F,
    0xE2, 0x81, 0xA0,
    0xE2, 0x81, 0xA1,
    0xE2, 0x81, 0xA2,
    0xE2, 0x81, 0xA3,
    0xE3, 0x80, 0x80,
    0xEF, 0xBB, 0xBF,
    0x00, 0x00, 0x00,
};

unsigned char* map_space[] = {
    NULL,
    map_1b,
    map_2b,
    map_3b,
};

int is_first(unsigned char c) {
    return ! ((c >> 6) == 0x02);
}

int get_byte_size(unsigned char c) {

    int i;

    for (i = 0; (c << i) & 0x80; i++)
        ;

    return ((i == 1) ? 0 : (i ? i : 1));
}

int is_space(unsigned char *str, int byte_size) {

    unsigned char *p = map_space[ byte_size ];
    int i = 0;
    int j = 0;

    while (p[j] != 0x00) {
        for (i = 0; ( (str[i] == p[j + i]) && (i < byte_size) ); i++)
            ;

        if (i == byte_size) {
            return 1;
        }
        j += byte_size;
    }

    return 0;
}

int strip_space(unsigned char* src, unsigned char *dest, int length) {

    int i = 0;
    int j = 0;
    int byte_size = 0;

    while (src[i] != '\0') {
        if (j >= length) {
            return 0;
        }

        byte_size = get_byte_size(src[i]);
        if  ( is_space(&src[i], byte_size) ) {
            i += byte_size;
        } else {
            memcpy(&dest[j], &src[i], byte_size);
            i += byte_size;
            j += byte_size;
        }
    }

    dest[j] = '\0';

    return j;
}

int pack_space(unsigned char* src, unsigned char *dest, int length) {

    int i = 0;
    int j = 0;
    int byte_size = 0;

    int has_space = 0;

    while (src[i] != '\0') {
        if (j >= length) {
            return 0;
        }

        byte_size = get_byte_size(src[i]);
        if  ( is_space(&src[i], byte_size) ) {
            has_space = 1;
            i += byte_size;
        } else {
            if (has_space) {
                dest[j] = 0x20;
                j++;
            }
            memcpy(&dest[j], &src[i], byte_size * sizeof(unsigned char));
            i += byte_size;
            j += byte_size;
            has_space = 0;
        }
    }

    dest[j] = '\0';

    return j;
}

int ltrim(unsigned char* src, unsigned char *dest, int length) {

    int i = 0;
    int byte_size = 0;
    int src_length = 0;

    while (src[i] != '\0') {

        byte_size = get_byte_size(src[i]);
        if  ( is_space(&src[i], byte_size) ) {
            i += byte_size;
        } else {
            src_length = strlen((char*)src) - i;
            if (src_length >= length) {
                return 0;
            }
            memcpy(dest, &src[i], src_length);
            dest[src_length] = '\0';
            break;
        }
    }

    return src_length;
}

int rtrim(unsigned char* src, unsigned char *dest, int length) {

    int i = 0;
    int j = 0;

    i = strlen((char*)src);

    while (i > 0) {
        i--;

        for (j = 1; ! is_first(src[i]); i--, j++)
            ;

        if  (! is_space(&src[i], j) ) {
            i += j;
            if (i >= length) {
                return 0;
            }
            memcpy(dest, src, i);
            dest[i] = '\0';
            break;
        }
    }

    return i;
}


int trim(unsigned char* src, unsigned char *dest, int length) {
    if (ltrim(src, dest, length) == 0) {
        return 0;
    }

    return rtrim(dest, dest, length);
}
