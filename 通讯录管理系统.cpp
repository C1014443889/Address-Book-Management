//通讯录管理系统

/* 1、添加联系人：联系人上限为1000，联系人信息包括：姓名、性别、年龄、住址、联系电话、家庭住址
*     实现：设计联系人结构体、设计通讯录结构体、main函数中创建通讯录、封装添加联系人函数、测试添加联系人功能
*
* 2、删除联系人，按照姓名进行删除指定联系人
*     实现：封装检测联系人是否存在、封装删除联系人函数、测试删除联系人功能
*     删除联系人之前，先判断用户输入的联系人是否存在，如果存在删除，提示删除成功，返回联系人在通讯录数组中的位置；
* 不存在提示用户没有要删除的联系人，返回-1
*
* 3、查找联系人：封装查找联系人函数，测试查找指定联系人
*    查找联系人函数：判断用户指定的联系人是否存在，存在则显示信息，不存在提示查无此人
*
* 4、修改联系人：按照姓名重新修改指定联系人
*   实现：封装修改联系人函数、测试修改联系人函数
*   查找用户输入的联系人，成功则进行修改，查找失败提示查无此人
*/

#include<iostream>//输入输出标准头文件
#include<string>
using namespace std;//使用命名空间

#define MAX 100
//联系人信息结构体
struct Person
{
	string m_Name;
	int m_Sex;  //1 男 2 女
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];//通讯录中保存的联系人数组，保存所有联系人的数据
	int m_Size;//通讯录中的人员个数
};


//显示菜单界面
void showmenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

//添加联系人
void addperson(Addressbooks* abs)
{
	//通讯录是否满，满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else  //通讯录未满
	{
		//添加具体联系人
		//添加名字
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;//第几个联系人的名字

		//添加性别
		int sex=0;
		cout << "请选择性别:" << endl;
		cout << "1 ---- 男" << endl;//提示
		cout << "2 ---- 女" << endl;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;//退出循环
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//添加年龄
		cout << "请输入年龄:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//添加电话
		cout << "请输入联系电话:" << endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//添加地址
		cout << "请输入地址:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//显示所有的联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为空
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1 ? "男":"女") << "\t";//采用三目运算符，1返回男，2返回女
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;//换行
		}
	}

	system("pause");//按任意键继续
	system("cls");//清屏
}

//检测联系人是否存在，存在返回联系人所在数组中的位置，不存在返回-1
//参数1:通讯录  参数2：对比姓名
int isExist(Addressbooks* abs,string name)
{    //遍历通讯录中
	for (int i = 0; i < abs->m_Size; i++)
	{   //通讯录中存在该名字
		if (abs->personArray[i].m_Name == name)
		{
			return i;//返回在数组中的下标编号
		}
	}
	return -1;
}

//删除指定的联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);//ret=-1,未查到此人
	if (ret != -1)
	{
		//查找到人，要进行删除操作；将后面的数据做一个前移，并将通讯录中记录的人员数减一
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中人员个数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找指定的联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


//修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);

	if (ret != -1)//存在
	{  
		//修改姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		
		//修改性别
		int sex = 0;
		cout << "请选择性别:" << endl;
		cout << "1 ---- 男" << endl;//提示
		cout << "2 ---- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;//退出循环
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//修改年龄
		cout << "请输入年龄:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}


		//修改电话
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//修改地址
		cout << "请输入地址:" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	
		cout << "修改成功" << endl;
	}
	else //不存在
	{
		cout << "查无此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//清空通讯录
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//当前通讯录中记录人数为0
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");
}


int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;//创建用户选择输入的变量

	while (true)
	{
		//调用菜单
		showmenu();
		cin >> select; //输入选择

		switch (select)
		{
		case 1:  //1、添加联系人 
			addperson(&abs);//利用地址传递，可以修饰实参
			break;
		case 2:  //2、显示联系人
			showPerson(&abs);
			break;
		case 3:  // 3、删除联系人
			deletePerson(&abs);
			break;
		case 4:  //4、查找联系人
			findPerson(&abs);
			break;
		case 5:  //5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: //6、清空联系人 
			cleanPerson(&abs);
			break;
		case 0:// 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");//请按任意键继续.
			return 0;//退出系统
			break;
		}
	}
	
	
	system("pause");
	return 0;
}

