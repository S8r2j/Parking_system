#include <iostream>
#include <string>

#define max_size 5
using namespace std;

int i=0;

class parking_system
{
private:
    string name;
    string car_num;
    int age;
    int plot_num=1;
    struct navail_list{                                                 //this contains the parking slot that are not available
        int slot_num=0;
        struct navail_list* next= NULL;
    };
    struct navail_list* head0= new navail_list();                       //head0 is the pointer that always denotes the very first node of the list
    struct navail_list* ptr1= new navail_list();
    struct navail_list* ptr2= new navail_list();
public:
    int count=0;
    parking_system *next=NULL;
    parking_system* entry_point()                                       //this function takes the data from the driver and allocates him the parking slot number
    {
        parking_system *p;
        int k=0;
        if(plot_num<=max_size)
        {
            p=new parking_system();
            cout<<"Enter the driver's name: "<<"\n";
            getline(cin>>ws,p->name);
            cout<<p->name<<endl;
            cout<<"Enter the driver's age: "<<endl;
            cin>>p->age;
            cout<<"Enter the car number: "<<endl;
            cin.ignore();
            getline(cin>>ws,p->car_num);
            cout<<p->car_num<<endl;
            struct navail_list* node=new navail_list();
            p->plot_num = plot_num;
            node->slot_num=plot_num;
            if(i==0)
            {
                ptr1=node;
                head0=ptr1;
                i=i+1;
                cout<<head0->slot_num<<"\n";
            }
            else
            {
                ptr1->next=node;
                ptr1=ptr1->next;
                cout<<ptr1->slot_num<<"\n";
            }
            plot_num=plot_num+1;
            display2();                                                         //called the function to show the list of non available slots
            cout << "Your parking slot number is: " << p->plot_num << endl;
        }
        else if(plot_num>max_size) {
            cout << "Plot number exceed max size" << "\n";
            ptr2 = head0;
            for (int j = 1; j <= max_size; j++) {
                while (ptr2 != NULL) {
                    if ((ptr2->slot_num) == j) {
                        k = 0;
                        break;
                    } else
                        k = j;
                    ptr2 = ptr2->next;
                }
            }
            if (k == 0) {
                cout << "All parking slots are full" << "\n";
            } else {
                p = new parking_system();
                cout << "Enter the driver's name: " << "\n";
                getline(cin >> ws, p->name);
                cout << p->name << endl;
                cout << "Enter the driver's age: " << endl;
                cin >> p->age;
                cout << "Enter the car number: " << endl;
                cin.ignore();
                getline(cin >> ws, p->car_num);
                cout << p->car_num << endl;
                plot_num = k;
                struct navail_list *node = new navail_list();
                p->count = k;
                p->plot_num = plot_num;
                node->slot_num = plot_num;
                ptr1 = head0;
                while ((ptr1->next) = NULL) {
                    ptr1 = ptr1->next;
                }
                ptr1->next = node;
                cout << ptr1->slot_num << "\n";
                cout << "Your parking slot number is: " << p->plot_num << endl;
            }
        }
        return p;
    }
    void display2()                                                             //this displays the list of slots that are not available
    {
        ptr2=head0;
        while(ptr2!=NULL)
        {
            cout<<ptr2->slot_num<<"\t";
            ptr2=ptr2->next;
        }
        cout<<"\n";
    }
    void leave_point(parking_system* head) {
        cout << "Enter the allocated parking slot number: " << "\n";
        int key;
        cin >> key;
        ptr1 = head0;
        if (key != head0->slot_num) {
            while (key != (ptr1->slot_num)) {
                ptr2 = ptr1;
                ptr1 = ptr1->next;
            }
            ptr2->next = ptr1->next;
        } else {
            head0 = head0->next;
        }
        parking_system *str = new parking_system();
        parking_system *str1 = new parking_system();
        str = head;
        if (key == head->plot_num)  {
            str = head;
            head = head->next;
        } else {
            while (str != NULL and key != str->plot_num) {
                str1 = str;
                str = str->next;
            }
        }
        if (str == NULL) {
            cout << "Please enter the parking slot number carefully" << "\n";
        } else {
            str1->next = str->next;
            cout << "Vehicle that has left: " << "\n";
            cout << str->name << "-------" << str->age << "-------" << str->car_num << "\n";
            str = head;
            cout << "Vehicles that are still in the parking area: " << "\n";
            while (str != NULL) {
                str->display();
                str = str->next;
            }
        }
    }
    void display()                                                              //this displays the data of the number of cars that are parked in the parking area
    {
        cout << "Name= " << name << "---------" << "Car Number= " << car_num << "---------" << "Age= " << age
             << "\n";
    }
};
parking_system *head= new parking_system();
int main()
{
    int l=0;
    parking_system *p1, *p, *ptr;
    p=new parking_system();
    p1=new parking_system();
    ptr=new parking_system();
    while(1)
    {
        string decision;
        cout << "Want to park or leave?(Enter either 'park' or 'leave')" << "\n";
        getline(cin>>ws,decision);
        if(decision == "park")
        {
            if(l<=0)  {
                p = p1->entry_point();
                head =p;
                l = l + 1;
            }
            else
            {
                if(p1->count==0) {
                    p->next = p1->entry_point();
                    p = p->next;
                }
                else
                {
                    ptr=head;
                    p=p1->entry_point();
                    for(int j=1;j<(p->count);j++)
                    {
                        ptr=ptr->next;
                    }
                    p->next=ptr->next;
                    ptr->next=p;
                }
            }
        }
        else if (decision == "leave")
        {
            p1->leave_point(head);
        }
        else
        {
            cout<<"Please enter a valid command"<<"\n";
        }
    }
}