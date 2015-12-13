#include<stdio.h>   
#include<stdlib.h> 
#include<string.h>
typedef struct
{
	char score[10];               /*编号*/
	char name[10];            /*姓名*/
	char num[15];             /*号码*/
	char email[20];           /*邮箱*/
}Person;
Person pe[300];
int menu_select()
{
	char c;
	do{
		system("cls");
		printf("\t                     欢迎使用手机通讯录                   \t \n");
		printf("\t                     ------------------                   \t\n");
		printf("\t                    *  1. 添加记录          \t\n");
		printf("\t                    *  2. 显示记录          \t\n");
		printf("\t                    *  3. 拨号功能          \t\n");
		printf("\t                    *  4. 修改记录          \t\n");
		printf("\t                    *  5. 查询记录          \t\n");
		printf("\t                    *  6. 删除记录          \t\n");
		printf("\t                    *  7. 保存记录          \t\n");
		printf("\t                    *  0. 退出程序          \t\n");
		printf("\t                                            \t\n");
		printf("\t\t请输入您选择的操作(0-7):");
		c = getchar();
	} while (c<'0' || c>'7');
	return(c - '0');
}

int Input(Person per[], int n)                           //添加记录函数 
{
	int i = 0;
	char sign;
	do
	{
		printf("\t编号:");
		scanf("%s", per[n + i].score);
		printf("\t姓名:");
		scanf("%s", per[n + i].name);
		printf("\t电话号码:");
		scanf("%s", per[n + i].num);
		printf("\t电子邮箱:");
		scanf("%s", per[n + i].email);
		printf("\n\t是否继续添加?(Y/N)");
		scanf(" %c", &sign);
		i++;
	} while (sign != 'n'&&sign != 'N');
	return(n + i);
}
void Display(Person per[], int n)                         //显示记录函数 
{
	int i;
	printf("----------------------------------------------------------------------\n");              /*格式*/
	printf("编号\t姓名\t电话号码\t电子邮箱\n");
	printf("----------------------------------------------------------------------\n");
	for (i = 0; i<n; i++)
	{
		printf("%s\t%s\t%s\t\t%s\t\n", per[i].score, per[i ].name, per[i].num, per[i].email);
		if (i % 10 ==9)
		{
			printf("\t-----------------------------------\n");
			printf("\t-----------------------------------\n");
		}
	}
	printf("   -----------------------------------------------------\n");
	system("pause");
}
void Dial(Person per[], int n)//拨号
{
	int i;
	char a[20];
	printf("\n\n\t                  拨号功能\n");
	printf("\t*****************************************************\n\n");
	if (n == 0)
	{
		printf(" 您的电话号码簿为空\n ");
		printf("按任意键返回主菜单！");
	}
	else
	{
		printf("姓名有：\n");
		for (i = 0; i < n; i++)
		{
			puts(per[i].name);
		}
		printf("请输入您要拨打的联系人:");
		scanf("%s", a);
		for (i = 0; i < n; i++)
		{
			if (strcmp(per[i].name, a) == 0)
			{
				printf("您正在拨打的电话号码为：%s\a\n\n\n", per[i].num);
				printf("按任意键挂断！");
				system("pause");
				break;
			}
		}
		if (i == n)
		{
			printf("您拨打的联系人不存在！\n");
			printf("请按任意键返回上层");
		}
	}
}
void Change(Person per[], int n)                 //修改记录函数
{
	char s[20];
	int i = 0;
	printf("\t请输入想修改的记录中的名字:");
	scanf("%s", s);
	while (strcmp(per[i].name, s) != 0 && i<n) i++;
	if (i == n)
	{
		printf("\t通讯录中没有此人!\n");
		return;
	}
	printf("\t编号:");
	scanf("%s", per[i].score);
	printf("\t姓名:");
	scanf("%s", per[i].name);
	printf("\t电话号码:");
	scanf("%s", per[i].num);
	printf("\t电子邮箱:");
	scanf("%s", per[i].email);
	printf("\t修改成功！");
}
void Query_a_record(Person per[], int n)               //查找记录函数
{
	int m;
	printf("\t\n请选择查询方式:\n");
	printf("\t┌──────—┐\n");
	printf("\t│1------姓名   │\n");
	printf("\t│2------电话   │\n");
	printf("\t│3------返回   │\n");
	printf("\t└──────—┘\n");
	printf("请选择:");
	scanf("%d", &m);
	while (m != 1 && m != 2 && m != 3)
	{
		printf("输入错误，请重新选择:");
		scanf("%d", &m);
	}
	if (m == 1)
	{
		char s[20];
		int i = 0;
		printf("\t请输入想查询的姓名:");
		scanf("%s", s);
		while (strcmp(per[i].name, s) != 0 && i<n) i++;
		if (i==n)
		{
			printf("\t通讯录中没有此人!\n");
			return;
		}
		printf("\t此人编号: %s\n", per[i].score);
		printf("\t电话号码: %s\n", per[i].num);
		printf("\t电子邮箱: %s\n", per[i].email);
	}
	if (m == 2)
	{
		char s[20];
		int i = 0;
		printf("\t请输入想查询的电话:");
		scanf("%s", s);
		while (strcmp(per[i].num, s) != 0 && i<n) i++;
		if (i==n)
		{
			printf("\t通讯录中没有此人!\n");
			return;
		}

		printf("\t此人编号: %s\n", per[i].score);
		printf("\t此人姓名: %s\n", per[i].name);
		printf("\t电子邮箱: %s\n", per[i].email);
	}
}
int Delete_a_record(Person per[], int n)           //删除记录函数 
{
	char s[20];
	int i = 0, j;
	printf("\t请输入想删除记录中的名字:");
	scanf("%s", s);
	while (strcmp(per[i].name, s) != 0 && i<n) i++;
	if (i==n)
	{
		printf("\t通讯录中没有此人!\n");
		return(n);
	}
	for (j = i; j<n-1; j++)
	{
		strcpy(per[j].num, per[j + 1].num);
		strcpy(per[j].name, per[j + 1].name);
		strcpy(per[j].email, per[j + 1].email);
		strcpy(per[j].score, per[j + 1].score);
	}
	printf("\t\t\t已经成功删除!\n");
	return(n - 1);
}
void WritetoText(Person per[], int n)                 //存储记录函数
{
	int i = 0;
	FILE *fp;                                /*定义文件指针*/
	//char filename[20];                       /*定义文件名*/
	//printf("\t保存到文件\n");                /*输入文件名*/
	//printf("\t请输入所保存的文件名:");
	//scanf("%s", filename);
	if ((fp = fopen("Tongxunlu.txt", "w")) == NULL)
	{
		printf("\t无法打开文件\n");
		system("pause");
		return;
	}
	while (i<n)
	{
		fprintf(fp, "%-3s\t%-6s\t%-13s\t%-20s\n", per[i].score, per[i].name, per[i].num, per[i].email);
		i++;
	}
	fclose(fp);                                /*关闭文件*/
	printf("保存成功!\n");
}
int Read(Person per[])                 //存储记录函数
{
	int i = 0;
	FILE *fp;                                /*定义文件指针*/
	if ((fp = fopen("Tongxunlu.txt", "r")) != NULL)
	{
		while (fscanf(fp, "%s%s%s%s\n", per[i].score, per[i].name, per[i].num, per[i].email) == 4)
			i++;
		fclose(fp);                                /*关闭文件*/
	}
	return i;
}
void main()                         /*主函数*/
{
	int n = Read(pe);
	for (;;)
	{
		switch (menu_select())
		{
		case 1:
			printf("\n\t添加记录到通讯录\n");                /*添加记录*/
			n = Input(pe, n);
			break;
		case 2:
			printf("\n\t\t\t 通讯录记录表\n");               /*显示记录*/
			Display(pe, n);
			break;
		case 3:
			printf("\n\t从通讯录中进行拨号\n");              /*拨号功能*/
			Dial(pe, n);
			printf("\t");
			system("pause");
			break;
		case 4:
			printf("\n\t从通讯录中修改记录\n");
			Change(pe, n);                         /*修改记录*/
			printf("\t");
			system("pause");
			break;
		case 5:
			printf("\n\t在通讯录中查找记录\n");
			Query_a_record(pe, n);                           /*查找记录*/
			printf("\t");
			system("pause");
			break;
		case 6:
			printf("\n\t修改通讯录中的记录\n");
			n = Delete_a_record(pe, n);                                  /*删除数据*/
			printf("\t");
			system("pause");
			break;
		case 7:
			printf("\n\t保存功能\n");
			WritetoText(pe, n);                    /*保存数据*/
			printf("\t");
			system("pause");
			break;
		case 0:
			printf("\n\t\t谢谢使用，再见!\n");              /*结束程序*/
			printf("\n\t\t");
			system("pause");
			exit(0);
		}
	}
}