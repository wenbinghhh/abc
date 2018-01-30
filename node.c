#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "node.h"

struct Stu * setStu()
{
	struct Stu *p=NULL;
	char temp_id[9];
	char temp_name[13];
	int temp_age;
	printf("请输入学号：\n");
	scanf("%s",temp_id);
	printf("请输入姓名:\n");
        scanf("%s",temp_name);
	printf("请输入年龄：\n");
        scanf("%d",&temp_age);
	p=(struct Stu *)malloc(sizeof(struct Stu));
	strcpy((*p).id,temp_id);
	strcpy((*p).name,temp_name);
	(*p).age=temp_age;
	return p;
}

void printStu( struct Stu *p)

{

	printf("学号：%s  姓名：%s  年龄：%d\n",(*p).id,(*p).name,(*p).age);

}

int stucmp(struct Stu *p1,struct Stu *p2)
{
	return strcmp(p1->id,p2->id);
}
