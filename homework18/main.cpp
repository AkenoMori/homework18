#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

class User {
public:
    string _name;
    string _login;
    string _pass;
};

class Message {
public:
    string _text;
    string _sender;
    string _receiver;
};

int main() {
    // ��������� ����� ������� ������ ��� ������������, ������� ��������� ���������
    chmod("user.dat", S_IRUSR | S_IWUSR);

    // ������ ������� User �� �����
    User user;
    ifstream userFile("user.dat", ios::binary);
    if (userFile) {
        userFile.read((char*)&user, sizeof(User));
        userFile.close();
    }
    else {
        // ��������� ������ �������� �����
        cerr << "Error opening user file" << endl;
        return 1;
    }

    // ������ ������� User � ����
    ofstream userFileOut("user.dat", ios::binary);
    if (userFileOut) {
        userFileOut.write((char*)&user, sizeof(User));
        userFileOut.close();
    }
    else {
        // ��������� ������ �������� �����
        cerr << "Error opening user file" << endl;
        return 1;
    }

    // ��������� ����� ������� ������ ��� ������������, ������� ��������� ���������
    chmod("message.dat", S_IRUSR | S_IWUSR);

    // ������ ������� Message �� �����
    Message message;
    ifstream messageFile("message.dat", ios::binary);
    if (messageFile) {
        messageFile.read((char*)&message, sizeof(Message));
        messageFile.close();
    }
    else {
        // ��������� ������ �������� �����
        cerr << "Error opening message file" << endl;
        return 1;
    }

    // ������ ������� Message � ����
    ofstream messageFileOut("message.dat", ios::binary);
    if (messageFileOut) {
        messageFileOut.write((char*)&message, sizeof(Message));
        messageFileOut.close();
    }
    else {
        // ��������� ������ �������� �����
        cerr << "Error opening message file" << endl;
        return 1;
    }

    return 0;
}