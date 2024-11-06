#include <iostream>
#include <cctype>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Make these Stack and Queue Classes Using Linked List to Refrain from STL
class Node1
{
public:
    int t_ID;
    string res_detail;
    Node1 *next;

    Node1()
    {
        next = nullptr;
    }
    Node1(int ID, string res, Node1 *newNode)
    {
        t_ID = ID;
        res_detail = res;
        next = newNode;
    }
};

class Stack
{
private:
    Node1 *head;

public:
    Stack()
    {
        head = nullptr;
    }
    ~Stack()
    {
        while (head)
        {
            Node1 *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int id, string de)
    {
        Node1 *new_node = new Node1{id, de, head};
        head = new_node;
    }

    void pop()
    {
        if (head)
        {
            Node1 *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            cout << "No Resolutions ." << endl;
        }
    }

    void display()
    {
        Node1 *ptr = head;
        while (ptr)
        {
            cout << "Resolution: " << ptr->res_detail << endl;
            cout << "Ticket ID : " << ptr->t_ID << endl;
            ptr = ptr->next;
        }
    }
};

class Node2
{
public:
    int t_ID;
    string name;
    int priority;
    Node2 *next;

    Node2()
    {
        next = nullptr;
    }

    Node2(int id, string n, int p)
    {
        t_ID = id;
        name = n;
        priority = p;
        next = nullptr;
    }
    Node2(int id)
    {
        id = t_ID;
        next = nullptr;
    }
};

class Queue
{
private:
    Node2 *front;
    Node2 *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        while (front)
        {
            Node2 *temp = front;
            front = front->next;
            delete temp;
        }
    }
    string getname(int id)
    {
        Node2 *temp = front;
        while (temp != nullptr)
        {
            if (temp->t_ID == id)
                return temp->name;
            temp = temp->next;
        }

        return "Does not exists";
    }
    int getPriority(int id)
    {
        Node2 *temp = front;
        while (temp != nullptr)
        {
            if (temp->t_ID == id)
                return temp->priority;
            temp = temp->next;
        }

        return -1;
    }
    // It checks that the ticket is input by the user or Not
    bool Ticket_Exists(int id)
    {
        Node2 *temp = front;
        while (temp != nullptr)
        {
            if (temp->t_ID == id)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void enqueue(int id)
    {
        Node2 *new_node = new Node2{id};
        if (rear)
        {
            rear->next = new_node;
        }
        else
        {
            front = new_node;
        }
        rear = new_node;
        cout << "Ticket " << id << " added to the queue." << endl;
    }

    void dequeue()
    {
        if (front)
        {
            Node2 *temp = front;
            front = front->next;
            if (front == nullptr)
            {
                rear = nullptr;
            }
            delete temp;
            cout << "Ticket dequeued." << endl;
        }
        else
        {
            cout << "Queue Empty." << endl;
        }
    }

    void display()
    {
        Node2 *ptr = front;
        if (!ptr)
        {
            cout << "No Tickets, Queue is Empty." << endl;
            return;
        }
        cout << "Tickets in Queue:" << endl;
        while (ptr)
        {
            cout << "Customer: " << ptr->name << endl;
            cout << "Priority: " << ptr->priority << endl;
            cout << "Ticket ID: " << ptr->t_ID << endl;
            ptr = ptr->next;
        }
    }
};

// Tickets Class ----------------(1. Service Request (Ticket) Management)
class Node3
{
public:
    int t_ID;
    int priority;
    bool status;
    string c_Name;
    string request;
    time_t c_time;
    string c_time_str;
    string end_time;
    Node3 *next;

    Node3() {}

    Node3(int id, string name, int pri, string des, bool sta)
    {

        time(&c_time);
        c_time_str = ctime(&c_time);
        end_time = "";
        t_ID = id;
        c_Name = name;
        priority = pri;
        request = des;
        status = sta;
        next = nullptr;
    }
};

class Tickets
{
protected:
    Node3 *head;

public:
    Tickets()
    {
        head = nullptr;
    }
    // helper functions
    Node3 *LastNode(Node3 *Node)
    {
        while (Node != nullptr && Node->next != nullptr)
        {
            Node = Node->next;
        }
        return Node;
    }
    // helper functions
    void swapping(Node3 *a, Node3 *b)
    {
        if (a != b)
        {
            swap(a->t_ID, b->t_ID);
            swap(a->c_Name, b->c_Name);
            swap(a->priority, b->priority);
            swap(a->request, b->request);
            swap(a->c_time, b->c_time);
            swap(a->c_time_str, b->c_time_str);
            swap(a->status, b->status);
            swap(a->end_time, b->end_time);
        }
    }
    // helper functions
    void Swap_(Node3 *a, Node3 *b)
    {
        swap(a->t_ID, b->t_ID);
        swap(a->c_Name, b->c_Name);
        swap(a->priority, b->priority);
        swap(a->request, b->request);
        swap(a->c_time, b->c_time);
        swap(a->c_time_str, b->c_time_str);
        swap(a->status, b->status);
        swap(a->end_time, b->end_time);
    }
    // add tickets ; simple logic of insertion using in singly linked list
    void Add_Ticket(int id, string name, int p, string req, bool sta)
    {
        Node3 *temp = new Node3(id, name, p, req, sta);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node3 *ptr = head;
            while (ptr->next)
            {
                ptr = ptr->next;
            }
            ptr->next = ptr;
        }
        cout << "New ticket created with ID: " << temp->t_ID << endl;
    }
    // remove tickets ; simple logic of deletion using in singly linked list
    void Remove_Ticket(int id)
    {
        if (!head)
        {
            cout << "Tickets are not available" << endl;
            return;
        }

        if (head->t_ID == id)
        {
            Node3 *to_delete = head;
            head = head->next;
            delete to_delete;
            cout << "Ticket with ID " << id << " removed" << endl;
            return;
        }

        Node3 *ptr = head;
        while (!ptr->next && ptr->next->t_ID != id)
        {
            ptr = ptr->next;
        }

        if (!ptr->next)
        {
            cout << "No ticket found with ID " << id << endl;
        }
        else
        {
            Node3 *to_delete = ptr->next;
            ptr->next = ptr->next->next;
            delete to_delete;
            cout << "Ticket with ID " << id << " removed" << endl;
        }
    }
    // count the total number of nodes
    int count(Node3 *head)
    {
        int c = 0;
        Node3 *ptr = head;
        while (ptr)
        {
            ptr = ptr->next;
            c++;
        }
        return c;
    }

    // search tickets
    void Search_Ticket(int id, string algo, int n, string search)
    {

        if (count(head) < n)
        {

            if (algo == "Insertion_Sort")
            {
                Insertion_Sort(head);
            }
            else if (algo == "Bubble_Sort")
            {
                Bubble_Sort(head);
            }
            else if (algo == "Selection_Sort")
            {
                Selection_Sort(head);
            }
        }
        else
        {
            Merge_Sort(head);
        }
        vector<Node3 *> arr;
        Node3 *ptr = head;
        while (ptr != nullptr)
        {
            arr.push_back(ptr);
            ptr = ptr->next;
        }
        bool found = 0;
        if (search == "Interpolation_Search")
        {
            int start = 0;
            int end = arr.size() - 1;

            while (start <= end && id >= arr[start]->t_ID && id <= arr[end]->t_ID)
            {
                if (start == end)
                {
                    if (arr[start]->t_ID == id)
                    {
                        found = 1;
                    }
                }

                int pos = start + ((id - arr[start]->t_ID) * (end - start) / (arr[end]->t_ID - arr[start]->t_ID));

                if (arr[pos]->t_ID == id)
                {
                    found = 1;
                }

                if (arr[pos]->t_ID < id)
                    start = pos + 1;
                else
                    end = pos - 1;
            }
        }
        else if (search == "Binary_Search")
        {
            int start = 0;
            int end = arr.size() - 1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (arr[mid]->t_ID == id)
                {
                    found = 1;
                }
                else if (arr[mid]->t_ID < id)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        if (found)
        {
            cout << "Ticket Found : " << id << endl;
        }
        else
        {
            cout << "Ticket Not Found : " << endl;
        }
    }

    bool Check_Ticket(int id)
    {
        Node3 *temp = head;
        while (temp != nullptr)
        {
            if (temp->t_ID == id)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void Display_Tickets()
    {
        Node3 *temp = head;
        if (temp == nullptr)
        {
            cout << "No tickets available" << endl;
            return;
        }
        while (temp != nullptr)
        {
            cout << "Status: ";
            if (temp->status)
            {
                cout << "Open" << endl;
            }
            else
            {
                cout << "Closed" << endl;
            }

            cout << "Ticket ID: " << temp->t_ID << endl;
            cout << "Customer Name: " << temp->c_Name << endl;
            cout << "Priority: " << temp->priority << endl;
            cout << "Request Description: " << temp->request << endl;
            cout << "Creation Time: " << temp->c_time_str;

            if (!temp->status)
            {
                cout << "Close Time: " << temp->end_time;
            }
            temp = temp->next;
        }
    }

    Node3 *Merge(Node3 *ptr1, Node3 *ptr2)
    {
        if (!ptr1)
            return ptr2;
        if (!ptr2)
            return ptr1;

        Node3 *temp;
        if (ptr1->t_ID <= ptr2->t_ID)
        {
            temp = ptr1;
            temp->next = Merge(ptr1->next, ptr2);
        }
        else
        {
            temp = ptr2;
            temp->next = Merge(ptr1, ptr2->next);
        }
        return temp;
    }
    void Split(Node3 *source, Node3 *ptr1, Node3 *ptr2)
    {
        Node3 *fast = source->next;
        Node3 *slow = source;

        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        ptr1 = source;
        ptr2 = slow->next;
        slow->next = nullptr;
    }
    void Merge_Sort(Node3 *head)
    {
        if (!head || !head->next)
            return;

        Node3 *a;
        Node3 *b;
        Split(head, a, b);

        Merge_Sort(a);
        Merge_Sort(b);

        head = Merge(a, b);
    }

    void Selection_Sort(Node3 *head)
    {
        Node3 *temp = head;

        while (temp)
        {
            Node3 *min = temp;
            Node3 *ptr = temp->next;

            while (ptr)
            {
                if (ptr->t_ID < min->t_ID)
                    min = ptr;
                ptr = ptr->next;
            }
            swapping(temp, min);
            temp = temp->next;
        }
    }
    void Insertion_Sort(Node3 *head)
    {
        Node3 *ptr = nullptr;
        Node3 *temp = head;

        while (temp)
        {
            Node3 *next = temp->next;
            Insert_In_Sorted(ptr, temp);
            temp = next;
        }
        head = ptr;
    }

    void Insert_In_Sorted(Node3 *head, Node3 *New)
    {
        if (!head || head->t_ID >= New->t_ID)
        {
            New->next = head;
            head = New;
        }
        else
        {
            Node3 *curr = head;
            while (curr->next && curr->next->t_ID < New->t_ID)
            {
                curr = curr->next;
            }
            New->next = curr->next;
            curr->next = New;
        }
    }

    void Bubble_Sort(Node3 *head)
    {
        if (head == nullptr)
            return;

        bool swapped;
        Node3 *ptr1;
        Node3 *ptr2 = nullptr;

        do
        {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != ptr2)
            {
                if (ptr1->t_ID > ptr1->next->t_ID)
                {
                    swapping(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            ptr2 = ptr1;
        } while (swapped);
    }

    void Sort_By_Priority()
    {
        if (head == nullptr)
            return;

        for (Node3 *temp1 = head; temp1 != nullptr; temp1 = temp1->next)
        {
            Node3 *mini = temp1;
            for (Node3 *temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next)
            {
                if (temp2->priority < mini->priority)
                {
                    mini = temp2;
                }
            }
            if (mini != temp1)
            {
                Swap_(temp1, mini);
            }
        }
    }

    void Sort_By_Name()
    {
        if (head == nullptr)
            return;

        for (Node3 *ptr1 = head; ptr1 != nullptr; ptr1 = ptr1->next)
        {
            for (Node3 *ptr2 = ptr1->next; ptr2 != nullptr; ptr2 = ptr2->next)
            {
                if (ptr1->c_Name > ptr2->c_Name)
                {
                    Swap_(ptr1, ptr2);
                }
            }
        }
    }

    void Sort_By_Time()
    {
        if (head == nullptr)
            return;

        for (Node3 *ptr1 = head; ptr1 != nullptr; ptr1 = ptr1->next)
        {
            Node3 *mini = ptr1;
            for (Node3 *ptr2 = ptr1->next; ptr2 != nullptr; ptr2 = ptr2->next)
            {
                if (ptr2->c_time < mini->c_time)
                {
                    mini = ptr2;
                }
            }
            if (mini != ptr1)
            {
                Swap_(ptr1, mini);
            }
        }
    }

    void Sorting(int choice)
    {
        if (choice == 1)
        {
            Sort_By_Time();
        }
        else if (choice == 2)
        {
            Sort_By_Name();
        }
        else if (choice == 3)
        {
            Sort_By_Priority();
        }
        else
        {
            cout << "Invalid Choice : " << endl;
        }
    }
};

// Agent Class --------------------(2. Agent Management)
class Agent
{
public:
    int agent_id;
    string name;
    int *assign_tickets;
    bool availability;
    int capacity;

    Agent()
    {
        assign_tickets = nullptr;
    }
    Agent(int id, string n)
    {
        agent_id = id;
        name = n;
        availability = true;
        capacity = 0;
        assign_tickets = nullptr;
    }
    // first check if capacity is less than 5 then assign ticket
    void assign_ticket(int t_ID)
    {
        if (capacity > 5)
        {
            availability = false;
            cout << "Agent " << name << " has reached max capacity." << endl;
            return;
        }

        int *temp = new int[capacity + 1];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = assign_tickets[i];
        }

        temp[capacity] = t_ID;

        delete[] assign_tickets;
        assign_tickets = temp;
        capacity++;

        if (capacity >= 5)
        {
            availability = false;
        }

        cout << "Ticket " << t_ID << " has been assigned to agent " << name << endl;
    }
    void Display_Agent()
    {
        cout << "Agent ID: " << agent_id << endl;
        cout << "Name: " << name << endl;
        cout << ", Availability: " << endl;

        if (availability)
        {
            cout << " Status : Available " << endl;
        }
        else
        {
            cout << "Status : Unavailable " << endl;
        }

        if (capacity == 0)
        {
            cout << " Tickets Assigned : None";
        }
        else
        {
            cout << " Tickets Assigned : ";
            for (int i = 0; i < capacity; i++)
            {
                cout << assign_tickets[i] << " ";
            }
        }
        cout << endl;
    }
    int get_Capacity()
    {
        return capacity;
    }
    //Delete the assigned memory
    ~Agent()
    {
        delete[] assign_tickets;
    }
};

class Manage_Agent
{
public:
    Agent *agents;
    int counter;

    Manage_Agent()
    {
        counter = 0;
        agents = nullptr;
    }

    void Add_Agent(Agent a)
    {
        // Dynamically Allocate Menory
        Agent *temp = new Agent[counter + 1];
        for (int i = 0; i < counter; i++)
        {
            temp[i] = agents[i];
        }

        temp[counter] = a;

        delete[] agents;
        agents = temp;
        counter++;

        cout << "Agent Added with Name :  " << a.name << " and ID : " << a.agent_id << endl;
    }

    void Assign_Ticket(int id)
    {
        if (counter == 0)
        {
            cout << "No  Agents  are available to assign ticket" << endl;
            return;
        }

        int limit = 6;
        int index = -1;

        for (int i = 0; i < counter; i++)
        {
            if (agents[i].availability && agents[i].get_Capacity() < limit)
            {
                limit = agents[i].get_Capacity();
                index = i;
            }
        }

        if (index != -1)
        {
            agents[index].assign_ticket(id);
        }
        else
        {
            cout << "No  Agents  are available to assign ticket " << id << endl;
        }
    }
    int Binary_Search(Agent *a, int n, int key)
    {
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (a[mid].agent_id == key)
            {
                return mid;
            }
            if (a[mid].agent_id < key)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
    int Interpolation_Search(Agent *a, int n, int key)
    {
        int start = 0;
        int end = n - 1;

        while (start <= end && key >= a[start].agent_id && key <= a[end].agent_id)
        {
            if (start == end)
            {
                if (a[start].agent_id == key)
                {
                    return start;
                }
                return -1;
            }

            int pos = start + ((end - start) / (a[end].agent_id - a[start].agent_id) * (key - a[start].agent_id));

            if (a[pos].agent_id == key)
            {
                return pos;
            }

            if (a[pos].agent_id < key)
            {
                start = pos + 1;
            }
            else
            {
                end = pos - 1;
            }
        }
        return -1;
    }

    void Sort_Agent_By_Tickets()
    {
        for (int i = 0; i < counter - 1; i++)
        {
            for (int j = i + 1; j < counter; j++)
            {
                if (agents[i].get_Capacity() > agents[j].get_Capacity())
                {
                    Agent temp = agents[i];
                    agents[i] = agents[j];
                    agents[j] = temp;
                }
            }
        }
        cout << "Agents sorted by the number of assigned tickets." << endl;
    }
    void Sort_Agent_By_ID()
    {
        for (int i = 0; i < counter - 1; i++)
        {
            bool swapped = false;

            for (int j = i + 1; j < counter; j++)
            {
                if (agents[i].agent_id > agents[j].agent_id)
                {
                    Agent temp = agents[i];
                    agents[i] = agents[j];
                    agents[j] = temp;
                    swapped = true;
                }
            }

            if (!swapped)
            {
                break;
            }
        }
        cout << "Agents sorted by Agent ID." << endl;
    }
    void Display_All_Agents()
    {
        cout << "Agent Details:" << endl;
        for (int i = 0; i < counter; i++)
        {
            agents[i].Display_Agent();
        }
    }
    ~Manage_Agent()
    {
        delete[] agents;
    }
};

// Transcation Class ------------(Ticket Resolution Logs (Transaction Log)
class Transaction_Log
{
private:
    // class to refrain from STL
    class stack
    {
    public:
        int t_ID;
        string res_detail;
        stack *next;
    };

    // class to refrain from STL
    class queue
    {
    public:
        int t_ID;
        string name;
        int priority;
        queue *next;
    };

    stack *st_top;
    queue *st;
    queue *qr;

public:
    Transaction_Log()
    {
        st_top = nullptr;
        st = nullptr;
        qr = nullptr;
    }

    ~Transaction_Log()
    {

        while (st_top)
        {
            stack *ptr = st_top;
            st_top = st_top->next;
            delete ptr;
        }

        while (st)
        {
            queue *ptr = st;
            st = st->next;
            delete ptr;
        }
    }

    void Log_Closed_Ticket(int id, string res)
    {
        stack *newNode = new stack{id, res, st_top};
        st_top = newNode;
        cout << "Ticket " << id << " resolve and added to resolution log" << endl;
    }
    // Function to add a ticket to the pending queue based on priority
    void Add_Ticket_To_Pending_Queue(int id, string name, int p)
    {
        queue *New = new queue{id, name, p, nullptr};

        if (!st)
        {
            st = qr = New;
        }
        else
        {

            if (st->priority < p)
            {
                New->next = st;
                st = New;
            }
            else
            {
                queue *temp = st;
                while (temp->next && temp->next->priority >= p)
                {
                    temp = temp->next;
                }
                New->next = temp->next;
                temp->next = New;
                if (New->next == nullptr)
                {
                    qr = New;
                }
            }
        }
        cout << "Ticket " << id << " added to  queue with priority " << p << endl;
    }

    void Display_Log()
    {
        if (!st_top)
        {
            cout << "No  tickets to display" << endl;
            return;
        }
        stack *temp = st_top;
        while (temp)
        {
            cout << "Ticket ID: " << temp->t_ID << endl;
            cout << "Resolution: " << temp->res_detail << endl;
            temp = temp->next;
        }
    }

    void Display_Pending_Tickets()
    {
        if (!st)
        {
            cout << "No Tickets in Pending " << endl;
            return;
        };
        queue *ptr = st;
        while (ptr)
        {
            cout << "Ticket ID: " << ptr->t_ID << endl;
            cout << "Customer: " << ptr->name << endl;
            cout << " Priority: " << ptr->priority << endl;
            ptr = ptr->next;
        }
    }
    void Remove_From_Queue()
    {
        if (!st)
        {
            cout << "No Tickets  available" << endl;
            return;
        }

        queue *temp = st;
        st = st->next;
        if (!st)
        {
            qr = nullptr;
        }
        cout << "Ticket " << temp->t_ID << " dequeued from queue" << endl;
        delete temp;
    }
};

// Handles The Flow of whole program -------------(4. Reporting and Analytics)
class Report_Analytics
{

private:
    Manage_Agent manage;
    Stack res_st;
    Queue ticketpending;
    Transaction_Log tlog;
    Tickets t;
    string Searching_Algorithm;
    string Sorting_Algorithm;
    int threshold;

public:
    Report_Analytics(string search, string sort, int n)
    {
        Searching_Algorithm = search;
        Sorting_Algorithm = sort;
        threshold = n;
    }
    void Add_Ticket()
    {
        int ticket_id, priority;
        string customer_name, request_description;
        cout << "Enter Ticket ID: ";
        cin >> ticket_id;
        cout << "Enter Customer Name: ";
        cin >> customer_name;
        cout << "Enter Request Description: ";
        cin.ignore();
        getline(cin, request_description);
        t.Add_Ticket(ticket_id, customer_name, 0, request_description, 1);
        cout << "Ticket " << ticket_id << " added to the system.\n";
        if (t.Check_Ticket(ticket_id))
        {
            manage.Assign_Ticket(ticket_id);
            cout << "Ticket " << ticket_id << " assigned to an agent.\n";
        }
        else
        {
            cout << "No ticket with ID " << ticket_id << " exists.\n\n";
        }
    }
    void Remove_Tickets()
    {
        int ticket_id;
        cout << "Enter Ticket ID to remove: ";
        cin >> ticket_id;
        if (t.Check_Ticket(ticket_id))
        {
            t.Remove_Ticket(ticket_id);
            cout << "Ticket with ID " << ticket_id << " has been removed" << endl;
        }
        else
        {
            cout << "Ticket with ID " << ticket_id << " does not exist" << endl;
        }
    }
    void Search_For_Open_Tickets()
    {
        int id;
        cout << "Enter Ticket ID to Search :  " << endl;
        cin >> id;
        if (t.Check_Ticket(id))
        {
            t.Search_Ticket(id, Sorting_Algorithm, threshold, Searching_Algorithm);
        }
        else
        {
            cout << "Invalid Ticket" << endl;
        }
    }
    void Display_Tickets()
    {
        t.Display_Tickets();
    }
    void Add_Agent()
    {
        int agent_id;
        string agent_name;
        cout << "Enter Agent ID: ";
        cin >> agent_id;
        cout << "Enter Agent Name: ";
        cin >> agent_name;
        manage.Add_Agent(Agent(agent_id, agent_name));
    }
    void Sort_Agents()
    {
        if (manage.counter == 0)
        {
            cout << "No available agents\n";
            return;
        }
        cout << " 1 Sort by id press" << endl;
        cout << " 2 Sort by ticket count press " << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            manage.Sort_Agent_By_ID();
        }
        else
        {
            manage.Sort_Agent_By_Tickets();
        }
    }
    void Search_Agents()
    {

        cout << "Enter ID of the agent: ";
        int agent_id;
        cin >> agent_id;
        int found;
        manage.Sort_Agent_By_ID();
        if (Searching_Algorithm == "Interpolation_Search")
        {
            found = manage.Interpolation_Search(manage.agents, manage.counter, agent_id);
        }
        else if (Searching_Algorithm == "Binary_Search")
        {
            found = manage.Binary_Search(manage.agents, manage.counter, agent_id);
        }
        else
        {
            cout << "Invalid search choice." << endl;
        }

        if (found != -1)
        {
            cout << "Agent found: ";
            manage.agents[found].Display_Agent();
        }
        else
        {
            cout << "Agent with ID " << agent_id << " not found." << endl;
        }
    }
    void Display_Agent()
    {
        manage.Display_All_Agents();
    }
    void SortTickets()
    {
        int option;
        cout << "Enter : ";
        cout << "1 Sort by Time " << endl;
        cout << "3 Sort by Name" << endl;
        cout << "2 Sort by Priority" << endl;
        cin >> option;
        if (option >= 1 && option <= 3)
        {
            t.Sorting(option);
            cout << "Tickets sorted by priority level " << option << endl;
        }
    }
    void Enqueue_Ticket()
    {
        int ticket_id;
        cout << "Enter Ticket ID to enqueue: ";
        cin >> ticket_id;
        if (t.Check_Ticket(ticket_id))
        {
            ticketpending.enqueue(ticket_id);
            string name = ticketpending.getname(ticket_id);
            int p = ticketpending.getPriority(ticket_id);
            tlog.Add_Ticket_To_Pending_Queue(ticket_id, name, p);
            cout << "Ticket " << ticket_id << " added to pending queue" << endl;
        }
    }
    void Dequeue_Ticket()
    {
        tlog.Remove_From_Queue();
        ticketpending.dequeue();
    }
    void Display_Ticket_Pending()
    {
        ticketpending.display();
    }
    void Res_Log()
    {
        int ticket_id;
        string resolution_detail;
        cout << "Enter Ticket ID for resolution: ";
        cin >> ticket_id;
        cout << "Enter Resolution Detail: ";
        cin.ignore();
        getline(cin, resolution_detail);
        if (t.Check_Ticket(ticket_id))
        {
            res_st.push(ticket_id, resolution_detail);
            t.Remove_Ticket(ticket_id);
            cout << "Ticket " << ticket_id << " resolved and logged in resolution stack" << endl;
        }
        else
        {
            cout << "Ticket with ID " << ticket_id << " does not exist" << endl;
        }
    }
    void Ticket_Resolution_History()
    {
        res_st.display();
    }
};

// Read User by Default Searching and Sorting Algo i.e config file
/*There should be a configuration file where the user can specify which sorting and searching
algorithm will be used by default. When the items to be sorted are less than any threshold
(decide the threshold yourselves), the configured elementary sorting algorithm should be used.
Otherwise the configured Merge Sort or Quick Sort should be used when handling larger
datasets.*/

void Read_From_File(string &sorting, string &searching, int &threshold)
{
    ifstream fptr("config.txt");
    if (fptr.is_open())
    {
        string line;
        while (getline(fptr, line))
        {
            stringstream ss(line);
            string key, fetch;
            getline(ss, key, '=');
            getline(ss, fetch);
            if (key == "sorting_algo")
            {
                sorting = fetch;
            }
            else if (key == "searching_algo")
            {
                searching = fetch;
            }
            else if (key == "threshold")
            {
                threshold = stoi(fetch);
            }
        }
        fptr.close();
    }
}

int main()
{

    string searching_algo;
    string sorting_algo;
    int threshold;
    Read_From_File(sorting_algo, searching_algo, threshold);
    Report_Analytics r(searching_algo, sorting_algo, threshold);

    cout << "Sorting Algorithm: " << sorting_algo << endl;
    cout << "Searching Algorithm: " << searching_algo << endl;
    cout << "Threshold: " << threshold << endl;
    int ch;

    do
    {

        cout << "--------ABDULLAH KHAN (23K-0607)------------(BCS-3F)---------------" << endl;
        cout << "________________OPERATIONS__________WITH______TIME_COMPLEXITIES________" << endl;
        cout << "0 -> Exit Program" << endl;
        cout << "1 -> Add a Ticket --------------------------------- O(N)" << endl;
        cout << "2 -> Remove Ticket by ID--------------------------- O(N)" << endl;
        cout << "3 -> Find Open Ticket by ID------------------------ O(logN)" << endl;
        cout << "4 -> Show All Tickets------------------------------ O(N)" << endl;
        cout << "5 -> Add an Agent---------------------------------- O(N)" << endl;
        cout << "6 -> Sort Agents----------------------------------  O(N^2)" << endl;
        cout << "7 -> Find Agent------------------------------------ O(logN)" << endl;
        cout << "8 -> Show Agent Details---------------------------- O(N)" << endl;
        cout << "9 -> Sort Tickets-----------------------------------O(N^2)" << endl;
        cout << "10 -> Add Ticket to Pending------------------------ O(N)" << endl;
        cout << "11 -> Remove Ticket from Pending------------------- O(1)" << endl;
        cout << "12 -> Show Pending Tickets------------------------- O(N)" << endl;
        cout << "13 -> Add to Resolution Log------------------------ O(N)" << endl;
        cout << "14 -> Ticket_Resolution_History---------------------O(N)" << endl;

        cout << "Choose an option: ";

        cin >> ch;

        if (ch == 0)
        {
            cout << "Ending the program" << endl;
            return 0;
        }
        else if (ch == 1)
        {
            r.Add_Ticket();
        }
        else if (ch == 2)
        {
            r.Remove_Tickets();
        }
        else if (ch == 3)
        {
            r.Search_For_Open_Tickets();
        }
        else if (ch == 4)
        {
            r.Display_Tickets();
        }
        else if (ch == 5)
        {
            r.Add_Agent();
        }
        else if (ch == 6)
        {
            r.Sort_Agents();
        }
        else if (ch == 7)
        {
            r.Search_Agents();
        }
        else if (ch == 8)
        {
            r.Display_Agent();
        }
        else if (ch == 9)
        {
            r.SortTickets();
        }
        else if (ch == 10)
        {
            r.Enqueue_Ticket();
        }
        else if (ch == 11)
        {
            r.Dequeue_Ticket();
        }
        else if (ch == 12)
        {
            r.Display_Ticket_Pending();
        }
        else if (ch == 13)
        {
            r.Res_Log();
        }
        else if (ch == 14)
        {
            r.Ticket_Resolution_History();
        }
        else
        {
            cout << "Invalid choice. Please try again" << endl;
        }
    } while (ch != 0);
}
