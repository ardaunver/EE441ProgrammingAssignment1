#include <iostream>
using namespace std;

int coef = 1;

class Discs
{
private:
    int m_diameter;
public:
    Discs(int diameter = 0);
    void Set_Diameter(int new_diameter);
    int Get_Diameter();
};

Discs::Discs(int diameter) {
    m_diameter = diameter;
}

void Discs::Set_Diameter(int new_diameter){
    m_diameter = new_diameter;
}

int Discs::Get_Diameter(){
    return m_diameter;
}

class Hanoi
{
private:

    int rod0[20] = {0}, rod1[20] = {0},
        rod2[20] = {0}, all_discs[20] = {0};


public:
    int num_disc[3] = {0};
    int disc_quantity = 0;
    Hanoi(int no_disc);
    int Get_Diameter(int index, int row);
    int Disc_Storage(int member);
    //int Get_No_Disc(int index);

    void move(int from, int to);
    int rod0_disc_quantity();


};

Hanoi::Hanoi(int no_disc) {
    num_disc[0] = no_disc;
    disc_quantity = no_disc;
    for(int i = 0; i < no_disc; i++){
        Discs Disc(coef*i + 2);
        rod0[num_disc[0] - 1 - i] = Disc.Get_Diameter();
        all_discs[num_disc[0] - 1 - i] = (coef*i) + 2;
    }
    for(int i = 0; i < no_disc; i++){
            rod0[20 - num_disc[0]] = 0;
    }
    for(int i = 0; i < no_disc; i++){
        cout << "Disk" << i << ": " << rod0[i] << endl;
    }
}

int Hanoi::Disc_Storage(int member_number){
    return all_discs[member_number];
}

int Hanoi::Get_Diameter(int index, int row){

    switch(index) {
        case 0:
            return rod0[row];
        case 1:
            return rod1[row];
        case 2:
            return rod2[row];
    }
    return 0;
}

