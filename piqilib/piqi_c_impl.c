/*
   Copyright 2009, 2013 Anton Lavrik

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#include <caml/fail.h>


uint64_t piqi_strtoull(char *str)
{
    char *src, *dst;

    src = dst = str;

    /* check that input string contains only decimal digits and underscores and
     * remove underscores from the string */
    while (*src)
    {
        if (*src >= '0' && *src <= '9')
            *dst++ = *src++; /* copy digit */
        else if (*src == '_')
            src++; /* skip '_' character */
        else /* invalid character */
            goto fail;
    }
    if (dst == str) goto fail; /* no digits, i.e. string is empty */ 
    *dst = '\0'; /* terminate */

    /* convert input decimal string to uint64 value */
    errno = 0;
    uint64_t res = strtoull(str, NULL, 10);
    if (errno) goto fail;

    return res;

fail:
    caml_failwith("piqi_strtoull");
    return 0;
}


/* NOTE: the stub code below was originally generated by camlidl from
 * idl/piqi_c.idl and was manually edited afterwards:
 *
 * 1. change incorrectly generated type for the "_res" variable from "int"
 *    to "int64_t"
 *
 * 2. remove unnecesasry includes; namely, <caml/camlidlruntime.h> to avoid
 *    compile-time dependency on camlidl
 *
 * Note that the same code could have been easily written by hand. It was just
 * convenient to have camlidl to generate the initial version.
 */

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/callback.h>

value camlidl_piqi_c_piqi_strtoull(
	value _v_str)
{
  char *str; /*in*/
  int64 _res;
  value _vres;

  str = String_val(_v_str);
  _res = piqi_strtoull(str);
  _vres = copy_int64(_res);
  return _vres;
}

