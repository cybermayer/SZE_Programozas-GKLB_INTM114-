/*

5. struktúrát egyszeresen láncolt lista létrehozásához. 
Készítse el azt a dataStuct* deleteOnCondition(dataStruct* head, int min) függvényt, 
ami kitörli a listából azokat az elemeket, melyek szam tagja min-nél kisebb. 
A visszatérési érték a módosított lista horgonya legyen!

*/

#pragma region<include>                                                                     //INCLUDE

    #include<iostream>

    using namespace std;

#pragma endregion<include>

struct dataStruct{                                                                          //STRUCT DECLARATION
    int data;
    dataStruct* next;
};

dataStruct* createList(int* list, int size){                                                //Create linked list from static list   
    int i=0;
    dataStruct* act=new dataStruct;
    dataStruct*  head=act;
    while(i < size){
       act->data=list[i];
        act->next=(i<size-1)? new dataStruct : nullptr;
        act = act->next;
        i++;       
    }
    
    return head;
}               

void printLL(dataStruct* head){                                                             //Print linked list

    dataStruct* act=head;
    while(act!=nullptr){
        cout << act->data << " ";
        act=act->next;
    }
    cout << endl;
}

void deleteLL(dataStruct* head){                                                            //Deallocate memory

    dataStruct* act=head;
    dataStruct* to_delete;
    while(act!=nullptr){
        to_delete=act;
        act = act->next;
        delete to_delete;
    }
}

dataStruct* deleteOnCondition(dataStruct* head, int min){                                   //Delete elements holding smaller value than min

    dataStruct* to_delete;
    dataStruct* act = head;
    dataStruct* recent_good=nullptr;
    head = nullptr;

    while(act!=nullptr){        
        if ((act->data)>=min){
            if (head==nullptr){head=act;};
            recent_good=act;
            act=act->next;
        } else {
            to_delete = act;
            act = act->next;
            if (recent_good!=nullptr){recent_good->next=act;};
            delete to_delete;
        }        
    }   
    return head;
}                                   

int main(){                                                                                 //MAIN

    int list1[8] = {4, 5, 6, 2, 1, 1, 7, 2};
    int list2[8] = {1, 2, 5, 7, 8, 8, 1, 9};

    dataStruct* LL1 = createList(list1, 8);
    dataStruct* LL2 = createList(list2, 8);
    
    printLL(LL1);
    dataStruct* newLL1 = deleteOnCondition(LL1, 3);
    printLL(newLL1);
    deleteLL(newLL1);

    cout << endl;

    printLL(LL2);
    dataStruct* newLL2 = deleteOnCondition(LL2, 3);
    printLL(newLL2);
    deleteLL(newLL2);
    
    return 0;
}
