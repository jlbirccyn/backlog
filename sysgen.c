/*
 *
 */
 #include <stdio.h>
 #include <inttypes.h>
 #include <stdint.h>
 #include <stdbool.h>
 #include <stdlib.h>

void printSystem(
  const int numberOfTask,
  const int backlog,
  const int * const deadline)
{
  printf("echo \"%d",numberOfTask);
  for (int task = 0; task < numberOfTask; task++) {
    printf(" %d", deadline[task]);
  }
  printf("\" | ./combis %d\n", backlog);
}

void computeDeadline(
  const int task,
  const int initialDeadline,
  const int numberOfTask,
  const int backlog,
  int * const deadline)
{
  if (task < numberOfTask) {
    for (int d = initialDeadline; d <= backlog; d++) {
      deadline[task] = d;
      computeDeadline(task + 1, d, numberOfTask, backlog, deadline);
    }
  }
  else {
    printSystem(numberOfTask, backlog, deadline);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: sysgen <t> <b>\n"
           "       where <t>the number of tasks\n"
           "       and <b> the backlog\n");
    exit(1);
  }
  else {
    int numberOfTask = strtol(argv[1], NULL, 0);
    int backlog = strtol(argv[2], NULL, 0);;

    int *deadline = malloc(sizeof(int) * numberOfTask);

    printf("#!/bin/bash\n");
    computeDeadline(0, 0, numberOfTask, backlog, deadline);
  }
}
