/*
 *	DATE:
 *		13:39:15 金 10 月 07, 2022
 *
 *	AUTHOR:
 *		Shogo Kitada (Twitter, GitHub: shogo0x2e)
 *		Mail: shogo.kitada@outlook.jp
 *
 *	DESCRIPTION:
 *		Topic: 配列による stack の実現
 * 
 *      ここでは example として, RPN (Reverse Polish Notation)
 *      を入力とする電卓のコードを示す. 
 * 
 *      Documentation には Doxygen を使用している. 
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * @brief スタックの大きさ
 * 
 */
#define SIZE 100

/**
 * @brief スタックの要素の型
 * 
 */
typedef long E;

/**
 * @brief スタックの実体
 * 
 */
E stack[SIZE];

/**
 * @brief スタックポインタ (end を指す)
 * 
 */
int n;

/**
 * @brief エラー終了する
 * 
 * @param s エラーメッセージ
 */
void    error(const char s[]) {

    fprintf(stderr, s);
    exit(EXIT_FAILURE);
}

/**
 * @brief スタックを初期化する
 * 
 */
void    init() {

    n = 0;
}

/**
 * @brief スタックにデータを push する
 * 
 * @param x push する要素 x
 */
void    push(E x) {

    if (n >= SIZE) {
        error("Error! Stack has overflowed.\n");
    }
    stack[n++] = x;
}

/**
 * @brief スタックからデータを pop する
 * 
 * @return E pop した要素
 */
E        pop() {
    
    if (n <= 0) {
        error("Error! Stack has underflowed.\n");
    }
    return stack[--n];
}

/**
 * @brief スタックが空であるかを判定する
 * 
 * @return int 空ならば 0 以外, 空でなければ 0
 */
int     empty() {

    return n == 0;
}

///////////////////////////////////////////////////////////

int main() {
    
    int c;
    long x, a, b;

    printf("Please input numbers and operators by separating space or tab.\n");
    printf("You can exit by entering e character.\n");

    init();
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {

            // これなに？
            ungetc(c, stdin);
            scanf("%ld", &x);
            push(x);
        }
        else {
            switch (c) {
            case '+':
                b = pop(); a = pop();
                push(a + b);
                break;
            case '-':
                b = pop(); a = pop();
                push(a - b);
                break;
            case '*':
                b = pop(); a = pop();
                push(a * b);
                break;
            case '/':
                b = pop(); a = pop();
                if (b == 0) {
                    error("Error! Division by zero has occured.\n");
                }
                else {
                    push(a / b);
                }
                break;
            case '\n':
                if (!empty()) {
                    printf("The answer is %ld\n", pop());
                    init();
                }
                break;
            case ' ':
            case '\t':
                break;
            case 'e':
            case 'E':
                printf("Bye!\n");
                return 0;
            default:
                printf("There is an invalid value. Press any key to re-input\n");
                while ((c = getchar()) != EOF && c != '\n');
                break;
            }
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////
