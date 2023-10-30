#pragma once
#include <exception>
#include <vector>
#include <memory>
#include "message.h"


class UserLoginException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "error: this login already exists";
        }
};


class Chat {
    public:
        void start();
        bool getLaunchChat() const {
            return launchChat_;
        }
        std::shared_ptr<User> getCurrentUser() const {
            return currentUser_; 
        }
        void authorizationMenu();
        void customMenu();
    private:
        bool launchChat_ = false;
        std::vector<User> arr_users_;
        std::vector<Message> arr_messages_;
        std::shared_ptr<User> currentUser_ = nullptr;

        void signUp();
        void authorzation();
        void showChat() const;
        void showAllUserName() const;
        void addMessage();
        std::vector<User>& getAllUsers() {
            return arr_users_;
        }
        std::vector<Message>& getAllMessages() {
            return arr_messages_;
        }
        std::shared_ptr<User> getUserByLogin(const std::string& login) const;
        std::shared_ptr<User> getUserByName(const std::string& name) const;
};