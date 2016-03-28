#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>
#include "hashset.h"
#include "bool.h"

static const signed long kHashMultiplier = -1664117991L;

int main(int argc, char **argv) {
  hashset hash;
  vector keys;
  printf("Usage [Order] [AmountWords] [FileName]\n");
  calculateNext(&hash, &keys, atoi(argv[1]), argv[3], atoi(argv[2]));
  return 0;
}

int hash(const char *s, int buckets) {
  int i;
  unsigned long hashcode = 0;
  for (i = 0; i < strlen(s); i++)
    hashcode = hashcode * kHashMultiplier + tolower(s[i]);
  return hashcode % buckets;
}

char* ran(hashset* hash, vector *keys, char *prev) {
  int i, rnd, b;
  char *rs;
  keysv search, *tmp;
  search.string = strdup(prev);
  tmp = (keysv*)HashSetLookup(hash, &search);
  b = tmp->amount;
  if (b == 0) {
    b = keys->currentPosition;
    rnd = rand() % b;
    return  VectorNth(keys, rnd);
  }
  rnd = rand() % b + 1;
  for (i = 0; rnd > 0 && i < tmp->vectorv.currentPosition; i++) {
    rnd = rnd - ((vectorv*)VectorNth(&tmp->vectorv, i))->frecuency;
    rs = ((vectorv*)VectorNth(&tmp->vectorv, i))->string;
  }
  return rs;
}

void calculateNext(hashset *hash, vector*  keys, int k, char* f, int size) {
  int currK, i, elems = 0, seedNumber;
  char *nxt, *cnt, *key2, *storage = (char*)malloc(sizeof(char) * k);
  FILE *fileR;
  vectorv keyNext;
  keysv *rs, key;
  k+=1;
  fileR = fopen(f, "r");
  assert(fileR != NULL && "Cannot open the file");
  VectorNew(keys, sizeof(char*) * k, NULL, 10);
  while (fgets(storage, k, fileR) != NULL) {
    currK = strlen(storage);
    if (currK < k && storage[currK - 1] == '\n') {
      fgets(&storage[currK], k - currK, fileR);
    }
    VectorAppend(keys, storage);
  }
  storage = (char*)VectorNth(keys, keys->currentPosition - 1);
  fclose(fileR);
  HashSetNew(hash, sizeof(keysv), keys->currentPosition * 3, hashVector, cmpVector, NULL);
  for (i = 0; i < (keys->currentPosition - 1); i++) {
    rs = (keysv*)malloc(sizeof(keysv));
    vector nexts;
    cnt = VectorNth(keys, i);
    nxt = VectorNth(keys, i + 1);
    rs->string = strdup(cnt);
    rs = (keysv*)HashSetLookup(hash, rs);
    keyNext.string = nxt;
    key.string = cnt;
    if (rs == NULL) {
      keyNext.frecuency = 1;
      VectorNew(&nexts, sizeof(vectorv), NULL, 1);
      VectorAppend(&nexts, &keyNext);
      key.frecuency = 1;
      key.vectorv = nexts;
      key.amount = 1;
      HashSetEnter(hash, &key);
    } else {
      rs->frecuency++;
      rs->amount++;
      vectorv* rSucessor;
      int idx = VectorSearch(&rs->vectorv, &keyNext, cmpvct, 0, false);
      if (idx >= 0) {
        rSucessor = VectorNth(&rs->vectorv, idx);
        rSucessor->frecuency++;
      } else {
        keyNext.frecuency = 1;
        VectorAppend(&rs->vectorv, &keyNext);
      }
    }
  }
  key.string = VectorNth(keys, keys->currentPosition - 1);
  key.frecuency = 1;
  key.amount = 0;
  HashSetEnter(hash, &key);
  if (k == 0) {
    elems = keys->currentPosition;
  } else {
    HashSetMap(hash, mapFn, &elems);
  }
  seedNumber = rand() % elems;
  key2 = (char*)VectorNth(keys, seedNumber);
  printf("Generated text:\n");
  printf("%s", key2);
  if (k > 0) {
    for (i = 0; i < size;) {
      key2 = ran(hash, keys, key2);
      printf("%s", key2);
      if (strstr(key2, " ") != NULL || strstr(key2, "\n") != NULL) {
        i++;
      }
    }
  }
  else {
    for (i = 0; i < size;) {
      seedNumber = rand() % elems;
      key2 = (char*)VectorNth(keys, seedNumber);
      printf("%s", key2);
      if (strstr(key2, " ") != NULL || strstr(key2, "\n") != NULL) {
        i++;
      }
    }
  }
  printf("\n");
}
//