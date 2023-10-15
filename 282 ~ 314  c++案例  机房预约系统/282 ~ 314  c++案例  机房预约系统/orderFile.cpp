#include"orderFile.h"

//���캯��

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;        //����
	string interval;    //ʱ���
	string stuId;       //ѧ�����
	string stuName;     //ѧ������
	string roomId;      //�������
	string status;      //ԤԼ״̬

	this->m_Size = 0;   //��¼����

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//date:1
		//����
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");    //4
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);     //size = 9   pos = 4

			m.insert(make_pair(key, value));
		}

		//ʱ���
		pos = interval.find(":");    //4
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);     //size = 9   pos = 4

			m.insert(make_pair(key, value));
		}

		//ѧ�����
		pos = stuId.find(":");    //4
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);     //size = 9   pos = 4

			m.insert(make_pair(key, value));
		}

		//ѧ������
		pos = stuName.find(":");    //4
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);     //size = 9   pos = 4

			m.insert(make_pair(key, value));

		}

		//�������
		pos = roomId.find(":");    //4
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);     //size = 9   pos = 4

			m.insert(make_pair(key, value));

		}

		//ԤԼ״̬
		pos = status.find(":");    //4
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);     //size = 9   pos = 4

			m.insert(make_pair(key, value));

		}

		//��Сmap���������map������
		this->m_orderData.insert(make_pair(this->m_Size,m));
		this->m_Size++;
	}
	ifs.close();
}

//����ԤԼ��¼
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;  //ԤԼ��¼0��,ֱ��return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << " ";	
	}
	ofs.close();
}
