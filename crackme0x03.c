#include <stdio.h>
#include <string.h>

int shift(char *key)
{
  int len = 0;
  int i = 0;
  char s[0x20] = {0};

  while (1)
  {
    len = strlen(key);
    if (i >= len)
    {
      break;
    }
    s[i] = key[i]-(char)0x03;
    i++;
  }
  printf("%s\n",s);
  return 0;
}

int test(int password, int seed)
{
  int ret = 1;
  if ( password != seed )
  {
    ret = shift("Lqydolg#Sdvvzrug$\x00");
    goto GTFO;
  }
  ret = shift("Sdvvzrug#RN$$$#=,\x00");

GTFO:
  return ret;
}

void main(int argc, char *argv[])
{
  int password = 0;
  int seed = 0;
  printf("IOLI Crackme Level 0x03\n");
  printf("Password: ");
  scanf("%d",&password);
  seed = 0x5a + 0x1ec;
  seed = seed * seed;
  test(password,seed);
  return;
}
