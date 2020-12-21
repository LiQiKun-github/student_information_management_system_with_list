#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"student.h"

void student_Menu() {
	char sel;
	for(;;)
	{
		
		printf("\n%s",STUDENT_MENU);
		sel = getchar();
		while (getchar() != '\n');
		switch (sel)
		{
		case '1':add_student(); break;
			
		case '2':show_Student(); break;

		case '3':find_One_Student(); break;

		case '4':delete_One_Student(); break;

		case '5':reverse_Output_Student(); break;

		case '6':delete_All_Student(); break;

		case '7':return;

		default:printf("\nAre you kidding me!!!Please input a num again!!!\n\n");
		}
	}
	

}