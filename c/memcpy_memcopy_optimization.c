//simplest

void * memcpy(void * dst, void const * src, size_t len)
{
    char * pDst = (char *) dst;
    char const * pSrc = (char const *) src;

    while (len–)
    {
        *pDst++ = *pSrc++;
    }

    return (dst);
}

//modified GNU version - uses computation to adjust for address misalignment

void * memcpy(void * dst, void const * src, size_t len)
{
    long * plDst = (long *) dst;
    long const * plSrc = (long const *) src;

    if (!(src & 0xFFFFFFFC) && !(dst & 0xFFFFFFFC))
    {
        while (len >= 4)
    {
            *plDst++ = *plSrc++;
            len -= 4;
        }
    }

    char * pcDst = (char *) plDst;
    char const * pcDst = (char const *) plSrc;

    while (len–)
    {
        *pcDst++ = *pcSrc++;
    }

    return (dst);
}
