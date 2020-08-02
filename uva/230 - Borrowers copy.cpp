#include <bits/stdc++.h>
using namespace std;

struct Book {
    string name;
    string author;
    Book(string _n, string _a) : name(_n), author(_a) {}
    bool operator == (const Book &b) const {
        return b.author == author && b.name == name;
    }
    bool operator < (const Book &b) const {
        if (author != b.author) {
            return author < b.author;
        }
        return name < b.name;
    }


};

const string BORROW = "BORROW";
const string RETURN = "RETURN";
const string SHELVE = "SHELVE";



Book parseBookName(string &book) {
    string op = "";
    string name = "";
    string author = "";
    int ptr = 0;
    // while(ptr < book.size() && book[ptr] != ' ') op.push_back(book[ptr++]);
    int qcount = 0;
    while(ptr < book.size() && qcount < 2) {
        if(book[ptr] == '\"') {
            qcount++;
        }
        if(qcount) name.push_back(book[ptr]);
        ptr++;
    }
    // cout<<qcount<<' '<<name<<' '<<book<<endl;
    assert(qcount == 2);
    
    while(ptr<book.size() && book[ptr]==' ') ptr++;
    ptr+=2; // by
    while(ptr<book.size() && book[ptr]==' ') ptr++;
    // printf("%d, %d book = %s\n", ptr,book.size(),  book.c_str());
    if (ptr < book.size()) {
       author = book.substr(ptr);
       assert(author!="");
    }
    assert(name!="");
    return Book(name, author);
}

vector<string> ProcessBooks(vector<string> &library, vector<string> &operations) {
    vector<string> instruction;
    map<string, int> bookPosition;
    vector<Book> books;    

    for(string &lib : library) {
        books.push_back(parseBookName(lib));
    }

    sort(books.begin(), books.end());
    vector<bool> borrowed(books.size(), false);
    vector<bool> returned(books.size(), false);
    
    map<string, bool> existing;
    map<string, bool> author;

    for (int i = 0;i<books.size();i++) {
        bookPosition[books[i].name] = i; 
        existing[books[i].name] = true;
    }

    for(string &operation: operations) {
        // cout << "operation line : " + operation<<endl;
        char op[20];
        char title[200];
        sscanf(operation.c_str(), " %s ", op);
        if (string(op) == BORROW) {
            string t = operation.substr(strlen(op)); 
            Book b = parseBookName(t);
            assert(existing[b.name]);
            assert(b.name!="");

            borrowed[bookPosition[b.name]] = true;
            returned[bookPosition[b.name]] = false;
        }else if (string(op) == RETURN) {
            string t = operation.substr(strlen(op)); 
            Book b = parseBookName(t);
            assert(existing[b.name]);
            assert(b.name!="");
            returned[bookPosition[b.name]] = true;
        }else if (string(op)==SHELVE){
            int positon = -1;
            for(int i = 0;i<books.size();i++) {
                if(borrowed[i]==false) positon = i;
                else if(returned[i] == true) {
                    if (positon == -1) {
                        printf("%s", ("Put "+ books[i].name + " first"+"\n").c_str());
                    }else {
                        printf("%s",("Put "+ books[i].name +" after "+ books[positon].name+"\n").c_str());
                    }
                    positon = i;
                    returned[i]= false;
                    borrowed[i]=false;
                }
            }
            printf("END\n");

        }else {
            assert(0);
        }
        // printf("op: %s title: %s\n", op, operation.substr(strlen(op)).c_str());
    }
    
    return instruction;


}


int main() {

    vector<string> library;
    vector<string> operations;
    char line[2000];
    int end = 0;
    while(scanf( " %[^\n] ", line)!=EOF) {
        if (string(line) == "END") {
            end++;
            if (end == 2) 
                break;
            else 
               continue;
        }
        if (end == 0) {
            library.push_back(line);
        }else if(end == 1) {
           operations.push_back(line); 
        }else {
            break;
        }
    }

    auto instruction = ProcessBooks(library, operations);
    // for(auto &inst: instruction) {
    //     printf("%s\n", inst.c_str());
    // }
    // if(instruction.size())
    //     printf("END\n");
    
}