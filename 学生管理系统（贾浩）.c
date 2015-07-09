
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<windows.h>
#include<time.h>

int _count=0;
FILE *fp,*fp2;
char pwd_root[6]="135856";

void input();
void output();
void search_menu();
void search_(int j);
void edit();
void Delete();
void write();
void read();
void gotoxy(int x,int y);
void login();
unsigned int __stdcall Time(PVOID pM);
void login_root();
int judge(char *p,char *q);
void menu();
void reorder_menu();
void reorder_name(int i);
void count();

struct info
{
	char name[10];
	char id[12];
	char sex[5];
	char clas[7];
	char ad[20];
	char tel[11];
	struct info *next;
} *head;



void main(void)
{ 
	
	HANDLE handle;
	fp2=fopen("e:\\pwd.txt","wt+");
	fscanf(fp2,"%s",pwd_root);
	fclose(fp2);
	head=(struct info *)malloc(sizeof(struct info));
    head->next=NULL;
	//handle = (HANDLE)_beginthreadex(NULL, 0, Time, NULL, 0, NULL);
	login();
	gotoxy(0,0);
	menu();
}
void menu()
{
	int choice=1,i=38,j=6;
	char p;
	while(choice!=0)
	{
		p=1;
		system("cls");
		printf("\n\n\t\t--------------------------------------------------------\n");
		printf("\t\t|                       ���˵�                         |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                       1.¼��                         |\n");
		printf("\t\t|                       2.��ʾ                         |\n");
		printf("\t\t|                       3.����                         |\n");
		printf("\t\t|                       4.�޸�                         |\n");
		printf("\t\t|                       5.ɾ��                         |\n");
		printf("\t\t|                       6.����                         |\n");
		printf("\t\t|                       7.ͳ��                         |\n");
		printf("\t\t|                       8.������Ϣ                     |\n");
		printf("\t\t|                       9.�ļ���ȡ                     |\n");
		printf("\t\t|                       0.�˳�                         |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t--------------------------------------------------------\n");
		while(p!=13)
		{
			gotoxy(i,j);
			printf(">>");
			p=getch();
			if(p==72&&j>6)
			{
				gotoxy(i,j);
				printf("  ");
				j--;
				choice--;
			}
			if(p==80&&j<=14)
			{
				gotoxy(i,j);
				printf("  ");
				j++;
				choice++;
			}
			if(j==15&&p==13)
				choice=0;
			if(p==27)
				login();
		}

	switch(choice)
	{
	case 1:
		system("cls");
		input();
		break;
	case 2:
		system("cls");
		output();
		break;
	case 3:
		system("cls");
		search_menu();
		break;
	case 4:
		system("cls");
		edit();
		break;
	case 5:
		system("cls");
		Delete();
		break;
	case 6:
		system("cls");
		reorder_menu();
		break;
	case 7:
		system("cls");
		count();
		break;
	case 8:
		system("cls");
		write();
		break;
	case 9:
		system("cls");
		read();
		break;
	case 0:
		gotoxy(18,17);
		login();
	}
	}


}
void count()
{
	struct info *p;
	int i=0,j=0,m=0,n=0;
	int x=18,y=6;
	char temp[][20]={"1401","1402","1403","1404","1405","1406","shan","ji"};
	p=head->next;
	printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                          ͳ��                        |\n");
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	while(p!=NULL)
	{
		if(strcmp(p->sex,"��")==0)
		{
			i++;
		}
		else
			j++;
		p=p->next;
	}
	gotoxy(18,5);
	printf("����%d��  Ů��%d��",i,j);
	while(m<6)
	{
		p=head->next;
		n=0;
		while(p!=NULL)
		{
			if(strcmp(p->clas,temp[m])==0)
			{
				n++;
			}
			p=p->next;
		}
		if(n!=0)
		{
			gotoxy(x,y);
			printf("%s��%d��",temp[m],n);
			x+=10;
		}
		m++;
	}
	x=18,y=7;
	while(m<8)
	{
		p=head->next;
		n=0;
		while(p!=NULL)
		{
			if(strcmp(p->ad,temp[m])==0)
			{
				n++;
			}
			p=p->next;
		}
		if(n!=0)
		{
			gotoxy(x,y);
			if(m==6)
				printf("����%d��",n);
			if(m==7)
				printf("�ӱ�%d��",n);
			x+=10;
		}
		m++;
	}
	getch();
}
void login()//ѧ����¼
{
	int choice=1,i=18,j=7;
	char p;
	while(choice!=0)
	{
		system("cls");
		p=1;
	printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                ѧ����Ϣ����ϵͳ��¼                  |\n");
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|   ����Ա��¼                                         |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|   �˳�                                               |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	while(p!=13)
	{
		gotoxy(i,j);
		printf("->");
		p=getch();
		if(p==72&&j>7)
		{
			gotoxy(i,j);
			printf("  ");
			j-=2;
			choice--;
		}
		if(p==80&&j<=7)
		{
			gotoxy(i,j);
			printf("  ");
			j+=2;
			choice++;
		}
		if(p==27)
		{
			gotoxy(18,17);
			exit(0);
		}
	}
	switch(choice)
	{
		case 1:
			login_root();
			break;
		case 2:
			gotoxy(18,20);
			exit(0);

	}
	}
}
void login_root()
{
	int choice=1,i=24,j=17;
	int m=0,n=0;
	char temp[6],y;
	char p,pwd[6],f='a';
	while(choice!=2)
	{
		system("cls");
		p=1;
	printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                      ����Ա��¼                      |\n");
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|    ����Ա���룺                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|         ��    ¼        �޸�����        ��    ��     |\n");
	printf("\t\t--------------------------------------------------------\n");
		gotoxy(33,9);
		for(m=0;m<6;)
		{
			f=getch();
			if((f>='0'&&f<='9')||(f>='A'&&f<='Z')||(f>='a'&&f<='z'))
			{
				pwd[m]=f;
				printf("*");
				m++;
			}
			if(f==13)
				break;
			if(f==27)
				return;
		}

	while(p!=13)
	{
		gotoxy(i,j);
		printf("->");
		p=getch();
		if(p==75&&i>24)
		{
			gotoxy(i,j);
			printf("  ");
			i-=16;
			choice--;
		}
		if(p==77&&i<=50)
		{
			gotoxy(i,j);
			printf("  ");
			i+=16;
			choice++;
		}
		if(p==27)
			return;
	}
	switch(choice)
	{
		case 1:
			if(judge(pwd,pwd_root)==1)
			{
				gotoxy(18,17);
				printf("  ��¼�ɹ�");
				gotoxy(30,17);
				printf("                                    ");
				gotoxy(30,17);
				while(n<3)
				{
					printf(".");
					n++;
					Sleep(500);
				}
				menu();
			}
			else
			{
				printf("                                            ");
				gotoxy(18,17);
				printf("�������");
			    Sleep(1000);
			}
			break;
		case 2:
			if(judge(pwd,pwd_root)==1)
			{
			system("cls");
			printf("\n\n\t\t--------------------------------------------------------\n");
			printf("\t\t|                      �޸�����                      |\n");
			printf("\t\t--------------------------------------------------------\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|    ���������룺                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t--------------------------------------------------------\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t--------------------------------------------------------\n");
			gotoxy(30,9);
			scanf("%s",temp);
			gotoxy(18,17);
			printf("��ȷ���޸����룡");
			y=getch();
			if(y==13)
			{
				fp2=fopen("e:\\pwd.txt","wt");
				strcpy(pwd_root,temp);
				fprintf(fp2,"%s",temp);
				fclose(fp2);
				return;
			}
			if(y==27)
				return;
			}
			else
				return;
		case 3:
			return;
	}
	}
	
}
int judge(char *p,char *q)//�ж������ַ����Ƿ����
{
	int i,f;
	for(i=0;i<6;i++)
	{
		if(p[i]==q[i])
		{
			f=1;
			continue;
		}
		else
		{
			f=0;
			break;
		}
	}
	return f;

}
void read()//���ļ�����
{

    char f;
    struct info *p,*q=head;
    printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                        �ļ���ȡ                      |\n");
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	gotoxy(18,9);
    printf("\t      ȷ��Ҫ���ļ���ȡ��Ϣ��");
	gotoxy(18,17);
	printf("ȷ��:Enter ����:Esc");
    f=getch();
	if(f==27)
		return;
    if(f==13)
	{
		fp=fopen("e:\\stu.txt","rt");
		if(fp==NULL)
		{
			gotoxy(18,17);
			printf("���ļ�ʧ�ܣ�����������أ�");
			getch();
			return;
		}
		else
		{
			while(!feof(fp))
			{
				p=(struct info *)malloc(sizeof(struct info));
				fscanf(fp,"%s %s %s %s %s %s\n",p->ad,p->clas,p->sex,p->tel,p->name,p->id);
				q->next=p;
				q=p;
			}
			q->next=NULL;
			gotoxy(18,17);
			printf("��ȡ�ɹ���������������˵���                        ");
			getch();
		}
		fclose(fp);
	}
	return;
}
void write()//д���ļ�
{

	char f;
	struct info *p=head->next;
    printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                        д���ļ�                      |\n");
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	gotoxy(18,9);
	printf("\t      ȷ��Ҫд���ļ���");
	gotoxy(18,17);
	printf("ȷ��:Enter ����:Esc");
	f=getch();
	if(f==27)
		return;
	if(f==13)
	{
		fp=fopen("e:\\stu.txt","w");
		if(fp==NULL)
		{
			gotoxy(18,17);
			printf("���ļ�ʧ�ܣ�");
			return;
		}
	else
	{
		if(feof(fp)==1)
		{
			gotoxy(18,17);
			printf("�ļ�Ϊ�գ�");
			flushall();
			getch();

		}
		else
		{
		while(p!=NULL)
		{
			fprintf(fp,"%s %s %s %s %s %s\n",p->ad,p->clas,p->sex,p->tel,p->name,p->id);
			p=p->next;
		}
		gotoxy(18,17);
		printf("д��ɹ�!��������������˵���                        ");
		flushall();
		getch();
		}
	}
		fclose(fp);
  }
  return;
}
void reorder_menu()
{
	int choice=1,i=19,j=5;
	char p;
	while(choice!=0)
	{
		p=1;
		system("cls");
		printf("\n\n\t\t--------------------------------------------------------\n");
		printf("\t\t|                        ����                          |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|    1.����������                                      |\n");
		printf("\t\t|    2.��ѧ������                                      |\n");
		printf("\t\t|    3.���༶����                                      |\n");
		printf("\t\t|    0.�������˵�                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t--------------------------------------------------------\n");
		gotoxy(18,17);
		printf("ȷ��:Enter ����:Esc");
		while(p!=13)
		{
			gotoxy(i,j);
			printf(">>");
			p=getch();
			if(p==72&&j>5)
			{
				gotoxy(i,j);
				printf("  ");
				j--;
				choice--;
			}
			if(p==80&&j<=7)
			{
				gotoxy(i,j);
				printf("  ");
				j++;
				choice++;
			}
			if(j==8&&p==13)
				choice=0;
			if(p==27)
				return;
		}
		switch(choice)
		{
		case 1:
			reorder_name(1);
			break;
		case 2:
			reorder_name(2);
			break;
        case 3:
			reorder_name(3);
			break;
		case 0:
			gotoxy(18,15);
			return;
		}
	}
}
void reorder_name(int i)
{
	struct info *p,*q;
	char name[10],id[12],sex[5],ad[20],clas[7],tel[11];
	for(p=head->next;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(i==1)
			if(strcmp(p->name,q->name)>0)
			{
				strcpy(id,q->id);
				strcpy(q->id,p->id);
				strcpy(p->id,id);

				strcpy(name,q->name);
				strcpy(q->name,p->name);
				strcpy(p->name,name);

				strcpy(ad,q->ad);
				strcpy(q->ad,p->ad);
				strcpy(p->ad,ad);

				strcpy(tel,q->tel);
				strcpy(q->tel,p->tel);
				strcpy(p->tel,tel);

				strcpy(clas,q->clas);
				strcpy(q->clas,p->clas);
				strcpy(p->clas,clas);

				strcpy(sex,q->sex);
				strcpy(q->sex,p->sex);
				strcpy(p->sex,sex);

			}
			if(i==2)
				if(strcmp(p->id,q->id)>0)
			{
				strcpy(id,q->id);
				strcpy(q->id,p->id);
				strcpy(p->id,id);

				strcpy(name,q->name);
				strcpy(q->name,p->name);
				strcpy(p->name,name);

				strcpy(ad,q->ad);
				strcpy(q->ad,p->ad);
				strcpy(p->ad,ad);

				strcpy(tel,q->tel);
				strcpy(q->tel,p->tel);
				strcpy(p->tel,tel);

				strcpy(clas,q->clas);
				strcpy(q->clas,p->clas);
				strcpy(p->clas,clas);

				strcpy(sex,q->sex);
				strcpy(q->sex,p->sex);
				strcpy(p->sex,sex);

			}
			if(i==3)
				if(strcmp(p->clas,q->clas)>0)
			{
				strcpy(id,q->id);
				strcpy(q->id,p->id);
				strcpy(p->id,id);

				strcpy(name,q->name);
				strcpy(q->name,p->name);
				strcpy(p->name,name);

				strcpy(ad,q->ad);
				strcpy(q->ad,p->ad);
				strcpy(p->ad,ad);

				strcpy(tel,q->tel);
				strcpy(q->tel,p->tel);
				strcpy(p->tel,tel);

				strcpy(clas,q->clas);
				strcpy(q->clas,p->clas);
				strcpy(p->clas,clas);

				strcpy(sex,q->sex);
				strcpy(q->sex,p->sex);
				strcpy(p->sex,sex);

			}
		}

	}
	output();
}
void Delete()//ɾ������
{
	char temp[10],f[10];
	int count=0;
	struct info *p=head,*q;
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                        ɾ��                          |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	gotoxy(18,5);
	printf("����Ҫɾ����������ѧ��:");
    scanf("%s",temp);
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		if(strcmp(temp,p->name)==0||strcmp(temp,p->id)==0)
		{
			    gotoxy(18,6);
				printf("ѧ��\t����\t�Ա�\t�༶\tסַ\t�绰");
				gotoxy(18,7);
				printf("%s\t",p->id);
				printf("%s\t",p->name);
				printf("%s\t",p->sex);
				printf("%s\t",p->clas);
				printf("%s\t",p->ad);
				printf("%s\n",p->tel);
				count++;
				break;
		}
		
	}
	if(head->next==NULL||count==0)
	{
		gotoxy(18,17);
		printf("û�и���Ϣ����������������˵���");
		getch();
	    return;
	}
	else
	{
		gotoxy(18,17);
		printf("��ȷ��ɾ�������롰ɾ����ȷ�ϣ�:");
		scanf("%s",f);
		if(strcmp(f,"ɾ��")==0)
		{
			_count--;
			q->next=p->next;
			free(p);
		}
		gotoxy(18,17);
		printf("ɾ���ɹ�����������������˵���     ");
		getch();
	    return;
	}

}
void edit()//�޸Ĺ���
{
	char temp[10];
	char name[10];
	char id[12],ad[20],clas[7],tel[11],sex[5];
	char f;
	int count=0;
	struct info *p=head->next,*q;
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                        �޸�                          |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	gotoxy(18,5);
	printf("����Ҫ�޸ĵ�������ѧ��:");
    scanf("%s",temp);
	while(p!=NULL)
	{
		if(strcmp(temp,p->name)==0||strcmp(temp,p->id)==0)
		{
			gotoxy(18,7);
			printf("ѧ��\t����\t�Ա�\t�༶\tסַ\t�绰");
			gotoxy(18,8);
			printf("%s\t",p->id);
			printf("%s\t",p->name);
			printf("%s\t",p->sex);
			printf("%s\t",p->clas);
			printf("%s\t",p->ad);
			printf("%s\n",p->tel);
			q=p;
			count++;
		}
		p=p->next;
	}
		if(count==0)
		{
			gotoxy(18,17);
			printf("û�и���Ϣ������������أ�");
			getch();
		    return;
		}
		else
		{
			gotoxy(18,9);
			printf("�����޸ĺ��ѧ��ѧ��:");
			scanf("%s",id);
			gotoxy(18,10);
			printf("�����޸ĺ��ѧ������:");
			scanf("%s",name);
			gotoxy(18,11);
			printf("�����޸ĺ��ѧ���Ա�:");
			scanf("%s",sex);
			gotoxy(18,12);
			printf("�����޸ĺ��ѧ���༶:");
			scanf("%s",clas);
			gotoxy(18,13);
			printf("�����޸ĺ��ѧ��סַ:");
			scanf("%s",ad);
			gotoxy(18,14);
			printf("�����޸ĺ��ѧ���绰:");
			scanf("%s",tel);

			gotoxy(18,17);
			printf("��ȷ���޸ģ�");
			gotoxy(18,17);
		    printf("ȷ��:Enter ����:Esc");
			f=getch();
			if(f==13)
			{
				strcpy(q->name,name);
				strcpy(q->id,id);
				strcpy(q->sex,sex);
				strcpy(q->clas,clas);
				strcpy(q->ad,ad);
				strcpy(q->tel,tel);

				gotoxy(18,17);
				printf("�޸ĳɹ�������������أ�\n");
				getch();
		        return;
			}
			else if(f==27)
				return;
		}	
}
void search_menu()//���ҹ��ܲ˵�
{
	int choice=1,i=19,j=5;
	char p;
	while(choice!=0)
	{
		p=1;
		system("cls");
		printf("\n\n\t\t--------------------------------------------------------\n");
		printf("\t\t|                        ����                          |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|    1.��ѧ�Ų���                                      |\n");
		printf("\t\t|    2.����������                                      |\n");
		printf("\t\t|    3.��סַ����                                      |\n");
		printf("\t\t|    4.���༶����                                      |\n");
		printf("\t\t|    5.���绰����                                      |\n");
		printf("\t\t|    0.�������˵�                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t--------------------------------------------------------\n");
		gotoxy(18,17);
		printf("ȷ��:Enter ����:Esc");
		gotoxy(i,j);
		while(p!=13)
		{
			gotoxy(i,j);
			printf(">>");
			p=getch();
			if(p==72&&j>5)
			{
				gotoxy(i,j);
				printf("  ");
				j--;
				choice--;
			}
			if(p==80&&j<=9)
			{
				gotoxy(i,j);
				printf("  ");
				j++;
				choice++;
			}
			if(j==10&&p==13)
				choice=0;
			if(p==27)
				return;
		}
		switch(choice)
		{
		case 1:
			search_(1);
			break;
		case 2:
			search_(2);
			break;
		case 3:
			search_(3);
			break;
		case 4:
			search_(4);
			break;
		case 5:
			search_(5);
			break;
		case 0:
			gotoxy(18,15);
			return;
		}
		}
}

