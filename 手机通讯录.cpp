#include<stdio.h>   
#include<stdlib.h> 
#include<string.h>
typedef struct
{
	char score[10];               /*���*/
	char name[10];            /*����*/
	char num[15];             /*����*/
	char email[20];           /*����*/
}Person;
Person pe[300];
int menu_select()
{
	char c;
	do{
		system("cls");
		printf("\t                     ��ӭʹ���ֻ�ͨѶ¼                   \t \n");
		printf("\t                     ------------------                   \t\n");
		printf("\t                    *  1. ��Ӽ�¼          \t\n");
		printf("\t                    *  2. ��ʾ��¼          \t\n");
		printf("\t                    *  3. ���Ź���          \t\n");
		printf("\t                    *  4. �޸ļ�¼          \t\n");
		printf("\t                    *  5. ��ѯ��¼          \t\n");
		printf("\t                    *  6. ɾ����¼          \t\n");
		printf("\t                    *  7. �����¼          \t\n");
		printf("\t                    *  0. �˳�����          \t\n");
		printf("\t                                            \t\n");
		printf("\t\t��������ѡ��Ĳ���(0-7):");
		c = getchar();
	} while (c<'0' || c>'7');
	return(c - '0');
}

int Input(Person per[], int n)                           //��Ӽ�¼���� 
{
	int i = 0;
	char sign;
	do
	{
		printf("\t���:");
		scanf("%s", per[n + i].score);
		printf("\t����:");
		scanf("%s", per[n + i].name);
		printf("\t�绰����:");
		scanf("%s", per[n + i].num);
		printf("\t��������:");
		scanf("%s", per[n + i].email);
		printf("\n\t�Ƿ�������?(Y/N)");
		scanf(" %c", &sign);
		i++;
	} while (sign != 'n'&&sign != 'N');
	return(n + i);
}
void Display(Person per[], int n)                         //��ʾ��¼���� 
{
	int i;
	printf("----------------------------------------------------------------------\n");              /*��ʽ*/
	printf("���\t����\t�绰����\t��������\n");
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
void Dial(Person per[], int n)//����
{
	int i;
	char a[20];
	printf("\n\n\t                  ���Ź���\n");
	printf("\t*****************************************************\n\n");
	if (n == 0)
	{
		printf(" ���ĵ绰���벾Ϊ��\n ");
		printf("��������������˵���");
	}
	else
	{
		printf("�����У�\n");
		for (i = 0; i < n; i++)
		{
			puts(per[i].name);
		}
		printf("��������Ҫ�������ϵ��:");
		scanf("%s", a);
		for (i = 0; i < n; i++)
		{
			if (strcmp(per[i].name, a) == 0)
			{
				printf("�����ڲ���ĵ绰����Ϊ��%s\a\n\n\n", per[i].num);
				printf("��������Ҷϣ�");
				system("pause");
				break;
			}
		}
		if (i == n)
		{
			printf("���������ϵ�˲����ڣ�\n");
			printf("�밴����������ϲ�");
		}
	}
}
void Change(Person per[], int n)                 //�޸ļ�¼����
{
	char s[20];
	int i = 0;
	printf("\t���������޸ĵļ�¼�е�����:");
	scanf("%s", s);
	while (strcmp(per[i].name, s) != 0 && i<n) i++;
	if (i == n)
	{
		printf("\tͨѶ¼��û�д���!\n");
		return;
	}
	printf("\t���:");
	scanf("%s", per[i].score);
	printf("\t����:");
	scanf("%s", per[i].name);
	printf("\t�绰����:");
	scanf("%s", per[i].num);
	printf("\t��������:");
	scanf("%s", per[i].email);
	printf("\t�޸ĳɹ���");
}
void Query_a_record(Person per[], int n)               //���Ҽ�¼����
{
	int m;
	printf("\t\n��ѡ���ѯ��ʽ:\n");
	printf("\t������������������\n");
	printf("\t��1------����   ��\n");
	printf("\t��2------�绰   ��\n");
	printf("\t��3------����   ��\n");
	printf("\t������������������\n");
	printf("��ѡ��:");
	scanf("%d", &m);
	while (m != 1 && m != 2 && m != 3)
	{
		printf("�������������ѡ��:");
		scanf("%d", &m);
	}
	if (m == 1)
	{
		char s[20];
		int i = 0;
		printf("\t���������ѯ������:");
		scanf("%s", s);
		while (strcmp(per[i].name, s) != 0 && i<n) i++;
		if (i==n)
		{
			printf("\tͨѶ¼��û�д���!\n");
			return;
		}
		printf("\t���˱��: %s\n", per[i].score);
		printf("\t�绰����: %s\n", per[i].num);
		printf("\t��������: %s\n", per[i].email);
	}
	if (m == 2)
	{
		char s[20];
		int i = 0;
		printf("\t���������ѯ�ĵ绰:");
		scanf("%s", s);
		while (strcmp(per[i].num, s) != 0 && i<n) i++;
		if (i==n)
		{
			printf("\tͨѶ¼��û�д���!\n");
			return;
		}

		printf("\t���˱��: %s\n", per[i].score);
		printf("\t��������: %s\n", per[i].name);
		printf("\t��������: %s\n", per[i].email);
	}
}
int Delete_a_record(Person per[], int n)           //ɾ����¼���� 
{
	char s[20];
	int i = 0, j;
	printf("\t��������ɾ����¼�е�����:");
	scanf("%s", s);
	while (strcmp(per[i].name, s) != 0 && i<n) i++;
	if (i==n)
	{
		printf("\tͨѶ¼��û�д���!\n");
		return(n);
	}
	for (j = i; j<n-1; j++)
	{
		strcpy(per[j].num, per[j + 1].num);
		strcpy(per[j].name, per[j + 1].name);
		strcpy(per[j].email, per[j + 1].email);
		strcpy(per[j].score, per[j + 1].score);
	}
	printf("\t\t\t�Ѿ��ɹ�ɾ��!\n");
	return(n - 1);
}
void WritetoText(Person per[], int n)                 //�洢��¼����
{
	int i = 0;
	FILE *fp;                                /*�����ļ�ָ��*/
	//char filename[20];                       /*�����ļ���*/
	//printf("\t���浽�ļ�\n");                /*�����ļ���*/
	//printf("\t��������������ļ���:");
	//scanf("%s", filename);
	if ((fp = fopen("Tongxunlu.txt", "w")) == NULL)
	{
		printf("\t�޷����ļ�\n");
		system("pause");
		return;
	}
	while (i<n)
	{
		fprintf(fp, "%-3s\t%-6s\t%-13s\t%-20s\n", per[i].score, per[i].name, per[i].num, per[i].email);
		i++;
	}
	fclose(fp);                                /*�ر��ļ�*/
	printf("����ɹ�!\n");
}
int Read(Person per[])                 //�洢��¼����
{
	int i = 0;
	FILE *fp;                                /*�����ļ�ָ��*/
	if ((fp = fopen("Tongxunlu.txt", "r")) != NULL)
	{
		while (fscanf(fp, "%s%s%s%s\n", per[i].score, per[i].name, per[i].num, per[i].email) == 4)
			i++;
		fclose(fp);                                /*�ر��ļ�*/
	}
	return i;
}
void main()                         /*������*/
{
	int n = Read(pe);
	for (;;)
	{
		switch (menu_select())
		{
		case 1:
			printf("\n\t��Ӽ�¼��ͨѶ¼\n");                /*��Ӽ�¼*/
			n = Input(pe, n);
			break;
		case 2:
			printf("\n\t\t\t ͨѶ¼��¼��\n");               /*��ʾ��¼*/
			Display(pe, n);
			break;
		case 3:
			printf("\n\t��ͨѶ¼�н��в���\n");              /*���Ź���*/
			Dial(pe, n);
			printf("\t");
			system("pause");
			break;
		case 4:
			printf("\n\t��ͨѶ¼���޸ļ�¼\n");
			Change(pe, n);                         /*�޸ļ�¼*/
			printf("\t");
			system("pause");
			break;
		case 5:
			printf("\n\t��ͨѶ¼�в��Ҽ�¼\n");
			Query_a_record(pe, n);                           /*���Ҽ�¼*/
			printf("\t");
			system("pause");
			break;
		case 6:
			printf("\n\t�޸�ͨѶ¼�еļ�¼\n");
			n = Delete_a_record(pe, n);                                  /*ɾ������*/
			printf("\t");
			system("pause");
			break;
		case 7:
			printf("\n\t���湦��\n");
			WritetoText(pe, n);                    /*��������*/
			printf("\t");
			system("pause");
			break;
		case 0:
			printf("\n\t\tллʹ�ã��ټ�!\n");              /*��������*/
			printf("\n\t\t");
			system("pause");
			exit(0);
		}
	}
}