#include "11_28_contacts.h"

//菜单
static void meun(){
	printf("\n");
	printf("Welcome...\n");
	printf("-----------------------------------  CONTACTS  --------------------------------\n");
	printf("--           1.Add                                2.Delect                   --\n");
	printf("--           3.Search                             4.Edit                     --\n");
	printf("--           5.Show                               6.Empty                    --\n");
	printf("--           7.Sort                               8.Help                     --\n");
	printf("--           0.Exit                                                          --\n");
	printf("--           作者qq：248620932，ID:果冻，欢迎交流... =_=                     --\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("\n");
}

//添加
static void myAdd(contact_p c){
	person_t p;

	assert(c);

	printf("Please input information<name,sex,age,phone,addr>:\n");
	scanf("%s %s %d %s %s", p.name, p.sex, &p.age, p.phone, p.adds);
	addContact(c, &p);
}

//删除
static void myDel(contact_p c){
	char del_name[32];
	int n = 0;
	assert(c);

	if(isContactEmpty(c)){
		printf("Contact is empty!\n");
		return ;
	}

	printf("Please input the name whicth you want delect:");
	scanf("%s", del_name);
	printf("\nAre you sure delect: %s ?\n", del_name);
	while(1)
	{
		printf("----------------\n");
		printf("| 1.YES | 2.NO |\n");
		printf("----------------\n");

		scanf("%d", &n);
		if( 1 == n)
		{
			delContact(c, del_name);
			return ;
		}
		else if( 2 == n )
		{
			return;
		}
		else
		{
			printf("Error ！ \n");
		}
	}
	
}

//查找
static void mySearch(contact_p c)
{
	char search_name[32];
	int pos = 0;
	int i = 0;

	assert(c);

	if(isContactEmpty(c)){
		printf("Contact is empty!\n");
		return ;
	}

	printf("Please input rhe name whicth you want to search:");
	scanf("%s", search_name);
	pos = searchContact(c, search_name);
	if(-1 == pos){
		printf("Not find!\n");
	}
	else{

		printf("------------------------------------------------------------------------------\n");
		printf("| name      | sex  | age | phone           | adds                            |\n");
		printf("| %-10s| %-5s| %-4d| %-16s| %-32s|\n",c->contactList[i].name, \
		c->contactList[i].sex,c->contactList[i].age, \
		c->contactList[i].phone,c->contactList[i].adds);
		printf("------------------------------------------------------------------------------\n");
	}
}

int main()
{
	int s = -1;//选择控制变量
	contact_p myContact = NULL;//声明通讯录
	system("color 2");
	initContact(&myContact);//初始化
	while(1){ 
		meun();
		printf("Please select<0~7>:");
		fflush(stdin);
		scanf("%d", &s);
		switch(s){
		case 1:system("cls");
			myAdd(myContact);//添加联系人
			system("pause");
			break;
		case 2:system("cls");
			myDel(myContact);//删除联系人
			system("pause");
			break;
		case 3:system("cls");
			mySearch(myContact);//查找并打印联系人
			system("pause");
			break;
		case 4:system("cls");
			modContact(myContact);//修改联系人
			system("pause");
			break;
		case 5:system("cls");
			showContact(myContact);//显示联系人列表
			system("pause");
			break;
		case 6:system("cls");
			emptyContact(myContact);//清空通讯录
			system("pause");
			break;
		case 7:system("cls");
			sortContact(myContact);//排序通讯录
			system("pause");
			break;
		case 8:system("cls");
			helpContact();//帮助
			system("pause");
			break;
		case 0:system("cls");
			exitContact(myContact);//退出
			break;
		default:printf("ERROR SELECTION !!!\n");//错误选择
			system("pause");
			break;
		}
		system("cls");//清屏
	}

	return 0;
}
