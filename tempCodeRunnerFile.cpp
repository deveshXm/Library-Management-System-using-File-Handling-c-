#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
using namespace std;

class books
{
public:
    string book_no;
    string book_name;
    string author_name;
    string book_count;

    void write_book()
    {
        ofstream bout;
        cout << "enter book no. :";
        cin >> book_no;
        cout << "enter book name: ";
        cin >> book_name;
        cout << "enter book author: ";
        cin >> author_name;
        cout << "enter no. of books availaible: ";
        cin >> book_count;
        bout.open("book.txt", std::ios_base::app);
        bout << book_no << " " << book_name << " " << author_name << " " << book_count << endl;
        bout.close();
        system("cls");
    }

    void display_books()
    {

        ifstream bin;
        bin.open("book.txt");
        cout << "==============ALL BOOKS DETAIL==============" << endl;
        if (!bin)
        {
            cout << "error. file cannot be opened...." << endl;
            bin.close();
        }
        else
        {
            bin >> book_no >> book_name >> author_name >> book_count;
            while (!bin.eof())
            {

                cout << "Book No :" << book_no << endl;
                cout << "Book Name:" << book_name << endl;
                cout << "Book Author :" << author_name << endl;
                cout << "Book Count: " << book_count << endl;
                cout << "===============================================" << endl;
                bin >> book_no >> book_name >> author_name >> book_count;
            }
            bin.close();
        }
    }

    void delete_book()
    {
        ifstream bin;
        ofstream file;
        bin.open("book.txt");
        cout << "==============BOOK DELETE==============" << endl;
        int found = 0;
        if (!bin)
        {
            cout << "error. file cannot be opened...." << endl;
            bin.close();
        }
        else
        {
            cout << "enter book no: ";
            string bookn;
            cin >> bookn;
            bin >> book_no >> book_name >> author_name >> book_count;
            file.open("temp.txt", std::ios_base::app);
            while (!bin.eof())
            {
                if (bookn != book_no)
                {
                    file << book_no << " " << book_name << " " << author_name << " " << book_count << endl;
                }

                else
                {
                    found++;
                    cout << "successfully deleted data" << endl;
                    cout << "===============================================" << endl;
                }
                bin >> book_no >> book_name >> author_name >> book_count;
            }

            if (found == 0)
            {
                cout << "book not found ";
            }
            bin.close();
            file.close();
            remove("book.txt");
            rename("temp.txt", "book.txt");
        }
    }

    void modify_book()
    {

        ifstream bin;
        ofstream file;
        bin.open("book.txt");
        cout << "==============BOOK MODIFY==============" << endl;
        int found = 0;
        if (!bin)
        {
            cout << "error. file cannot be opened...." << endl;
            bin.close();
        }
        else
        {
            cout << "enter book no: ";
            string bookn;
            cin >> bookn;
            bin >> book_no >> book_name >> author_name >> book_count;
            file.open("temp.txt", std::ios_base::app);
            while (!bin.eof())
            {
                if (bookn != book_no)
                {
                    file << book_no << " " << book_name << " " << author_name << " " << book_count << endl;
                }
                else
                {
                    cout << "==============BEFORE MODIFICATION==============" << endl;
                    cout << "Book No :" << book_no << endl;
                    cout << "Book Name:" << book_name << endl;
                    cout << "Book Author :" << author_name << endl;
                    cout << "Book Count: " << book_count << endl;
                    cout << "===============================================" << endl;
                    cout << "enter book no. :";
                    cin >> book_no;
                    cout << "enter book name: ";
                    cin >> book_name;
                    cout << "enter book author: ";
                    cin >> author_name;
                    cout << "enter no. of books availaible: ";
                    cin >> book_count;
                    cout << "successfully modified data...." << endl;
                    cout << "===============================================" << endl;
                    file << book_no << " " << book_name << " " << author_name << " " << book_count << endl;
                    found++;
                }
                bin >> book_no >> book_name >> author_name >> book_count;
            }

            if (found == 0)
            {
                cout << "book not found ";
            }
            bin.close();
            file.close();
            remove("book.txt");
            rename("temp.txt", "book.txt");
        }
    }

