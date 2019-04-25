#include "b_system.h"

book_save()   //从文件尾部写入文件
{
	char c;
	int len;
	if ((fp = fopen("book.txt", "a")) == NULL)
	{
		if ((fp = fopen("book.txt", "r")) == NULL)
		{
			system("cls");
			printf("\n     文件创建失败 \n");
			system("puase");
			home(1);
		}
		book_save();
	}
	else
	{
		fseek(fp, 0L, 2);
		fprintf(fp, "%s ", stu.num);
		fprintf(fp, "%s ", stu.title);
		len = 20;
		while ((len - strlen(stu.title)) > 0)    //保证每次同样长
		{
			fprintf(fp, " ");
			len--;
		}
		fprintf(fp, "%s ", stu.author);
		len = 8;
		while ((len - strlen(stu.author)) > 0)
		{
			fprintf(fp, " ");
			len--;
		}
		fprintf(fp, "%s ", stu.publisher);
		len = 20;
		while ((len - strlen(stu.publisher)) > 0)
		{
			fprintf(fp, " ");
			len--;
		}
		fprintf(fp, "%s ", stu.time);
		len = 10;
		while ((len - strlen(stu.time)) > 0)
		{
			fprintf(fp, " ");
			len--;
		}
		fprintf(fp, "%s", stu.price);

	}
	fprintf(fp, "\n");
	fclose(fp);
	printf("\n\n    成功录入信息   是否继续?   \n\n");
	printf("输入①继续录入信息 ②返回菜单");
	c = getch();
	switch (c)
	{
	case'1': book_scan(); break;
	case'2':home('1'); break;
	}
}




book_scan()   //从用户处得到信息 准备输入
{
	system("cls");
	line('2');
	line('3');
	char c;
	int len_fp = 0;
	int len_scan = 0;
	int allow = 0;
	while (1)
	{
		if (allow == 1)
		{
			break;
		}
		printf("请输入ISBN编码(13位):");
		scanf("%s", stu.num);
		if (strlen(stu.num) == 13)
		{
			allow = 1;
		}
		else
		{
			printf("\n   输入错误!\n\n");
			allow = 0;
			system("pause");
		}
		system("cls");
		line('2');
		line('3');
	}

	while (1)
	{
		system("cls");
		line('2');
		line('3');
		printf("请输入ISBN编码(13位):%s\n", stu.num);
		printf("请输入书名(10个字以内):");
		scanf("%s", stu.title);
		if ((strlen(stu.title) <= 20 && strlen(stu.title) > 0))
		{
			system("cls");
			break;
		}
		else
		{
			printf("\n   请输入规范的书名(10个汉字以内)~!\n\n   ");
			system("pause");
		}
		system("cls");
		line('2');
		line('3');
	}
	while (1)
	{
		system("cls");
		line('2');
		line('3');
		printf("请输入ISBN编码(13位):%s\n", stu.num);
		printf("请输入书名(10个字以内):%s\n", stu.title);
		printf("请输入作者名(4个字以内):");
		scanf("%s", stu.author);
		if ((strlen(stu.author) > 0 && strlen(stu.author) <= 8))
		{
			system("cls");
			break;
		}
		else
		{
			printf("\n   请输入规范的作者名(4个汉字以内)~!\n\n   ");
			system("pause");
		}
		system("cls");
	}


	while (1)
	{
		system("cls");
		line('2');
		line('3');
		printf("请输入ISBN编码(13位):%s\n", stu.num);
		printf("请输入书名(10个字以内):%s\n", stu.title);
		printf("请输入作者名(4个字以内):%s\n", stu.author);
		printf("请输入出版单位名字:");
		scanf("%s", stu.publisher);
		if ((strlen(stu.publisher)) <= 20 && strlen(stu.publisher) > 0)
		{
			system("cls");
			break;
		}
		else
		{
			printf("\n   请输入规范的出版单位(必须为10个汉字以内)~!\n\n   ");
			system("pause");
		}
		system("cls");
		line('2');
		line('3');
	}
	system("cls");
	while (1)
	{
		system("cls");
		line('2');
		line('3');
		printf("请输入ISBN编码(13位):%s\n", stu.num);
		printf("请输入书名(10个字以内):%s\n", stu.title);
		printf("请输入作者名(4个字以内):%s\n", stu.author);
		printf("请输入出版单位名字:%s\n", stu.publisher);
		printf("请输入规范日期(格式:2011/01/01):");
		scanf("%s", stu.time);
		if (strlen(stu.time) == 10)
		{
			system("cls");
			break;
		}
		else
		{
			printf("\n   请输入规范的日期(必须为2011/01/01格式)~!\n\n   ");					//若数据不合法则强制重新输入
			system("pause");
		}
		system("cls");
		line('2');
		line('3');

	}

	while (1)
	{
		system("cls");
		line('2');
		line('3');
		printf("请输入ISBN编码(13位):%s\n", stu.num);
		printf("请输入书名(10个字以内):%s\n", stu.title);
		printf("请输入作者名(4个字以内):%s\n", stu.author);
		printf("请输入出版单位名字(10个字以内):%s\n", stu.publisher);
		printf("请输入规范日期(格式:2011/01/01):%s\n", stu.time);
		printf("请输入价格(6位数字以内):");
		scanf("%s", stu.price);
		if ((0 < strlen(stu.price)) && (strlen(stu.price) <= 7))
		{
			system("cls");
			break;
		}							//若数据合法则终止循环
		else
		{
			printf("\n   请输入规范的价格(必须为6位数字以内)~!\n\n   ");					//若数据不合法则强制重新输入
			system("pause");
		}
		system("cls");
		line('2');
		line('3');
	}
	book_save();
}

