#include "b_system.h"

find_turn(int turn)                               // to find how many match times
{
	if (strlen(stu.num) != 13)
		return(turn);
	else
	{
		turn++;
		*p1 = stu;
		p1 = (struct infor*)malloc(LEN);															//遍历链表
		p2->next = p1;
		p3 = p2;
		p2 = p1;
		return(turn);
	}
}
  
showresult(int turn)                               
{
	char c, found;
	char msg[100];
	int len, time = 0, i;
		if (turn == 1)
		{
			line('2');
			printf("\n\n");
			printf("\n\n");
			printf("查找失败!   是否继续？\n");
			printf("输入[Y]确定,[N]回到菜单");
			c = getch();
			while (c != 'y' && c != 'n')
				c = getch();
			switch (c)
			{
			case 89:
			case 121:sec(); break;
			case 78:
			case 110:home('1'); break;
			}
		}
		if(turn == 2)
		{
			line('2');
			printf("\n\n\n\n");
			mid(); printf("      登录号:%s\n\n", head->num);
			mid(); printf("      书  名:%s\n\n", head->title);
			mid(); printf("      作者名:%s\n\n", head->author);
			mid(); printf("      出版单位:%s\n\n", head->publisher);
			mid(); printf("      出版时间:%s\n\n", head->time);
			mid(); printf("      价格:%s", head->price);
			fclose(fp);
			printf("\n\n");
			printf("查找成功!   是否继续？\n");
			printf("输入[Y]确定,[N]回到菜单");
			c = getch();
			while (c != 'y' && c != 'n')
				c = getch();
			switch (c)
			{
			case 89:
			case 121:sec();
			case 78:
			case 110:home('1');
			}
		}
		else
		{
			while (1)
			{
				p1 = head;
				system("cls");
				line('2');
				line('3');
				line('1');
				printf("   ");
				do																					//循环输出输出数据
				{
					printf("%s ", p1->num);
					printf("%s ", p1->title);
					len = 20;
					while ((len - strlen(p1->title)) > 0)
					{
						printf(" ");
						len--;
					}
					printf("%s ", p1->author);
					len = 8;
					while ((len - strlen(p1->author)) > 0)
					{
						printf(" ");
						len--;
					}
					printf("%s ", p1->publisher);
					len = 20;
					while ((len - strlen(p1->publisher)) > 0)
					{
						printf(" ");
						len--;
					}
					printf("%s ", p1->time);
					len = 10;
					while ((len - strlen(p1->time)) > 0)
					{
						printf(" ");
						len--;
					}
					printf("%s ", p1->price);
					len = 6;
					while ((len - strlen(p1->price)) > 0)
					{
						printf(" ");
						len--;
					}
					printf("\n   ");
					p1 = p1->next;
				} while (p1 != NULL);
				printf("\n\n\n\n\n\n\n输入①返回菜单②退出程序");
				c = getch();
				switch (c)
				{
				case'1':home('1'); break;
				case'2':byebye_check(); break;
				}
			}
		}
}

found_book() //        precise find the book
{
	char Found;
	int turn = 1;
	head = NULL;
	p1 = p2 = p3 = (struct Book*)malloc(LEN);
	head = p1;
	system("cls");
	if ((fp = fopen("book.txt", "r")) == NULL)
	{
		system("cls");
		line(2);
		printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	if (feof(fp))
	{
		system("cls");
		line(2);
		printf("\n\n    文件读取失败!\n\n    ");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s", stu.num, stu.title, stu.author, stu.publisher, stu.time, stu.price);
			if (!strcmp(stu.title, tem.title) && (!feof(fp)))
				turn = find_turn(turn);
		}
		fclose(fp);
		p3->next = NULL;
		showresult(turn);
	}

}

kmp_f_book()  //fuzzy search
{
	SString T, S;
	int i, j;
	char Found;
	int turn = 1;
	head = NULL;
	p1 = p2 = p3 = (struct Book*)malloc(LEN);
	head = p1;
	system("cls");
	if ((fp = fopen("book.txt", "r")) == NULL)
	{
		system("cls");
		line(2);
		printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	if (feof(fp))
	{
		system("cls");
		line(2);
		printf("\n\n    文件读取失败!\n\n    ");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s", stu.num, stu.title, stu.author, stu.publisher, stu.time, stu.price);
			for (i = 0; tem.title[i] != '\0'; ++i)
			{
				S[i + 1] = tem.title[i];
			}
			S[0] = i;//汉字算两个字符 英语数字符号算一个
			for (i = 0; stu.title[i] != '\0'; ++i)
			{
				T[i + 1] = stu.title[i];
			}
			T[0] = i;
			if (kmp(T, S) && (!feof(fp)))
				turn = find_turn(turn);
		}
		fclose(fp);
		p3->next = NULL;
		showresult(turn);
	}

}

