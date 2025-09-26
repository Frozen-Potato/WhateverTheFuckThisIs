#include "Employee.h"

using Vec = std::vector<std::shared_ptr<Employee>>;
class Company {
    Vec employed;
    std::string name;
    int foundingYear;
    public:
        Company(std::string name, int year) : name(name), foundingYear(year) {};
        ~Company() = default;

        const int& getFoundingYear() const {return foundingYear;};
        const std::string& getName() const {return name;};
        const Vec& getEmployed() const {return employed;};

        void addEmployee(const std::shared_ptr<Employee>& person) {
            employed.emplace_back(person);
        }

        template<typename T, typename... Args>
        void addEmployeeR(Args&&... args){
            employed.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
        }
};

class Project: public std::enable_shared_from_this<Project> {
    std::string name;
    std::chrono::year_month_day startDate;
    Vec currentWorker;
    std::weak_ptr<Manager> PM;
    public:
        Project(std::string name, std::shared_ptr<Manager> person ,std::chrono::year_month_day date) : name(name), PM(person), startDate(date) {
            std::cout << "New project registered on " << printDate(startDate) << ". Managed by " << person->getName() <<"\n";
            person->addProject(shared_from_this());
        };
        ~Project() = default;

        std::string printDate(const std::chrono::year_month_day& date) const {
            std::ostringstream result;
            result << (unsigned)date.day() << '-' << (unsigned)date.month() << '-' << (int)date.year();
            return result.str();
        }
        
        void addEmployee(const std::shared_ptr<Employee>& person) {
            currentWorker.emplace_back(person);
        }

        template<typename T, typename... Args>
        void addEmployeeR(Args&&... args){
            currentWorker.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
        }
};

class Employee {
    std::string name;
    int id;

    public:
        explicit Employee(std::string name, int id) : name(name), id(id) {};

        virtual ~Employee() = default;

        std::string getName() const { return name; }
        virtual void work() { std::cout << "Working...\n"; };
        virtual std::string getRole() const { return "Sla...Employee\n"; };
};

class Manager : public Employee {
    std::vector<std::weak_ptr<Project>> currentProject;
    public:
        Manager(std::string name, int id) : Employee(std::move(name), id) {};
        ~Manager() { std::cout << "Lost 1 Manager\n"; };

        void work() override { std::cout << "Managing...\n"; };
        std::string getRole() const override { return "Manager\n"; };
        std::vector<std::weak_ptr<Project>> getProject() const { return currentProject; };
        
        void addProject(std::shared_ptr<Project> project){
            currentProject.emplace_back(project);
        } 
};

class Engineer : public Employee {
    public:
        Engineer(std::string name, int id) : Employee(std::move(name), id) {};
        ~Engineer() { std::cout << "Lost 1 Engieer\n"; };
        void work() override { std::cout << "Designing overly complicated solution...\n"; };
        std::string getRole() const override { return "Engineer\n"; };
};

class Intern : public Employee {
    public:
        Intern(std::string name, int id) : Employee(std::move(name), id) {};
        ~Intern() { std::cout << "Losing money\n"; };
        void work() override { std::cout << "Coding..\n"; };
        std::string getRole() const override { return "Intern\n"; };
};

using Vec = std::vector<std::shared_ptr<Employee>>;
class HR : public Employee {
    Vec recruited;
    public:
        HR(std::string name, int id) : Employee(std::move(name), id) {};
        HR(std::string name, int id, const Vec& list) : Employee(std::move(name), id), recruited(list) {};
        HR(std::string name, int id, Vec&& list) : Employee(std::move(name), id), recruited(std::move(list)) {};
        HR(std::string name, int id, std::initializer_list<std::shared_ptr<Employee>> list) : Employee(std::move(name), id), recruited(list) {};
        ~HR() { std::cout << "Losing money\n"; };
        void work() override { std::cout << "Nothing..\n"; };
        std::string getRole() const override { return "HR\n"; };
        void recruit(const std::shared_ptr<Employee>& person) {
            recruited.emplace_back(person);
        }
        const Vec& getRecruited() const { 
            return recruited;
        }

        Vec getRecruitedCopy() {
            return recruited;
        }
};