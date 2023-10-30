#pragma once
#include "user.h"

class Message {
    public:
        Message(const std::string& sender, const std::string& recipient, const std::string& text_message)
        : sender_(sender), recipient_(recipient), text_message_(text_message) {}

        const std::string& getSender() const {
            return sender_;
        }

        const std::string& getRecipient() const {
            return recipient_;
        }
        const std::string& getTextMessage() const {
            return text_message_;
        }
    private:
        const std::string sender_;
        const std::string recipient_;
        const std::string text_message_;
};