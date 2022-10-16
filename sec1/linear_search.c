/*
 *	DATE:
 *		14:00:44 金 10 月 07, 2022
 *
 *	AUTHOR:
 *		Shogo Kitada (Twitter, GitHub: shogo0x2e)
 *		Mail: shogo.kitada@outlook.jp
 *
 *	DESCRIPTION:
 *		線形探索のコード例
 */

#include <stdio.h>

#define N 10

struct {
    int key;
    int data;
} table[] = {
    {1, 10}, {2, 11}, {3, 12}, {4, 13},  {5, 14},
    {6, 15}, {7, 16}, {8, 17}, {9, 18}, {10, 19}
};

int linear_search(int key) {
    
    for (int i = 0; i < N; i++) {
        if (table[i].key == key) {
            return table[i].data;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    
    int k = 5;

    printf("Element %d has %d.\n", k, linear_search(k));

    return 0;
}
