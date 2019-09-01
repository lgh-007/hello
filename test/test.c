#include "test.h"


/*
 * 1. 结构体各个属性初始化、各属性赋值函数，由业务自己定义；
 * 2. 约束：在 DL_HASH_OP之前需要声明这两个函数；
 * 3. 函数名约束：name##_cache_obj_init(), name##_app_attr_copy(), name 与注册hash的一致；
 */

static inline void detail_cache_obj_init(detail_t *detail)
{
    memset(detail, 0, sizeof(detail[0]));
}

static inline void detail_app_attr_copy(detail_t *detail_obj, detail_t *detail_in)
{
    detail_obj->alloc_times = detail_in->alloc_times;
}

/* 初始化hash表  */
DL_KHASH_DEF(detail);

/* hash操作接口 */
DL_HASH_OP(detail);

void test(){
  detail_hash_init();
}
/* =================================打印接口 demo======================================== */


static int ut_dump_intf_op(void *item, void *para)
{
    detail_t *obj;
    int *lmt;

    lmt = (int *)para;
    if ((*lmt)-- == 0) {
        return -1;
    }

    obj = (detail_t *)item;

    printf("%7s %7d %7d\n", obj->key.filep, obj->key.line, obj->alloc_times);
    return 0;
}
//
static int intf_dump(int lmt)
{
    printf("dump-ss-intf:\n");
    printf("count:%d \n", detail_hash_size());
    printf(" filep    line    times  \n");
    printf("------- ------- ------- \n");
    DL_CACHE_TRAVERSE(detail, ut_dump_intf_op, &lmt);

    return 0;
}
// static int intf_dump2(int lmt)
// {
//     printf(" filep  total_alloc_times    total_free_times \n");
//     printf("------- ------- ------- \n");
//     DL_CACHE_TRAVERSE(detail, ut_dump_intf_op, &lmt);
//
//     return 0;
// }

/*================================main=================================*/


char* intf_mtrace_malloc(size_t size, char *filep, int line){
  void *mp;
  detail_t *obj;
  detail_t tmp;
  mp = malloc(size);
  if (mp != NULL) {
     /* 内存申请计数加1 */
     // node->count++;

       memset(&tmp, 0, sizeof(tmp));
       tmp.key.filep = filep;
       tmp.key.line = line;
       if (NULL == (obj = DL_CACHE_GET(detail, &tmp))){
           // printf("not found. \n");
           tmp.alloc_times++;
           if (NULL == DL_CACHE_CREATE(detail, obj, &tmp)) {
               printf("create fail. \n");
           }
       }else{
         obj->alloc_times++;
       }
  }
  return mp;
}

void intf_mtrace_free(void *mp, char *filep, int line){//
  if (mp != NULL) {
    free(mp);
    /* 内存申请计数减1 */
    // node.count--;
  }
  return;
}

void info_printf(){
  int dump_cnt;
  dump_cnt = -1;       /* -1表示全部打印 */
  intf_dump(dump_cnt);
}
