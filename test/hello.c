#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "hello.h"




void hello(){
  int **test1,i;
  test1 = (int **)m_malloc(sizeof(int*) * 5);
  for(i = 0;i<5;i++ ){
    test1[i] = (int*)m_malloc(sizeof(int*)*10);
  }
  for(i = 0;i<3;i++){
    m_free(test1[i]);
  }
}
