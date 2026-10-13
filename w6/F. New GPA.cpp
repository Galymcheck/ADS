#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string lastname;
    string firstname;
    double gpa;

    bool operator<(const Student& other) const {
        if (gpa != other.gpa) return gpa < other.gpa;
        if (lastname != other.lastname) return lastname < other.lastname;
        return firstname < other.firstname;
    }

    bool operator>(const Student& other) const {
        return other < *this;
    }
};

double getGradePoint(string grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A") return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B") return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C") return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D") return 1.00;
    return 0.0;
}

void quick(vector<Student>& a, int l, int r) {
    int i = l, j = r;
    Student p = a[(l + r) / 2];
    while(i <= j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);

    for(int i = 0; i < n; i++) {
        string lastname, firstname;
        cin >> lastname >> firstname;
        int m;
        cin >> m;
        double total_points = 0;
        double total_credits = 0;
        for(int j = 0; j < m; j++) {
            string grade;
            double credits;
            cin >> grade >> credits;
            total_points += getGradePoint(grade) * credits;
            total_credits += credits;
        }
        double gpa = total_points / total_credits;
        students[i] = {lastname, firstname, gpa};
    }

    if (n > 1) {
        quick(students, 0, n - 1);
    }

    for(int i = 0; i < n; i++) {
        cout << students[i].lastname << " " << students[i].firstname << " " 
             << fixed << setprecision(3) << students[i].gpa << "\n";
    }

    return 0;
}