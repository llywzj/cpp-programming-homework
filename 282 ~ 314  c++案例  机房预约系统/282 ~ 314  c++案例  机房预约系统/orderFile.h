#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include "globalFile.h"
#include<map>
#include<string>

class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������  key��¼����  value�Ǿ����¼��ֵ����Ϣ
	map<int, map<string, string>> m_orderData;


};