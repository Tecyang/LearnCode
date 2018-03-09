//
// Created by tecyang on 18-3-1.
//

#include <stdio.h>
#include <stdlib.h>

//递归方式求字符串长度
int RecurLength(char* str) {
    if (str[0] == '\0')
        return 0;
    else return RecurLength(str + 1) + 1;
}

//求解字符串中最后一个单词长度
int LastWordLen(char *str,int len) {
    int lastlen = 0;
    int index = len - 1;
    while (index >= 0 && str[index--] != ' ')
        lastlen++;
    return lastlen;

}
//求解字符串最后单词长度不知道字符串总长度
int LastWordLen2(char* str) {
    int lastlen = 0;
    int index = 0;
    while (str[index] != '\0') {
        if (str[index++] != ' ')
            lastlen++;
        else
            lastlen = 0;
    }
    return lastlen;
}

//字符串内存的拷贝 实现memmove函数
char* my_memmove(char* dst,char* src,int count) {
    char *ret = dst;
    if (dst == NULL || src == NULL)
        return NULL;
    //如果dst和src区域没有重叠,那么从开始处逐一拷贝
    if (dst <= src || dst >= (src + count)) {
        while (count--) {
            *dst = *src;
            dst++;
            src++;
        }
    }
        //如果dst和src区域有交叉,那么从尾部开始向起始位置拷贝,这样可以避免数据重叠
    else {
        dst = dst + count - 1;
        src = src + count - 1;
        while (count--) {
            *dst = *src;
            dst--;
            src--;
        }
    }
    return ret;
}
int main() {
    char str[] = "Hello World";
    printf("str len is %d\n", RecurLength(str));
    printf("lastword len is %d\n",LastWordLen(str,11));
    printf("lastword len is %d",LastWordLen2(str));
    return 0;
}

