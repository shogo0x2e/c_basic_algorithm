/*
 *	DATE:
 *		14:00:44 金 10 月 07, 2022
 *
 *	AUTHOR:
 *		Shogo Kitada (Twitter, GitHub: shogo0x2e)
 *		Mail: shogo.kitada@outlook.jp
 *
 *	DESCRIPTION:
 *		二分探索のコード例
 */

#include <stdio.h>

#define N 10

struct {
    int key;
    int data;
} table[] = {
    {1, 10}, {2, 11}, {3, 12}, {5, 13},  {6, 14},
    {7, 15}, {8, 16}, {11, 17}, {14, 18}, {19, 19}
};

int binary_search(int key) {
    
    // left と right は key ではない
    int left = 0, right = N-1;
    int mid = (left + right) / 2;

    while (left <= right) {
        
        // key が一致したとき
        if (key == table[mid].key) {
            return table[mid].data;
        }
        // ここの条件式は key
        else if (table[mid].key < key) {
            left = mid + 1;
        }
        else if (key < table[mid].key) {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    
    int k = 5;

    printf("Element %d has %d.\n", k, binary_search(k));

    return 0;
}
