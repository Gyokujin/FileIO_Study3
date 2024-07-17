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

        // ������ �̸�
        size_t nameLength;
        inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        char* nameBuffer = new char[nameLength + 1];
        inFile.read(nameBuffer, nameLength);
        nameBuffer[nameLength] = '\0';
        curMonster.name = string(nameBuffer);
        delete[] nameBuffer;

        // ���ݷ�
        inFile.read(reinterpret_cast<char*>(&curMonster.atk), sizeof(curMonster.atk));

        // ����
        inFile.read(reinterpret_cast<char*>(&curMonster.def), sizeof(curMonster.def));

        // �����
        inFile.read(reinterpret_cast<char*>(&curMonster.hp), sizeof(curMonster.hp));

        monsters.push_back(curMonster); // �Ҵ��� ���� ��ü�� ���Ϳ� �߰��Ѵ�.
    }

    inFile.close(); // �б� ����
    cout << "\n�б� ����\n" << endl;

    for (Monster monster : monsters)
    {
        cout << "���� �̸� : " << monster.name << endl;
        cout << "���ݷ� : " << monster.atk << endl;
        cout << "���� : " << monster.def << endl;
        cout << "����� : " << monster.hp << endl;
        cout << endl;
    }

    cout << "input �Լ� ����" << endl;
}