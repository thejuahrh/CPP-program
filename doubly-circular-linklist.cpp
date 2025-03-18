#include<iostream>
using namespace std;
class Node
{
  public:

    Node* prevLink;
    int data;
    Node* link;

  Node()
    {

    }
  Node(int data)
    {
      prevLink = NULL;
      this->data = data;
      link = NULL;
    }
  ~Node()
     {
       cout<<"Nodes deleted!"<<endl;
     }
};

class DoublyCirclarList
{
  Node* head;
  Node* tail;
  Node* lastNode;
  int countNode;

 public:

   DoublyCirclarList()
     {
       head = NULL;
       tail = NULL;
       lastNode = NULL;
       countNode =0;
     }
  void prepandNode()
     {
       int predata;

       cout<<"Enter the data:";
       cin>>predata;
       Node* prevNode = new Node(predata);

        if(head == NULL && tail == NULL)
            {
              head = prevNode;
              tail = prevNode;
              lastNode = prevNode;

              head->link = head;
              tail->prevLink = tail;
              cout<<"Head node prepende"<<endl;
              countNode++;
              //cout<<"prenode Head count:"<<countNode<<endl;
            }
        else
            {
              prevNode->link = head;
              prevNode->prevLink = tail;

              head->prevLink = prevNode;
              tail->link = prevNode;
              head = prevNode;
              cout<<"Node prepended!"<<endl;
              countNode++;
              //cout<<"prenode temp count:"<<countNode<<endl;
            }
     }
  void appendNode()
     {
       int data;

       cout<<"Enter the data:";
       cin>>data;
       Node* apNode = new Node(data);

       if(head == NULL)
          {
            head = apNode;
            tail = apNode;
            lastNode = apNode;

            head->link = head;
            head->prevLink = tail;
            cout<<"Head node appende"<<endl;
            countNode++;
          }
       else
          {
            Node* temp = head;
            while(temp->link!=head)
                {
                   temp = temp->link;
                }
             temp->link = apNode;
             tail = apNode;
             tail->prevLink = temp;
             tail->link = head;
             head->prevLink = tail;
             cout<<"Node appended!"<<endl;
             countNode++;
          }
     }
   void insertNode()/////////////////////////////////INSERT NODES//////
     {
        int beforeData,afterData;
        Node* beforeNode = NULL;
        Node* afterNode =NULL;

        if(head == NULL)
           {
              int insertData;
              cout<<"Enter the data:";
              cin>>insertData;
              Node* insNode = new Node(insertData);
              head = insNode;
              tail=head;

              lastNode = head;
              head->link = head;
              head->prevLink = tail;
              cout<<"Head node appende"<<endl;
              countNode++;

           }
        else
            {
                int insertData;
                cout<<"Enter the data:";
                cin>>insertData;
                Node* insNode = new Node(insertData);
                cout<<"Enter the before data:";
                cin>>beforeData;
                cout<<"Enter the after data:";
                cin>>afterData;

                Node* temp = head;
                do
                  {
                    if(temp->data == beforeData)
                      {
                        cout<<"First data:"<<temp->data<<endl;
                        beforeNode = temp;
                        cout<<"Before:"<<beforeNode->data<<endl;
                      }

                    if(temp->data == afterData)
                      {
                        cout<<"First data:"<<temp->data<<endl;
                        afterNode = temp;
                        cout<<"After:"<<afterNode->data<<endl;
                      }

                    temp = temp->link;

                  }while(temp!=head);

                  insNode->prevLink = beforeNode;
                  beforeNode->link = insNode;

                  insNode->link = afterNode;
                  afterNode->prevLink = insNode;
                  cout<<"Data "<<insertData<<" inserted"<<endl;
                  countNode++;
          }
     }
   void displayNode()/////////////////////////////////DISPLAYING NODES//////
     {
        if(head == NULL)
	        {
	          cout<<"List is empty!"<<endl;
	        }
         else
	        {
              string opt;
              cout<<"Enter the option for dispaly"<<endl;
              cout<<"Type(a) for forward display ||Type(b) for backward display :";
              cin>>opt;

              if(opt == "a")
                 {
                    int startNum,endNum;
                    Node* startNode,*endNode;
                    cout<<"Enter the Starting number:";
                    cin>>startNum;
                    cout<<"Enter the Ending number:";
                    cin>>endNum;

                    Node* temp = head;
                    do
                      {
                        if(startNum == temp->data)
                            {
                              startNode = temp;
                            }
                        if(endNum == temp->data)
                            {
                                endNode = temp;
                            }
                        temp = temp->link;
                      }while(temp!=head);

                      Node* travel = startNode;

                          do{
                            cout<<travel->data<<endl;
                            travel = travel->link;

                          }while(travel!=endNode->link);

		              }
	              else if(opt == "b")
		              {
                    int startNum,endNum;
                    Node* startNode,*endNode;
                    cout<<"Enter the Ending number:";
                    cin>>endNum;
                    cout<<"Enter the Starting number:";
                    cin>>startNum;

		                Node* temp = tail;
                    do
                      {
                        if(startNum == temp->data)
                            {
                              startNode = temp;
                            }
                        if(endNum == temp->data)
                            {
                                endNode = temp;
                            }
                        temp = temp->prevLink;

                      }while(temp!=head);

		                  Node* travel = endNode;

                      do{
                        cout<<travel->data<<endl;
                        travel = travel->prevLink;

                      }while(travel!=startNode->prevLink);

		              }
           }
     }
   void deleteNode()
      {
        int deleData;
        cout<<"Enter the number to be delete:";
        cin>>deleData;

        if(countNode == 1)
           {

             if(head->data == deleData)
                {

                   lastNode = head;
                   head = NULL;
                   delete(lastNode);
                   countNode--;
                   cout<<"Last Node deleted!"<<endl;
                }
           }
        else
            {
              if(deleData == head->data)
                {
                  Node* deleteNode = head;
                  head  = head->link;
                  head->prevLink = tail;
                  tail->link = head;
                  delete(deleteNode);
                  cout<<"Head Node deleted!"<<endl ;
                  countNode--;

                }
              else if(deleData == tail->data)
                {
                  Node* deleteNode = tail;
                  tail = tail->prevLink;
                  tail->link = head;
                  head->prevLink = tail;
                  delete(deleteNode);
                  cout<<"Tail Node deleted!"<<endl ;
                  countNode--;

                }
              else
                {
                  Node* deleNode;
                  Node* temp = head;

                  while(temp!=tail)
                      {

                        if(deleData == (temp->data))
                            {

                              deleNode = temp;
                              temp->link->prevLink = temp->prevLink;
                              temp->prevLink->link = temp->link;
                              delete(deleNode);
                              cout<<"Node deleted!"<<endl;
                              countNode--;
                            }

                            temp = temp->link;
                      }
                }
            }
      }
   void display()
      {
        if(head == NULL)
          {
            cout<<"List is empty!"<<endl;
          }
        else
          {
              string opt;
              cout<<"(a) for forward display"<<endl;
              cout<<"(b) for backward display"<<endl;
              cout<<"Enter the option for display :";
              cin>>opt;
              if(opt == "a")
                 {
                    Node* temp =head;
                    do
                      {
                        cout<<temp->data<<endl;
                        temp = temp->link;
                      }while(temp!=head);

                    cout<<"Count:"<<countNode<<endl;
                }
              else if(opt == "b")
                 {
                    Node* temp =tail;
	                  do
		                  {
                        cout<<temp->data<<endl;
                        temp = temp->prevLink;
                      }while(temp!=tail);

        	            cout<<"Count:"<<countNode<<endl;
                 }
              else
                 {
                   cout<<"Invalid option!"<<endl;
                 }

          }
        //  cout<<"last node data:"<<lastNode->data<<endl;
       }
};

