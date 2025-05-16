#include <bits/stdc++.h>

class Group;

class User {
    std::string name;
    int id;
    std::weak_ptr<Group> group_ref;
    int group_id = -1;

public:
    User(const std::string& name_, int id_) : name(name_), id(id_) {}
    User(const std::string& name_, int id_, std::weak_ptr<Group> group);

    int get_group_id() const { return group_id; }
    std::string get_name() const { return name; }
    int get_id() const { return id; }

    void set_group(std::weak_ptr<Group> group);
};

class Group {
    int id;
    std::vector<std::weak_ptr<User>> users;

public:
    Group(int id_) : id(id_) {}

    int get_id() const { return id; }
    const std::vector<std::weak_ptr<User>>& get_users() const { return users; }

    void addUser(std::weak_ptr<User> user) {
        users.push_back(user);
    }

    void deleteUser(std::weak_ptr<User> user) {
        auto shared_user = user.lock();
        users.erase(
            std::remove_if(users.begin(), users.end(),
                [&shared_user](const std::weak_ptr<User>& u) {
                    return u.lock() == shared_user;
                }),
            users.end()
        );
    }
};

class Manager {
    std::vector<std::shared_ptr<User>> user_list;
    std::vector<std::shared_ptr<Group>> group_list;

    void printUser(const User& user) const {
        std::cout << "  * User: " << user.get_name()
                  << " (ID: " << user.get_id() << ")\n";
    }

    auto findUser(int user_id) const {
        return std::find_if(user_list.begin(), user_list.end(),
            [user_id](const auto& user) {
                return user->get_id() == user_id;
            });
    }

    auto findGroup(int group_id) const {
        return std::find_if(group_list.begin(), group_list.end(),
            [group_id](const auto& group) {
                return group->get_id() == group_id;
            });
    }

public:
    void createUser(const std::string& name, int user_id, int group_id = -1) {
        if (findUser(user_id) != user_list.end()) {
            std::cout << "\nUser with this ID already exists\n";
            return;
        }

        std::shared_ptr<User> new_user;

        if (group_id == -1) {
            new_user = std::make_shared<User>(name, user_id);
        } else {
            auto group_it = findGroup(group_id);
            if (group_it == group_list.end()) {
                std::cout << "\nNo group with this id!\n";
                return;
            }
            new_user = std::make_shared<User>(name, user_id, *group_it);
            (*group_it)->addUser(new_user);
        }

        user_list.push_back(new_user);
        std::cout << "\nUser created!\n";
    }

    void deleteUser(int user_id) {
        auto it = findUser(user_id);
        if (it == user_list.end()) {
            std::cout << "\nNo User in Data!\n";
            return;
        }

        if ((*it)->get_group_id() != -1) {
            auto group_it = findGroup((*it)->get_group_id());
            if (group_it != group_list.end()) {
                (*group_it)->deleteUser(*it);
            }
        }

        user_list.erase(it);
        std::cout << "\nUser deleted!\n";
    }

    void createGroup(int group_id) {
        if (group_id < 0) {
            std::cout << "\nWrong ID for Group!\n";
            return;
        }

        if (findGroup(group_id) != group_list.end()) {
            std::cout << "\nGroup with this ID already exists\n";
            return;
        }

        group_list.push_back(std::make_shared<Group>(group_id));
        std::cout << "\nGroup created!\n";
    }

    void deleteGroup(int group_id) {
        auto it = findGroup(group_id);
        if (it == group_list.end()) {
            std::cout << "\nNo Group in Data!\n";
            return;
        }

        for (auto& user : user_list) {
            if (user->get_group_id() == group_id) {
                user->set_group(std::weak_ptr<Group>());
            }
        }

        group_list.erase(it);
        std::cout << "\nGroup deleted!\n";
    }

    void allUsers() const {
        if (user_list.empty()) {
            std::cout << "\nNo users in system\n";
            return;
        }

        std::cout << "\n=== Users Information ===\n";
        for (const auto& user : user_list) {
            printUser(*user);
        }
        std::cout << "=== End of Users List ===\n";
    }

    void allGroups() const {
        if (group_list.empty()) {
            std::cout << "\nNo groups in system\n";
            return;
        }

        std::cout << "\n=== Groups Information ===\n";
        for (const auto& group : group_list) {
            std::cout << "\nGroup ID: " << group->get_id() << "\n";
            std::cout << "Members (" << group->get_users().size() << "):\n";

            if (group->get_users().empty()) {
                std::cout << "  No members\n";
            } else {
                for (const auto& member : group->get_users()) {
                    if (auto user = member.lock()) {
                        printUser(*user);
                    }
                }
            }
        }
        std::cout << "\n=== End of Groups List ===\n";
    }

    void getUser(int user_id) const {
        auto it = findUser(user_id);
        if (it == user_list.end()) {
            std::cout << "\nNo User in Data!\n";
            return;
        }

        std::cout << "\n=== User Information ===\n";
        printUser(**it);
        std::cout << "========================\n";
    }

    void getGroup(int group_id) const {
        auto it = findGroup(group_id);
        if (it == group_list.end()) {
            std::cout << "\nNo Group in Data!\n";
            return;
        }

        std::cout << "\n=== Group Information ===\n";
        std::cout << "Group ID: " << (*it)->get_id() << "\n";
        std::cout << "Members (" << (*it)->get_users().size() << "):\n";

        if ((*it)->get_users().empty()) {
            std::cout << "  No members\n";
        } else {
            for (const auto& member : (*it)->get_users()) {
                if (auto user = member.lock()) {
                    printUser(*user);
                }
            }
        }
        std::cout << "=========================\n";
    }
};

User::User(const std::string& name_, int id_, std::weak_ptr<Group> group) :
    name(name_), id(id_)
{
    set_group(group);
}

void User::set_group(std::weak_ptr<Group> group) {
    group_ref = group;
    if (auto g = group.lock()) {
        group_id = g->get_id();
    } else {
        group_id = -1;
    }
}

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