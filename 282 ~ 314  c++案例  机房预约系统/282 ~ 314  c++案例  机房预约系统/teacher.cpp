#include "teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{
}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ: " << this->m_Name << "��¼!" << endl;
	cout << "\t\t-----------------------------------------\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|            1. �鿴����ԤԼ            |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|            2. ���ԤԼ                |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|            0. ע����¼                |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t-----------------------------------------\n";
	cout << "����������ѡ��:" << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << ".";
		cout << "ԤԼ����:  ��" << of.m_orderData[i]["date"] << "\t";
		cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "\t";
		cout << "ѧ��: " << of.m_orderData[i]["stuId"] << "\t";
		cout << "����: " << of.m_orderData[i]["stuName"] << "\t";
		cout << "�������: " << of.m_orderData[i]["roomId"] << "\t";
		string status = "״̬: ";
		//1:�����    2:��ԤԼ   -1:ԤԼʧ��   0:ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		if (of.m_orderData[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��,���δͨ��";
		}
		if (of.m_orderData[i]["status"] == "0")
		{
			status += "ȡ��ԤԼ";
		}
		cout << status << "\t" << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;  //����������
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")     
		{
			v.push_back(i);
			cout << ++index << ".";
			cout << "ԤԼ����:  ��" << of.m_orderData[i]["date"];
			cout << "   ʱ���:  " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "   �������:  " << of.m_orderData[i]["roomId"];

			string status = "  ״̬: ";
			//1:�����    2:��ԤԼ 
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}

	cout << "��������˵ļ�¼,0������" << endl;

	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��:" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				

				of.updateOrder();
				cout << "������!" << endl;

				break;
			}
		}
		cout << "��������,����������" << endl;


	}

	system("pause");
	system("cls");

}
