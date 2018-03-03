
#ifndef __LINK_H
#define __LINK_H
#include<stdio.h>
void printLink( struct Stu *);
struct Stu *insertLink(struct Stu *,struct Stu *);
void search( struct Stu *);
void del(struct Stu **);
void change(struct Stu *);
void save( struct Stu *,int);
struct Stu * eadlink();

#endif /*__LINK_H*/
