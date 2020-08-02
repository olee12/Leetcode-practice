#include <bits/stdc++.h>
using namespace std;

struct Book {
    string name;
    string author;
    Book(string _n, string _a) : name(_n), author(_a) {}
    bool operator == (const Book &b) const {
        return b.author == author && b.name == name;
    }
    
};
struct Book_comparator {
    bool operator () (const Book& a,const Book& b) const {
        if(a.author == b.author) {
            return a.name < b.name;
        }
        return a.author < b.author;
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
    
    while(ptr<book.size() && book[ptr]==' ') ptr++;
    ptr+=2; // by
    while(ptr<book.size() && book[ptr]==' ') ptr++;
    // printf("%d, %d book = %s\n", ptr,book.size(),  book.c_str());
    if (ptr < book.size()) {
       author = book.substr(ptr);
    }
    return Book(name, author);
}

vector<string> ProcessBooks(vector<string> &library, vector<string> &operations) {
    set<Book, Book_comparator> slv;
    set<Book, Book_comparator> rtn;
    map<string, string> bookToAuthor;
    vector<string> instruction;

    for( string &title : library) {
        Book b = parseBookName(title);
        // printf("slv -- name: %s, author: %s\n", b.name.c_str(), b.author.c_str());
        slv.insert(b);
        bookToAuthor[b.name] = b.author;
    }

    for(string &operation: operations) {
        // cout << "operation line : " + operation<<endl;
        char op[20];
        char title[200];
        sscanf(operation.c_str(), " %s ", op);
        if (string(op) == BORROW) {
            string t = operation.substr(strlen(op)); 
            Book b = parseBookName(t);
            slv.erase(Book(b.name, bookToAuthor[b.name]));
        }else if (string(op) == RETURN) {
            string t = operation.substr(strlen(op)); 
            Book b = parseBookName(t);
            rtn.insert(Book(b.name, bookToAuthor[b.name]));
        }else if (string(op)==SHELVE){
            // printf("sleve---- %s\n", operation.c_str());

            // for(auto s : slv) {
            //     cout<<s.name << ' '<< s.author << endl;
            // }
            // printf("-------\n");
            for(auto b : rtn) {
                // printf("--- %s %s\n", b.author.c_str(), b.name.c_str());
                multiset<Book>::iterator it = slv.lower_bound(b);
                if(slv.size()==0 || (it == slv.begin() && b.author + b.name < (*it).author + (*it).name) )  {
                    // put first
                    
                    instruction.push_back("PUT "+ b.name + " first");
                }
                else {
                    if (it != slv.begin()) it--;
                    instruction.push_back("PUT "+b.name +" after "+ (*it).name);
                }
                slv.insert(b);
            }
            rtn.clear();
        }
        // printf("op: %s title: %s\n", op, operation.substr(strlen(op)).c_str());
    }
    
    return instruction;


}


int main() {

    vector<string> library;
    vector<string> operations;
    char line[200];
    int end = 0;
    while(scanf( " %[^\n]", line)!=EOF) {
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
    for(auto &inst: instruction) {
        printf("%s\n", inst.c_str());
    }
    if(instruction.size())
        printf("END\n");
    
}