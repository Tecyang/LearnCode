//
// Created by tecyang on 18-3-5.
//

#include <stdio.h>
#include <stdlib.h>

//题目描述
//        在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
//        请找出数组中任意一个重复的数字。例如，如果输入长度为 7 的数组 {2, 3, 1, 0, 2, 5, 3}，那么对应的输出是第一个重复的数字 2。
//
//解题思路
//        这种数组元素在 [0, n-1] 范围内的问题，可以将值为 i 的元素放到第 i 个位置上。

/**
 *
 * 交换函数
 * */
void swap(int numbers[],int i,int j) {
    printf("S1:i is %d \t j is %d \t numbers[i] is %d \t numbers[j] is %d \n",i,j,numbers[i],numbers[j]);
    int t = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = t;
    printf("S2:i is %d \t j is %d \t numbers[i] is %d \t numbers[j] is %d \n",i,j,numbers[i],numbers[j]);
}

/**
 *
 * 查找重复元素数字
 * */
bool duplicate(int numbers[],int length,int duplication[]) {
    if (numbers == NULL || length <= 0)return false;
    for (int i = 0; i < length; i++) {
        while (numbers[i] != i && numbers[i] != numbers[numbers[i]]) {
            swap(numbers, i, numbers[i]);
        }
        if (numbers[i] != i && numbers[i] == numbers[numbers[i]]) {
            duplication[0] = numbers[i];
           // printf("duplication 0 is %d\n",numbers[i]);
            return true;
        }
    }
    return false;
}


int main() {

    int numbers[] = {4,7,8,9,5,9,2,3,1,4};
    int duplication[] = {};
    duplicate(numbers,10,duplication);
//    if(duplicate(numbers,7,duplication))
//        printf("duplication[0] is :%d",duplication[0]);

    return 0;
}