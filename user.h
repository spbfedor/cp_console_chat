#pragma once
#include <string>


class User {
    public:
        User(std::string& name, const std::string& login, std::string& password)
        : name_(name), login_(login), password_(password) {}
    
        void setUserName(const std::string& name) {
            name_ = name;
        }

        const std::string& getUserName() const {
            return name_;
        }

        const std::string& getUserLogin() const {
            return login_;
        }

        void setUserPassword(const std::string& password) {
            password_ = password;
        }

        const std::string& getUserPassword() const {
            return password_;
        }

    private:
        std::string name_;
        const std::string login_;
        std::string password_;
};