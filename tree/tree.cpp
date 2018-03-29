#include <iostream>
using namespace std;

class tree {
public:
  double value;
  string type;
  tree* child = NULL;
  tree* next = NULL;
};

void add(tree* tree1,tree* tree2){
  if(tree2->type == "node"){
    tree1->next = tree2;
  }
  if(tree2->type == "tree"){
    tree1->child = tree2;
  }
};

void remove(tree* tree1,tree* tree2){
  if(tree2 == tree1->next){
    tree1->next = NULL;
  }
  if(tree2 == tree1->child){
    tree1->child = NULL;
  }
}

void show_(tree* tree){
  if(tree->next != NULL){
    cout << tree->next->value << " ";
    show_(tree->next);
  }
  if(tree->child != NULL){
    cout << "(";
    show_(tree->child);
    cout << ")";
  }
}

void show(tree* tree){
  cout << "(";
  show_(tree);
  cout << ")" << endl;
}

int main(){
  tree tree1;
  tree1.type = "tree";

  tree node1;
  node1.type = "node";
  node1.value = 25;
  add(&tree1,&node1);

  tree node2;
  node2.type = "node";
  node2.value = 30;
  add(&node1,&node2);

  tree tree2;
  tree2.type = "tree";
  add(&node2,&tree2);

  tree node3;
  node3.type = "node";
  node3.value = 5;
  add(&tree2,&node3);

  show(&tree1);

  return 0;
}