found_publisher()       
{
	char Found;
	int turn = 1;
	head = NULL;
	p1 = p2 = p3 = (struct Book*)malloc(LEN);
	head = p1;
	system("cls");
	if ((fp = fopen("book.txt", "r")) == NULL)
	{
		system("cls");
		line(2);
		printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	if (feof(fp))
	{
		system("cls");
		line(2);
		printf("\n\n    文件读取失败!\n\n    ");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s", stu.num, stu.title, stu.author, stu.publisher, stu.time, stu.price);
			if (!strcmp(stu.publisher, tem.publisher) && (!feof(fp)))
				turn = find_turn(turn);
		}
		fclose(fp);
		p3->next = NULL;
		showresult(turn);
	}
}


found_isbn()
{
	char Found;
	int turn = 1;
	head = NULL;
	p1 = p2 = p3 = (struct Book*)malloc(LEN);
	head = p1;
	system("cls");
	if ((fp = fopen("book.txt", "r")) == NULL)
	{
		system("cls");
		line(2);
		printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	if (feof(fp))
	{
		system("cls");
		line(2);
		printf("\n\n    文件读取失败!\n\n    ");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s", stu.num, stu.title, stu.author, stu.publisher, stu.time, stu.price);
			if (!strcmp(stu.num, tem.num) && (!feof(fp)))
				turn = find_turn(turn);
		}
		fclose(fp);
		p3->next = NULL;
		showresult(turn);
	}
}


sec()                 chose function
{
	char c;
	system("cls");
	line('2');
	line('3');
	printf("请选择你要查找的方式\n");
	printf("1.书名       2.出版社      3.ISBN编码     4.模糊搜索书名");
	c = getch();
	while (c != '1' && c != '2' && c != '3' && c != '4')
		c = getch();
	switch (c)
	{
	case'1':resec('1'); break;
	case'2':resec('2'); break;
	case'3':resec('3'); break;
	case'4':resec('4'); break;
	}
	
}

resec(int Sec)     rechose function																			//接受用户输入的相应查找条件
{
	switch (Sec)
	{
	case '1':system("cls");
		line(2);
		line(3);
		printf("\n\n"); mid(); printf("      请输入要查找(准确)的书名：");
		while (1)
		{
			scanf("%s", tem.title);
			if (!(strlen(tem.title) > 20 || strlen(tem.title) <= 0)) break;						//若输入数据合法则跳出循环
			else																		//若输入数据非法则重新输入
			{
				printf("\n\n"); mid(); printf("      请输入规范的书名(10个汉字以内)~!\n\n"); mid();
				printf("      ");
				system("pause");
				resec('1');
			}
			system("cls");
		}
		found_book();
	case '2':	system("cls");
		line(2);
		line(3);
		printf("\n\n"); mid(); printf("      请输入要查找的出版单位：");
		while (1)
		{
			scanf("%s", tem.publisher);
			if ((strlen(tem.publisher) <= 20) && (strlen(tem.publisher) > 0)) break;			//若输入数据合法则跳出循环
			else																		//若输入数据非法则重新输入
			{
				printf("\n\n"); mid(); printf("      请输入规范的出版单位(必须为10个汉字以内)~!\n\n"); mid();
				printf("      ");
				system("pause");
				resec('2');
			}
			system("cls");
		}
		found_publisher();
	case'3':system("cls");
		line(2);
		line(3);
		printf("\n\n"); mid(); printf("      请输入要查找的ISBN编码：");
		while (1)
		{
			scanf("%s", tem.num);
			if ((strlen(tem.num) == 13)) break;			//若输入数据合法则跳出循环
			else																		//若输入数据非法则重新输入
			{
				printf("\n\n"); mid(); printf("      请输入规范的ISBN编码(13个数字)~!\n\n"); mid();
				printf("      ");
				system("pause");
				resec('3');
			}
			system("cls");
		}
		found_isbn();
	case'4':system("cls");
		line(2);
		line(3);
		printf("\n\n"); mid(); printf("      请输入要查找的书本（模糊）：");
		while (1)
		{
			scanf("%s", tem.title);
			if (!(strlen(tem.title) > 20 || strlen(tem.title) <= 0)) break;						//若输入数据合法则跳出循环
			else																		//若输入数据非法则重新输入
			{
				printf("\n\n"); mid(); printf("      请输入规范的书名(10个汉字以内)~!\n\n"); mid();
				printf("      ");
				system("pause");
				resec('4');
			}
			system("cls");
		}
		kmp_f_book();
	}

}