void search_(int j)//����������
{
	char temp[20];
	int count=0,i=8;
	struct info *p=head->next;
	gotoxy(18,5);
	printf("               ");
	gotoxy(18,6);
	printf("               ");
	gotoxy(18,7);
	printf("               ");
	gotoxy(18,8);
	printf("               ");
	gotoxy(18,9);
	printf("               ");
	gotoxy(18,10);
	printf("               ");
	if(head->next==NULL)
	{
		gotoxy(18,17);
		printf("��ǰû�����ݣ�����������أ�\n");
	}
	else
	{
		gotoxy(18,5);
		if(j==1)
		printf("����ѧ��:");
		if(j==2)
		printf("��������:");
		if(j==3)
		printf("����סַ:");
		if(j==4)
		printf("����༶:");
		if(j==5)
		printf("����绰:");
	    scanf("%s",temp);

		gotoxy(18,7);
		printf("ѧ��\t����\t�Ա�\t�༶\tסַ\t�绰");
	    while(p!=NULL)
		{
		   if(j==1)
		   if(strcmp(temp,p->id)==0)
		   {
			   gotoxy(18,i);
			   printf("%s\t",p->id);
				printf("%s\t",p->name);
				printf("%s\t",p->sex);
				printf("%s\t",p->clas);
				printf("%s\t",p->ad);
				printf("%s\n",p->tel);
			   count++;
			   i++;
		   }
		   if(j==2)
		   if(strcmp(temp,p->name)==0)
		   {
			   gotoxy(18,i);
			   printf("%s\t",p->id);
				printf("%s\t",p->name);
				printf("%s\t",p->sex);
				printf("%s\t",p->clas);
				printf("%s\t",p->ad);
				printf("%s\n",p->tel);
			   count++;
			   i++;
		   }
		   if(j==3)
		   if(strcmp(temp,p->ad)==0)
		   {
			   gotoxy(18,i);
			   printf("%s\t",p->id);
				printf("%s\t",p->name);
				printf("%s\t",p->sex);
				printf("%s\t",p->clas);
				printf("%s\t",p->ad);
				printf("%s\n",p->tel);
			   count++;
			   i++;
		   }
		   if(j==4)
		   if(strcmp(temp,p->clas)==0)
		   {
			   gotoxy(18,i);
			   printf("%s\t",p->id);
				printf("%s\t",p->name);
				printf("%s\t",p->sex);
				printf("%s\t",p->clas);
				printf("%s\t",p->ad);
				printf("%s\n",p->tel);
			   count++;
			   i++;
		   }
		   if(j==5)
		   if(strcmp(temp,p->tel)==0)
		   {
			   gotoxy(18,i);
			   printf("%s\t",p->id);
				printf("%s\t",p->name);
				printf("%s\t",p->sex);
				printf("%s\t",p->clas);
				printf("%s\t",p->ad);
				printf("%s\n",p->tel);
			   count++;
			   i++;
		   }
		 p=p->next;

		}
		gotoxy(18,17);
	    printf("���ҵ������� %d��,����������أ�",count);
	}
	getch();
	return;
}

