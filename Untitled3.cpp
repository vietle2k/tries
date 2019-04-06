#include <bits/stdc++.h>

using namespace std;

stack<string> st;

struct Tag {
    string name, value;
    map<string, bool> nextTag;
    map<string, string> attri;
};

map<string, Tag> A;
map<string, bool> firstTag;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    // Tao danh sach
    for (int i = 1; i <= n; i++){
        cin >> s;
        if (s[1] == '/')
            st.pop();
        else {// Them vao danh sach
            s.erase(0, 1);
            bool ok = 1;
            if (s[s.size() - 1] == '>'){// Tag do khong co thuoc tinh
                ok = 0;
                s.erase(s.size() - 1, 1);
            }
            if (st.size())
                A[st.top()].nextTag[s] = 1; // st.top() di toi s
            else firstTag[s] = 1;
            st.push(s);
            while (ok){// Lap lai viec them thuoc tinh
                string sAttri, stam, sValue;
                cin >> sAttri >> stam >> sValue;
                if (sValue[sValue.size() - 1] == '>'){
                    ok = 0;
                    sValue.erase(sValue.size() - 1, 1);
                }
                sValue.erase(sValue.size() - 1, 1);
                sValue.erase(0, 1);
                A[s].attri[sAttri] = sValue;
            }
        }
    }
    /////////Querrrrryyyyyyyyy!!!/////////////////
    for (int i = 1; i <= q; i++){
        cin >> s;
        string stam = "", tagNow = "";
        bool ok = 0;
        for (int j = 0; j < s.size(); j++)
        if (s[j] == '.' || s[j] == '~'){
            if ( (tagNow == "" && !firstTag[stam]) || (tagNow != "" && !A[tagNow].nextTag[stam]) ) {// Truy van sai
                cout << "Not Found!" << '\n';
                ok = 1;
                break;
            }
            tagNow = stam;
            stam = "";
        }
        else stam += s[j];
        if (ok == 1)
            continue;
        if (A[tagNow].attri[stam] == "") // Khong co thuoc tinh
            cout << "Not Found!" << '\n';
        else
            cout << A[tagNow].attri[stam] << '\n';
    }
    return 0;
}
