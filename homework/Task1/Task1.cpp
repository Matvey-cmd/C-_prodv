#include "Task1.h"

User::User(const std::string& name_, int id_) : name(name_), id(id_) {}

User::User(const std::string& name_, int id_, std::weak_ptr<Group> group)
    : name(name_), id(id_) {
    set_group(group);
}

int User::get_group_id() const { return group_id; }
std::string User::get_name() const { return name; }
int User::get_id() const { return id; }

void User::set_group(std::weak_ptr<Group> group) {
    group_ref = group;
    if (auto g = group.lock()) {
        group_id = g->get_id();
    } else {
        group_id = -1;
    }
}

Group::Group(int id_) : id(id_) {}
int Group::get_id() const { return id; }
const std::vector<std::weak_ptr<User>>& Group::get_users() const { return users; }

void Group::addUser(std::weak_ptr<User> user) {
    users.push_back(user);
}

void Group::deleteUser(std::weak_ptr<User> user) {
    auto shared_user = user.lock();
    users.erase(
        std::remove_if(users.begin(), users.end(),
            [&shared_user](const std::weak_ptr<User>& u) {
                return u.lock() == shared_user;
            }),
        users.end()
    );
}

void Manager::printUser(const User& user) const {
    std::cout << "  * User: " << user.get_name()
              << " (ID: " << user.get_id() << ")\n";
}

auto Manager::findUser(int user_id) const {
    return std::find_if(user_list.begin(), user_list.end(),
        [user_id](const auto& user) {
            return user->get_id() == user_id;
        });
}

auto Manager::findGroup(int group_id) const {
    return std::find_if(group_list.begin(), group_list.end(),
        [group_id](const auto& group) {
            return group->get_id() == group_id;
        });
}

void Manager::createUser(const std::string& name, int user_id, int group_id) {
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

void Manager::deleteUser(int user_id) {
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

void Manager::createGroup(int group_id) {
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

void Manager::deleteGroup(int group_id) {
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

void Manager::allUsers() const {
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

void Manager::allGroups() const {
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

void Manager::getUser(int user_id) const {
    auto it = findUser(user_id);
    if (it == user_list.end()) {
        std::cout << "\nNo User in Data!\n";
        return;
    }

    std::cout << "\n=== User Information ===\n";
    printUser(**it);
    std::cout << "========================\n";
}

void Manager::getGroup(int group_id) const {
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