    void view_book()
    {
        ifstream bin;
        bin.open("book.txt");
        cout << "==============BOOK DETAIL==============" << endl;
        int found = 0;
        if (!bin)
        {
            cout << "error. file cannot be opened...." << endl;
            bin.close();
        }
        else
        {
            cout << "enter book no: ";
            string bookn;
            cin >> bookn;
            bin >> book_no >> book_name >> author_name >> book_count;
            while (!bin.eof())
            {
                if (bookn == book_no)
                {
                    cout << "Book No: " << book_no << endl;
                    cout << "Book Name:" << book_name << endl;
                    cout << "Book Author :" << author_name << endl;
                    cout << "Book Count: " << book_count << endl;
                    cout << "===============================================" << endl;
                    found++;
                }
                bin >> book_no >> book_name >> author_name >> book_count;
            }

            if (found == 0)
            {
                cout << "Book Not Found....";
            }
            bin.close();
        }
    }
};

class student
{
public:
    string student_name;
    string admission_no;
    string Class;
    string books_issued = "0";
    string book1;
    string book2;

    void write_student()
    {
        ofstream sout;
        cout << "enter name: ";
        cin >> student_name;
        cout << "enter admission number: ";
        cin >> admission_no;
        cout << "enter Class: ";
        cin >> Class;
        sout.open("student.txt", std::ios_base::app);
        sout << admission_no << " " << student_name << " " << Class << endl;
        sout.close();
        ofstream issue;
        issue.open("issue.txt", ios_base::app);
        issue << admission_no << " "
              << "0"
              << " "
              << "0000"
              << " "
              << "0000" << endl;
        issue.close();
    }

