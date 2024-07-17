#include "Output.h"

void output()
{
	vector<Monster> monsters;

	int count;
	cout << "���͸� �����մϴ�. ���͸� �� �� ü �����ϰڽ��ϱ�? ";
	cin >> count;

	string input1;
	int input2, input3, input4;

	for (int i = 0; i < count; i++)
	{
		cout << "\n������ �̸� : ";
		cin >> input1;

		cout << "���ݷ� : ";
		cin >> input2;

		cout << "���� : ";
		cin >> input3;

		cout << "����� : ";
		cin >> input4;

		Monster createMonster = { input1, input2, input3, input4 };
		monsters.push_back(createMonster);
	}

	ofstream outFile("monsterData.dat", ios::binary);

	if (outFile.is_open())
	{
		for (int i = 0; i < monsters.size(); i++) // string fileName = "monsterData" + to_string(i + 1);
		{
			size_t nameLength = monsters[i].name.size();
			outFile.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength)); // �����͵��� ���ڷ� ��ȯ => ���̳ʸ� ������ ���� ���Ͽ� �ۼ��Ѵ�.
			outFile.write(monsters[i].name.c_str(), nameLength);
			outFile.write(reinterpret_cast<char*>(&monsters[i].atk), sizeof(monsters[i].atk));
			outFile.write(reinterpret_cast<char*>(&monsters[i].def), sizeof(monsters[i].def));
			outFile.write(reinterpret_cast<char*>(&monsters[i].hp), sizeof(monsters[i].hp));
		}

		outFile.close();
		cout << "\n���� ����" << endl;
	}
	else
	{
		cout << "Output Error" << endl;
	}

	cout << "output �Լ� ����" << endl;
}