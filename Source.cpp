#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void max_of_two();
void bissextile_year();
void quadratic_equation();
void divisible_by_two();
void table_of_squares();
void maximum_in_sequence();
void function_value_table();
void show_array();
int min_element(int[5][5]);
int max_element(int[5][5]);
void students_practice();
void train_practice();

struct Student {
public: 
    string Name;
    int Group;
    int Marks[5];
    double MeanMark;

    double find_mean_mark() {
        int mean_mark = 0;

        for (int i = 0; i < 5; i++) {
            mean_mark = mean_mark + Marks[i];
        }
        return mean_mark / 5;
    };
};

struct Train {
public:
    string Desination;
    int Train_number;
    int Time; // 1020 == 10:20
};

int main()
{
    //max_of_two();
    //bissextile_year();
    //quadratic_equation();
    //divisible_by_two();
    //table_of_squares();
    //maximum_in_sequence();
    //function_value_table();
    //show_array();
    //students_practice();
    train_practice();
}

void max_of_two() {
    int num1, num2;

    cout << "Type first integer number" << endl;
    cin >> num1;
    cout << "Type second integer number" << endl;
    cin >> num2;

    if (num1 < num2) {
        cout << num2 << " is bigger then " << num1;
    }
    if (num2 < num1) {
        cout << num1 << " is bigger then " << num2;
    }
    else {
        cout << num1 << " equals " << num2;
    }
}

void bissextile_year() {
    int year;
    
    cout << "Please, type year" << endl;
    cin >> year;

    if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) ?
        cout << "Its a leap year" << endl :
        cout << "Its not a leap year" << endl);
}

void quadratic_equation() {
    int a, b, c;
    double x1, x2, d;

    cout << "Enter Equation Coefficients (a, b, c)" << endl;
    cin >> a >> b >> c;

    if (a == 0)
        cout << "The equation is not square" << endl;
    else
    {
        d = b ^ 2 - 4 * a * c;
        if (d < 0)
            cout << "The equation has no real roots" << endl;
        else if (d == 0) {
            x1 = -b / (2 * a);
            cout << "x1=x2= " << x1 << endl;
        }
        else if (d > 0) {
            x1 = (-b - sqrt(d)) / (2 * a);
            x2 = (-b + sqrt(d)) / (2 * a);
            cout << "x1= " << x1 << " x2= " << x2 << endl;
        }
    }
}

void divisible_by_two() {
    int num;

    cout << "Type the number" << endl;
    cin >> num;

    (num % 2 == 0) ? cout << "divisible by two" : cout << "not divisible by two";
}

void table_of_squares() {
    int n = 11;

    cout << "Table of squares 10" << endl;

    for (int i = 1; i < n; i++) {
        cout << pow(i, 2) << endl;
    }
}

void maximum_in_sequence() {
    double t, max = 0.0;

    cout << "Enter the sequence (while not ctrl + z)" << endl;

    do { //пока вводится до сочетания ctrl + z на windows
        cin >> t;
        if (t > max) max = t;
        
    } while (cin);

    cout << "Max = " << max << endl;
}

void function_value_table() {
    double x = -4.0, a = 4.0;

    while (x <= a) {
        cout << x << "\t" << -2 * pow(x, 2) - 5 * x - 8 << endl;
        x += 0.5;
    }
}

void show_array() {
    int matrix[5][5] = {};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = 30 + rand() % 31;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Min = " << min_element(matrix) << endl;
    cout << "Max = " << max_element(matrix) << endl;
}

int min_element(int matrix[5][5]) {
    int min = matrix[0][0];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
    }
    return min;
}

int max_element(int matrix[5][5]) {
    int max = matrix[0][0];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] > max)
                max = matrix[i][j];
        }
    }
    return max;
}

