#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Book
{
private:
    char *title, *author;
    int* stock;
    float* cost;
    
public:
    Book()
    {
        title = new char[20];
        author = new char[20];
        stock = new int;
        cost = new float;

    }
    void newBook();
    void editBook();
    int search(char [], char []);
    void display();
    void buyBook();
};

void Book::newBook()
{
    cin.ignore();
    cout << "Enter the Title: ";
    cin.getline(title, 20);
    cout << "Enter the author's name: ";
    cin.getline(author, 20);

    cout << "Enter the cost: ";
    cin >> *cost;

    cout << "Enter the no. of copies available: ";
    cin >> *stock;
}
void Book::editBook()
{
    cout << "Enter the Title: ";
    cin.getline(title, 40);

    cout << "Enter the author's name: ";
    cin.getline(author, 20);

    cout << "Enter the cost: ";
    cin >> *cost;

    cout << "Enter the no. of copies available: ";
    cin >> *stock;
}
int Book::search(char ts[20], char as[20])
{
    if (strcmp(ts, title) == 0 && strcmp(as, author) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Book::buyBook()
{
    int count;
    cout << "Enter no. of books to buy: ";
    cin >> count;
    if (count <= *stock)
    {
        *stock = *stock - count;
        cout << "Thank you for buying!!!" << endl;
        cout << "Price: " << (*cost) * count;
        system("PAUSE");
    }
    else
    {
        cout << "Stock not available";
    }
}
void Book::display()
{
    cout << "\nTitle Name: " << title;
    cout << "\nAuthor Name: " << author;
    cout << "\nPrice: " << *cost;
    cout << "\nStock Position: " << *stock;
}
int main()
{
    int choice,i=0,t;
    Book *b[25];
    char tbuy[20], abuy[20];
    while (1)
    {
        system("CLS");
        cout << "\t\tMenu\n" << endl;;
        cout << "1) Register a new book\n2) Edit book details\n3) Search a book\n4) Buy a Book\n5) Exit";
        cout << "\n\nEnter the index number: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b[i] = new Book;
            b[i]->newBook();
            i++;
            break;

        case 2:
            cin.ignore();
            cout << "Enter the title to edit details: ";
            cin.getline(tbuy, 20);
            cout << "Enter the Author's name: ";
            cin.getline(abuy, 20);
            for (t = 0; t < i; t++)
            {
                if (b[t]->search(tbuy, abuy))
                {
                    cout << "Book found successfully";
                    b[t]->editBook();
                    system("PAUSE");
                }
            }
            if (t == i)
            {
                cout << "Book is not in stock rn";
            }
            break;

        case 3:
            cin.ignore();
            cout << "Enter the title to edit details: ";
            cin.getline(tbuy, 40);
            cout << "Enter the Author's name: ";
            cin.getline(abuy, 20);
            for (t = 0; t < i; t++)
            {
                if (b[t]->search(tbuy, abuy))
                {
                    cout << "Book found successfully";
                    b[t]->display();
                }
            }
            if (t == i)
            {
                cout << "Book is not in stock rn";
            }
            break;

        case 4:
            cin.ignore();
            cout << "Enter the title to edit details: ";
            cin.getline(tbuy, 40);
            cout << "Enter the Author's name: ";
            cin.getline(abuy, 20);
            for (t = 0; t < i; t++)
            {
                if (b[t]->search(tbuy, abuy))
                {
                    cout << "Book found successfully\n\n";
                    b[t]->buyBook();
                }
            }
            if (t == i)
            {
                cout << "Book is not in stock rn";
            }
            break;

        case 5:
            exit(0);

        default:
            cout << "Enter a valid option!!!";
        }
    }
    return 0;
}