    void book_issue()
    {
        string BOOK = "0000";
        ifstream student, issue;
        ofstream FILE;
        student.open("student.txt");
        issue.open("issue.txt", std::ios_base::app);
        cout << "==============STUDENT BOOK ISSUE==============" << endl;
        cout << "enter student admission number: ";
        string ano, b1, b2, issueno;
        cin >> ano;
        // checking if student exists
        int found = 0;
        student >> admission_no >> student_name >> Class;
        while (!student.eof())
        {
            if (admission_no == ano)
                found++;

            student >> admission_no >> student_name >> Class;
        }

        student.close();
        if (found == 0)
        {
            cout << "invalid admission number......" << endl;
            return;
        }
        cout << "enter number of books issued (1 or 2): ";
        cin >> issueno;
        if (issueno == "1")
        {
            int found = 0;
            cout << "enter book : ";
            cin >> b1;
            ifstream book;
            ofstream file;
            book.open("book.txt");
            file.open("temp.txt", ios_base::app);
            books b;
            book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
            while (!book.eof())
            {
                if (b1 != b.book_no)
                {
                    file << b.book_no << " " << b.book_name << " " << b.author_name << " " << b.book_count << endl;
                }
                else
                {
                    int x = stoi(b.book_count);
                    if (x == 0)
                    {
                        cout << "book out of stock....." << endl;
                        return;
                    }
                    string a = to_string(x - 1);
                    file << b.book_no << " " << b.book_name << " " << b.author_name << " " << a << endl;
                    found++;
                }

                book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
            }
            book.close();
            file.close();
            remove("book.txt");
            rename("temp.txt", "book.txt");
            if (found == 0)
            {
                cout << "book not found......" << endl;
                return;
            }
            FILE.open("temp1.txt", ios_base::app);
            issue >> admission_no >> books_issued >> book1 >> book2;
            while (!issue.eof())
            {
                if (admission_no != ano)
                    FILE << admission_no << " " << books_issued << " " << book1 << " " << book2 << endl;
                else
                {
                    FILE << admission_no << " " << issueno << " " << b1 << " " << BOOK << endl;
                }
                issue >> admission_no >> books_issued >> book1 >> book2;
            }
            cout << "Book issued successfully......." << endl;
            issue.close();
            FILE.close();
            remove("issue.txt");
            rename("temp1.txt", "issue.txt");
            return;
        }
        else if (issueno == "2")
        {
            cout << "enter book 1 : ";
            cin >> b1;
            cout << "enter book 2 : ";
            cin >> b2;
            string BOOK = "0000";
            ifstream student, issue;
            ofstream FILE;
            student.open("student.txt");
            issue.open("issue.txt", std::ios_base::app);
            cout << "==============STUDENT BOOK ISSUE==============" << endl;
            cout << "enter student admission number: ";
            string ano, b1, b2, issueno;
            cin >> ano;
            // checking if student exists
            int found = 0;
            student >> admission_no >> student_name >> Class;
            while (!student.eof())
            {
                if (admission_no == ano)
                    found++;

                student >> admission_no >> student_name >> Class;
            }

            student.close();
            if (found == 0)
            {
                cout << "invalid admission number......" << endl;
                return;
            }
            cout << "enter number of books issued (1 or 2): ";
            cin >> issueno;
            if (issueno == "1")
            {
                int found = 0;
                cout << "enter book : ";
                cin >> b1;
                ifstream book;
                ofstream file;
                book.open("book.txt");
                file.open("temp.txt", ios_base::app);
                books b;
                book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
                while (!book.eof())
                {
                    if (b1 != b.book_no)
                    {
                        file << b.book_no << " " << b.book_name << " " << b.author_name << " " << b.book_count << endl;
                    }
                    else
                    {
                        int x = stoi(b.book_count);
                        if (x == 0)
                        {
                            cout << "book out of stock....." << endl;
                            return;
                        }
                        string a = to_string(x - 1);
                        file << b.book_no << " " << b.book_name << " " << b.author_name << " " << a << endl;
                        found++;
                    }

                    book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
                }
                book.close();
                file.close();
                remove("book.txt");
                rename("temp.txt", "book.txt");
                if (found == 0)
                {
                    cout << "book not found......" << endl;
                    return;
                }
                book.open("book.txt");
                file.open("temp.txt", ios_base::app);
                book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
                int found1 = 0;
                while (!book.eof())
                {
                    if (b2 != b.book_no)
                    {
                        file << b.book_no << " " << b.book_name << " " << b.author_name << " " << b.book_count << endl;
                    }
                    else
                    {
                        int x = stoi(b.book_count);
                        if (x == 0)
                        {
                            cout << "book out of stock....." << endl;
                            return;
                        }
                        string a = to_string(x - 1);
                        file << b.book_no << " " << b.book_name << " " << b.author_name << " " << a << endl;
                        found1++;
                    }

                    book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
                }
                book.close();
                file.close();
                remove("book.txt");
                rename("temp.txt", "book.txt");
                if (found1 == 0)
                {
                    cout << "book not found......" << endl;
                    return;
                }
                FILE.open("temp1.txt", ios_base::app);
                issue >> admission_no >> books_issued >> book1 >> book2;
                while (!issue.eof())
                {
                    if (admission_no != ano)
                        FILE << admission_no << " " << books_issued << " " << book1 << " " << book2 << endl;
                    else
                    {
                        FILE << admission_no << " " << issueno << " " << b1 << " " << b2 << endl;
                    }
                    issue >> admission_no >> books_issued >> book1 >> book2;
                }
                cout << "Book issued successfully......." << endl;
                issue.close();
                FILE.close();
                remove("issue.txt");
                rename("temp1.txt", "issue.txt");
                return;
            }
            else
            {
                cout << "invalid number" << endl;
            }
        }
    }

