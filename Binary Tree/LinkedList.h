using namespace std;

class Node{
public:
  int data;
  Node *next=NULL;
  Node(int data){
    this->data = data;
  }
};
void display(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

//

Node* inputLinkedList(){
  Node* head = NULL;
  Node* tail = NULL;
  int data;
  cin>>data;
  while(data != -1){
    Node* newnode = new Node(data);
    if(head == NULL){
      head = newnode;
      tail = newnode;
    }
    else{
      tail->next = newnode;
      tail = newnode;
    }
    cin>>data;
  }
  return head;
}
Node* insert(Node* head,int index,int data){
  Node *node = new Node(data);
  Node* temp = head;
  if(index==0){
    node->next = head;
    head = node;
    return head;
  }
  int count=0;
  while(count < index-1 && temp!= NULL){
    temp = temp->next;
    count++;
  }
  if(temp!= NULL){
    node->next = temp->next;
    temp->next = node;
    return head;
  }
  else return head;
}
Node* reverse(Node* head){
  Node* tail = head->next;
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* out = reverse(head->next);
  tail->next = head;
  head->next = NULL;
  return out;
}
