#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 0x78

int dummy(int passwd, char **envp)
{
  int i = 0;
  int sz = 0x03;
  char *c = "LOLO";
  char *env;

  while (1)
  {
    env = envp[i];
    if (env == NULL)
    {
      goto GTFO;
    }
    if (strncmp(env, c, sz) == 0)
    {
      return 1;
    }
    i++;
  }
GTFO:
  return 0;
}

void parell(char *passwd, char **envp)
{
  int t = 0;

  sscanf(passwd,"%d",&t);
  if (dummy(t,envp))
  {
    if (((char)t & 0x01) == 0)
    {
      printf("Password OK!\n");
      exit(0);
    }
  }
  return;
}

void check(char *passwd, char **envp)
{
  int i = 0;
  int t = 0;
  char s = 0;
  int len = 0;
  int tot = 0;

  len = strlen(passwd);
  while(1)
  {
    if (i >= len)
    {
      goto GTFO;
    }
    s = passwd[i];
    sscanf(&s,"%d",&t);
    tot += t;
    if (tot == 0x10)
    {
      parell(passwd, envp);
      goto GTFO;
    }
    i++;
  }
GTFO:
  printf("Password Incorrect!\n");
  return;
}


void main(int argc, char **argv, char **envp)
{
  char passwd[MAX];
  printf("IOLI Crackme Level 0x08\n");
  printf("Password: ");
  scanf("%s", passwd);
  check(passwd, envp);
  return;
}
