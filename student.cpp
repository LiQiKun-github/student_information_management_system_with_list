#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include"student_list.h"
#include"student.h"

STU* head = NULL;

//将要添加的学生信息返回成一个节点
void add_student()
{
	STU* p = (STU*)malloc(sizeof(STU));
	if (NULL == p)
	{
		printf("error\n");
		exit(-1);
	}
	printf("id:"); scanf_s("%d", &p->id); while (getchar() != '\n');
	if (find_One_Student_Node(head, p->id) != NULL) {
		printf("这个id已经存在!!!\n");
		return;
	}
	printf("name:"); scanf_s("%s", p->name,20); while (getchar() != '\n');
	printf("age:"); scanf_s("%d", &p->age); while (getchar() != '\n');
	printf("Chinese:"); scanf_s("%lf", &(p->transcript.Chinese)); while (getchar() != '\n');
	printf("Math:"); scanf_s("%lf", &(p->transcript.Math)); while (getchar() != '\n');
	printf("English:"); scanf_s("%lf", &(p->transcript.English)); while (getchar() != '\n');
	list_Add(&head, p);
}

//显示所有学生
void show_Student()
{
	print_Stuent_List(head);
}

//查找一个学生
void find_One_Student()
{
	printf("Please input id:");
	int id; scanf_s("%d", &id);
	while (getchar() != '\n');
	if (!show_One_Node(find_One_Student_Node(head, id))) printf("查无此人\n");
}

//删除一个学生
void delete_One_Student()
{
	printf("Please input the id to be deleted:");
	int id;
	scanf_s("%d", &id);
	while (getchar()!= '\n');
	STU* temp = find_One_Student_Node(head, id);
	if (NULL == temp)
	{
		printf("无法删除，查无此人\n");
		return;
	}
	delete_One_Node(&head,temp);
}

//删除所有学生信息
void delete_All_Student()
{
	destroy_List(head);
	head = NULL;//头指针指向了被销毁的地址需要重置为NULL

}


void reverse_Output_Student()
{
	STU *new_head=reverse_Output_List(head);
	print_Stuent_List(new_head);
}