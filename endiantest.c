/*
  Test for endian-ness
  "endiantest.c"
  M. Yamanaka
  email: myamanaka@live.com
  website: csmyamanaka.com
  license: MIT (See included "LICENSE" file for details)
*/

#include <stdio.h>

int main(){
  /*
    Originally, this test was used as a test for my other project "File IO ++" (fileiopp)
    because it was quite necessary that I know the endian-ness of my compiler.
    I figured it could be useful in itself to the point that it merits its own repo.
  */

  /*
    I'm pretty sure integers are 4 bytes long at least on the compiler that I'm using.
    Integer 65 could be stored as 00 00 00 65 or 65 00 00 00 (btw I chose 65 because it's the letter 'A' as a char).
    I'm not bothering with the whole signed vs unsigned because it should be irrelevant given how small the number is
    and also given that it's a positive number so there is no issue with any of the two's complement stuff.
  */
  int n = 65;
  
  int* pn = &n;
  /*
    Having a char pointer point to the "first byte" of the integer could either mean
    that it's pointing to "00" or to "65".
  
    For big-endian, the most significant byte is stored in the first byte (i.e. how normal humans read)
    The reverse is true for little endian.

    Using a char pointer (which has a stride length of 1 byte) it should be fairly trivial to read the byte at the address of integer n
    and the three following bytes (reading any more than that would probably cause a seg fault).

    The following table should serve as a tl;dr

    byte  | 00 | 01 | 02 | 03 |
    ------+----+----+----+----+
          | 00 | 00 | 00 | 65 | big endian
    int n +----+----+----+----+
          | 65 | 00 | 00 | 00 | little endian
    ------+----+----+----+----+
    char* | +0 | +1 | +2 | +3 |

  */
  char* pcn = (char*)pn;
  

  if(*pcn == '\0' && *(pcn + 3) == 'A') printf("big endian\n");
  else if(*pcn == 'A' && *(pcn + 3) == '\0') printf("little endian\n");
  else printf("something probably went wrong\n");
  return 0;
}
