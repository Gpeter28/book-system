#include "b_system.h"

inf_change()
{
	int num = 0;
	int i;
	int pm = 0;
	head = NULL;
	p1 = p2 = (struct Book*)malloc(LEN);
	head = p1;
	char c, d;

	if ((fp = fopen("book.txt", "r")) == NULL)												//若文件打开失败则报错
	{
		system("cls");
		line(1);
		printf("\n\n   打开失败!文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	int b = fgetc(fp);
	if (feof(fp))
	{
		printf("error");
	}
	else
	{
		rewind(fp);
		fscanf(fp, "%s %s %s %s %s %s", p1->num, p1->title, p1->author, p1->publisher, p1->time, p1->price);
		while (!feof(fp))
		{
			num++;
			p1 = (struct Book*)malloc(LEN);
			p2->next = p1;
			p2 = p1;
			fscanf(fp, "%s %s %s %s %s %s", p1->num, p1->title, p1->author, p1->publisher, p1->time, p1->price);
		}
		p2->next = NULL;
		fclose(fp);
	}
	p1 = head;
	system("cls");
	int now_num = 1;
	line('2');
	printf("\n\n\n\n");
	printf("ISBN:%s\n", p1->num);
	printf("书名:%s\n", p1->title);                 //num总共书本数  now_num现在指向第几本书   pm指 指针该移动多少本书
	printf("作者:%s\n", p1->author);
	printf("出版社:%s\n", p1->publisher);
	printf("出版时间:%s\n", p1->time);
	printf("价格:%s\n", p1->price);
	line('3');
	line('4');
start:
	p1 = head;
	c = getch();
	while (c != '1'&&c != '2' && c != '3' && c != '4'&& c != '5')
		c = getch();
	switch (c)
	{
	case'1':
		if (now_num == 1)
		{
			system("cls");
			line('3');
			printf("这已经是最前一本了!!!!!");
			Sleep(400);
			system("cls");
			line('2');
			printf("\n\n\n\n");
			printf("ISBN:%s\n", p1->num);
			printf("书名:%s\n", p1->title);
			printf("作者:%s\n", p1->author);
			printf("出版社:%s\n", p1->publisher);
			printf("出版时间:%s\n", p1->time);
			printf("价格:%s\n", p1->price);
			line('3');
			line('4');
			goto start;
		}
		else
		{
			now_num--;
			pm--;
			for (i = 0; i < pm; ++i)
				p1 = p1->next;
			system("cls");
			line('2');
			printf("\n\n\n\n");
			printf("ISBN:%s\n", p1->num);
			printf("书名:%s\n", p1->title);
			printf("作者:%s\n", p1->author);
			printf("出版社:%s\n", p1->publisher);
			printf("出版时间:%s\n", p1->time);
			printf("价格:%s\n", p1->price);
			line('3');
			line('4');
			goto start;
		}
	case'2':
		if (num == now_num)
		{
			system("cls");
			line('3');
			printf("这已经是最后一本了!!!!!");
			Sleep(400);
			system("cls");
			line('2');
			printf("\n\n\n\n");
			for (i = 0; i < pm; ++i)
				p1 = p1->next;
			printf("ISBN:%s\n", p1->num);
			printf("书名:%s\n", p1->title);
			printf("作者:%s\n", p1->author);
			printf("出版社:%s\n", p1->publisher);
			printf("出版时间:%s\n", p1->time);
			printf("价格:%s\n", p1->price);
			line('3');
			line('4');
			goto start;
		}
		else
		{
			now_num++;
			pm++;
			for (i = 0; i < pm; ++i)
				p1 = p1->next;
			system("cls");
			line('2');
			printf("\n\n\n\n");
			printf("ISBN:%s\n", p1->num);
			printf("书名:%s\n", p1->title);
			printf("作者:%s\n", p1->author);
			printf("出版社:%s\n", p1->publisher);
			printf("出版时间:%s\n", p1->time);
			printf("价格:%s\n", p1->price);
			line('3');
			line('4');
			goto start;
		}
	case'3':printf("请选择 你要修改的数据1. ISBN编码       2.书名\n");
		printf("                     3. 作者           4.出版社\n");
		printf("                     5.出版时间        6.价格\n");
		c = getch();
		p1 = head;
		while (c != '1'&&c != '2' && c != '3' && c != '4' && c != '5' && c != '6')
		{
			c = getch();
		}
		for (i = 0; i < pm; ++i)
			p1 = p1->next;
		rewrite(c);
	case'4':printf("\n你确定要删除吗? 输入1确定  输入2回到主页!!!!");
		c = getch();
		p1 = head;
		for (i = 0; i < pm - 1; ++i)
		{
			p1 = p1->next;
		}
		while (c != '1'&& c != '2')
		{
			c = getch();
		}
		switch (c)
		{
		case'1':
			if (p1 == head)
			{
				head = p1->next;
			}
			else
			{
				p2 = p1->next;
				if (p2->next != NULL)
				{
					p1->next = p2->next;
				}
				else
				{
					p1->next = NULL;
				}
			}
			del();//function.c
			system("cls");
			line('3');
			printf("\n修改成功!!!!");
			printf("输入1回到主程序，2退出程序");
			d = getch();
			while (d != '1'&&d != '2')
			{
				d = getch();
			}
			switch (d)
			{
			case'1':home('1');
			case'2':byebye_check();
			}
			break;
		case'2':
			home('1');
		}
	case'5':home('1');
	}
}

del()
{
	int len;
	p2 = p1 = head;
	if ((fp = fopen("book.txt", "w+")) == NULL)
	{
		system("cls");
		printf("\n\n\n   文件修改失败!\n\n   磁盘拒绝访问!\n   ");
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

/*function_test()
{
	head = NULL;
	p1 = p2 = (struct Book*)malloc(LEN);
	head = p1;

	if ((fp = fopen("book.txt", "r")) == NULL)												//若文件打开失败则报错
	{
		system("cls");
		line(1);
		printf("\n\n   打开失败!文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	int c = fgetc(fp);
	if (feof(fp))
	{
			printf("error");
	}
	else
	{
		rewind(fp);
		fscanf(fp, "%s %s %s %s %s %s", p1->num, p1->title, p1->author, p1->publisher, p1->time, p1->price);
		while (!feof(fp))
		{
			p1 = (struct Book*)malloc(LEN);
			p2->next = p1;
			p2 = p1;
			fscanf(fp, "%s %s %s %s %s %s", p1->num, p1->title, p1->author, p1->publisher, p1->time, p1->price);
		}
		p2 ->next = NULL;
	}
	p1 = head;
	while (p1->next != NULL)
	{
		printf("ISBN:%s\n", p1->num);
		printf("书名:%s\n", p1->title);
		printf("作者:%s\n", p1->author);
		printf("出版社:%s\n", p1->publisher);
		printf("出版时间:%s\n", p1->time);
		printf("价格:%s\n", p1->price);
		p1 = p1->next;
	}
}*/



rewrite(char c)                    // inf_change()修改
{

	switch (c)
	{
	case'1': system("cls");
		line('2');
		line('3');
		printf("请输入新的ISBN编码:");
		scanf("%s", p1->num);
		if ((strlen(p1->num) <= 13 && strlen(p1->num) > 0))
		{
			sortwrite();
			printf("\n\n    成功修改信息   是否继续?   \n\n");
			printf("输入①继续录入信息 ②返回菜单");
			c = getch();
			while (c != '1'&&c != '2')
				c = getch();
			switch (c)
			{
			case'1':inf_change(); break;
			case'2':home('1'); break;
			}

		}
		else
		{
			printf("\n\n"); mid(); printf("      请输入规范的ISBN编码(13个数字)~!\n\n"); mid();
			printf("      ");
			system("pause");
			rewrite('1');
		}
	case'2':system("cls");
		line('2');
		line('3');
		printf("请输入新的书名:");
		scanf("%s", p1->title);
		if ((strlen(p1->title) <= 20 && strlen(p1->title) > 0))
		{
			sortwrite();
			printf("\n\n    成功修改信息   是否继续?   \n\n");
			printf("输入①继续录入信息 ②返回菜单");
			c = getch();
			while (c != '1'&&c != '2')
				c = getch();
			switch (c)
			{
			case'1':inf_change(); break;
			case'2':home('1'); break;
			}
		}
		else
		{
			printf("\n\n"); mid(); printf("      请输入规范的书名(10个汉字以内)~!\n\n"); mid();
			printf("      ");
			system("pause");
			rewrite('2');
		}
	case'3':system("cls");
		line('2');
		line('3');
		printf("请输入新的作者名:");
		scanf("%s", p1->author);
		if ((strlen(p1->author) <= 8 && strlen(p1->author) > 0))
		{
			sortwrite();
			printf("\n\n    成功修改信息   是否继续?   \n\n");
			printf("输入①继续录入信息 ②返回菜单");
			c = getch();
			while (c != '1'&&c != '2')
				c = getch();
			switch (c)
			{
			case'1':inf_change(); break;
			case'2':home('1'); break;
			}

		}
		else
		{
			printf("\n\n"); mid(); printf("      请输入规范的作者名(4个汉字以内)~!\n\n"); mid();
			printf("      ");
			system("pause");
			rewrite('3');
		}
	case'4':system("cls");
		line('2');
		line('3');
		printf("请输入新的出版社:");
		scanf("%s", p1->publisher);
		if ((strlen(p1->publisher) <= 20 && strlen(p1->publisher) > 0))
		{
			sortwrite();                                          //function.c----------用于重新写入文件
			printf("\n\n    成功修改信息   是否继续?   \n\n");
			printf("输入①继续录入信息 ②返回菜单");
			c = getch();
			while (c != '1'&&c != '2')
				c = getch();
			switch (c)
			{
			case'1':inf_change(); break;
			case'2':home('1'); break;
			}

		}
		else
		{
			printf("\n\n"); mid(); printf("      请输入规范的出版社(10个汉字以内)~!\n\n"); mid();
			printf("      ");
			system("pause");
			rewrite('4');
		}
	case'5':system("cls");
		line('2');
		line('3');
		printf("请输入新的出版时间:");
		scanf("%s", p1->time);
		if (strlen(p1->time) == 10)
		{
			sortwrite();
			printf("\n\n    成功修改信息   是否继续?   \n\n");
			printf("输入①继续录入信息 ②返回菜单");
			c = getch();
			while (c != '1'&&c != '2')
				c = getch();
			switch (c)
			{
			case'1':inf_change(); break;
			case'2':home('1'); break;
			}

		}
		else
		{
			printf("\n\n"); mid(); printf("      请输入规范的时间(必须为2011/01/01格式)~!\n\n"); mid();
			printf("      ");
			system("pause");
			rewrite('5');
		}
	case'6':system("cls");
		line('2');
		line('3');
		printf("请输入新的价格:");
		scanf("%s", p1->price);
		if ((strlen(p1->price) <= 7 && strlen(p1->price) > 0))
		{
			sortwrite();
			printf("\n\n    成功修改信息   是否继续?   \n\n");
			printf("输入①继续录入信息 ②返回菜单");
			c = getch();
			while (c != '1'&&c != '2')
				c = getch();
			switch (c)
			{
			case'1':inf_change(); break;
			case'2':home('1'); break;
			}
		}
		else
		{
			printf("\n\n"); mid(); printf("      请输入规范的价格(必须为6位数字以内)~!\n\n"); mid();
			printf("      ");
			system("pause");
			rewrite('6');
		}
	}
}