    void book_deposit()
    {
        cout << "==============BOOK DEPOSIT==============" << endl;
        string ano, bookno;
        cout << "Enter Admission Number: ";
        cin >> ano;
        ifstream student;
        student.open("student.txt");
        int found = 0;
        student >> admission_no >> student_name >> Class;
        while (!student.eof())
        {
            if (admission_no == ano)
                found++;

            student >> admission_no >> student_name >> Class;
        }
        if (found == 0)
        {
            cout << "invalid admission number......" << endl;
            return;
        }
        student.close();
        cout << "Enter Book Number: ";
        cin >> bookno;
        books b;
        int found1 = 0;
        ifstream file, book;
        ofstream file1, file2;
        book.open("book.txt");
        book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
        while (!book.eof())
        {
            if (b.book_no == bookno)
            {
                found1++;
            }
            book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
        }
        if (found1 == 0)
        {
            cout << "invalid book no......" << endl;
            return;
        }
        book.close();
        book.open("book.txt");
        file2.open("temp.txt", ios_base::app);
        book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
        while (!book.eof())
        {
            if (bookno != b.book_no)
            {
                file2 << b.book_no << " " << b.book_name << " " << b.author_name << " " << b.book_count << endl;
            }
            else
            {
                int x = stoi(b.book_count);                
                string a = to_string(x + 1);
                file2 << b.book_no << " " << b.book_name << " " << b.author_name << " " << a << endl;
                found++;
            }

            book >> b.book_no >> b.book_name >> b.author_name >> b.book_count;
        }
        book.close();
        file2.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        file.open("issue.txt");
        file1.open("temp.txt");
        file >> admission_no >> books_issued >> book1 >> book2;
        string a = "0000";
        while (!file.eof())
        {
            if (admission_no != ano)
                file1 << admission_no << " " << books_issued << " " << book1 << " " << book2 << endl;
            else
            {
                int x = stoi(books_issued);
                if (x == 0)
                {
                    cout << "no books issued...." << endl;
                    return;
                }
                books_issued = to_string(x - 1);
                if (book1 == bookno)
                    file1 << admission_no << " " << books_issued << " " << a << " " << book2 << endl;
                if (book2 == bookno)
                    file1 << admission_no << " " << books_issued << " " << book1 << " " << a << endl;
                cout << "book deposited successfully...." << endl;
            }

            file >> admission_no >> books_issued >> book1 >> book2;
        }
        file.close();
        file1.close();
        remove("issue.txt");
        rename("temp.txt", "issue.txt");
    }

    void display_students()
    {
        system("cls");
        ifstream sin;
        sin.open("student.txt");
        cout << "==============ALL STUDENTS DETAIL==============" << endl;
        if (!sin)
        {
            cout << "error. files cannot be opened...." << endl;
            sin.close();
        }
        else
        {
            sin >> admission_no >> student_name >> Class;
            while (!sin.eof())
            {

                cout << "Admission No: " << admission_no << endl;
                cout << "Student Name: " << student_name << endl;
                cout << "Class: " << Class << endl;
                sin >> admission_no >> student_name >> Class;
            }
            sin.close();
        }
    }

    void delete_student()
    {
        ifstream sin;
        ifstream file;
        ofstream file1, file2;
        sin.open("student.txt");
        file.open("issue.txt");
        cout << "==============STUDENT DELETION==============" << endl;
        string ano;
        cout << "enter student admission no. : " << endl;
        cin >> ano;
        int found = 0;
        file1.open("temp.txt");
        file2.open("temp1.txt");
        sin >> admission_no >> student_name >> Class;
        file >> admission_no >> books_issued >> book1 >> book2;
        while (!sin.eof())
        {
            if (ano != admission_no)
            {
                file1 << admission_no << " " << student_name << " " << Class << endl;
            }

            else
            {
                found++;
                cout << "successfully deleted data.........(1)" << endl;
            }

            sin >> admission_no >> student_name >> Class;
            ;
        }

        while (!sin.eof())
        {
            if (ano != admission_no)
            {

                file2 << admission_no << " " << books_issued << " " << book1 << " " << book2 << endl;
            }

            else
            {
                found++;
                cout << "successfully deleted data.........(2)" << endl;
            }
            file >> admission_no >> books_issued >> book1 >> book2;
        }

        if (found == 0)
        {
            cout << "student not found......" << endl;
            cout << "===============================================" << endl;
        }

        sin.close();
        file.close();
        file1.close();
        file2.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        remove("issue.txt");
        rename("temp1.txt", "issue.txt");
    }

