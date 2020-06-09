//ͨѶ¼����ϵͳ

/* 1�������ϵ�ˣ���ϵ������Ϊ1000����ϵ����Ϣ�������������Ա����䡢סַ����ϵ�绰����ͥסַ
*     ʵ�֣������ϵ�˽ṹ�塢���ͨѶ¼�ṹ�塢main�����д���ͨѶ¼����װ�����ϵ�˺��������������ϵ�˹���
*
* 2��ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
*     ʵ�֣���װ�����ϵ���Ƿ���ڡ���װɾ����ϵ�˺���������ɾ����ϵ�˹���
*     ɾ����ϵ��֮ǰ�����ж��û��������ϵ���Ƿ���ڣ��������ɾ������ʾɾ���ɹ���������ϵ����ͨѶ¼�����е�λ�ã�
* ��������ʾ�û�û��Ҫɾ������ϵ�ˣ�����-1
*
* 3��������ϵ�ˣ���װ������ϵ�˺��������Բ���ָ����ϵ��
*    ������ϵ�˺������ж��û�ָ������ϵ���Ƿ���ڣ���������ʾ��Ϣ����������ʾ���޴���
*
* 4���޸���ϵ�ˣ��������������޸�ָ����ϵ��
*   ʵ�֣���װ�޸���ϵ�˺����������޸���ϵ�˺���
*   �����û��������ϵ�ˣ��ɹ�������޸ģ�����ʧ����ʾ���޴���
*/

#include<iostream>//���������׼ͷ�ļ�
#include<string>
using namespace std;//ʹ�������ռ�

#define MAX 100
//��ϵ����Ϣ�ṹ��
struct Person
{
	string m_Name;
	int m_Sex;  //1 �� 2 Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];//ͨѶ¼�б������ϵ�����飬����������ϵ�˵�����
	int m_Size;//ͨѶ¼�е���Ա����
};


//��ʾ�˵�����
void showmenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

//�����ϵ��
void addperson(Addressbooks* abs)
{
	//ͨѶ¼�Ƿ��������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else  //ͨѶ¼δ��
	{
		//��Ӿ�����ϵ��
		//�������
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;//�ڼ�����ϵ�˵�����

		//����Ա�
		int sex=0;
		cout << "��ѡ���Ա�:" << endl;
		cout << "1 ---- ��" << endl;//��ʾ
		cout << "2 ---- Ů" << endl;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;//�˳�ѭ��
			}
			cout << "������������������" << endl;
		}

		//�������
		cout << "����������:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		
		//��ӵ绰
		cout << "��������ϵ�绰:" << endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ӵ�ַ
		cout << "�������ַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");//��������
	}
}

//��ʾ���е���ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ��
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1 ? "��":"Ů") << "\t";//������Ŀ�������1�����У�2����Ů
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;//����
		}
	}

	system("pause");//�����������
	system("cls");//����
}

//�����ϵ���Ƿ���ڣ����ڷ�����ϵ�����������е�λ�ã������ڷ���-1
//����1:ͨѶ¼  ����2���Ա�����
int isExist(Addressbooks* abs,string name)
{    //����ͨѶ¼��
	for (int i = 0; i < abs->m_Size; i++)
	{   //ͨѶ¼�д��ڸ�����
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�����������е��±���
		}
	}
	return -1;
}

//ɾ��ָ������ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);//ret=-1,δ�鵽����
	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ���������������������һ��ǰ�ƣ�����ͨѶ¼�м�¼����Ա����һ
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼����Ա����
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//����ָ������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}


//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);

	if (ret != -1)//����
	{  
		//�޸�����
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		
		//�޸��Ա�
		int sex = 0;
		cout << "��ѡ���Ա�:" << endl;
		cout << "1 ---- ��" << endl;//��ʾ
		cout << "2 ---- Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;//�˳�ѭ��
			}
			cout << "������������������" << endl;
		}
		
		//�޸�����
		cout << "����������:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}


		//�޸ĵ绰
		cout << "��������ϵ�绰:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//�޸ĵ�ַ
		cout << "�������ַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	
		cout << "�޸ĳɹ�" << endl;
	}
	else //������
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//���ͨѶ¼
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//��ǰͨѶ¼�м�¼����Ϊ0
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");
}


int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;//�����û�ѡ������ı���

	while (true)
	{
		//���ò˵�
		showmenu();
		cin >> select; //����ѡ��

		switch (select)
		{
		case 1:  //1�������ϵ�� 
			addperson(&abs);//���õ�ַ���ݣ���������ʵ��
			break;
		case 2:  //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  // 3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:  //4��������ϵ��
			findPerson(&abs);
			break;
		case 5:  //5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //6�������ϵ�� 
			cleanPerson(&abs);
			break;
		case 0:// 0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");//�밴���������.
			return 0;//�˳�ϵͳ
			break;
		}
	}
	
	
	system("pause");
	return 0;
}

