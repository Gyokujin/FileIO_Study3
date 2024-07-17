#include "Output.h"

void output()
{
	vector<Monster> monsters;

	int count;
	cout << "몬스터를 생성합니다. 몬스터를 총 몇 체 생성하겠습니까? ";
	cin >> count;

	string input1;
	int input2, input3, input4;

	for (int i = 0; i < count; i++)
	{
		cout << "\n몬스터의 이름 : ";
		cin >> input1;

		cout << "공격력 : ";
		cin >> input2;

		cout << "방어력 : ";
		cin >> input3;

		cout << "생명력 : ";
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
			outFile.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength)); // 데이터들을 문자로 변환 => 바이너리 수정을 거쳐 파일에 작성한다.
			outFile.write(monsters[i].name.c_str(), nameLength);
			outFile.write(reinterpret_cast<char*>(&monsters[i].atk), sizeof(monsters[i].atk));
			outFile.write(reinterpret_cast<char*>(&monsters[i].def), sizeof(monsters[i].def));
			outFile.write(reinterpret_cast<char*>(&monsters[i].hp), sizeof(monsters[i].hp));
		}

		outFile.close();
		cout << "\n쓰기 종료" << endl;
	}
	else
	{
		cout << "Output Error" << endl;
	}

	cout << "output 함수 종료" << endl;
}