    void modify_student()
    {
        ifstream sin;
        ofstream file1;
        cout << "==============STUDENT RECORD UPDATION==============" << endl;
        cout << "enter admission number: ";
        string ano;
        cin >> ano;
        int found = 0;
        string newano, newname, newclass, newbook1, newbook2, newissue;
        cout << "Enter New Admission No: " << newano;
        cin >> newano;
        cout << "Enter New Student Name: " << newname;
        cin >> newname;
        cout << "Enter New Class: " << newclass;
        cin >> newclass;
        sin.open("student.txt");
        file1.open("temp.txt", ios_base::app);
        sin >> admission_no >> student_name >> Class;
        while (!sin.eof())
        {
            if (ano != admission_no)
            {
                file1 << admission_no << " " << student_name << " " << Class << endl;
            }

            else
            {
                found++;
                file1 << newano << " " << newname << " " << newclass << endl;
            }
            sin >> admission_no >> student_name >> Class;
            ;
        }
        if (found == 0)
        {
            cout << "Invalid Admission Number......." << endl;
            return;
        }

        sin.close();
        file1.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }

    void view_student()
    {
        system("cls");
        ifstream sin;
        ifstream file;
        int found = 0;
        string ano;
        sin.open("student.txt");
        file.open("issue.txt");
        cout << "==============STUDENT DETAIL==============" << endl;
        if (!sin && !file)
        {
            cout << "error. files cannot be opened...." << endl;
            sin.close();
            file.close();
        }
        else
        {
            sin >> admission_no >> student_name >> Class;
            file >> books_issued >> book1 >> book2;
            cout << "Enter admission no. of student: ";
            cin >> ano;
            while (!file.eof())
            {

                if (ano == admission_no)
                {
                    cout << "Admission No: " << admission_no << endl;
                    cout << "Student Name: " << student_name << endl;
                    cout << "Class: " << Class << endl;
                    cout << "books issued: " << books_issued << endl;
                    if (book1 != "0000")
                        cout << "book 1 : " << book1 << endl;
                    if (book2 != "0000")
                        cout << "book 2 : " << book2 << endl;
                    cout << "===============================================" << endl;
                    found++;
                }
                sin >> admission_no >> student_name >> Class;
                file >> books_issued >> book1 >> book2;
            }
            sin.close();
        }
        if (found == 0)
        {
            cout << "Student not found....." << endl;
        }
        file.close();
    }
};

void menu()
{

    cout << "==============LIBRARY MANAGEMENT PORGRAM==============" << endl;
    cout << "               1. insert student detail" << endl;
    cout << "               2. insert book detail" << endl;
    cout << "               3. delete student detail" << endl;
    cout << "               4. delete book detail" << endl;
    cout << "               5. update student detail" << endl;
    cout << "               6. update book detail" << endl;
    cout << "               7. view particular student detail" << endl;
    cout << "               8. view particular book detail" << endl;
    cout << "               9. view all student detail" << endl;
    cout << "               10.view all book detail" << endl;
    cout << "               11.ISSUE BOOK" << endl;
    cout << "               12.DEPOSIT BOOK" << endl;
}

int main()
{
    cout << "enter data in format: firstname_lastname use \"_\" to give space" << endl;
    cout << "a student can issue at most 2 books at a time" << endl;
menubook:
    student s;
    books b;
    menu();
    int a;
    cout << "enter choice: ";
    cin >> a;
    system("cls");

    if (a == 1)
        s.write_student();
    if (a == 2)
        b.write_book();
    if (a == 3)
        s.delete_student();
    if (a == 4)
        b.delete_book();
    if (a == 5)
        s.modify_student();
    if (a == 6)
        b.modify_book();
    if (a == 7)
        s.view_student();
    if (a == 8)
        b.view_book();
    if (a == 9)
        s.display_students();
    if (a == 10)
        b.display_books();
    if (a == 11)
        s.book_issue();
    if (a == 12)
        s.book_deposit();
    goto menubook;
}