int main()
{
  DoublyCirclarList dcl;
  Node* n = new Node();

  string* option = new string();
  bool stop = true;

  cout<<"Type (pre) for Prepend Node"<<endl;
  cout<<"Type (app) for Append Node"<<endl;
  cout<<"Type (ins) for Insert Node"<<endl;
  cout<<"Type (dele) for Delete Node"<<endl;
  cout<<"Type (dis) for Display Node"<<endl;
  cout<<"Type (qut) for Quit"<<endl;

  while(stop)
      {
        cout<<"Enter the option:";
        cin>>*(option);
         if(*(option) == "app")
            {
               dcl.appendNode();
            }
         else if(*(option) == "pre")
            {
              dcl.prepandNode();
            }
         else if(*(option) == "ins")
            {
               dcl.insertNode();
            }
         else if(*(option) == "dis")
            {
               string choice;
               cout<<"(n) for normal display"<<endl;
               cout<<"(co) for custom display"<<endl;
               cout<<"Enter the option:";
               cin>>choice;
               if(choice == "n")
                  {
                    dcl.display();
                  }
               else if(choice == "co")
                  {
                    dcl.displayNode();
                  }
               else
                  {
                    cout<<"No such option!"<<endl;
                  }
            }
         else if(*(option) == "dele")
            {
               dcl.deleteNode();
            }
         else if(*(option) == "qut")
            {
               stop = false;
               delete n;
            }
         else
            {
              cout<<"Invalid option!"<<endl;
            }
      }

  return 0;
}