void students_practice() {
    string name [10] = { "Brig B.", "Weak J.", "Krop P.", "Berg G.", "Darvin C.", "Neuron P.", "Alen B.", "West I.", "Frost K.", "Snow J." };

    Student Students[10];

    for (int i = 0; i < 10; i++)
    {
        Students[i].Name = name[i];
        Students[i].Group = rand() % 10;

        for (int j = 0; j < 5; j++)
        {
            Students[i].Marks[j] = 2 + rand() % 5;
        }
        Students[i].MeanMark = Students[i].find_mean_mark();
    }

    Student temp;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (Students[j].MeanMark > Students[j + 1].MeanMark) {
                temp = Students[j];
                Students[j] = Students[j + 1];
                Students[j + 1] = temp;
            }
        }
    }

    cout << "All sorted student:" << endl;

    for (int k = 0; k < 10; k++)
    {
        cout << "Name " << Students[k].Name << " | " << "Group " 
            << Students[k].Group << " | " << "Mean Mark " 
            << Students[k].MeanMark << endl;
    }

    cout << "Students with only good marks" << endl;
    
    for (int i = 0; i < 10; i++) {
        int count_of_bad_marks = 0;
        
        for (int j = 0; j < 5; j++) {
            if (Students[i].Marks[j] < 4) count_of_bad_marks++;
        }
        if (count_of_bad_marks == 0) 
            cout << "Name " << Students[i].Name << " | " << "Group "
            << Students[i].Group << " | " << "Mean Mark "
            << Students[i].MeanMark << endl;
    }
}

void train_practice() {
    string destinations[5] = { "Moscow", "St. Peterburg", "Moscow", "Novosibirsk", "Kemerovo" };

    Train Trains[5];

    for (int i = 0; i < 5; i++)
    {
        Trains[i].Desination = destinations[i];
        
        if (i == 0) {
            Trains[i].Train_number = rand() % 6000;
            Trains[i].Time = 1200 + rand() % 1200;
        }

        for (int j = 0; j < i; j++)
        {
            int random_number;

            for (;;)
            {
                bool good = true;
                random_number = rand() % 6000;
                if (random_number == Trains[j].Train_number) { good = false; break; }
                if (good) break;
            }

            Trains[i].Train_number = random_number;
        }

        for (int j = 0; j < i; j++)
        {
            int random_time;

            for (;;)
            {
                bool good = true;
                random_time = 1200 + rand() % 1200;
                if (random_time == Trains[j].Train_number) { good = false; break; }
                if (good) break;
            }

            Trains[i].Time = random_time;
        }
    }

    Train temp;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (Trains[j].Train_number > Trains[j + 1].Train_number) {
                temp = Trains[j];
                Trains[j] = Trains[j + 1];
                Trains[j + 1] = temp;
            }
        }
    }

    cout << "All sorted by number trains:" << endl;

    for (int k = 0; k < 5; k++)
    {
        cout << "Train number " << Trains[k].Train_number << " | " << "Destination "
            << Trains[k].Desination << " | " << "Time "
            << Trains[k].Time << endl;
    }

    int number_of_train;
    bool found = false;
    cout << "In which train you interested? (Type number)" << endl;
    cin >> number_of_train;

    for (int k = 0; k < 5; k++)
    {
        if (number_of_train == Trains[k].Train_number) {
            cout << "Train number " << Trains[k].Train_number << " | " << "Destination "
                << Trains[k].Desination << " | " << "Time "
                << Trains[k].Time << endl;
            found = true;
        }
    }

    if (!found) cout << "Train not found" << endl;

    cout << "Sort by destination" << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            int res = strcmp(Trains[j].Desination.c_str(), Trains[j + 1].Desination.c_str());
            if (res == 1)
                swap(Trains[j], Trains[j + 1]);
            else if (res == 0) {
                if (Trains[j].Time > Trains[j + 1].Time)
                    swap(Trains[j], Trains[j + 1]);
            }
        }
    }

    for (int k = 0; k < 5; k++)
    {
        cout << "Train number " << Trains[k].Train_number << " | " << "Destination "
            << Trains[k].Desination << " | " << "Time "
            << Trains[k].Time << endl;
    }
}