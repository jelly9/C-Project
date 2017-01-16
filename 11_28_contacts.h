//条件编译
#ifndef __CONTACT_H__
#define __CONTACT_H__

//头文件列表
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

//忽略警告
#pragma warning(disable:4996)

//宏
#define INITCAP 128//初始化长度
#define INCREMENT 32//自增长度
#define FILE_NAME "contact_back"

//声明：
//联系人结构体
typedef struct person{
	char name[32];//姓名 性别 年龄 电话 地址
	char sex[8];
	unsigned char age;
	char phone[16];
	char adds[64];
}person_t, *person_p, **person_pp;

//通讯录结构体
typedef struct contact{
	int cap;//最大长度
	int size;//当前长度
	person_p contactList;//联系人列表
}contact_t, *contact_p, **contact_pp;

//函数声明
void initContact(contact_pp c);//初始化通讯录
void addContact(contact_p c, person_p p);//添加联系人
void showContact(contact_p c);//打印联系人列表
void delContact(contact_p c, char *del_name);//删除
void emptyContact(contact_p c);//清空
void destroyContact(contact_p c);//摧毁通讯录
int  searchContact(contact_p c, char *search_name);//查找
void sortContact(contact_p c);//排序
void modContact(contact_p c);//修改
void helpContact();//帮助
void exitContact(contact_p c);//退出
int  isContactEmpty(contact_p c);//判空
int fileLoad(contact_p c);//下载到项目
int fileStore(contact_p c);//储存到文件


#endif __CONTACT_H__ 
