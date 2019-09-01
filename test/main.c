#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "hello.h"
// #include "dl_hash_def.h"

// extern intf_mtrace_info_t test;
int main(int argc, char const *argv[]){

  test();

  int **test1,i;
  hello();
  test1 = (int **)m_malloc(sizeof(int*) * 5);
  for(i = 0;i<5;i++ ){
    test1[i] = (int*)m_malloc(sizeof(int*)*10);
  }
  test1 = (int **)m_malloc(sizeof(int*) * 5);

  // for(i = 0;i<5;i++){
  //   m_free(test1[i]);
  // }
  // m_free(test1);
  info_printf();

  return 0;
}
