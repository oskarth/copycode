#include <stdio.h>
#include "priority_queue.h"

int pq_parent(int n) {
  if (n == 1) return(-1);
  else return((int) n/2); /* implicitly take floor(n/2) */
}

// as opposed to old?
int pq_young_child(int n) {
  return(2 * n);
}

void pq_swap(priority_queue *q, int i, int j) {
	item_type temp;

	temp = q->q[i];
	q->q[i] = q->q[j];
	q->q[j] = temp;
}

// where is pq_swap?
void bubble_up(priority_queue *q, int p) {
  if (pq_parent(p) == -1) return; /* at root of heap, no parent */

  if (q->q[pq_parent(p)] > q->q[p]) {
    pq_swap(q, p, pq_parent(p));
    bubble_up(q, pq_parent(p));
  }
}

// what's n here?
void pq_insert(priority_queue *q, item_type x) {
  if (q->n >= PQ_SIZE)
    printf("Warning: priority queue overflow insert x=%d\n", x);
  else {
    q->n = (q->n) + 1;
    q->q[q->n] = x;
    bubble_up(q, q->n);
  }
}

void pq_init(priority_queue *q) {
  q->n = 0;
}

void make_heap(priority_queue *q, item_type s[], int n) {
  int i;

  pq_init(q);
  for (i=0; i<n; i++)
    pq_insert(q, s[i]);
}

int main() {
  return 0;
}
