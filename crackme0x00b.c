#include <stdio.h>
#include <string.h>
#include <wchar.h>

#define MAX 0x17
const wchar_t *w0wgreat = (wchar_t *)U"w0wgreat";

void main(void)
{
  wchar_t passwd[MAX];
  int fail = 0;
  printf("Enter password: ");
  scanf("%ls",passwd);
  fail = wcscmp(passwd,w0wgreat);
  if (!fail)
  {
    printf("Congrats!\n");
    goto GTFO;
  }
  printf("Wrong!\n");
GTFO:
  return;
}
