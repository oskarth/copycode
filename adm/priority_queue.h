#define PQ_SIZE 1000

typedef int item_type; // put in item.h

typedef struct {
  item_type q[PQ_SIZE+1];
  int n;
} priority_queue;
