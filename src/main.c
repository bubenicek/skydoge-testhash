
#include <stdio.h>
#include <unistd.h>

#include "skydoge.h"
#include "trace.h"


#define HASH_SIZE    64

int main(int argc, char *argv[])
{
   int i;
   char input[HASH_SIZE];
   char output[HASH_SIZE / 2];

   if (argc >= 2)
   {
      if (read(STDIN_FILENO, input, sizeof(input)) != sizeof(input))
      {
         printf("Read from stdin failed\n");
         return 1;
      }
   }
   else
   {
      for (i = 0; i < HASH_SIZE; i++)
         input[i] = i;
   }

   skydoge_hash(input, output, 64);

   return 0;
}

