#include <bits/stdc++.h>

using namespace std;

class Process
{
    string processName, memory;
    int ID;

public:
    Process(string processName, string memory, int ID)
    {
        this->processName = processName;
        this->memory = memory;
        this->ID = ID;
    }

    string getName()
    {
        return processName;
    }
    string getMemory()
    {
        return memory;
    }
    int getID()
    {
        return ID;
    }
};

class TaskManager
{
    vector<Process> pList;
public:
    vector<Process>& get_list(){
        return pList;
    }
    void set_list(vector<Process>s){
        pList=s;
    }
    void addProcess(Process p)
    {
        pList.push_back(p);
    }
    void print()
    {
        cout << left << setw(30) << "Procces Name" << right << setw(10) << "Procces ID" << setw(10) << "Memory" << '\n';     
        for(auto i : pList)
        {
            cout << left << setw(30) << i.getName();
            cout << setw(14) << i.getID() ;
            cout << setw(10) << i.getMemory() ;
            cout << '\n';
        }
    }
    void sortByID(){
        sort(pList.begin(), pList.end(), [](Process &p , Process &r){ return p.getID()<r.getID();});
    }
    void sortMomery(){
        sort(pList.begin(), pList.end(), [](Process &p , Process &r){ 
                string r1 , r2;
                r1=p.getMemory();
                r2 = r.getMemory();
                double num , num2 , mem1 , mem2;
                r1= r1.substr(0,r1.size()-1);
                stringstream geek(r1);
                geek>> num;
                mem1=num;
                r2= r2.substr(0,r2.size()-1);
                stringstream geek1(r2);
                geek1>> num2;
                mem2=num2;



            return  mem1<mem2;
            
            
            });
    }
    void sortNames(){
        sort(pList.begin(), pList.end(), [](Process &p , Process &r){ return tolower(p.getName()[0])<tolower(r.getName()[0]);});
    }
    vector<Process> load_from_file(fstream& file){
        vector<Process> pro;
        file.open("TaskManager.txt", ios::out | ios::in | ios::app);
        string name="" , momery, line,word;
        int id,count1=1 , count2=1, num=0;
        while(getline(file, line)){
            name="";
            count2=1;
            if(count1>2){
            stringstream s(line);
            while(s>>word){
                if((word[0]<48 or word[0]>57) and count2==1){
                name = name + " " + word;
                }
                else{
                    count2++;
                    if(count2==2){
                        stringstream geek(word);
                        geek>> num;
                        id=num;
                    }
                    if(count2==3 or count2==4){
                        continue;
                    }
                    if(count2==5){
                        momery= word;
                    }
                    if(count2==6){
                        momery=momery + word;
                    }
                }

            }
            name=name.substr(1);
            pro.push_back(Process(name , momery,id));
            }
            count1++;
            

        }

        file.close();
        return pro;
    }
    
};


int main()
{
    TaskManager tm;
    fstream file;
    tm.set_list( tm.load_from_file(file));
    tm.print();
    cout<<"*********************************************************"<<endl;
    cout<<"---------------------"<<"Sort By memory"<<"-------------------------"<<endl;
    tm.sortMomery();
    tm.print();
    cout<<"*********************************************************"<<endl;
    cout<<"----------------------------"<<"sort By ID"<<"--------------------------"<<endl;
    tm.sortByID();
    tm.print();
    cout<<"*********************************************************"<<endl;
    cout<<"------------------------"<<"Sort By Names"<<"------------------------"<<endl;
    tm.sortNames();
    tm.print();
   
}