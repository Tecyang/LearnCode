//
// Created by tecyang on 18-3-7.
//

//题目描述
//
//        在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//
//解题思路
//
//        从右上角开始查找。因为矩阵中的一个数，它左边的数都比它来的小，下边的数都比它来的大。因此，从右上角开始查找，就可以根据 target 和当前元素的大小关系来改变行和列的下标，从而缩小查找区间。

#include <stdio.h>
#include <stdlib.h>

bool Find(int target, int arrays[3][5],int rowcount, int celcount) {

    if (arrays == NULL || celcount == 0 || rowcount == 0) return false;
    int row = 0, cel = celcount - 1;
    while (row < rowcount && cel >= 0) {
        if (target == arrays[row][cel]) return true;
        else if (target > arrays[row][cel])
            row++;
        else
            cel--;
    }
    return false;

}


int main() {
    int arrays[3][5] = {
            {1, 2, 3, 4, 5},
            {2, 3, 4, 5, 6},
            {3, 4, 5, 6, 7}
    };

    int allLength = sizeof(arrays) / sizeof(int);
    int celcount = sizeof(arrays[0]) / sizeof(int);
    int rowcount = allLength / celcount;

    printf("%d", Find(7, arrays, rowcount, celcount));
    return 0;
}