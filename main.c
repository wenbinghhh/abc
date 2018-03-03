#include <stdio.h>
#include "link.h"
#include "node.h"
#include <stdlib.h>
//
int main()
{
	struct Stu *head=NULL;
	struct Stu *pnew=NULL;
	int n=0, sel;
	struct Stu *p=NULL;
	p=head=readlink();
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	while(1)
	{
		printf("1.插入\n2.输出\n3.查询\n4.删除\n5.修改\n6.保存\n7.退出");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
				pnew=setStu();
				head=insertLink(head,pnew);
				n++;
				break;
			case 2:
				printLink(head);
				break;

			case 3:
				search(head);
				break;
			case 4:
				del(&head);
				break;
			case 5:
				change(head);
				break;
			case 6:
				save(head,n);
				break;
			case 7:
				return 0;
				break;
			default :
				break;	
		}

	}
	return 0;
}
