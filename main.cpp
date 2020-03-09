#include <iostream>
#include <utility>
using namespace std;

// 1̶.̶ ̶С̶о̶з̶д̶а̶т̶ь̶ ̶н̶е̶с̶к̶о̶л̶ь̶к̶о̶ ̶H̶u̶m̶a̶n̶.
// 2̶.̶ ̶Д̶о̶б̶а̶в̶и̶т̶ь̶ ̶н̶е̶с̶к̶о̶л̶ь̶к̶о̶ ̶д̶о̶п̶о̶л̶н̶и̶т̶е̶л̶ь̶н̶ы̶х̶ ̶п̶о̶л̶е̶й̶ ̶(̶н̶е̶ ̶з̶а̶б̶ы̶в̶а̶т̶ь̶ ̶д̶о̶б̶а̶в̶и̶т̶ь̶ ̶з̶н̶а̶ч̶и̶м̶ы̶е̶ ̶п̶о̶л̶я̶ ̶в̶ ̶к̶о̶н̶с̶т̶р̶у̶к̶т̶о̶р̶)
// 3̶.̶ ̶Д̶о̶б̶а̶в̶и̶т̶ь̶ ̶g̶e̶t̶t̶e̶r̶'̶ы̶ ̶и̶ ̶s̶e̶t̶t̶e̶r̶'̶ы
// 4̶.̶ ̶П̶р̶о̶д̶е̶м̶о̶н̶с̶т̶р̶и̶р̶о̶в̶а̶т̶ь̶ ̶о̶б̶р̶а̶щ̶е̶н̶и̶е̶ ̶к̶ ̶п̶о̶л̶я̶м̶ ̶о̶б̶ъ̶е̶к̶т̶о̶в̶ ̶д̶о̶ч̶е̶р̶н̶и̶х̶ ̶и̶ ̶р̶о̶д̶и̶т̶е̶л̶ь̶с̶к̶и̶х̶ ̶к̶л̶а̶с̶с̶о̶в
// ̶5̶.̶ ̶Д̶о̶б̶а̶в̶и̶т̶ь̶ ̶н̶е̶с̶к̶о̶л̶ь̶к̶о̶ ̶н̶а̶с̶л̶е̶д̶н̶и̶к̶о̶в̶ ̶о̶т̶ ̶р̶а̶з̶л̶и̶ч̶н̶ы̶х̶ ̶р̶о̶д̶и̶т̶е̶л̶е̶й̶ ̶(̶с̶д̶е̶л̶а̶т̶ь̶ ̶д̶е̶р̶е̶в̶о̶ ̶и̶з̶ ̶5̶ ̶к̶л̶а̶с̶с̶о̶в̶)̶

enum GENDER {UFO, M, F};

class Human {
protected:
    int age;
    GENDER gender;
    string hobby;

public:
    Human(int age, GENDER gender, string hobby) : age(age) {
        this->gender = gender;
        this->hobby = hobby;
    }

    int getAge() const{
        return age;
    }

    void setAge(int age){
        this->age = age;
    }

    GENDER getGender() const{
        return gender;
    }

    void setGender(GENDER gender){
        this->gender = gender;
    }

    string getHobby() const{
        return hobby;
    }

    void setHobby(string hobby){
        this->hobby = hobby;
    }
};

class Student: public Human {
protected:
    string numberofZachetka;

public:
    Student(int age, GENDER gender, const string &numberofZachetka, string hobby) : Human(age, gender, hobby) {
        this->numberofZachetka = numberofZachetka;
    }

    const string &getnumberofZachetka() const {
        return numberofZachetka;
    }

    void setnumberofZachetka(const string &numberofZachetka){
        this->numberofZachetka = numberofZachetka;
    }
};

class BadStudent: public Student {
public:
    BadStudent(int age, GENDER gender, const string &numberofZachetka) : Student(age, gender, numberofZachetka, "Anime") {
    }
};

class GoodStudent : public Student {
public:
    GoodStudent(int age, GENDER gender, const string &numberofZachetka, string hobby) : Student(age, gender, numberofZachetka, hobby) {
    }
};


class Specialist {
    string profession;
    int experience;

public:
    Specialist(string profession, int experience) : profession(profession) {
        this->experience = experience;
    }

    string getProfession() const{
        return profession;
    }

    void setProfession(string profession){
        this->profession = profession;
    }

    int getExperience() const{
        return experience;
    }

