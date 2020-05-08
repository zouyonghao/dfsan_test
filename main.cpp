#include <cassert>
#include <cstdio>
#include <sanitizer/dfsan_interface.h>

int main() {
  int i = 1;
  dfsan_label i_label = dfsan_create_label("i", nullptr);
  dfsan_set_label(i_label, &i, sizeof(i));

  int j = 2;
  dfsan_label j_label = dfsan_create_label("j", nullptr);
  dfsan_set_label(j_label, &j, sizeof(j));

  int k = 3;
  dfsan_label k_label = dfsan_create_label("k", nullptr);
  dfsan_set_label(k_label, &k, sizeof(k));

  dfsan_label ij_label = dfsan_get_label(i + j);
  assert(dfsan_has_label(ij_label, i_label));
  assert(dfsan_has_label(ij_label, j_label));
  assert(!dfsan_has_label(ij_label, k_label));

  dfsan_label ijk_label = dfsan_get_label(i + j + k);
  assert(dfsan_has_label(ijk_label, i_label));
  assert(dfsan_has_label(ijk_label, j_label));
  assert(dfsan_has_label(ijk_label, k_label));

  printf("i_label = %d\n", i_label);
  printf("j_label = %d\n", j_label);
  printf("k_label = %d\n", k_label);
  printf("ijk_label = %d\n", ijk_label);

  return 0;
}
