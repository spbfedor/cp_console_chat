#include <iostream>
#include "chat.h"


void Chat::start() {
    launchChat_ = true;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const {
    for (auto &user : arr_users_) {
        if (login == user.getUserLogin()) {
            return std::make_shared<User>(user);
        }
    }
    return nullptr;
}

std::shared_ptr<User> Chat::getUserByName(const std::string& name) const {
    for (auto &user : arr_users_) {
        if (name == user.getUserName()) {
            return std::make_shared<User>(user);
        }
    }
    return nullptr;
}

void Chat::authorizationMenu() {

    currentUser_ = nullptr;
    short int operation;

    do {
        std::cout << "Приветствуем Вас в нашем чате!!!" << std::endl;
        std::cout << "***" << std::endl;
        std::cout << "Нажмите \"1\" для регистрации" << std::endl;
        std::cout << "Нажмите \"2\" для авторизации" << std::endl;
        std::cout << "Нажмите \"0\" что бы покинуть чат" << std::endl;

        std::cin >> operation;

        switch (operation) {
        case 1:
            signUp();
            break;
        case 2:
            authorzation();
            break;
        case 0:
            launchChat_ = false;
            break;
        
        default:
            std::cout << "Вы ввели неправильное значение" << std::endl;
            break;
        }
    } while (!currentUser_ && launchChat_);
}

void Chat::signUp() {
    std::string name, login, password;

    std::cout << "Введите имя:" << std::endl;
    std::cin >> name;
    std::cout << "Придумайте логин:" << std::endl;
    std::cin >> login;
    std::cout << "Придумайте пароль:" << std::endl;
    std::cin >> password;

    if (getUserByLogin(login) || login == "all") {
        throw UserLoginException();
    }

    User user = User(name, login, password);
    arr_users_.push_back(user);
    currentUser_ = std::make_shared<User>(user);

}

void Chat::authorzation() {
    std::string login, password;
    short int operation;
    do {
        std::cout << "Введите логин:" << std::endl;
        std::cin >> login;
        std::cout << "Введите пароль:" << std::endl;
        std::cin >> password;

        currentUser_ = getUserByLogin(login);

        if (currentUser_ == nullptr || (password != currentUser_->getUserPassword())) {
            currentUser_ = nullptr;
            std::cout << "Неверный пароль" << std::endl;
            std::cout << "Нажмите \"0\" что бы выйти" << std::endl;
            std::cin >> operation;

            if (operation == 0) {
                break;
            }
        }
    } while (!currentUser_);
}

void Chat::customMenu() {
    short int operation;

    std::cout << "Hello, " << currentUser_->getUserName() << std::endl;
    std::cout << "***"  << std::endl;

    while (currentUser_) {
        std::cout << "Нажмите \"1\" что бы посмотреть сообщения" << std::endl;
        std::cout << "Нажмите \"2\" что бы добавить сообщение" << std::endl;
        std::cout << "Нажмите \"3\" что бы посмотреть пользователей" << std::endl;
        std::cout << "Нажмите \"0\" что бы покинуть чат" << std::endl;

        std::cin >> operation;

        switch (operation) {
        case 1:
            showChat();
            break;
        case 2:
            addMessage();
            break;
        case 3:
            showAllUserName();
            break;
        case 0:
            currentUser_ = nullptr;
            break;
        default:
            std::cout << "Выберите один из предложенных вариантов" << std::endl;
            break;
        } 
    }
    
}

void Chat::showChat() const {
    std::string sender;
    std::string recipient;

    std::cout << "Сообщения" << std::endl;
    for (auto &mess : arr_messages_) {
        if (currentUser_->getUserLogin() == mess.getSender() || 
        currentUser_->getUserLogin() == mess.getRecipient() || 
        mess.getRecipient() == "all") {
            sender = (currentUser_->getUserLogin() == mess.getSender()) ? "me" :
            getUserByLogin(mess.getSender())->getUserName();

            if (mess.getRecipient() == "all") {
                recipient = "(all)";
            } else {
                recipient = (currentUser_->getUserLogin() == mess.getRecipient()) ? "me" :
            getUserByLogin(mess.getRecipient())->getUserName();
            }

            std::cout << "Сообщение от " << sender << " для " << recipient << std::endl;
            std::cout << "Текст сообщения: " << mess.getTextMessage() << std::endl;
        }
    }

    std::cout << "___________" << std::endl;
}

void Chat::showAllUserName() const {
    std::cout << "---Users---" << std::endl;
    for (auto &user : arr_users_) {
        std::cout << user.getUserName();
        if (currentUser_->getUserLogin() == user.getUserLogin()) {
            std::cout << "(me)";
        }
        std::cout << std::endl;
    }
    std::cout << "___________" << std::endl;
}

void Chat::addMessage() {
    std::string recip, text;
    std::cout << "Введите логин получтателя или отправьте всем (all): " << std::endl;
    std::cin >> recip;
    std::cout << "Введите текст сообщения: " << std::endl;
    std::cin.ignore();
    getline(std::cin, text);

    if (!(recip == "all" || getUserByLogin(recip))) {
        std::cout << "Такого получателя не существует " << recip << std::endl;
        return;
    }

    if (recip == "all") {
        arr_messages_.push_back(Message(currentUser_->getUserLogin(), "all", text));
    } else {
        arr_messages_.push_back(Message(currentUser_->getUserLogin(), getUserByName(recip)->getUserLogin(), text));
    }
}