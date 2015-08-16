#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "order.h"

int solve(int n, int nums[], int p);

#ifndef TESTING
void read (int n, int nums[]) {
  int i;
  for (i = 0; i < n*n; i++) {
    scanf("%d",&nums[i]);
  }
}

int main () {
  int p, n;
  scanf("%d\n", &p);
  scanf("%d\n", &n);
  int nums[n*n];
  read(n, nums);
  printf("%d\n", solve(n, nums, p));
  return 0;
}
#endif

struct pos {
    int x;
    int y;
};

void up    (struct pos *result) { result->y = result->y + 1; }
void down  (struct pos *result) { result->y = result->y - 1; }
void left  (struct pos *result) { result->x = result->x - 1; }
void right (struct pos *result) { result->x = result->x + 1; }

bool valid (struct pos *p, int n) {
  return (   p->x >= 0
          && p->x <  n
          && p->y >= 0
          && p->y <  n);
}

int value (struct pos *p, int n, int nums[]) {
  if (valid(p, n)){
    return nums[n * p->x + p->y];
  }
  return 0;
}

int prod_down (int l, struct pos *p, int n, int nums[]) {
  if (l == 0) { return 1; }
  int v = value(p, n, nums);
  down(p);
  return v * prod_down(l - 1, p, n, nums);
}

int prod_right (int l, struct pos *p, int n, int nums[]) {
  if (l == 0) { return 1; }
  int v = value(p, n, nums);
  right(p);
  return v * prod_right(l - 1, p, n, nums);
}

int prod_downright (int l, struct pos *p, int n, int nums[]) {
  if (l == 0) { return 1; }
  int v = value(p, n, nums);
  down(p);
  right(p);
  return v * prod_downright(l - 1, p, n, nums);
}

int prod_downleft (int l, struct pos *p, int n, int nums[]) {
  if (l == 0) { return 1; }
  int v = value(p, n, nums);
  down(p);
  left(p);
  return v * prod_downleft(l - 1, p, n, nums);
}

int solve(int n, int nums[], int q) {
  int i, j; struct pos p;
  int d, r, dr, dl, m;
  int mm = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      p.x = i;
      p.y = j;

      d = prod_down(q, &p, n, nums);
      r = prod_right(q, &p, n, nums);
      dr = prod_downright(q, &p, n, nums);
      dl = prod_downleft(q, &p, n, nums);

      m = max(max(d,r), max(dr, dl));
      if (m > mm) { mm = m; }
    }
  }
  return mm;
}
