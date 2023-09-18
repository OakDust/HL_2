#include <iostream>


using namespace std;

class FooString {
    char* buf;
    public:
        FooString(char* tbuf) { 
            buf = tbuf;
        };
        ~FooString() {
            delete[] buf;
        };
        void show() {
            cout << this->buf << endl;
        };

        int length() {
            int i = 0;
            while (buf[i] != '\0') { i++; }
            return i;
        }

        bool compare(FooString str) {
            if (this->length() == str.length()) {
                for (int i = 0; i < this->length(); i++) {
                    if (this->buf[i] != str.buf[i]) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
};

bool test() {
    char* test_buf1 = "Hi, John";
    char* test_buf2 = "Hi, John";
    FooString test_str1(test_buf1);
    FooString test_str2(test_buf2);

    return test_str1.compare(test_str2);
}

int main() {
    char* buf;
    cout << "Enter your string\n";
    cin.getline(buf, 256);
    FooString string(buf);

    char* u_buf;
    cout << "Enter another string\n";
    cin.getline(u_buf, 256);
    FooString u_str(u_buf);

    bool check = string.compare(u_str);
    check ? cout << "They are equal\n" : cout << "They are different\n";

    string.show();

    test() ? cout << "Tests are passed\n" : cout << "Tests are not passed\n";

    return 0;
}