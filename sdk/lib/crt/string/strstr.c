/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     classicOS system libraries
 * FILE:        lib/sdk/crt/string/strstr.c
 * PURPOSE:     Unknown
 * PROGRAMER:   Unknown
 * UPDATE HISTORY:
 *              25/11/05: Added license header
 */

#include <precomp.h>
/*
 * @implemented
 */
char *
CDECL
strstr(const char *s, const char *find)
{
  char c, sc;
  size_t len;

  if ((c = *find++) != 0)
  {
    len = strlen(find);
    do {
      do {
	if ((sc = *s++) == 0)
	  return 0;
      } while (sc != c);
    } while (strncmp(s, find, len) != 0);
    s--;
  }
  return (char *)((size_t)s);
}
