
#include<iostream>
#include<queue>
using namespace std;
class node{
public:
int data;
node*left;
node*right;
node*parent;
node(int value){
data=value;
left=NULL;
right=NULL;
parent=NULL;
}
};
class BST{
public:
node*root;
//constructor
BST(){
root=NULL;
}
void insert1(node*current,int value){
if(current==NULL){current=new node(value);
root=current;
root->parent=NULL;
//return root;
}
else if(value>current->data){
    if(current->right==NULL){current->right=new node(value);
       current->right->parent=current;
    }
    else insert1(current->right,value);
}
else{
    if(current->left==NULL){current->left=new node(value);
    current->left->parent=current;
    }
    else insert1(current->left,value);
}
}
void insert(int value){
insert1(root,value);
}
void display1(node*current){
if(current==NULL) return;
display1(current->left);
cout<<current->data<<"  ";
 display1(current->right);
}
void display(){
display1(root);
cout<<endl;
}
bool search3(node*current,int value){
if(current==NULL){return false;}
else if(current->data==value)
{return true;}
else if(value>current->data) return search3(current->right,value);
else if(value<current->data) return search3(current->left,value);
}
void search(int value){
    if(search3(root,value)==1)
    cout<<endl<<"the element "<<value<<" is  found in the binary search tree  ";
    else
        cout<<" The element  "<<value<<" is not found  ";
}
//function to find minimum of all values
 node*findmin1(node*current){
//take current as argument
if(current->left==NULL)
    {return current;}
else return findmin1(current->left);
}
//function to return address of min node
node* findmin(){
return findmin1(root);
}
//return min element of BST
int min(){
return findmin1(root)->data;}

//function to find the no of element present in the BST
int counte(node*current){
if(current==NULL)return 0;
else if(current!=NULL)
  return 1+counte(current->left)+counte(current->right);
}
int count(){
return counte(root);
}
/*
void replace1(node*current,node*temp){

int x=temp->data;
temp->data=current->data;
current->data=x;
}
//void replace(node*current,int value){
node*temp=new node(value);
replace1(current,temp);
}
*/
/*
void Delete(node*current,int value){
if(root=NULL){
    cout<<endl<<"we can not delete element as no element is there  "<<endl;
}
if(root!=NULL){
 if(current->left==NULL && current->right==NULL)
    replace1(current,NULL);
else if(current->left=NULL){
    replace1(current,current->right);
    delete current->data;
}
else if(current->right)
    replace1(current,current->left);
else{
   node*temp=findmin1(current->right);
   delete findmin(current->right);
   replace1(current,temp);
}
}
}
void deletee(int value){
Delete(root,value);
}*/


/*/delete element of binary search tree
node* delete1(node*current,int value){
if(root==NULL) return root;
else if(value<current->data) current->left=delete1(current->left,value);
else if(value>current->data) current->right=delete1(current->right,value);
if(current->data==value){
    //desired element
    //CASE-------1
    if(current->left==NULL && current->right==NULL){
        delete current;
        current=NULL;
        return current;
    }
    //CASE--------2
    else if(current->left==NULL){
        node*temp=current;
        current=current->right;
        delete temp;
    }

    else if(current->right==NULL){
        node*temp=current;
        current=current->left;
        delete temp;
    }
   //CASE---------3
   else{
    node*temp=findmin1(current->right);
    node*as=current;
    current->data=temp->data;
     current->right=delete1(current->right,temp->data);
   }
}
  return current;
}




//function to delete elements
node* deletee(node*current,int value){
if(root==NULL) return root;
else if(value>current->data) current->right=deletee(current->right,value);
else if(value<current->data) current->left=deletee(current->left,value);
else{
    //case -------------------------------------------------1
    if(current->right==NULL && current->right==NULL){
        delete current;
        current=NULL;
        return current;
        }
//case------------------------------------------------------2
    else if(current->left==NULL){
        node*temp=current;
        current=current->right;
        delete temp;

    }
    else if(current->right==NULL){

       node*temp=current;
        current=current->left;
        delete temp;
    }
else{
    node*temp=findmin1(current->right);
    current->data=temp->data;
    current->right=deletee(current->right,temp->data);
}
}return current;

}
*/
void replace(node*current,node*child){
if(current->parent!=NULL){
if(current->parent->left==current) {current->parent->left=child;

}
if(current->parent->right==current){current->parent->right=child;
}
}
if(child!=NULL)
child->parent=current->parent;
}
void deletee(node*current,int value){
if(current==NULL) return;
else if(value>current->data) {deletee(current->right,value);
    return;
    }
else if(value<current->data) {deletee(current->left,value);
  return;}
else{
    if(current->left==NULL &&current->right==NULL){
        replace(current,NULL);
       // if(root==current) root=NULL;
}
else if(current->right==NULL){
    replace(current,current->left);
    //if(current==root) root=root->left;
}
else if(current->left==NULL){ replace(current,current->right);
// if(current==root) root=root->right;
}
else{
    node*temp=findmin1(current->right);
    current->data=temp->data;
    deletee(temp,temp->data);
}
}
}
void Delete(int value){
if(search3(root,value)==1)
deletee(root,value);
else
    cout<<" entered no "<<value<<" is invalid"<<endl;
}




//print BST in two dimension
void print2D(node*current,int space){
//base case
if(current==NULL)
    return;
space+=count();
//process right child first
print2D(current->right,space);
//print current node after space count
cout<<endl;
for(int i=count();i<space;i++)
    cout<<" ";
    cout<<current->data;
//process left child
print2D(current->left,space);

}
void print2d(){
print2D(root,0);
}


void levdisplay(node*current){
    if(current==NULL || root==NULL)
        return;
    queue<node*>q;
    q.push(current);
    while(!q.empty()){
        node*current=q.front();
        cout<<current->data<<"  ";
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        q.pop();
    }
}


//function to find the height of
int maximum(int a,int b){
if(a>b)return b;
else return a;
}
int height(node*current){
if(root==NULL) return 0;
else if(current==NULL) return 0;
else{
    int lh=height(current->left)+1;
    int rh=height(current->right)+1;

return lh>rh?lh:rh;

}
}
void Height(){
  cout<<"  the height of tree is "<<height(root)<<endl;
}


//function to print the number between given range
void rangeprint(int value1,int value2,node*current){
    if(current==NULL) return;
 if(current->data>value1) rangeprint(value1,value2,current->left);
    if(value1<=current->data && value2>=current->data){
    cout<<current->data<< "  ";
   }
if(value2>current->data)
    rangeprint(value1,value2,current->right);

}
void Rprint(int val1,int val2){
rangeprint(val1,val2,root);
}

//function to count the leaf node of BST

