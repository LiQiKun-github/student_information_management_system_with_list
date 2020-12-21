#ifndef _STUDENT_LIST_H_
#define _STUDENT_LIST_H_

#include"student.h"

//学生链表添加学生信息
void list_Add(STU** head, STU* p);

//打印学生链表信息
void print_Stuent_List(STU* head);

//学生链表当中查找一个节点
STU *find_One_Student_Node(STU *head,int id);

//显示一个学生节点信息
bool show_One_Node(STU *p);

//查找学生链表某个节点的上一个节点
STU* find_last_node(STU *head,STU *p);

//取出链表某个节点
STU* take_Out_One_Node(STU** head, STU* p);

//删除某个节点
void delete_One_Node(STU **head,STU* p);

//递归销毁链表
void destroy_List(STU* head);

//实现链表反转并创建新的链表
STU* reverse_Output_List(STU* head);

#endif // 

