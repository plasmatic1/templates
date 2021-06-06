#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Defines and one-liners
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
template <typename T> inline T& back(vector<T> &vec) { return *(vec.end() - 1); }
template <typename T> inline void pop(vector<T> &vec) { return vec.erase(vec.end() - 1); }

// Scan, Debug, and other nonsense
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void printArray(ostream& out,T* arr,int sz){out<<"[";for(int i=0;i<sz;i++){out<<arr[i]<<", "; } out<<"]";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

mt19937 gen(time(NULL));
uniform_int_distribution<int> dis;
struct Node {
    int val; int pri, sz; Node *l, *r;
    Node(int val0) : val(val0), pri(dis(gen)), sz(1), l(nullptr), r(nullptr) {}
};
struct ImplicitTreap {
    Node* root;
    ImplicitTreap() : root(nullptr) {}
    int sz(Node* &cur) { return cur ? cur->sz : 0; }
    void upd(Node* &cur) { 
        if (cur) cur->sz = sz(cur->l) + sz(cur->r) + 1; 
    }
    void pushDown(Node* &cur) {
        // assert(("Not Implemented Yet!", 0));
    }
    void split(Node* cur, int key, Node* &l, Node* &r) {
        pushDown(cur);
        if (!cur) l = r = nullptr;
        else if (key <= sz(cur->l) + 1) { split(cur->l, key, l, cur->l); r = cur; }
        else { split(cur->r, key - sz(cur->l) - 1, cur->r, r); l = cur; }
        upd(cur);
    }
    void merge(Node* &cur, Node* l, Node* r) {
        pushDown(l); pushDown(r);
        if (!l || !r) cur = l ? l : r;
        else if (l->pri > r->pri) { merge(l->r, l->r, r); cur = l; }
        else { merge(r->l, l, r->l); cur = r; }
        upd(cur);
    }
    void insert(Node* &cur, int key, Node* node) {
        Node* rhs;
        split(cur, key, cur, rhs);
        merge(cur, cur, node);
        merge(cur, cur, rhs);
    }
    void remove(Node* &cur, int key) {
        pushDown(cur);
        if (!cur) return;
        int cKey = sz(cur->l) + 1;
        if (key == cKey) { merge(cur, cur->l, cur->r); }
        else { key > cKey ? remove(cur->r, key - cKey) : remove(cur->l, key); }
        upd(cur);
    }
    Node* kth(Node* &cur, int idx) {
        pushDown(cur);
        int cKey = sz(cur->l) + 1;
        if (idx == cKey) return cur;
        auto ret = idx < cKey ? kth(cur->l, idx) : kth(cur->r, idx - cKey);
        upd(cur);
        return ret;
    }
    void inOrder(Node* &cur) {
        if (!cur) return;
        pushDown(cur);
        inOrder(cur->l); cout << cur->val << " "; inOrder(cur->r);
    }
};

ImplicitTreap t;

void doInOrder() {
    cout << "(Pre-Query) Inorder: ";
    t.inOrder(t.root);
    cout << "\n"; cout.flush();
}

void ins(int before, int val) {
    doInOrder();

    cout << "Insert At Pos: " << before << ", Value: " << val << "\n"; cout.flush();
    t.insert(t.root, before, new Node(val));
}

void del(int idx) {
    doInOrder();

    cout << "Delete At Pos: " << idx << "\n"; cout.flush();
    t.remove(t.root, idx);
}

void kth(int idx, int ans) {
    doInOrder();

    auto nd = t.kth(t.root, idx);
    cout << "Search for Pos: " << idx << ", Return|Ans: " << nd->val << "|" << ans << "\n"; cout.flush();
    assert(nd->val == ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ins(1, 4);
    ins(1, 15);
    del(2);
    del(1);
    ins(1, 17);
    ins(1, 12);
    ins(1, 15);
    ins(3, 16);
    del(3);
    kth(2, 12);
    ins(4, 7);
    ins(1, 10);
    ins(6, 11);
    kth(5, 7);
    kth(6, 11);
    ins(7, 11);
    kth(2, 15);
    kth(6, 11);
    ins(1, 2);
    kth(4, 12);
    kth(4, 12);
    kth(1, 2);
    ins(1, 17);
    del(1);
    del(3);
    ins(4, 20);
    ins(9, 13);
    kth(5, 17);
    del(9);
    ins(6, 15);
    ins(1, 5);
    ins(9, 1);
    kth(2, 2);
    kth(6, 17);
    ins(1, 10);
    ins(1, 2);
    ins(11, 19);
    del(6);
    ins(3, 4);
    del(11);
    kth(9, 15);
    kth(7, 20);
    ins(3, 3);
    ins(1, 20);
    ins(12, 15);
    kth(16, 11);
    kth(4, 3);
    kth(8, 10);
    kth(3, 10);
    kth(16, 11);
    ins(14, 10);
    kth(9, 20);
    ins(4, 10);
    ins(18, 10);
    ins(6, 12);
    kth(10, 10);
    ins(13, 10);
    ins(12, 18);
    del(11);
    ins(1, 14);
    del(6);
    kth(20, 10);
    del(7);
    kth(19, 10);
    kth(2, 20);
    ins(11, 3);
    ins(3, 11);
    del(8);
    kth(7, 12);
    kth(9, 10);
    ins(2, 6);
    ins(8, 1);
    ins(1, 11);
    ins(8, 12);
    ins(7, 9);
    del(14);
    kth(3, 6);
    kth(7, 9);
    kth(24, 10);
    ins(7, 12);
    ins(9, 20);
    ins(3, 19);
    ins(18, 14);
    ins(9, 17);
    ins(21, 5);
    del(4);
    kth(6, 2);
    ins(29, 4);
    ins(7, 6);
    kth(9, 17);
    ins(16, 10);
    del(33);
    ins(15, 5);
    ins(17, 1);
    del(33);
    ins(16, 19);
    ins(27, 16);
    ins(32, 1);
    kth(6, 2);
    ins(37, 18);
    kth(27, 16);
    kth(2, 14);
    del(9);
    kth(21, 18);
    kth(21, 18);
    ins(27, 4);
    ins(36, 13);
    ins(37, 12);
    kth(34, 1);
    ins(4, 12);
    ins(30, 14);
    kth(32, 15);
    ins(34, 19);
    ins(20, 13);
    ins(13, 6);
    del(35);
    kth(8, 6);
    del(26);
    ins(25, 14);
    ins(36, 11);
    kth(32, 14);
    kth(9, 12);
    ins(30, 16);
    kth(37, 11);
    ins(45, 20);
    kth(33, 14);
    kth(11, 20);
    ins(3, 11);
    ins(29, 6);
    del(5);
    ins(3, 10);
    ins(17, 1);
    del(22);
    del(12);
    del(39);
    del(25);
    ins(33, 20);
    kth(37, 19);
    ins(26, 18);
    del(24);
    del(44);
    kth(28, 17);
    kth(15, 10);
    kth(12, 10);
    del(23);
    kth(34, 15);
    ins(5, 3);
    kth(22, 13);
    ins(33, 8);
    ins(38, 5);
    kth(46, 20);
    ins(47, 2);
    del(5);
    ins(16, 15);
    kth(37, 15);
    kth(8, 2);
    kth(37, 15);
    ins(43, 7);
    del(4);
    del(40);
    kth(31, 10);
    ins(11, 15);
    del(23);
    ins(2, 14);
    kth(29, 16);
    ins(36, 4);
    ins(49, 3);
    kth(37, 15);
    ins(12, 18);
    kth(20, 5);
    ins(15, 15);
    del(1);
    ins(22, 13);
    ins(15, 14);
    ins(46, 12);
    kth(9, 12);
    kth(17, 12);
    ins(8, 10);
    ins(34, 14);
    ins(31, 4);
    kth(29, 18);
    ins(29, 16);
    kth(49, 1);
    kth(14, 10);
    kth(33, 6);
    ins(19, 9);
    ins(57, 1);
    ins(22, 18);
    kth(38, 14);
    del(2);
    del(37);
    ins(47, 15);
    kth(27, 1);
    ins(9, 12);
    ins(41, 12);
    del(17);
    kth(56, 12);
    ins(52, 19);
    kth(3, 19);
    kth(32, 5);
    ins(57, 8);
    del(43);
    ins(44, 17);
    ins(27, 13);
    del(52);
    ins(40, 11);
    kth(51, 19);
    kth(7, 10);
    kth(16, 14);
    ins(8, 5);
    del(60);
    ins(57, 4);
    ins(26, 18);
    kth(39, 16);
    ins(22, 4);
    kth(38, 6);
    kth(31, 1);
    ins(6, 16);
    del(34);
    del(32);
    kth(36, 4);
    kth(17, 15);
    kth(11, 12);
    kth(27, 19);
    ins(44, 16);
    kth(63, 20);
    del(33);
    kth(62, 20);
    ins(61, 11);
    ins(24, 3);
    ins(40, 7);
    ins(56, 10);
    kth(2, 10);
    kth(43, 11);
    kth(17, 15);
    kth(41, 16);
    ins(9, 13);
    kth(21, 9);
    ins(42, 8);
    del(35);
    ins(40, 2);
    kth(17, 10);
    ins(7, 17);
    ins(23, 3);
    kth(36, 13);
    del(2);
    del(10);
    ins(57, 16);
    ins(48, 14);
    del(18);
    kth(51, 4);
    kth(13, 9);
    ins(3, 6);
    del(39);
    del(39);
    del(59);
    kth(8, 2);
    ins(61, 8);
    ins(47, 5);
    ins(26, 19);
    del(21);
    ins(11, 4);
    ins(72, 9);
    ins(1, 2);
    kth(31, 19);
    kth(72, 1);
    kth(43, 16);
    kth(7, 16);
    del(64);
    kth(65, 4);
    ins(75, 4);
    ins(45, 7);
    del(2);
    kth(69, 8);
    kth(20, 12);
    del(70);
    ins(6, 11);
    kth(9, 2);
    kth(76, 18);
    ins(73, 7);
    kth(28, 18);
    ins(63, 20);
    ins(56, 9);
    ins(56, 10);
    ins(6, 20);
    ins(47, 13);
    ins(35, 8);
    del(48);
    kth(62, 5);
    kth(30, 1);
    ins(2, 2);
    kth(7, 20);
    ins(4, 12);
    ins(12, 11);
    ins(67, 10);
    del(31);
    ins(45, 7);
    ins(25, 14);
    ins(44, 15);
    kth(74, 19);
    ins(7, 11);
    kth(82, 8);
    ins(26, 5);
    ins(80, 5);
    kth(17, 4);
    kth(20, 12);
    kth(34, 18);
    del(37);
    kth(76, 12);
    kth(51, 16);
    ins(54, 16);
    del(50);
    kth(42, 13);
    del(29);
    del(14);
    kth(10, 11);
    ins(1, 16);
    ins(56, 9);
    del(47);
    ins(76, 2);
    kth(79, 5);
    del(74);
    kth(34, 1);
    kth(68, 15);
    ins(88, 16);
    kth(34, 1);
    ins(90, 3);
    kth(42, 5);
    ins(81, 8);
    del(6);
    kth(34, 5);
    ins(57, 10);
    ins(18, 12);
    ins(78, 9);
    del(80);
    ins(12, 12);
    kth(56, 9);
    kth(49, 16);
    del(71);
    kth(81, 13);
    del(25);
    kth(85, 9);
    kth(6, 20);
    del(76);
    kth(63, 17);
    del(55);
    del(76);
    kth(86, 16);
    del(51);
    del(25);
    ins(76, 4);
    ins(21, 16);
    kth(43, 4);
    ins(76, 15);
    ins(24, 3);
    kth(6, 20);
    kth(1, 16);
    kth(44, 4);
    ins(35, 14);
    ins(65, 20);
    ins(53, 13);
    ins(84, 4);
    ins(24, 17);
    ins(78, 8);
    del(2);
    ins(6, 1);
    ins(6, 4);
    kth(23, 12);
    kth(80, 2);
    ins(44, 12);
    ins(43, 16);
    kth(48, 5);
    ins(2, 14);
    ins(100, 2);
    kth(81, 12);
    kth(72, 9);
    ins(81, 13);
    kth(63, 5);
    kth(78, 19);
    ins(26, 5);
    ins(62, 7);
    ins(21, 14);
    kth(51, 5);
    del(43);
    kth(82, 20);
    kth(91, 4);
    del(76);
    kth(86, 9);
    ins(100, 17);
    kth(28, 17);
    ins(1, 12);
    ins(88, 17);
    ins(49, 5);
    ins(60, 19);
    kth(101, 7);
    kth(59, 4);
    ins(57, 11);
    kth(73, 20);
    del(81);
    del(82);
    ins(44, 1);
    del(27);
    del(99);
    ins(78, 19);
    kth(93, 13);
    kth(31, 15);
    kth(79, 9);
    ins(93, 10);
    kth(106, 4);
    ins(7, 7);
    ins(49, 3);
    del(75);
    kth(99, 11);
    ins(14, 18);
    ins(6, 15);
    del(106);
    ins(80, 6);
    ins(58, 17);
    ins(24, 14);
    ins(85, 6);
    del(7);
    kth(106, 1);
    ins(60, 8);
    ins(13, 12);
    ins(21, 7);
    ins(31, 15);
    ins(23, 8);
    ins(8, 2);
    kth(4, 2);
    ins(62, 3);
    ins(37, 18);
    ins(72, 8);
    ins(67, 17);
    kth(58, 12);
    del(62);
    kth(56, 1);
    ins(65, 14);
    ins(77, 20);
    ins(119, 12);
    ins(104, 2);
    kth(76, 19);
    kth(3, 14);
    ins(63, 2);
    ins(64, 20);
    ins(63, 17);
    kth(17, 11);
    ins(115, 4);
    del(42);
    del(4);
    kth(10, 1);
    del(21);
    ins(103, 7);
    ins(90, 5);
    del(126);
    kth(120, 8);
    del(127);
    kth(5, 15);
    ins(6, 12);
    kth(20, 17);
    ins(120, 14);
    kth(121, 11);
    ins(31, 6);
    kth(8, 2);
    ins(131, 19);
    kth(29, 12);
    del(57);
    del(95);
    kth(101, 10);
    del(5);
    kth(16, 11);
    del(27);
    ins(115, 18);
    kth(41, 10);
    del(7);
    kth(110, 10);
    kth(51, 16);
    kth(48, 1);
    kth(32, 5);
    kth(72, 16);
    kth(44, 18);
    ins(112, 3);
    del(128);
    kth(112, 3);
    ins(116, 18);
    ins(49, 6);
    del(41);
    ins(54, 3);
    ins(5, 7);
    ins(67, 10);
    kth(117, 4);
    ins(27, 8);
    kth(19, 17);
    kth(43, 4);
    ins(19, 5);
    del(115);
    del(44);
    ins(88, 13);
    kth(48, 5);
    del(103);
    ins(108, 20);

    return 0;
}