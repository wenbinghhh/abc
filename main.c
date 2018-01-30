#include <stdio.h>
#include "link.h"
#include "node.h"
#include <stdlib.h>
//
int main()
{
	struct Stu *head=NULL;
	struct Stu *pnew=NULL;
	int sel;
	while(1)
	{
		printf("1.插入\n2.输出\n3.查询\n4.删除\n5.退出\n");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
				pnew=setStu();
				head=insertLink(head,pnew);	
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
				return 0;
				break;
			default :
				break;	
		}

	}
	return 0;
}
