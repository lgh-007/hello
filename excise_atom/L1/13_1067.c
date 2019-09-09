#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int node_num, d;
	int *arr;
	int i, front, rear;

	while (scanf("%d", &node_num) != EOF) {
        if(node_num == 0){
            continue;
        }
        arr = (int*)malloc(sizeof(int) * node_num);
        for(i = 0; i < node_num; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &d);

        front = (int)pow(2, d - 1) -1;
        rear = (int)pow(2, d) -1;
        if (front > node_num) {
            printf("EMPTY\n");
        } else {
            for(i = front; i < rear; i++) {
                printf("%d ", arr[i]);
            }
        }
        free(arr);
	} /* end of while (scanf("%d", &node_num) != EOF) */
	return 0;
}
