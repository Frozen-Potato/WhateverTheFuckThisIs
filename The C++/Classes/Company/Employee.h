#ifndef E_H
#define E_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

using Vec = std::vector<std::shared_ptr<class Employee>>;

class Employee {
    std::string name;
    int id;

public:
    explicit Employee(std::string name, int id);
    virtual ~Employee() = default;

    std::string getName() const;
    virtual void work();
    virtual std::string getRole() const;
};

class Manager : public Employee {
public:
    Manager(std::string name, int id);
    ~Manager();

    void work() override;
    std::string getRole() const override;
};

class Engineer : public Employee {
public:
    Engineer(std::string name, int id);
    ~Engineer();

    void work() override;
    std::string getRole() const override;
};

class Intern : public Employee {
public:
    Intern(std::string name, int id);
    ~Intern();

    void work() override;
    std::string getRole() const override;
};

class HR : public Employee {
    Vec recruited;

public:
    HR(std::string name, int id);
    HR(std::string name, int id, const Vec& list);
    HR(std::string name, int id, Vec&& list);
    HR(std::string name, int id, std::initializer_list<std::shared_ptr<Employee>> list);
    ~HR();

    void work() override;
    std::string getRole() const override;

    void recruit(const std::shared_ptr<Employee>& person);
    const Vec& getRecruited() const;
    Vec getRecruitedCopy();
};

class Company {
    Vec employed;
    std::string name;
    int foundingYear;

public:
    Company(std::string name, int year);
    ~Company() = default;

    const int& getFoundingYear() const;
    const std::string& getName() const;
    const Vec& getEmployed() const;

    void addEmployee(const std::shared_ptr<Employee>& person);

    template<typename T, typename... Args>
    void addEmployeeR(Args&&... args) {
        employed.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
    }
};

#endif