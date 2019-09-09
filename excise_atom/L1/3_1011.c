#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int arr1[2][3];
int arr2[3][2];
int arr3[2][2];

int intput()
{
    int tmp;
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            tmp = scanf("%d", &arr1[i][j]);
        }
        getchar();
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            tmp = scanf("%d", &arr2[i][j]);
        }
        getchar();
    }
    return tmp;
}
int main(int argc, char *argv[]) {
    int i, j;

    while (intput() != EOF) {
        for(i = 0; i < 2; i++){
            for(j = 0; j < 3; j++){
                arr3[0][i] += arr1[0][j]*arr2[j][i];
            }
        }
        for(i = 0; i < 2; i++){
            for(j = 0; j < 3; j++){
                arr3[1][i] += arr1[1][j]*arr2[j][i];
            }
        }
        
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("%d ", arr3[i][j]);
            }
            printf("\n");
        }
        memset(arr3, 0, sizeof(arr3));
    } /* end of while */

	return 0;
}
