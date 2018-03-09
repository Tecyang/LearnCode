//
// Created by tecyang on 18-3-8.
//

//题目描述
//
//        请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为 We Are Happy. 则经过替换之后的字符串为 We%20Are%20Happy。

#include <stdio.h>
#include <stdlib.h>

char* ReplaceSpace(char str[], int len) {

    if (len == 0) return NULL;
    int idxOfOriginal = len - 2;//字符串长度为元素个数+1('\0') 可以引入string.h 使用strlen()
    int idxOfNew = len - 1;

    for (int i = 0; i < len - 1; i++) {
        if (str[i] == ' ') {
            str[idxOfNew++] = str[i];
            str[idxOfNew++] = str[i];
            str[idxOfNew] = '\0';
        }
    }

    while (idxOfOriginal >= 0 && idxOfNew > idxOfOriginal) {
        if (str[idxOfOriginal] == ' ') {
            str[--idxOfNew] = '0';
            str[--idxOfNew] = '2';
            str[--idxOfNew] = '%';
        } else {
            str[--idxOfNew] = str[idxOfOriginal];
        }
        idxOfOriginal--;
    }
    return str;
}

int main() {
    char str[] = "We Are Happy";
    printf("%s", ReplaceSpace(str, sizeof(str)));
    return 0;
}


