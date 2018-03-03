//
// Created by tecyang on 18-3-3.
//

#include <stdio.h>
#include <stdlib.h>

//查找字符串中各个字符出现的次数
void FindTimes(char* str) {
    int hash[256] = {0};
    int index = 0;
    while (str[index] != '\0') {
        hash[str[index]]++;
        index++;
    }
    for (index = 0; index < 256; index++) {
        printf("%c : %d\n", index, hash[index]);
    }
    printf("\r\n");
}

//翻转字符串不翻转单词
//1.为每个单词建立索引 内存空间占用 代价高
//2.1字符串字节单位翻转
//2.2单词翻转

//对字符串中固定位置的区域进行翻转
void Reverse(char* str,int begin,int end) {
    char tmp;
    while (begin < end) {
        tmp = str[begin];
        str[begin] = str[end];
        str[end] = tmp;
        begin++;
        end--;
    }
}

//字符串内部单词翻转,从头部开始,每确定一个单词就进行翻转
void Reverse_second(char* str,int len) {
    int begin, i, j;
    for (i = 0; i < len;) {
        begin = i;
        for (j = i; j < len; j++) {
            if (str[j] == ' ')
                break;
        }
        Reverse(str, begin, j - 1);
        i = j + 1;
    }
}

int main() {
    char str[] = "Hello World";
    FindTimes(str);
    Reverse(str, 0, 10);
    Reverse_second(str, 11);
    printf("%s\n", str);
    return 0;
}
