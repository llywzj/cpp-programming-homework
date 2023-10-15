#include "manager.h"


//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���   ����:ѧ�š�����������
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������  ��ȡ�������ļ�����ʦ��ѧ������Ϣ
	initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;

	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ: " << vCom.size() << endl;
}

//�˵�����
void Manager::operMenu()
{

	cout << "��ӭ����Ա: " << this->m_Name << "��¼!" << endl;
	cout << "\t\t-----------------------------------------\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              1. ����˺�              |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              2. �鿴�˺�              |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              3. �鿴����              |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              4. ���ԤԼ              |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              0. ע����¼              |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t-----------------------------------------\n";
	cout << "����������ѡ��:" << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺�����:" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;   //�����ļ���
	string tip;        //��ʾid��
	string errorTip;   //�ظ�������ʾ

	ofstream ofs;      //�ļ���������

	int select = 0; 
	cin >> select;    //�����û���ѡ��

	if (select == 1)
	{
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�,����������:" ;
	}
	else
	{
		//��ӵ�����ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
		errorTip = "ְ������ظ�,����������:";
	}
	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;        //ѧ��/ְ����
	string name;   //����
	string pwd;    //����

	cout << tip << endl;
	

	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)   //���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	

	cout << "����������: " << endl;
	cin >> name;

	cout << "����������: " << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�!" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�������ӿ�,���»�ȡ�ļ��е�����
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ��: " << s.m_Id << "  ����: " << s.m_Name << "  ����: " << s.m_Pwd << endl;
}
void printTeacher(Teacher& s)
{
	cout << "ְ�����: " << s.m_EmpId << "  ����: " << s.m_Name << "  ����: " << s.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����:" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;   //�����û���ѡ��
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ����:" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ����:" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");

	return;
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ����: " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������: " << it->m_ComId << "  �����������: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");

}

//��ʼ������
void Manager::initVector()
{
	//ȷ���������״̬
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ   ѧ��/��ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "��ǰ��ѧ������Ϊ: " << vStu.size() << endl;
	ifs.close();

	//��ȡ��Ϣ   ѧ��/��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ����ʦ����Ϊ: " << vTea.size() << endl;
	ifs.close();
}

//����ظ�   ����һ:���ѧ��/ְ����  ������:�������
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
