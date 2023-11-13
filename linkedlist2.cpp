 #include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    n * next;
};

typedef n node;

void bastir(node * r){ 
    while (r != NULL){
        printf("%d ", r->x);
        r = r->next;
    }
    
}

void ekle(node *r, int x){
    while(r->next != NULL){
        r = r->next;
    };
    r->next = (node *)malloc(sizeof(node));
    r->next-> x = x;
    r->next->next = NULL;
 } 

node * ekleSirali(node *r, int x){
    if(r==NULL){ //linkedlist boşsa
        r=(node *)malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        return r;
    }
    if (r->x > x){ // ilk elemandan küçükse, root değişiyor
            node * temp = (node *)malloc(sizeof(node));
            temp-> x = x;
            temp ->next = r;
            return temp;
    }
    node * iter = r;
    while (iter->next !=NULL && iter->next->x < x){
        iter = iter->next;    
    }
        node * temp = (node *)malloc(sizeof(node));
        temp ->next = iter->next;
        iter ->next = temp;
        temp ->x = x; 
        return r;
    
    /*
    if (r->next = NULL){
        else{
            node * temp = (node *)malloc(sizeof(node));
                temp-> x = x;
                temp ->next = NULL;
                r->next = temp;
                return r;
        }
    }
    */
}

int main(){
    node * root;
    root = NULL;
    /*
    root = (node*)malloc(sizeof(node));
    root -> next = NULL;
    root -> x = 500;
    
    int i=0; 
    for(i=0;i<5;i++){
        ekle(root, i*10);
        
        iter->next = (node *)malloc(sizeof(node));
        iter = iter->next;
        iter->x = i*10;
        iter->next = NULL; 
        }
        */
    root = ekleSirali(root,400);
    root = ekleSirali(root,40);
    root = ekleSirali(root,4);
    root = ekleSirali(root,450);
    root = ekleSirali(root,50);
    bastir(root);
    /*
    node * iter = root;
    for(i = 0; i<3;i++)
        iter = iter->next;
    node * temp = (node *)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp-> x = 100;
    bastir(root);
    */
}