void input()//���빦��
{
	char name[10],id[12],sex[5],ad[20],tel[11],clas[7],f;
	struct info *p,*q;
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                    ¼��ѧ����Ϣ                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	gotoxy(18,5);
	printf("����:");
	scanf("%s",name);
	gotoxy(18,6);
	printf("ѧ��:");
	scanf("%s",id);
	gotoxy(18,7);
	printf("�༶:");
	scanf("%s",clas);
	gotoxy(18,8);
	printf("�Ա�:");
	scanf("%s",sex);
	gotoxy(18,9);
	printf("סַ:");
	scanf("%s",ad);
	gotoxy(18,10);
	printf("�绰:");
	scanf("%s",tel);

	gotoxy(18,17);
	printf("��ȷ�ϱ���:");
	gotoxy(50,17);
	printf("ȷ��:Enter ����:Esc");
	f=getch();
	if(f==13)
	{
	  p=(struct info *)malloc(sizeof(struct info));
	  strcpy(p->name,name);
	  strcpy(p->id,id);
	  strcpy(p->sex,sex);
	  strcpy(p->clas,clas);
		strcpy(p->ad,ad);
		strcpy(p->tel,tel);
	  q=head;
	  p->next=q->next;
	  q->next=p;
      gotoxy(18,17);
	  printf("����ɹ�!����������أ�                             ");
	  _count++;
	  getch();
	}
	else if(f==27)
		return;

}
void output()//�������
{
	int i=6;
	struct info *p=head->next;
	system("cls");
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                        ��ʾ                          |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	gotoxy(18,5);
	if(head->next==NULL)
	{ 
		gotoxy(18,17);
		printf("��ǰû������!����������أ�");
	}
	else
	{
		gotoxy(18,5);
		printf("ѧ��\t����\t�Ա�\t�༶\tסַ\t�绰");
		while(p!=NULL)
		{
			gotoxy(18,i);
			printf("%s\t",p->id);
				printf("%s\t",p->name);
				printf("%s\t",p->sex);
				printf("%s\t",p->clas);
				printf("%s\t",p->ad);
				printf("%s\n",p->tel);
			p=p->next;
			i++;
		}
		gotoxy(18,17);
		printf("��ʾ��ϣ�����������أ�");
	}
	getch();
	return;
}
void gotoxy(int x,int y)
{
	int xx=0x0b;
	HANDLE hOutput;
	COORD loc;
	loc.X=x;
	loc.Y=y;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,loc);
	return;
}
/*unsigned int __stdcall Time(PVOID pM)  
{ 
	int i=0;
	time_t t;
	while(1)
	{
		time(&t);
		gotoxy(30,1);
		printf("%s",ctime(&t));
		Sleep(1000);
		i++;
	}
    return 0;  
} */