 int leafcount(node*current){
 if(current==NULL)return 0;
 if(current->right==NULL && current->left==NULL) return 1;
 else return leafcount(current->right)+leafcount(current->left);
 }

//function to print the data of leaf nodes of BST
void leaf_datadisplay(node*current){
//base case
if(current==NULL) return;
else if(current->right==NULL && current->left==NULL){
    cout<<"  "<<current->data<<"  ";
}
else{
    leaf_datadisplay(current->left);
    leaf_datadisplay(current->right);
}

}










};

int main(){
BST b;
b.insert(2);
b.insert(3);
b.insert(4);
b.insert(4);
b.insert(4);
b.insert(4);
b.insert(4);
b.insert(4);
b.insert(4);
b.insert(18);
b.insert(17);
b.insert(16);
b.insert(15);
b.display();
b.Delete(4);
b.display();
b.Delete(15);
b.display();
b.search(5);
cout<<"the minimum element is :"<<b.findmin()->data<<b.min()<<endl;
cout<<"the no of element is :"<<b.count()<<endl;

cout<<endl<<"the root of tree is  "<<b.root->data<<endl;
b.print2d();
//b.replace(b.root,4);
b.print2d();
cout<<endl;
b.display();
b.levdisplay(b.root);
cout<<endl;
b.Delete(1);
b.display();
b.Delete(4);
b.display();
b.Height();
b.print2d();

cout<<endl<<"the root is "<<b.root->data<<endl;
//
//function to print in between two range
b.Rprint(5,14);

cout<<endl<<"the number of leaf nodes is  "<<b.leafcount(b.root)<<endl;
cout<<"the data of leaf nodes are  :";
b.leaf_datadisplay(b.root);
return 0;
}

