#include <iostream>
#include <string>

class User {
public:
    std::string name;
    int age;
    std::string email;

    void displayUserDetails() {
        std::cout << name << std::endl;
        std::cout << age << std::endl;
        std::cout << email << std::endl;
    }
};

struct Request {
    int job_id;
    Request* next;
    Request* prev;

    std::string type;
    std::string re_msg;

    Request(int id, const std::string& t)
        : job_id(id), next(nullptr), prev(nullptr),
          type(t), re_msg("") {}
};

class Process {
private:
    Request* head;
    Request* tail;
    int counter;   

public:
    Process() : head(nullptr), tail(nullptr), counter(1) {}

    void createRequest(const std::string& type) {
        Request* req = new Request(counter++, type);

        if (head == nullptr) { 
            head = tail = req;
        } else {
            req->next = head;
            head->prev = req;
            head = req;
        }
    }

    void printList() {
        Request* temp = head;
        while (temp != nullptr) {
            std::cout << "Job ID: " << temp->job_id
                      << " | Type: " << temp->type 
                      << " | Message: " << temp->re_msg 
                      << std::endl;
            temp = temp->next;
        }
    }

    ~Process() {
        
        Request* temp = head;
        while (temp) {
            Request* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
    }
};

int main() {
    Process pro;
    pro.createRequest("first_job");
    pro.createRequest("second_job");
    pro.printList();
    return 0;
}
