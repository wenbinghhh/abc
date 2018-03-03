#include "node.h"
#include <stdio.h>
#include <stdlib.h>
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
void change( struct Stu *head)
{
	printLink(head);
	int ch,t=0;
	char id[9],name[13];
	struct Stu *p;
	p=head;	
	printf("输入要修改学生的学号：\n");
	scanf("%s",id);
	while(p!=NULL)
		{
			if(strcmp(p->id,id)==0)						
				{
					printStu(p);
					printf("选择要修改的项目\n");	
					printf("1:姓名\n");	
					printf("2:年龄\n");
					scanf("%d",&ch);	
					switch(ch)
					{
						case 1:
							printf("输入修改后的姓名：\n");
							scanf("%s",name);
							strcpy(p->name,name);
						break;
						case 2:
							printf("输入修改后的年龄：\n");
							scanf("%d",&(p->age));
						break;
						default:
						break;
					}
					t=1;
				}
			p=p->next;
		}
		if(t==0)
			{
				printf("\n要修改的学生不存在\n");
			}
		else
			{
				printf("\n修改成功！\n");
	
			}
}

int save(struct Stu *head,int len)
{
	struct Stu *p=NULL;
	FILE *data=NULL;
	data=fopen("/home/wenebing/wp/abc/file1","w");
	fwrite(&len,4,1,data);
	p=head;
	while(p!=NULL)
	{
		fwrite(p,sizeof(struct Stu),1,data);
		p=p->next;
	}
	fclose(data);
	printf("文件保存完成\n");
}
struct Stu *readlink()
{
	struct Stu *head=NULL;
	FILE *fp=NULL;
	struct Stu *new=NULL;
	struct Stu *p=NULL;
	int i,len=0;
	fp=fopen("/home/wenebing/wp/abc/file1","r");	
	if(fp==NULL)
	{
		printf("打开文件失败\n");
		return NULL;
	}
	fread(&len,4,1,fp);
	p=head;
	for(i=0;i<len;i++)
	{
		new=(struct Stu * )malloc(sizeof(struct Stu));
		fread(new,sizeof(struct Stu),1,fp);
		new->next=NULL;
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			p->next=new;
		}
		p=new;
	}
	fclose(fp);
	return head;
}