void Hanoi::move(int from, int to){

    int state;

    if(from == 0 && to == 1){ state = 0;}
    else if(from == 0 && to == 2){ state = 1;}
    else if(from == 1 && to == 0){ state = 2;}
    else if(from == 1 && to == 2){ state = 3;}
    else if(from == 2 && to == 0){ state = 4;}
    else if(from == 2 && to == 1){ state = 5;}
    else{cerr << "invalid operation" << endl; exit(0);}

    switch(state) {
        case 0:
            //cout << "case:0 " << endl;
            if(num_disc[1] == 0 && rod0[0] != 0){
                //cout << "legal move 1" << endl;
                num_disc[1]++;
                rod1[num_disc[1] - 1] = rod0[num_disc[0] - 1];
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                     " is moved from rod0 to rod1" << endl;
            }
            else if(rod0[num_disc[0] - 1] < rod1[num_disc[1] - 1] && rod0[0] != 0){
                //cout << "legal move 2" << endl;
                num_disc[1]++;
                rod1[num_disc[1] - 1] = rod0[num_disc[0] - 1];
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                     " is moved from rod0 to rod1" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 1:
            //cout << "case:1 " << endl;
            if(num_disc[2] == 0 && rod0[0] != 0){
                //cout << "legal move 1" << endl;
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod0[num_disc[0] - 1];
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                     " is moved from rod0 to rod2" << endl;
            }
            else if(rod0[num_disc[0] - 1] < rod2[num_disc[2] - 1] && rod0[0] != 0){
                //cout << "legal move 2" << endl;
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod0[num_disc[0] - 1];
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                     " is moved from rod0 to rod2" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 2:
            //cout << "case:2 " << endl;
            if(num_disc[0] == 0 && rod1[0] != 0){
                //cout << "legal move 1" << endl;
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                     " is moved from rod1 to rod0" << endl;
            }
            else if(rod1[num_disc[1] - 1] < rod0[num_disc[0] - 1] && rod1[0] != 0){
                //cout << "legal move 2" << endl;
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                     " is moved from rod1 to rod0" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 3:
            //cout << "case:3 " << endl;
            if(num_disc[2] == 0 && rod1[0] != 0){
                //cout << "legal move 1" << endl;
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                     " is moved from rod1 to rod2" << endl;
            }
            else if(rod1[num_disc[1] - 1] < rod2[num_disc[2] - 1] && rod1[0] != 0){
                //cout << "legal move 2" << endl;
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                     " is moved from rod1 to rod2" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 4:
            //cout << "case:4 " << endl;
            if(num_disc[0] == 0 && rod2[0] != 0){
               //cout << "legal move 1" << endl;
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                     " is moved from rod2 to rod0" << endl;
            }
            else if(rod2[num_disc[2] - 1] < rod0[num_disc[0] - 1] && rod2[0] != 0){
                //cout << "legal move 2" << endl;
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                     " is moved from rod2 to rod0" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 5:
            //cout << "case:5 " << endl;
            if(num_disc[1] == 0 && rod2[0] != 0){
                //cout << "legal move 1" << endl;
                num_disc[1]++;
                rod1[num_disc[1] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                     " is moved from rod2 to rod1" << endl;
            }
            else if(rod2[num_disc[2] - 1] < rod1[num_disc[1] - 1] && rod2[0] != 0){
                //cout << "legal move 2" << endl;
                num_disc[1]++;
                rod1[num_disc[1] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                     " is moved from rod2 to rod1" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
    }

}
/*
void Hanoi::solve(Hanoi& game){

    if(rod[]){
        cout << endl;
    };
    else if(rod1[0] != 0 && rod2[0] != 0){
        solve(game);
    }
    for(int i = 0; i < rod0_disc_quantity(); i++){
        if(Get_Diameter(0,i) - Get_Diameter(0, i + 1) == coef){

        }
    }
}
 */

void towerOfHanoi(Hanoi &game, int n, int from_rod, int to_rod,
                  int aux_rod)
{

    if (n == 0) {
        return;
    }
    else{
        towerOfHanoi(game,n - 1, from_rod, aux_rod, to_rod);
        game.move(from_rod,to_rod);
        towerOfHanoi(game,n - 1, aux_rod, to_rod, from_rod);
    }
}

void solve(Hanoi &game) {

    towerOfHanoi(game,game.disc_quantity,0,2,1);

    cout << "game is solved" << endl;

}




int Hanoi::rod0_disc_quantity(){
    int counter = 0;
    while(rod0[counter]){
        counter++;
    }
    return counter;
}

// ****************** Print Backwards Function for Part 2.2

void print_backwards(char const * str) {
    if(*str == '\0'){
        return;
    }
    else {
        print_backwards(str+1);
        cout<<*str;
    }
}

// ****************** nth prime number Function for Part 2.3

// PrimeOrNot is the "Helper" function

int PrimeOrNot(int number)
{
    // Checking if the number is 0 or 1
    if (number <= 1)
        return 0;
    // Checking if the number is 2 or 3
    if (number == 2 || number == 3)
        return 1;

    // if the number can be divided by 2 or 3, it is NOT a Prime number
    if (number % 2 == 0 || number % 3 == 0)
        return 0;

    // Every prime number other than 2 or 3 can be represented
    // in form of (6*k + 1) or (6*k - 1) while k is some integer
    for (int i = 5; i * i <= number; i = i + 6)
        if (number % i == 0 || number % (i + 2) == 0)
            return 0;

    return 1;
}

int nth_Prime(int counter)
{
    // starting from 2 since it is the first prime number
    int number = 2;

    while(counter)
    {
        if(PrimeOrNot(number))
            // a prime number is found decrease n until it reaches 0
            // and the loop terminates
            counter--;

        //incrementing i to check the next integer
        number++;
    }
    // since the number is incremented within the loop no matter what
    // it must be decreased by one to obtain the nth prime number
    number -= 1;

    return number;
}


int main() {
    /*
    Discs Disc1;
    Discs Disc2(4);

    cout << "testing Get_Diameter()..." << endl;
    cout << "Disc 1 diameter: " << Disc1.Get_Diameter() << endl;
    Disc1.Set_Diameter(3);

    cout << "testing Set_Diameter()..." << endl;
    cout << "Disc 2 diameter: " << Disc2.Get_Diameter() << endl;
    cout << "Disc 1 diameter: " << Disc1.Get_Diameter() << endl;
    */

    Hanoi han(6);

    for(int i = 0; i < 5; i++){
        cout << "Disc No:" << i + 1 << " has diameter " << han.Disc_Storage(i)<< endl;
    }
    /*
    //han.move(2,0);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(0,1);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(1,2);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(2,1);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(0,2);
    cout << "rod0[3]: " << han.Get_Diameter(0,3) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(1,2);
    cout << "rod0[2]: " << han.Get_Diameter(0,2) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;


    //han.move(0,2);
    //han.move(1,2);
    //han.move(2,2);
    */
    /*
    // Printing the message backwards for Part 2.2

    cout << "Printing the message backwards for Part 2.2... " << endl;

    char msg[] = "I had fun doing the Programming Assignment 1";
    cout <<"Original String: " << msg << endl;
    cout <<"Reversed String: ";print_backwards(msg);
    cout << endl;

    cout << "Checking if PrimeOrNot Function works or not" << endl;
    cout << "5: " << PrimeOrNot(5) << endl;
    cout << "6: " << PrimeOrNot(6) << endl;
    cout << "7: " << PrimeOrNot(7) << endl;
    cout << "11: " << PrimeOrNot(11) << endl;
    cout << "16: " << PrimeOrNot(16) << endl;
    cout << "131: " << PrimeOrNot(131) << endl;

    cout << "Obtaining the nth prime number via nth_Prime function..." << endl;
    cout << "5th prime number is " << nth_Prime(5) << endl;
    cout << "6th prime number is " << nth_Prime(6) << endl;
    cout << "12th prime number is " << nth_Prime(12) << endl;
    cout << "25th prime number is " << nth_Prime(25) << endl;
    */

    //han.move(0,1); han.move(0,2);
    //han.move(1,2); han.move(0,1);
    //han.move(2,1);

    cout << "rod0[1]: " << han.Get_Diameter(0,1) << endl;
    cout << "rod1[1]: " << han.Get_Diameter(1,1) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;

    cout << "There are " << han.rod0_disc_quantity() <<  " discs at rod0 " << endl;

    solve(han);
    cout << "There are " << han.rod0_disc_quantity() <<  " discs at rod0 " << endl;

    cout << "rod0[0]: " << han.Get_Diameter(0,0) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;

    cout << "rod2[3]: " << han.Get_Diameter(2,7) << endl;
    cout << "rod2[2]: " << han.Get_Diameter(2,6) << endl;
    cout << "rod2[1]: " << han.Get_Diameter(2,5) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,4) << endl;
    cout << "rod2[3]: " << han.Get_Diameter(2,3) << endl;
    cout << "rod2[2]: " << han.Get_Diameter(2,2) << endl;
    cout << "rod2[1]: " << han.Get_Diameter(2,1) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;




    return 0;
}
