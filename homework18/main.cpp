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
    // Установим права доступа только для пользователя, который запускает программу
    chmod("user.dat", S_IRUSR | S_IWUSR);

    // Чтение объекта User из файла
    User user;
    ifstream userFile("user.dat", ios::binary);
    if (userFile) {
        userFile.read((char*)&user, sizeof(User));
        userFile.close();
    }
    else {
        // Обработка ошибки открытия файла
        cerr << "Error opening user file" << endl;
        return 1;
    }

    // Запись объекта User в файл
    ofstream userFileOut("user.dat", ios::binary);
    if (userFileOut) {
        userFileOut.write((char*)&user, sizeof(User));
        userFileOut.close();
    }
    else {
        // Обработка ошибки открытия файла
        cerr << "Error opening user file" << endl;
        return 1;
    }

    // Установим права доступа только для пользователя, который запускает программу
    chmod("message.dat", S_IRUSR | S_IWUSR);

    // Чтение объекта Message из файла
    Message message;
    ifstream messageFile("message.dat", ios::binary);
    if (messageFile) {
        messageFile.read((char*)&message, sizeof(Message));
        messageFile.close();
    }
    else {
        // Обработка ошибки открытия файла
        cerr << "Error opening message file" << endl;
        return 1;
    }

    // Запись объекта Message в файл
    ofstream messageFileOut("message.dat", ios::binary);
    if (messageFileOut) {
        messageFileOut.write((char*)&message, sizeof(Message));
        messageFileOut.close();
    }
    else {
        // Обработка ошибки открытия файла
        cerr << "Error opening message file" << endl;
        return 1;
    }

    return 0;
}