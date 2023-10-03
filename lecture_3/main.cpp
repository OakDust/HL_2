#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class GiftTransformer {
    private:
    string fileTXT, fileGIFT;
    ifstream txt;
    ofstream gift;

    public:
    GiftTransformer(string fileTXT, string fileGIFT) {
        txt.open(fileTXT);
        gift.open(fileGIFT);
    }

    ~GiftTransformer() {
        gift.close();
        txt.close();
    }

    int txt_to_gift() {
        bool bracket = false;
        string str = "";
        while (getline(txt, str)){
            if (str.find(".") == 1 && str.find("?") != str.length()) {
                if (bracket) {
                    gift << "\n}\n" << str << " {";
                }
                else {
                    gift << str << " {";
                    bracket = true;
                }
            }
            else if (str[0] == '-') {
                gift << "\n" << str.replace(0, 1, "~");
            }
            else if (str[0] == '+') {
                gift << "\n" << str.replace(0, 1, "=");
            }
        }
    gift << "\n}";

    return 0;
    }
};

int main() {
    GiftTransformer transform("file.txt", "file.gift");
    transform.txt_to_gift();
    return 0;
}