    void setExperience(int experience){
        this->experience = experience;
    }
};

class Professor: public Specialist, public GoodStudent {

    int salary;

public:
    Professor(int age, GENDER gender, string hobby, const string &profession, int experience, int salary) : GoodStudent(age, gender, "Finish study", hobby), Specialist(profession, experience) {
        this->salary = salary;
    }

    int getSalary() const{
        return salary;
    }

    void setSalary(int money){
        this->salary = money;
    }
};

class ProfessorOfANIME: public Professor, public BadStudent {
public:
    ProfessorOfANIME(int age, int experience) :  Professor(age, UFO, "Anime", "Animeshnik", experience, 1000000), BadStudent(age, UFO, "Finish study") {
    }
};

int main() {
    Human Vasya(10, M, "Warframe");
    Human Igor(32, UFO, "Candy wrapper");
    Human Masha(19, F, "Collection");

    Student Olya(25, F, "23123124123", "Anecdote");

    BadStudent Fedya(90, UFO, "45635345433");

    GoodStudent Misha(35, M, "21211231232", "My little pony");

    Specialist JoJo("cynologist", 7);

    Professor Shurik(50, F, "DOTA 2", "IT-Specialist", 15, 60000);

    ProfessorOfANIME Roman(15, 9000);

    cout << "Human Vasya:"<< endl;
    cout << "  Age: " << Vasya.getAge() << endl;
    cout << "  Gender: " << Vasya.getGender() << endl;
    cout << "  Hobby: " << Vasya.getHobby() << endl << endl;

    cout << "Human Igor:"<< endl;
    cout << "  Age: " << Igor.getAge() << endl;
    cout << "  Gender: " << Igor.getGender() << endl;
    cout << "  Hobby: " << Igor.getHobby() << endl << endl;

    cout << "Human Masha:"<< endl;
    cout << "  Age: " << Masha.getAge() << endl;
    cout << "  Gender: " << Masha.getGender() << endl;
    cout << "  Hobby: " << Masha.getHobby() << endl << endl;

    cout << "Student Olya:"<< endl;
    cout << "  Age: " << Olya.getAge() << endl;
    cout << "  Gender: " << Olya.getGender() << endl;
    cout << "  Number of zachetka: " << Olya.getnumberofZachetka() << endl;
    cout << "  Hobby: " << Olya.getHobby() << endl << endl;

    cout << "Bad student Fedya:"<< endl;
    cout << "  Age: " << Fedya.getAge() << endl;
    cout << "  Gender: " << Fedya.getGender() << endl;
    cout << "  Number of zachetka: " << Fedya.getnumberofZachetka() << endl;
    cout << "  Hobby: " << Fedya.getHobby() << endl << endl;

    cout << "Good student Misha:"<< endl;
    cout << "  Age: " << Misha.getAge() << endl;
    cout << "  Gender: " << Misha.getGender() << endl;
    cout << "  Number of zachetka: " << Misha.getnumberofZachetka() << endl;
    cout << "  Hobby: " << Misha.getHobby() << endl << endl;

    cout << "Specialist JoJo:"<< endl;
    cout << "  Profession: " << JoJo.getProfession() << endl;
    cout << "  Experience: " << JoJo.getExperience() << endl << endl;

    cout << "Professor Shurik:"<< endl;
    cout << "  Profession: " << Shurik.getProfession() << endl;
    cout << "  Experience: " << Shurik.getExperience() << endl;
    cout << "  Salary: " << Shurik.getSalary() << endl;
    cout << "  Number of zachetka: " << Shurik.getnumberofZachetka() << endl;
    cout << "  Age: " << Shurik.getAge() << endl;
    cout << "  Gender: " << Shurik.getGender() << endl;
    cout << "  Hobby: " << Shurik.getHobby() << endl  << endl;

    cout << "Professor Of anime Roman:"<< endl;
    cout << "  Profession: " << Roman.getProfession() << endl;
    cout << "  Experience: " << Roman.getExperience() << endl;
    cout << "  Salary: " << Roman.getSalary() << endl;
    cout << "  Age: " << ((BadStudent)Roman).getAge() << endl;
    cout << "  Gender: " << ((BadStudent)Roman).getGender() << endl;
    cout << "  Number of zachetka: " << ((BadStudent)Roman).getnumberofZachetka() << endl;
    cout << "  Hobby: " << ((BadStudent)Roman).getHobby() << endl;

    return 0;
}