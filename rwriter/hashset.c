#include "hashset.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void HashSetNew(hashset *h, int elemSize, int numBuckets,
		HashSetHashFunction hashfn, HashSetCompareFunction comparefn, HashSetFreeFunction freefn){
	assert(elemSize > 0 && numBuckets > 0 && hashfn != NULL && comparefn != NULL && "not possible to construct the HashSet");
	h->elemSize = elemSize;
	h->numBuckets = numBuckets;
	h->hashfn = hashfn;
	h->comparefn = comparefn;
	h->freefn = freefn;
	h->buckets = malloc(sizeof(vector) * numBuckets);
	int i;
	for (i = 0; i < numBuckets; i++) {
    	vector *vAddress = h->buckets + i;
    	VectorNew(vAddress, elemSize, freefn, 4);
  	}
}

void HashSetDispose(hashset *h){
	int i;
	vector *vAddress;
	for(i = 0; i < h->numBuckets; i++){
		vAddress = h->buckets + i;
		VectorDispose(vAddress);
	}
	free(h->buckets);
}

int HashSetCount(const hashset *h){ 
	int i;
	int count = 0;
	vector *vAddress;
	for(i = 0; i < h->numBuckets; i++){
		vAddress = h->buckets + i;
		count += VectorLength(vAddress);
	}
	return count; 
}

void HashSetMap(hashset *h, HashSetMapFunction mapfn, void *auxData){
	assert(mapfn != NULL && "mapping routine is NULL");
	int i;
	vector *vAddress;
	for(int i = 0; i < h->numBuckets; i++){
		vAddress = h->buckets + i;
		VectorMap(vAddress, mapfn, auxData);
	}
}

void HashSetEnter(hashset *h, const void *elemAddr){
	assert(elemAddr != NULL && "elemAddr can't be NULL");
	int hashCode = h->hashfn(elemAddr, h->numBuckets);
	vector *vAddress;
	assert(hashCode >= 0 && hashCode < h->numBuckets && 
		"not possible to insert the specified element into the specified hashset");
	vAddress = h->buckets + hashCode;
	int position = VectorSearch(vAddress, elemAddr, h->comparefn, 0, false);
	if (position == -1)
	    VectorAppend(vAddress, elemAddr);
	else
	    VectorReplace(vAddress, elemAddr, position);
}

void *HashSetLookup(const hashset *h, const void *elemAddr){ 
	assert(elemAddr != NULL && "elemAddr can't be NULL");
	int hashCode = h->hashfn(elemAddr, h->numBuckets);
	vector *vAddress;
	assert(hashCode >= 0 && hashCode < h->numBuckets && 
		"not possible to insert the specified element into the specified hashset");
  	vAddress = h->buckets + hashCode;
  	int position = VectorSearch(vAddress, elemAddr, h->comparefn, 0, false);
  	if (position == -1)
    	return NULL;
  	else
    	return VectorNth(&h->buckets[hashCode], position);
	return NULL; 
}

int hashVector(const void *a, int numBuckets) {
  keysv* tm = (keysv*)a;
  char* t = tm->string;
  return hash(t, numBuckets);
}

int cmpVector(const void *a, const void *b) {
  char* t = ((keysv*)a)->string;
  char* r = ((keysv*)b)->string;
  return strcasecmp(t, r);
}

void mapFn(void *a, void *b) {
  keysv* t = (keysv*)a;
  int *c = (int*)b;
  *(c) += t->frecuency;
}

int cmpvct(const void *a, const void *b) {
  char* t = ((vectorv*)a)->string;
  char* r = ((vectorv*)b)->string;
  return strcmp(t, r);
}

int cmpFr(const void *a, const void *b) {
  int n1 = ((vectorv*)a)->frecuency;
  int n2 = ((vectorv*)b)->frecuency;
  return n1 == n2;
}

//antes hash set lookup
//NULL == Vsearch(elem) vappend else vreplace(pos)
