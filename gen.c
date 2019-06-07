/*
 *
 */
 #include <stdio.h>
 #include <inttypes.h>
 #include <stdint.h>
 #include <stdbool.h>
 #include <stdlib.h>
 #include <time.h>


int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: sysgen <n> <t> <b>\n"
           "       where <n> is the number of systems,\n"
           "       <t>the number of tasks\n"
           "       and <b> the backlog\n");
    exit(1);
  }
  else {
    int numberOfSentences = strtol(argv[1], NULL, 0);
    int numberOfWrongCRCSentences = 0;
    if (argc == 3) {
      numberOfWrongCRCSentences = strtol(argv[2], NULL, 0);
    }

    /* Init a the random seed with the epoch */
    srandom(time(NULL));

    for (int i = 0; i < numberOfSentences; i++) {
      generateSentence(true);
    }
    for (int i = 0; i < numberOfWrongCRCSentences; i++) {
      generateSentence(false);
    }
  }

}
