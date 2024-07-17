#include "Input.h"

void input()
{
    ifstream inFile("monsterData.dat", ios::binary);

    if (!inFile.is_open())
    {
        cout << "Input Error" << endl;
    }

    vector<Monster> monsters;

    while (inFile.peek() != EOF)
    {
        Monster curMonster;

        // 몬스터의 이름
        size_t nameLength;
        inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        char* nameBuffer = new char[nameLength + 1];
        inFile.read(nameBuffer, nameLength);
        nameBuffer[nameLength] = '\0';
        curMonster.name = string(nameBuffer);
        delete[] nameBuffer;

        // 공격력
        inFile.read(reinterpret_cast<char*>(&curMonster.atk), sizeof(curMonster.atk));

        // 방어력
        inFile.read(reinterpret_cast<char*>(&curMonster.def), sizeof(curMonster.def));

        // 생명력
        inFile.read(reinterpret_cast<char*>(&curMonster.hp), sizeof(curMonster.hp));

        monsters.push_back(curMonster); // 할당이 끝난 객체를 벡터에 추가한다.
    }

    inFile.close(); // 읽기 종료
    cout << "\n읽기 종료\n" << endl;

    for (Monster monster : monsters)
    {
        cout << "몬스터 이름 : " << monster.name << endl;
        cout << "공격력 : " << monster.atk << endl;
        cout << "방어력 : " << monster.def << endl;
        cout << "생명력 : " << monster.hp << endl;
        cout << endl;
    }

    cout << "input 함수 종료" << endl;
}