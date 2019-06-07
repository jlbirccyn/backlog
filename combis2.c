/*
 * Les paramètres d'entrée sont :
 *
 * le backlog k
 * le nombre de tâches
 * les deadlines des tâches
 *
 * L'algorithme est entièrement contenu dans la fonction attribue qui
 * s'appelle elle même récursivement
 *
 * On commence par la tache 0, à la date 0 (par rapport à la date de
 * l'hyperpériode).
 * Si la date est au dela de la deadline, on coupe, c'est un ordo infaisable.
 * Sinon, pour tout les backlog c allant de 0 à min(k,dealine(t0)),
 * la tache 0 consomme c, on avance la date de c, on diminue k de case
 * et on continue avec la tache 1. etc
 *
 * Pour calculer le nombre de combinaisons :
 * echo "n d0 d1 ... dn-1" | combis k
 * n est le nombre de taches, d1 les deadlines, k le backlog max
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int *d = NULL;
int combis = 0;
bool trace = false;

int min(int a, int b)
{
  return (a < b) ? a : b;
}

void attribue(int restant, int tache, const int max_tache, const int date, const int * const deadline)
{
  if (date <= deadline[tache]) {
    for (int combien = 0; combien <= min(restant, deadline[tache] - date); combien++) {
      if (trace) {
        for (int t = 0; t < tache; t++) printf("    ");
        printf(" %d\n", combien);
      }
      if (tache < max_tache) {
        attribue(restant - combien, tache + 1, max_tache, date + combien, deadline);
      }
      else {
        combis++;
      }
    }
  }
  else {
    printf("*\n");
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2 || argc > 3) {
    printf("Usage: combis [-t] <backlog>\n");
    exit(1);
  }

  int backlog;

  if (argc == 2) {
    backlog = atoi(argv[1]);
  }
  else {
    if (strcmp(argv[1], "-t") == 0) {
      trace = true;
      backlog = atoi(argv[2]);
    }
    else {
      printf("Unrecognize option: %s", argv[1]);
      exit(1);
    }
  }

  /* recupere le systeme de l'entrée standard */
  /* le format est <nb taches> <deadline tache 0> <deadline tache 1> ... */
  int nombre_de_taches;
  if (scanf(" %d",&nombre_de_taches)) {
    d = malloc(nombre_de_taches * sizeof(int));
    for (int t = 0; t < nombre_de_taches; t++) {
      if (scanf(" %d", &d[t]) == 0) {
        nombre_de_taches = t;
        break;
      }
    }
    if (nombre_de_taches > 0) {
      attribue(backlog, 0, nombre_de_taches - 1, 0, d);
    }
  }

  printf("%d taches, d=(", nombre_de_taches);
  for (int t = 0; t < nombre_de_taches; t++) {
    if (t > 0) putchar(',');
    printf("%d", d[t]);
  }
  printf("), combis = %d\n", combis);
}
