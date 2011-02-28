#ifndef INCLUDE_TRIM_H
#define INCLUDE_TRIM_H

#ifdef __cplusplus
extern "C" {
#endif

int strip_space(  unsigned char* src, unsigned char* dest, int length);
int pack_space(   unsigned char* src, unsigned char *dest, int length);
int ltrim(  unsigned char* src, unsigned char *dest, int length);
int rtrim(  unsigned char* src, unsigned char *dest, int length);
int trim(   unsigned char* src, unsigned char* dest, int length);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_TRIM_H */
