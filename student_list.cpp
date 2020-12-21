#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include"student_list.h"

 
//学生链表添加学生信息
void list_Add(STU** head, STU* p)
{
		p->next = *head;
		*head = p;
}

//打印学生链表信息
void print_Stuent_List(STU* head)
{
	while (head != NULL)
	{
		show_One_Node(head);
		head = head->next;
	}
}

//显示一个学生节点信息
bool show_One_Node(STU* p)
{
	if (NULL != p)
	{
		printf("id:%d\n", p->id);
		printf("name:%s\n", p->name);
		printf("age:%d\n", p->age);
		printf("Chinese:%.2lf\n", p->transcript.Chinese);
		printf("Math:%.2lf\n", p->transcript.Math);
		printf("English:%.2lf\n", p->transcript.English);
		printf("\n");
	}
	else return false;
	return true;
}

//根据学生id在链表当中查找一个节点
STU *find_One_Student_Node(STU *head,int id)
{
	for (;;)
	{
		if (head == NULL) return NULL;
		if (head->id == id) return head;
		else head = head->next;
	}
	return NULL;
}

//查找学生链表某个节点的上一个节点
STU* find_last_node(STU* head, STU* p)
{
	STU* temp = NULL;
	if (head == NULL) return NULL;
	while (head->next != NULL)
	{
		if (head->next == p) return head;
		head = head->next;
	}
	return NULL;
}

//取出链表某个节点
STU* take_Out_One_Node(STU **head,STU *p)//如果head==p==NULL 会死
{
	if (NULL==p) { printf("别瞎取出节点！！！\n"); return NULL; }
	STU* temp = NULL;
	if (*head == p)
	{
		temp = *head;
		*head = (*head)->next;
	}
	else {
		temp = p;
		STU* node = find_last_node(*head, p);
		node->next = temp->next;
	}
	temp->next = NULL;
	return temp;
}

//销毁一个节点
void delete_One_Node(STU **head,STU *p)
{
	STU* temp = take_Out_One_Node(head,p);
	free(temp);
}

void destroy_List(STU* head)
{
	if (head == NULL) return;
	destroy_List(head->next);
	free(head);
}

//实现链表反转并创建新的链表
STU *reverse_Output_List(STU *head)
{
	STU* head1=NULL;
	STU* temp = NULL;
	while (head != NULL)
	{
		temp=take_Out_One_Node(&head,head);
		list_Add(&head1, temp);
	}
	
	return head1;
}