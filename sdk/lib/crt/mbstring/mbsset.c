/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     classicOS system libraries
 * FILE:        lib/sdk/crt/mbstring/mbsset.c
 * PURPOSE:     Fills a string with a multibyte character
 * PROGRAMER:   Ariadne
 * UPDATE HISTORY:
 *              12/04/99: Created
 */

#include <mbstring.h>

size_t _mbclen2(const unsigned int s);

/*
 * @implemented
 */
unsigned char * _mbsset(unsigned char *src, unsigned int c)
{
	unsigned char *char_src = src;
	unsigned short *short_src = (unsigned short *)src;

	if ( _mbclen2(c) == 1 ) {

		while(*char_src != 0) {
			*char_src = c;
			char_src++;
		}
		*char_src = 0;
	}
	else {
		while(*short_src != 0) {
			*short_src = c;
			short_src++;
		}
		*short_src = 0;
	}

	return src;
}
