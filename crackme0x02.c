#include <stdio.h>

void main(int argc, char *argv[])
{
  int key = 0;
  int tmp = 0;
  printf("IOLI Crackme Level 0x02\n");
  printf("Password: ");
  scanf("%d",&key);

  // Do a thing.
  tmp = (0x5a + 0x1ec);
  tmp = tmp * tmp;

  if (key != tmp)
  {
    printf("Invalid Password!\n");
    return;
  }
  printf("Password OK :)\n");
  return;
}
