#include <iostream>
#include <random>
#include <unistd.h>
#include <omp.h>
#include <stdio.h>

using namespace std;

int select(){
        random_device rnd;
        mt19937 mt(rnd());
        uniform_int_distribution<> rand100(0, 3);
        return rand100(mt);
}

float Eatingtime(){
        random_device rand;
        return (float)rand()/RAND_MAX;
}

float Thinkingtime(){
        random_device rand;
        return (float)rand()/RAND_MAX;
}

class man {
string name;
int left_hand = 0;
int right_hand = 0;
man *prev_man;
man *next_man;

void take(){
        while(1) {
                if(prev_man->right_hand == 0 && left_hand == 0) {
                        left_hand = 1;
                        printf("%s picks left fork\n",name.c_str());
                }
                if(next_man->left_hand == 0 && right_hand == 0) {
                        right_hand = 1;
                        printf("%s picks right fork\n",name.c_str());
                }
                if(left_hand==1 && prev_man->left_hand==1 && prev_man->prev_man->left_hand==1 && prev_man->prev_man->prev_man->left_hand==1) {
                        printf("dead lock!\n");
                        exit(1);
                }
                if(left_hand==1 && right_hand==1) break;
        }
}
void put(){
        left_hand = 0;
        printf("%s puts left fork\n",name.c_str());
        right_hand = 0;
        printf("%s puts right fork\n",name.c_str());
}

public:
int state;
void set_man(string B, man *A, man *C){
        name = B;
        prev_man = A;
        next_man = C;
}

void eat(){
        state = 1;
        take();
        printf("%s is eating\n",name.c_str());
        usleep(Eatingtime());
        put();
        printf("%s is thinking\n",name.c_str());
        usleep(Thinkingtime());
        state = 0;
}
int left(){
        if (left_hand==1) return 1;
}
};

int main(){
        man A,B,C,D;
        A.set_man("A",&D,&B);
        B.set_man("B",&A,&C);
        C.set_man("C",&B,&D);
        D.set_man("D",&C,&A);

        int num = 10000;
        int index;

        int n;
        omp_set_num_threads(4);
        n = omp_get_max_threads();
        #pragma omp parallel for
        for(int i=0; i < num; i++) {
                index = select();
                switch(index) {
                case 0: if(A.state==0) A.eat();
                case 1: if(B.state==0) B.eat();
                case 2: if(C.state==0) C.eat();
                default: if(C.state==0) D.eat();
                }
        }

        return 0;
}
