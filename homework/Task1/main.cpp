#include "Task1.h"

int main() {
    Manager manager;
    std::string command;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "createUser") {
            std::string name;
            int user_id, group_id = -1;
            std::cin >> name >> user_id;
            if (std::cin.peek() != '\n') {
                std::cin >> group_id;
            }
            manager.createUser(name, user_id, group_id);
        }
        else if (command == "deleteUser") {
            int user_id;
            std::cin >> user_id;
            manager.deleteUser(user_id);
        }
        else if (command == "createGroup") {
            int group_id;
            std::cin >> group_id;
            manager.createGroup(group_id);
        }
        else if (command == "deleteGroup") {
            int group_id;
            std::cin >> group_id;
            manager.deleteGroup(group_id);
        }
        else if (command == "allUsers") {
            manager.allUsers();
        }
        else if (command == "allGroups") {
            manager.allGroups();
        }
        else if (command == "getUser") {
            int user_id;
            std::cin >> user_id;
            manager.getUser(user_id);
        }
        else if (command == "getGroup") {
            int group_id;
            std::cin >> group_id;
            manager.getGroup(group_id);
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "\nUnknown command!\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}