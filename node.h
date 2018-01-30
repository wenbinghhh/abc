#ifndef __NODE_H
#define __NODE_H

struct Stu
{
	char id[9];
	char name[13];
	int age;
	struct Stu *next;
};

struct Stu * setStu();
void printStu( struct Stu *);
int stucmp(struct Stu *,struct Stu *);

#endif/* __NODE_N*/
