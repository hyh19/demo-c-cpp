//
//  2-1-x.c
//  Demo-Data-Structure-C
//
//  Created by Yuhui Huang on 08/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/**
 学生信息
 */
typedef struct {
    int id; // 学号
    char name[10]; // 姓名
    float score; // 成绩
} Student;


/**
 顺序查找

 @param stu 顺序表
 @param n 顺序表的元素个数
 @param key 查找的key
 @return 查找成功，返回索引，查找失败，返回-1。
 */
int search(Student stu[], int n, int key) {
    for (int i=0; i<n; ++i) {
        if (stu[i].id == key) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    Student stu[4] = {{1004, "TOM", 100},
                      {1002, "LILY", 95},
                      {1001, "ANN", 93},
                      {1003, "LUCY", 98}};
    int index = search(stu, 4, 1001);
    printf("Student ID: %d\n", stu[index].id);
    printf("Student Name: %s\n", stu[index].name);
    printf("Student Score: %f\n", stu[index].score);
    
    return 0;
}
