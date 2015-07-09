
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
		printf("\t\t|                       主菜单                         |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                       1.录入                         |\n");
		printf("\t\t|                       2.显示                         |\n");
		printf("\t\t|                       3.查找                         |\n");
		printf("\t\t|                       4.修改                         |\n");
		printf("\t\t|                       5.删除                         |\n");
		printf("\t\t|                       6.排序                         |\n");
		printf("\t\t|                       7.统计                         |\n");
		printf("\t\t|                       8.保存信息                     |\n");
		printf("\t\t|                       9.文件提取                     |\n");
		printf("\t\t|                       0.退出                         |\n");
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
    printf("\t\t|                          统计                        |\n");
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
		if(strcmp(p->sex,"男")==0)
		{
			i++;
		}
		else
			j++;
		p=p->next;
	}
	gotoxy(18,5);
	printf("男生%d人  女生%d人",i,j);
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
			printf("%s班%d人",temp[m],n);
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
				printf("陕西%d人",n);
			if(m==7)
				printf("河北%d人",n);
			x+=10;
		}
		m++;
	}
	getch();
}
void login()//学生登录
{
	int choice=1,i=18,j=7;
	char p;
	while(choice!=0)
	{
		system("cls");
		p=1;
	printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                学生信息管理系统登录                  |\n");
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|   管理员登录                                         |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|   退出                                               |\n");
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
    printf("\t\t|                      管理员登录                      |\n");
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|    管理员密码：                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t|                                                      |\n");
	printf("\t\t--------------------------------------------------------\n");
	printf("\t\t|         登    录        修改密码        退    出     |\n");
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
				printf("  登录成功");
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
				printf("密码错误！");
			    Sleep(1000);
			}
			break;
		case 2:
			if(judge(pwd,pwd_root)==1)
			{
			system("cls");
			printf("\n\n\t\t--------------------------------------------------------\n");
			printf("\t\t|                      修改密码                      |\n");
			printf("\t\t--------------------------------------------------------\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|                                                      |\n");
			printf("\t\t|    输入新密码：                                      |\n");
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
			printf("请确认修改密码！");
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
int judge(char *p,char *q)//判断两个字符串是否相等
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
void read()//从文件读出
{

    char f;
    struct info *p,*q=head;
    printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                        文件提取                      |\n");
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
    printf("\t      确定要从文件提取信息吗？");
	gotoxy(18,17);
	printf("确定:Enter 放弃:Esc");
    f=getch();
	if(f==27)
		return;
    if(f==13)
	{
		fp=fopen("e:\\stu.txt","rt");
		if(fp==NULL)
		{
			gotoxy(18,17);
			printf("打开文件失败！按任意键返回！");
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
			printf("提取成功按任意键返回主菜单！                        ");
			getch();
		}
		fclose(fp);
	}
	return;
}
void write()//写入文件
{

	char f;
	struct info *p=head->next;
    printf("\n\n\t\t--------------------------------------------------------\n");
    printf("\t\t|                        写入文件                      |\n");
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
	printf("\t      确定要写入文件吗？");
	gotoxy(18,17);
	printf("确定:Enter 放弃:Esc");
	f=getch();
	if(f==27)
		return;
	if(f==13)
	{
		fp=fopen("e:\\stu.txt","w");
		if(fp==NULL)
		{
			gotoxy(18,17);
			printf("打开文件失败！");
			return;
		}
	else
	{
		if(feof(fp)==1)
		{
			gotoxy(18,17);
			printf("文件为空！");
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
		printf("写入成功!按任意键返回主菜单！                        ");
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
		printf("\t\t|                        排序                          |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|    1.按姓氏排序                                      |\n");
		printf("\t\t|    2.按学号排序                                      |\n");
		printf("\t\t|    3.按班级排序                                      |\n");
		printf("\t\t|    0.返回主菜单                                      |\n");
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
		printf("确定:Enter 放弃:Esc");
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
void Delete()//删除功能
{
	char temp[10],f[10];
	int count=0;
	struct info *p=head,*q;
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                        删除                          |\n");
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
	printf("输入要删除的姓名或学号:");
    scanf("%s",temp);
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		if(strcmp(temp,p->name)==0||strcmp(temp,p->id)==0)
		{
			    gotoxy(18,6);
				printf("学号\t姓名\t性别\t班级\t住址\t电话");
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
		printf("没有该信息！按任意键返回主菜单！");
		getch();
	    return;
	}
	else
	{
		gotoxy(18,17);
		printf("请确认删除（输入“删除”确认）:");
		scanf("%s",f);
		if(strcmp(f,"删除")==0)
		{
			_count--;
			q->next=p->next;
			free(p);
		}
		gotoxy(18,17);
		printf("删除成功！按任意键返回主菜单！     ");
		getch();
	    return;
	}

}
void edit()//修改功能
{
	char temp[10];
	char name[10];
	char id[12],ad[20],clas[7],tel[11],sex[5];
	char f;
	int count=0;
	struct info *p=head->next,*q;
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                        修改                          |\n");
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
	printf("输入要修改的姓名或学号:");
    scanf("%s",temp);
	while(p!=NULL)
	{
		if(strcmp(temp,p->name)==0||strcmp(temp,p->id)==0)
		{
			gotoxy(18,7);
			printf("学号\t姓名\t性别\t班级\t住址\t电话");
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
			printf("没有该信息！按任意键返回！");
			getch();
		    return;
		}
		else
		{
			gotoxy(18,9);
			printf("输入修改后的学生学号:");
			scanf("%s",id);
			gotoxy(18,10);
			printf("输入修改后的学生姓名:");
			scanf("%s",name);
			gotoxy(18,11);
			printf("输入修改后的学生性别:");
			scanf("%s",sex);
			gotoxy(18,12);
			printf("输入修改后的学生班级:");
			scanf("%s",clas);
			gotoxy(18,13);
			printf("输入修改后的学生住址:");
			scanf("%s",ad);
			gotoxy(18,14);
			printf("输入修改后的学生电话:");
			scanf("%s",tel);

			gotoxy(18,17);
			printf("请确认修改：");
			gotoxy(18,17);
		    printf("确定:Enter 放弃:Esc");
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
				printf("修改成功！按任意键返回！\n");
				getch();
		        return;
			}
			else if(f==27)
				return;
		}	
}
void search_menu()//查找功能菜单
{
	int choice=1,i=19,j=5;
	char p;
	while(choice!=0)
	{
		p=1;
		system("cls");
		printf("\n\n\t\t--------------------------------------------------------\n");
		printf("\t\t|                        查找                          |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|    1.按学号查找                                      |\n");
		printf("\t\t|    2.按姓名查找                                      |\n");
		printf("\t\t|    3.按住址查找                                      |\n");
		printf("\t\t|    4.按班级查找                                      |\n");
		printf("\t\t|    5.按电话查找                                      |\n");
		printf("\t\t|    0.返回主菜单                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t--------------------------------------------------------\n");
		printf("\t\t|                                                      |\n");
		printf("\t\t--------------------------------------------------------\n");
		gotoxy(18,17);
		printf("确定:Enter 放弃:Esc");
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

void search_(int j)//按姓名查找
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
		printf("当前没有数据！按任意键返回！\n");
	}
	else
	{
		gotoxy(18,5);
		if(j==1)
		printf("输入学号:");
		if(j==2)
		printf("输入姓名:");
		if(j==3)
		printf("输入住址:");
		if(j==4)
		printf("输入班级:");
		if(j==5)
		printf("输入电话:");
	    scanf("%s",temp);

		gotoxy(18,7);
		printf("学号\t姓名\t性别\t班级\t住址\t电话");
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
	    printf("查找到的数据 %d个,按任意键返回！",count);
	}
	getch();
	return;
}

void input()//输入功能
{
	char name[10],id[12],sex[5],ad[20],tel[11],clas[7],f;
	struct info *p,*q;
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                    录入学生信息                      |\n");
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
	printf("姓名:");
	scanf("%s",name);
	gotoxy(18,6);
	printf("学号:");
	scanf("%s",id);
	gotoxy(18,7);
	printf("班级:");
	scanf("%s",clas);
	gotoxy(18,8);
	printf("性别:");
	scanf("%s",sex);
	gotoxy(18,9);
	printf("住址:");
	scanf("%s",ad);
	gotoxy(18,10);
	printf("电话:");
	scanf("%s",tel);

	gotoxy(18,17);
	printf("请确认保存:");
	gotoxy(50,17);
	printf("确定:Enter 放弃:Esc");
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
	  printf("保存成功!按任意键返回！                             ");
	  _count++;
	  getch();
	}
	else if(f==27)
		return;

}
void output()//输出功能
{
	int i=6;
	struct info *p=head->next;
	system("cls");
	printf("\n\n\t\t--------------------------------------------------------\n");
	printf("\t\t|                        显示                          |\n");
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
		printf("当前没有数据!按任意键返回！");
	}
	else
	{
		gotoxy(18,5);
		printf("学号\t姓名\t性别\t班级\t住址\t电话");
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
		printf("显示完毕！按任意键返回！");
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