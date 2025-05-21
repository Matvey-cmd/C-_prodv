#ifndef USER_GROUP_MANAGER_HPP
#define USER_GROUP_MANAGER_HPP

#include <bits/stdc++.h>

class Group;

class User {
    std::string name;
    int id;
    std::weak_ptr<Group> group_ref;
    int group_id = -1;

public:
    User(const std::string& name_, int id_);
    User(const std::string& name_, int id_, std::weak_ptr<Group> group);

    int get_group_id() const;
    std::string get_name() const;
    int get_id() const;

    void set_group(std::weak_ptr<Group> group);
};

class Group {
    int id;
    std::vector<std::weak_ptr<User>> users;

public:
    Group(int id_);

    int get_id() const;
    const std::vector<std::weak_ptr<User>>& get_users() const;
    void addUser(std::weak_ptr<User> user);
    void deleteUser(std::weak_ptr<User> user);
};

class Manager {
    std::vector<std::shared_ptr<User>> user_list;
    std::vector<std::shared_ptr<Group>> group_list;

    void printUser(const User& user) const;
    auto findUser(int user_id) const;
    auto findGroup(int group_id) const;

public:
    void createUser(const std::string& name, int user_id, int group_id = -1);
    void deleteUser(int user_id);
    void createGroup(int group_id);
    void deleteGroup(int group_id);
    void allUsers() const;
    void allGroups() const;
    void getUser(int user_id) const;
    void getGroup(int group_id) const;
};

#endif