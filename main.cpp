#include "chat.h"
#include "chat.cpp"


int main() {
    Chat chat;

    chat.start();

    while(chat.getLaunchChat()) {
        chat.authorizationMenu();

        while (chat.getCurrentUser()) {
            chat.customMenu();
        }
    }
    return 0;
}