// save_into_file
reader()       //展示已保存的内容
{
	system("cls");
	char c;
	char msg[100];
	int len, i;
	line('2');
	if ((fp = fopen("book.txt", "r")) == NULL)
	{
		system("cls");
		printf("\n\n  打开失败!文件不存在! \n\n");
		system("pause");
		home('1');
	}
	int a = getc(fp);
	if (feof(fp))
	{
		system("cls");
		printf("\n\n  数据不存在!\n\n");
		system("pause");
		home('1');
	}
	else
	{
		rewind(fp);
		printf("\n\n\n");
		line('1');
		fgets(msg, 100, fp);
		while (!feof(fp))
		{
			for (int j = 0; j < 3; ++j)
				printf(" ");
			printf("%s", msg);
			fgets(msg, 100, fp);
		}
		fclose(fp);
	}
	printf("\n\n\n\n\n\n\n输入①返回菜单②退出程序");
	c = getch();
	switch (c)
	{
	case'1':home('1'); break;
	case'2':byebye_check(); break;
	}
}


sortwrite()                                 //用于重新写入文件        inf_change   case'4'      readi_in_linklist(全部)
{
	p2 = p1 = head;
	char c, b;
	int len;
	if ((fp = fopen("book.txt", "w+")) == NULL)
	{
		system("cls");
		line('2');
		printf("\n\n\n   文件修改失败! \n\n  磁盘拒绝访问! \n");
		system("pause");
		home('1');
	}
	else
	{
		while (p1 != NULL && p2 != NULL && p2->next != NULL && p1->next != NULL)
		{
			fprintf(fp, "%s ", p1->num);
			fprintf(fp, "%s ", p1->title);
			len = 20;
			while ((len - strlen(p1->title)) > 0)    //保证每次同样长
			{
				fprintf(fp, " ");
				len--;
			}
			fprintf(fp, "%s ", p1->author);
			len = 8;
			while ((len - strlen(p1->author)) > 0)
			{
				fprintf(fp, " ");
				len--;
			}
			fprintf(fp, "%s ", p1->publisher);
			len = 20;
			while ((len - strlen(p1->publisher)) > 0)
			{
				fprintf(fp, " ");
				len--;
			}
			fprintf(fp, "%s ", p1->time);
			len = 10;
			while ((len - strlen(p1->time)) > 0)
			{
				fprintf(fp, " ");
				len--;
			}
			fprintf(fp, "%s ", p1->price);
			fprintf(fp, "\n");
			p2 = p1;
			if (p1 != NULL && p2 != NULL && p2->next != NULL && p1->next != NULL)
				p1 = p2->next;
			else
				break;
		}
		fclose(fp);
	}
}



get_next(SString T,int next[])          //kmp算法实现模糊搜索
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++j;
			++i;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

kmp(SString S, SString T)
{	
	int i = 1;
	int j = 1;
	int next[100];
	get_next(T, next);
	while (i <= S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T[0]) return 1;
	else return 0;
}
