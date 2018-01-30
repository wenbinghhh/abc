#include "node.h"
#include <stdio.h>
#include <string.h>
void printLink( struct Stu *head)
{
	while(head!=NULL)
	{
		printStu(head);
		head=head->next;
	}
}

struct Stu *insertLink(struct Stu *head,struct Stu *pnew)
{
	struct Stu *p1,*p2;

	p2=p1=head;
	while(p1!=NULL&&stucmp(p1,pnew)<0)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1==p2)
	{
		head=pnew;
	}
	else
	{
		p2->next=pnew;
	}
	pnew->next=p1;
	return head;
}
void search( struct Stu *head)
{
	int ch,age,t=0;
	char id[9],name[13];
	struct Stu *p;	
	printf("选择查找依据：\n");
	printf("1：学号\n");
	printf("2:姓名\n");
	printf("3：年龄\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("输入要查找的学号：");
			scanf("%s",id);
			p=head;
			while(p!=NULL)
				{
					if(strcmp(p->id,id)==0)						
						{
							printStu(p);
							t=1;
						}
					p=p->next;
				}
			if(t==0)
				{
					printf("\n要查找的学号不存在\n");
				}
		break;
		case 2:
			
			printf("输入要查找的姓名：");
			scanf("%s",name);
			p=head;
			t=0;
			while(p!=NULL)
				{
					if(strcmp(p->name,name)==0)						
						{
							printStu(p);
							t=1;
						}
					p=p->next;
				}
			if(t==0)
				{
					printf("\n要查找的姓名不存在\n");
				}
			
		break;
		case 3:
			
			printf("输入要查找的年龄：");
			scanf("%d",&age);
			p=head;
			t=0;
			while(p!=NULL)
				{
					if(p->age==age)						
						{
							printStu(p);
							t=1;
						}
					p=p->next;
				}
			if(t==0)
				{
					printf("\n要查找的年龄不存在\n");
				}
		break;
		default:
		break;	
	}
		
}
void del(struct Stu ** head)
{
	int t=0;
	char id[9];	
	struct Stu * p1,*p2;
	printf("输入要删除的学号：");
	scanf("%s",id);
	p1=p2=(*head);
	while(p1!=NULL)
		{
			
			if(strcmp(p1->id,id)==0)						
				{
					if(p1==(*head))
					{
						(*head)=p1->next;
					}
					else
					{
						p2->next=p1->next;
					}
					t=1;
				}
			p2=p1;
			p1=p1->next;
		}
			if(t==0)
				{
					printf("\n要删除的学号不存在\n");
				}
			else
				{
					printf("\n删除成功！\n");
				}

	
}
