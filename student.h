#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct Transcript
{
	double Chinese;
	double Math;
	double English;
}Transcript;

typedef struct student
{
	char name[20];//姓名
	char sex;//性别
	int id;//学号
	int age;//年龄
	Transcript transcript;
	struct student* next;
}STU;


//将要添加的学生信息返回成一个节点
void add_student();

//显示所有学生
void show_Student();

//查找一个学生
void find_One_Student();

//删除一个学生
void delete_One_Student();

//删除所有学生信息
void delete_All_Student();

//逆向输出所有学生信息
void reverse_Output_Student();
#endif
