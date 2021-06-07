---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/test.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\ntypedef long long ll;\n\n// Defines and one-liners\n#define INF 0x3f3f3f3f\n\
    #define LLINF 0x3f3f3f3f3f3f3f3f\ntemplate <typename T> inline T& back(vector<T>\
    \ &vec) { return *(vec.end() - 1); }\ntemplate <typename T> inline void pop(vector<T>\
    \ &vec) { return vec.erase(vec.end() - 1); }\n\n// Scan, Debug, and other nonsense\n\
    template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<\"\
    [\";for(auto t:iter){out<<t<<\", \";}out<<\"]\";return out;}\ntemplate <typename\
    \ T> void printArray(ostream& out,T* arr,int sz){out<<\"[\";for(int i=0;i<sz;i++){out<<arr[i]<<\"\
    , \"; } out<<\"]\";}\n#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream&\
    \ out,type obj){out<<\"(\"<<#propa<<\"=\"<<obj. propa<<\", \"<<#propb<<\"=\"<<obj.\
    \ propb<<\")\";return out;}\n\nvoid scan(){}\ntemplate<typename F, typename...\
    \ R> void scan(F &f,R&... r){cin>>f;scan(r...);}\nint di_; string dnms_, co_ =\
    \ \",\";\nvoid debug_(){cout<<endl;}\ntemplate<typename F, typename... R> void\
    \ debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<\"\
    : \"<<f<<\",\";debug_(r...);}\n#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)\n\
    \nmt19937 gen(time(NULL));\nuniform_int_distribution<int> dis;\nstruct Node {\n\
    \    int val; int pri, sz; Node *l, *r;\n    Node(int val0) : val(val0), pri(dis(gen)),\
    \ sz(1), l(nullptr), r(nullptr) {}\n};\nstruct ImplicitTreap {\n    Node* root;\n\
    \    ImplicitTreap() : root(nullptr) {}\n    int sz(Node* &cur) { return cur ?\
    \ cur->sz : 0; }\n    void upd(Node* &cur) { \n        if (cur) cur->sz = sz(cur->l)\
    \ + sz(cur->r) + 1; \n    }\n    void pushDown(Node* &cur) {\n        // assert((\"\
    Not Implemented Yet!\", 0));\n    }\n    void split(Node* cur, int key, Node*\
    \ &l, Node* &r) {\n        pushDown(cur);\n        if (!cur) l = r = nullptr;\n\
    \        else if (key <= sz(cur->l) + 1) { split(cur->l, key, l, cur->l); r =\
    \ cur; }\n        else { split(cur->r, key - sz(cur->l) - 1, cur->r, r); l = cur;\
    \ }\n        upd(cur);\n    }\n    void merge(Node* &cur, Node* l, Node* r) {\n\
    \        pushDown(l); pushDown(r);\n        if (!l || !r) cur = l ? l : r;\n \
    \       else if (l->pri > r->pri) { merge(l->r, l->r, r); cur = l; }\n       \
    \ else { merge(r->l, l, r->l); cur = r; }\n        upd(cur);\n    }\n    void\
    \ insert(Node* &cur, int key, Node* node) {\n        Node* rhs;\n        split(cur,\
    \ key, cur, rhs);\n        merge(cur, cur, node);\n        merge(cur, cur, rhs);\n\
    \    }\n    void remove(Node* &cur, int key) {\n        pushDown(cur);\n     \
    \   if (!cur) return;\n        int cKey = sz(cur->l) + 1;\n        if (key ==\
    \ cKey) { merge(cur, cur->l, cur->r); }\n        else { key > cKey ? remove(cur->r,\
    \ key - cKey) : remove(cur->l, key); }\n        upd(cur);\n    }\n    Node* kth(Node*\
    \ &cur, int idx) {\n        pushDown(cur);\n        int cKey = sz(cur->l) + 1;\n\
    \        if (idx == cKey) return cur;\n        auto ret = idx < cKey ? kth(cur->l,\
    \ idx) : kth(cur->r, idx - cKey);\n        upd(cur);\n        return ret;\n  \
    \  }\n    void inOrder(Node* &cur) {\n        if (!cur) return;\n        pushDown(cur);\n\
    \        inOrder(cur->l); cout << cur->val << \" \"; inOrder(cur->r);\n    }\n\
    };\n\nImplicitTreap t;\n\nvoid doInOrder() {\n    cout << \"(Pre-Query) Inorder:\
    \ \";\n    t.inOrder(t.root);\n    cout << \"\\n\"; cout.flush();\n}\n\nvoid ins(int\
    \ before, int val) {\n    doInOrder();\n\n    cout << \"Insert At Pos: \" << before\
    \ << \", Value: \" << val << \"\\n\"; cout.flush();\n    t.insert(t.root, before,\
    \ new Node(val));\n}\n\nvoid del(int idx) {\n    doInOrder();\n\n    cout << \"\
    Delete At Pos: \" << idx << \"\\n\"; cout.flush();\n    t.remove(t.root, idx);\n\
    }\n\nvoid kth(int idx, int ans) {\n    doInOrder();\n\n    auto nd = t.kth(t.root,\
    \ idx);\n    cout << \"Search for Pos: \" << idx << \", Return|Ans: \" << nd->val\
    \ << \"|\" << ans << \"\\n\"; cout.flush();\n    assert(nd->val == ans);\n}\n\n\
    int main(){\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\n   \
    \ ins(1, 4);\n    ins(1, 15);\n    del(2);\n    del(1);\n    ins(1, 17);\n   \
    \ ins(1, 12);\n    ins(1, 15);\n    ins(3, 16);\n    del(3);\n    kth(2, 12);\n\
    \    ins(4, 7);\n    ins(1, 10);\n    ins(6, 11);\n    kth(5, 7);\n    kth(6,\
    \ 11);\n    ins(7, 11);\n    kth(2, 15);\n    kth(6, 11);\n    ins(1, 2);\n  \
    \  kth(4, 12);\n    kth(4, 12);\n    kth(1, 2);\n    ins(1, 17);\n    del(1);\n\
    \    del(3);\n    ins(4, 20);\n    ins(9, 13);\n    kth(5, 17);\n    del(9);\n\
    \    ins(6, 15);\n    ins(1, 5);\n    ins(9, 1);\n    kth(2, 2);\n    kth(6, 17);\n\
    \    ins(1, 10);\n    ins(1, 2);\n    ins(11, 19);\n    del(6);\n    ins(3, 4);\n\
    \    del(11);\n    kth(9, 15);\n    kth(7, 20);\n    ins(3, 3);\n    ins(1, 20);\n\
    \    ins(12, 15);\n    kth(16, 11);\n    kth(4, 3);\n    kth(8, 10);\n    kth(3,\
    \ 10);\n    kth(16, 11);\n    ins(14, 10);\n    kth(9, 20);\n    ins(4, 10);\n\
    \    ins(18, 10);\n    ins(6, 12);\n    kth(10, 10);\n    ins(13, 10);\n    ins(12,\
    \ 18);\n    del(11);\n    ins(1, 14);\n    del(6);\n    kth(20, 10);\n    del(7);\n\
    \    kth(19, 10);\n    kth(2, 20);\n    ins(11, 3);\n    ins(3, 11);\n    del(8);\n\
    \    kth(7, 12);\n    kth(9, 10);\n    ins(2, 6);\n    ins(8, 1);\n    ins(1,\
    \ 11);\n    ins(8, 12);\n    ins(7, 9);\n    del(14);\n    kth(3, 6);\n    kth(7,\
    \ 9);\n    kth(24, 10);\n    ins(7, 12);\n    ins(9, 20);\n    ins(3, 19);\n \
    \   ins(18, 14);\n    ins(9, 17);\n    ins(21, 5);\n    del(4);\n    kth(6, 2);\n\
    \    ins(29, 4);\n    ins(7, 6);\n    kth(9, 17);\n    ins(16, 10);\n    del(33);\n\
    \    ins(15, 5);\n    ins(17, 1);\n    del(33);\n    ins(16, 19);\n    ins(27,\
    \ 16);\n    ins(32, 1);\n    kth(6, 2);\n    ins(37, 18);\n    kth(27, 16);\n\
    \    kth(2, 14);\n    del(9);\n    kth(21, 18);\n    kth(21, 18);\n    ins(27,\
    \ 4);\n    ins(36, 13);\n    ins(37, 12);\n    kth(34, 1);\n    ins(4, 12);\n\
    \    ins(30, 14);\n    kth(32, 15);\n    ins(34, 19);\n    ins(20, 13);\n    ins(13,\
    \ 6);\n    del(35);\n    kth(8, 6);\n    del(26);\n    ins(25, 14);\n    ins(36,\
    \ 11);\n    kth(32, 14);\n    kth(9, 12);\n    ins(30, 16);\n    kth(37, 11);\n\
    \    ins(45, 20);\n    kth(33, 14);\n    kth(11, 20);\n    ins(3, 11);\n    ins(29,\
    \ 6);\n    del(5);\n    ins(3, 10);\n    ins(17, 1);\n    del(22);\n    del(12);\n\
    \    del(39);\n    del(25);\n    ins(33, 20);\n    kth(37, 19);\n    ins(26, 18);\n\
    \    del(24);\n    del(44);\n    kth(28, 17);\n    kth(15, 10);\n    kth(12, 10);\n\
    \    del(23);\n    kth(34, 15);\n    ins(5, 3);\n    kth(22, 13);\n    ins(33,\
    \ 8);\n    ins(38, 5);\n    kth(46, 20);\n    ins(47, 2);\n    del(5);\n    ins(16,\
    \ 15);\n    kth(37, 15);\n    kth(8, 2);\n    kth(37, 15);\n    ins(43, 7);\n\
    \    del(4);\n    del(40);\n    kth(31, 10);\n    ins(11, 15);\n    del(23);\n\
    \    ins(2, 14);\n    kth(29, 16);\n    ins(36, 4);\n    ins(49, 3);\n    kth(37,\
    \ 15);\n    ins(12, 18);\n    kth(20, 5);\n    ins(15, 15);\n    del(1);\n   \
    \ ins(22, 13);\n    ins(15, 14);\n    ins(46, 12);\n    kth(9, 12);\n    kth(17,\
    \ 12);\n    ins(8, 10);\n    ins(34, 14);\n    ins(31, 4);\n    kth(29, 18);\n\
    \    ins(29, 16);\n    kth(49, 1);\n    kth(14, 10);\n    kth(33, 6);\n    ins(19,\
    \ 9);\n    ins(57, 1);\n    ins(22, 18);\n    kth(38, 14);\n    del(2);\n    del(37);\n\
    \    ins(47, 15);\n    kth(27, 1);\n    ins(9, 12);\n    ins(41, 12);\n    del(17);\n\
    \    kth(56, 12);\n    ins(52, 19);\n    kth(3, 19);\n    kth(32, 5);\n    ins(57,\
    \ 8);\n    del(43);\n    ins(44, 17);\n    ins(27, 13);\n    del(52);\n    ins(40,\
    \ 11);\n    kth(51, 19);\n    kth(7, 10);\n    kth(16, 14);\n    ins(8, 5);\n\
    \    del(60);\n    ins(57, 4);\n    ins(26, 18);\n    kth(39, 16);\n    ins(22,\
    \ 4);\n    kth(38, 6);\n    kth(31, 1);\n    ins(6, 16);\n    del(34);\n    del(32);\n\
    \    kth(36, 4);\n    kth(17, 15);\n    kth(11, 12);\n    kth(27, 19);\n    ins(44,\
    \ 16);\n    kth(63, 20);\n    del(33);\n    kth(62, 20);\n    ins(61, 11);\n \
    \   ins(24, 3);\n    ins(40, 7);\n    ins(56, 10);\n    kth(2, 10);\n    kth(43,\
    \ 11);\n    kth(17, 15);\n    kth(41, 16);\n    ins(9, 13);\n    kth(21, 9);\n\
    \    ins(42, 8);\n    del(35);\n    ins(40, 2);\n    kth(17, 10);\n    ins(7,\
    \ 17);\n    ins(23, 3);\n    kth(36, 13);\n    del(2);\n    del(10);\n    ins(57,\
    \ 16);\n    ins(48, 14);\n    del(18);\n    kth(51, 4);\n    kth(13, 9);\n   \
    \ ins(3, 6);\n    del(39);\n    del(39);\n    del(59);\n    kth(8, 2);\n    ins(61,\
    \ 8);\n    ins(47, 5);\n    ins(26, 19);\n    del(21);\n    ins(11, 4);\n    ins(72,\
    \ 9);\n    ins(1, 2);\n    kth(31, 19);\n    kth(72, 1);\n    kth(43, 16);\n \
    \   kth(7, 16);\n    del(64);\n    kth(65, 4);\n    ins(75, 4);\n    ins(45, 7);\n\
    \    del(2);\n    kth(69, 8);\n    kth(20, 12);\n    del(70);\n    ins(6, 11);\n\
    \    kth(9, 2);\n    kth(76, 18);\n    ins(73, 7);\n    kth(28, 18);\n    ins(63,\
    \ 20);\n    ins(56, 9);\n    ins(56, 10);\n    ins(6, 20);\n    ins(47, 13);\n\
    \    ins(35, 8);\n    del(48);\n    kth(62, 5);\n    kth(30, 1);\n    ins(2, 2);\n\
    \    kth(7, 20);\n    ins(4, 12);\n    ins(12, 11);\n    ins(67, 10);\n    del(31);\n\
    \    ins(45, 7);\n    ins(25, 14);\n    ins(44, 15);\n    kth(74, 19);\n    ins(7,\
    \ 11);\n    kth(82, 8);\n    ins(26, 5);\n    ins(80, 5);\n    kth(17, 4);\n \
    \   kth(20, 12);\n    kth(34, 18);\n    del(37);\n    kth(76, 12);\n    kth(51,\
    \ 16);\n    ins(54, 16);\n    del(50);\n    kth(42, 13);\n    del(29);\n    del(14);\n\
    \    kth(10, 11);\n    ins(1, 16);\n    ins(56, 9);\n    del(47);\n    ins(76,\
    \ 2);\n    kth(79, 5);\n    del(74);\n    kth(34, 1);\n    kth(68, 15);\n    ins(88,\
    \ 16);\n    kth(34, 1);\n    ins(90, 3);\n    kth(42, 5);\n    ins(81, 8);\n \
    \   del(6);\n    kth(34, 5);\n    ins(57, 10);\n    ins(18, 12);\n    ins(78,\
    \ 9);\n    del(80);\n    ins(12, 12);\n    kth(56, 9);\n    kth(49, 16);\n   \
    \ del(71);\n    kth(81, 13);\n    del(25);\n    kth(85, 9);\n    kth(6, 20);\n\
    \    del(76);\n    kth(63, 17);\n    del(55);\n    del(76);\n    kth(86, 16);\n\
    \    del(51);\n    del(25);\n    ins(76, 4);\n    ins(21, 16);\n    kth(43, 4);\n\
    \    ins(76, 15);\n    ins(24, 3);\n    kth(6, 20);\n    kth(1, 16);\n    kth(44,\
    \ 4);\n    ins(35, 14);\n    ins(65, 20);\n    ins(53, 13);\n    ins(84, 4);\n\
    \    ins(24, 17);\n    ins(78, 8);\n    del(2);\n    ins(6, 1);\n    ins(6, 4);\n\
    \    kth(23, 12);\n    kth(80, 2);\n    ins(44, 12);\n    ins(43, 16);\n    kth(48,\
    \ 5);\n    ins(2, 14);\n    ins(100, 2);\n    kth(81, 12);\n    kth(72, 9);\n\
    \    ins(81, 13);\n    kth(63, 5);\n    kth(78, 19);\n    ins(26, 5);\n    ins(62,\
    \ 7);\n    ins(21, 14);\n    kth(51, 5);\n    del(43);\n    kth(82, 20);\n   \
    \ kth(91, 4);\n    del(76);\n    kth(86, 9);\n    ins(100, 17);\n    kth(28, 17);\n\
    \    ins(1, 12);\n    ins(88, 17);\n    ins(49, 5);\n    ins(60, 19);\n    kth(101,\
    \ 7);\n    kth(59, 4);\n    ins(57, 11);\n    kth(73, 20);\n    del(81);\n   \
    \ del(82);\n    ins(44, 1);\n    del(27);\n    del(99);\n    ins(78, 19);\n  \
    \  kth(93, 13);\n    kth(31, 15);\n    kth(79, 9);\n    ins(93, 10);\n    kth(106,\
    \ 4);\n    ins(7, 7);\n    ins(49, 3);\n    del(75);\n    kth(99, 11);\n    ins(14,\
    \ 18);\n    ins(6, 15);\n    del(106);\n    ins(80, 6);\n    ins(58, 17);\n  \
    \  ins(24, 14);\n    ins(85, 6);\n    del(7);\n    kth(106, 1);\n    ins(60, 8);\n\
    \    ins(13, 12);\n    ins(21, 7);\n    ins(31, 15);\n    ins(23, 8);\n    ins(8,\
    \ 2);\n    kth(4, 2);\n    ins(62, 3);\n    ins(37, 18);\n    ins(72, 8);\n  \
    \  ins(67, 17);\n    kth(58, 12);\n    del(62);\n    kth(56, 1);\n    ins(65,\
    \ 14);\n    ins(77, 20);\n    ins(119, 12);\n    ins(104, 2);\n    kth(76, 19);\n\
    \    kth(3, 14);\n    ins(63, 2);\n    ins(64, 20);\n    ins(63, 17);\n    kth(17,\
    \ 11);\n    ins(115, 4);\n    del(42);\n    del(4);\n    kth(10, 1);\n    del(21);\n\
    \    ins(103, 7);\n    ins(90, 5);\n    del(126);\n    kth(120, 8);\n    del(127);\n\
    \    kth(5, 15);\n    ins(6, 12);\n    kth(20, 17);\n    ins(120, 14);\n    kth(121,\
    \ 11);\n    ins(31, 6);\n    kth(8, 2);\n    ins(131, 19);\n    kth(29, 12);\n\
    \    del(57);\n    del(95);\n    kth(101, 10);\n    del(5);\n    kth(16, 11);\n\
    \    del(27);\n    ins(115, 18);\n    kth(41, 10);\n    del(7);\n    kth(110,\
    \ 10);\n    kth(51, 16);\n    kth(48, 1);\n    kth(32, 5);\n    kth(72, 16);\n\
    \    kth(44, 18);\n    ins(112, 3);\n    del(128);\n    kth(112, 3);\n    ins(116,\
    \ 18);\n    ins(49, 6);\n    del(41);\n    ins(54, 3);\n    ins(5, 7);\n    ins(67,\
    \ 10);\n    kth(117, 4);\n    ins(27, 8);\n    kth(19, 17);\n    kth(43, 4);\n\
    \    ins(19, 5);\n    del(115);\n    del(44);\n    ins(88, 13);\n    kth(48, 5);\n\
    \    del(103);\n    ins(108, 20);\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\ntypedef long long ll;\n\
    \n// Defines and one-liners\n#define INF 0x3f3f3f3f\n#define LLINF 0x3f3f3f3f3f3f3f3f\n\
    template <typename T> inline T& back(vector<T> &vec) { return *(vec.end() - 1);\
    \ }\ntemplate <typename T> inline void pop(vector<T> &vec) { return vec.erase(vec.end()\
    \ - 1); }\n\n// Scan, Debug, and other nonsense\ntemplate <typename T> ostream&\
    \ operator<<(ostream& out,vector<T> iter){out<<\"[\";for(auto t:iter){out<<t<<\"\
    , \";}out<<\"]\";return out;}\ntemplate <typename T> void printArray(ostream&\
    \ out,T* arr,int sz){out<<\"[\";for(int i=0;i<sz;i++){out<<arr[i]<<\", \"; } out<<\"\
    ]\";}\n#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type\
    \ obj){out<<\"(\"<<#propa<<\"=\"<<obj. propa<<\", \"<<#propb<<\"=\"<<obj. propb<<\"\
    )\";return out;}\n\nvoid scan(){}\ntemplate<typename F, typename... R> void scan(F\
    \ &f,R&... r){cin>>f;scan(r...);}\nint di_; string dnms_, co_ = \",\";\nvoid debug_(){cout<<endl;}\n\
    template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] !=\
    \ ',')cout<<dnms_[di_++];di_++;cout<<\": \"<<f<<\",\";debug_(r...);}\n#define\
    \ debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)\n\nmt19937 gen(time(NULL));\n\
    uniform_int_distribution<int> dis;\nstruct Node {\n    int val; int pri, sz; Node\
    \ *l, *r;\n    Node(int val0) : val(val0), pri(dis(gen)), sz(1), l(nullptr), r(nullptr)\
    \ {}\n};\nstruct ImplicitTreap {\n    Node* root;\n    ImplicitTreap() : root(nullptr)\
    \ {}\n    int sz(Node* &cur) { return cur ? cur->sz : 0; }\n    void upd(Node*\
    \ &cur) { \n        if (cur) cur->sz = sz(cur->l) + sz(cur->r) + 1; \n    }\n\
    \    void pushDown(Node* &cur) {\n        // assert((\"Not Implemented Yet!\"\
    , 0));\n    }\n    void split(Node* cur, int key, Node* &l, Node* &r) {\n    \
    \    pushDown(cur);\n        if (!cur) l = r = nullptr;\n        else if (key\
    \ <= sz(cur->l) + 1) { split(cur->l, key, l, cur->l); r = cur; }\n        else\
    \ { split(cur->r, key - sz(cur->l) - 1, cur->r, r); l = cur; }\n        upd(cur);\n\
    \    }\n    void merge(Node* &cur, Node* l, Node* r) {\n        pushDown(l); pushDown(r);\n\
    \        if (!l || !r) cur = l ? l : r;\n        else if (l->pri > r->pri) { merge(l->r,\
    \ l->r, r); cur = l; }\n        else { merge(r->l, l, r->l); cur = r; }\n    \
    \    upd(cur);\n    }\n    void insert(Node* &cur, int key, Node* node) {\n  \
    \      Node* rhs;\n        split(cur, key, cur, rhs);\n        merge(cur, cur,\
    \ node);\n        merge(cur, cur, rhs);\n    }\n    void remove(Node* &cur, int\
    \ key) {\n        pushDown(cur);\n        if (!cur) return;\n        int cKey\
    \ = sz(cur->l) + 1;\n        if (key == cKey) { merge(cur, cur->l, cur->r); }\n\
    \        else { key > cKey ? remove(cur->r, key - cKey) : remove(cur->l, key);\
    \ }\n        upd(cur);\n    }\n    Node* kth(Node* &cur, int idx) {\n        pushDown(cur);\n\
    \        int cKey = sz(cur->l) + 1;\n        if (idx == cKey) return cur;\n  \
    \      auto ret = idx < cKey ? kth(cur->l, idx) : kth(cur->r, idx - cKey);\n \
    \       upd(cur);\n        return ret;\n    }\n    void inOrder(Node* &cur) {\n\
    \        if (!cur) return;\n        pushDown(cur);\n        inOrder(cur->l); cout\
    \ << cur->val << \" \"; inOrder(cur->r);\n    }\n};\n\nImplicitTreap t;\n\nvoid\
    \ doInOrder() {\n    cout << \"(Pre-Query) Inorder: \";\n    t.inOrder(t.root);\n\
    \    cout << \"\\n\"; cout.flush();\n}\n\nvoid ins(int before, int val) {\n  \
    \  doInOrder();\n\n    cout << \"Insert At Pos: \" << before << \", Value: \"\
    \ << val << \"\\n\"; cout.flush();\n    t.insert(t.root, before, new Node(val));\n\
    }\n\nvoid del(int idx) {\n    doInOrder();\n\n    cout << \"Delete At Pos: \"\
    \ << idx << \"\\n\"; cout.flush();\n    t.remove(t.root, idx);\n}\n\nvoid kth(int\
    \ idx, int ans) {\n    doInOrder();\n\n    auto nd = t.kth(t.root, idx);\n   \
    \ cout << \"Search for Pos: \" << idx << \", Return|Ans: \" << nd->val << \"|\"\
    \ << ans << \"\\n\"; cout.flush();\n    assert(nd->val == ans);\n}\n\nint main(){\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n\n    ins(1, 4);\n\
    \    ins(1, 15);\n    del(2);\n    del(1);\n    ins(1, 17);\n    ins(1, 12);\n\
    \    ins(1, 15);\n    ins(3, 16);\n    del(3);\n    kth(2, 12);\n    ins(4, 7);\n\
    \    ins(1, 10);\n    ins(6, 11);\n    kth(5, 7);\n    kth(6, 11);\n    ins(7,\
    \ 11);\n    kth(2, 15);\n    kth(6, 11);\n    ins(1, 2);\n    kth(4, 12);\n  \
    \  kth(4, 12);\n    kth(1, 2);\n    ins(1, 17);\n    del(1);\n    del(3);\n  \
    \  ins(4, 20);\n    ins(9, 13);\n    kth(5, 17);\n    del(9);\n    ins(6, 15);\n\
    \    ins(1, 5);\n    ins(9, 1);\n    kth(2, 2);\n    kth(6, 17);\n    ins(1, 10);\n\
    \    ins(1, 2);\n    ins(11, 19);\n    del(6);\n    ins(3, 4);\n    del(11);\n\
    \    kth(9, 15);\n    kth(7, 20);\n    ins(3, 3);\n    ins(1, 20);\n    ins(12,\
    \ 15);\n    kth(16, 11);\n    kth(4, 3);\n    kth(8, 10);\n    kth(3, 10);\n \
    \   kth(16, 11);\n    ins(14, 10);\n    kth(9, 20);\n    ins(4, 10);\n    ins(18,\
    \ 10);\n    ins(6, 12);\n    kth(10, 10);\n    ins(13, 10);\n    ins(12, 18);\n\
    \    del(11);\n    ins(1, 14);\n    del(6);\n    kth(20, 10);\n    del(7);\n \
    \   kth(19, 10);\n    kth(2, 20);\n    ins(11, 3);\n    ins(3, 11);\n    del(8);\n\
    \    kth(7, 12);\n    kth(9, 10);\n    ins(2, 6);\n    ins(8, 1);\n    ins(1,\
    \ 11);\n    ins(8, 12);\n    ins(7, 9);\n    del(14);\n    kth(3, 6);\n    kth(7,\
    \ 9);\n    kth(24, 10);\n    ins(7, 12);\n    ins(9, 20);\n    ins(3, 19);\n \
    \   ins(18, 14);\n    ins(9, 17);\n    ins(21, 5);\n    del(4);\n    kth(6, 2);\n\
    \    ins(29, 4);\n    ins(7, 6);\n    kth(9, 17);\n    ins(16, 10);\n    del(33);\n\
    \    ins(15, 5);\n    ins(17, 1);\n    del(33);\n    ins(16, 19);\n    ins(27,\
    \ 16);\n    ins(32, 1);\n    kth(6, 2);\n    ins(37, 18);\n    kth(27, 16);\n\
    \    kth(2, 14);\n    del(9);\n    kth(21, 18);\n    kth(21, 18);\n    ins(27,\
    \ 4);\n    ins(36, 13);\n    ins(37, 12);\n    kth(34, 1);\n    ins(4, 12);\n\
    \    ins(30, 14);\n    kth(32, 15);\n    ins(34, 19);\n    ins(20, 13);\n    ins(13,\
    \ 6);\n    del(35);\n    kth(8, 6);\n    del(26);\n    ins(25, 14);\n    ins(36,\
    \ 11);\n    kth(32, 14);\n    kth(9, 12);\n    ins(30, 16);\n    kth(37, 11);\n\
    \    ins(45, 20);\n    kth(33, 14);\n    kth(11, 20);\n    ins(3, 11);\n    ins(29,\
    \ 6);\n    del(5);\n    ins(3, 10);\n    ins(17, 1);\n    del(22);\n    del(12);\n\
    \    del(39);\n    del(25);\n    ins(33, 20);\n    kth(37, 19);\n    ins(26, 18);\n\
    \    del(24);\n    del(44);\n    kth(28, 17);\n    kth(15, 10);\n    kth(12, 10);\n\
    \    del(23);\n    kth(34, 15);\n    ins(5, 3);\n    kth(22, 13);\n    ins(33,\
    \ 8);\n    ins(38, 5);\n    kth(46, 20);\n    ins(47, 2);\n    del(5);\n    ins(16,\
    \ 15);\n    kth(37, 15);\n    kth(8, 2);\n    kth(37, 15);\n    ins(43, 7);\n\
    \    del(4);\n    del(40);\n    kth(31, 10);\n    ins(11, 15);\n    del(23);\n\
    \    ins(2, 14);\n    kth(29, 16);\n    ins(36, 4);\n    ins(49, 3);\n    kth(37,\
    \ 15);\n    ins(12, 18);\n    kth(20, 5);\n    ins(15, 15);\n    del(1);\n   \
    \ ins(22, 13);\n    ins(15, 14);\n    ins(46, 12);\n    kth(9, 12);\n    kth(17,\
    \ 12);\n    ins(8, 10);\n    ins(34, 14);\n    ins(31, 4);\n    kth(29, 18);\n\
    \    ins(29, 16);\n    kth(49, 1);\n    kth(14, 10);\n    kth(33, 6);\n    ins(19,\
    \ 9);\n    ins(57, 1);\n    ins(22, 18);\n    kth(38, 14);\n    del(2);\n    del(37);\n\
    \    ins(47, 15);\n    kth(27, 1);\n    ins(9, 12);\n    ins(41, 12);\n    del(17);\n\
    \    kth(56, 12);\n    ins(52, 19);\n    kth(3, 19);\n    kth(32, 5);\n    ins(57,\
    \ 8);\n    del(43);\n    ins(44, 17);\n    ins(27, 13);\n    del(52);\n    ins(40,\
    \ 11);\n    kth(51, 19);\n    kth(7, 10);\n    kth(16, 14);\n    ins(8, 5);\n\
    \    del(60);\n    ins(57, 4);\n    ins(26, 18);\n    kth(39, 16);\n    ins(22,\
    \ 4);\n    kth(38, 6);\n    kth(31, 1);\n    ins(6, 16);\n    del(34);\n    del(32);\n\
    \    kth(36, 4);\n    kth(17, 15);\n    kth(11, 12);\n    kth(27, 19);\n    ins(44,\
    \ 16);\n    kth(63, 20);\n    del(33);\n    kth(62, 20);\n    ins(61, 11);\n \
    \   ins(24, 3);\n    ins(40, 7);\n    ins(56, 10);\n    kth(2, 10);\n    kth(43,\
    \ 11);\n    kth(17, 15);\n    kth(41, 16);\n    ins(9, 13);\n    kth(21, 9);\n\
    \    ins(42, 8);\n    del(35);\n    ins(40, 2);\n    kth(17, 10);\n    ins(7,\
    \ 17);\n    ins(23, 3);\n    kth(36, 13);\n    del(2);\n    del(10);\n    ins(57,\
    \ 16);\n    ins(48, 14);\n    del(18);\n    kth(51, 4);\n    kth(13, 9);\n   \
    \ ins(3, 6);\n    del(39);\n    del(39);\n    del(59);\n    kth(8, 2);\n    ins(61,\
    \ 8);\n    ins(47, 5);\n    ins(26, 19);\n    del(21);\n    ins(11, 4);\n    ins(72,\
    \ 9);\n    ins(1, 2);\n    kth(31, 19);\n    kth(72, 1);\n    kth(43, 16);\n \
    \   kth(7, 16);\n    del(64);\n    kth(65, 4);\n    ins(75, 4);\n    ins(45, 7);\n\
    \    del(2);\n    kth(69, 8);\n    kth(20, 12);\n    del(70);\n    ins(6, 11);\n\
    \    kth(9, 2);\n    kth(76, 18);\n    ins(73, 7);\n    kth(28, 18);\n    ins(63,\
    \ 20);\n    ins(56, 9);\n    ins(56, 10);\n    ins(6, 20);\n    ins(47, 13);\n\
    \    ins(35, 8);\n    del(48);\n    kth(62, 5);\n    kth(30, 1);\n    ins(2, 2);\n\
    \    kth(7, 20);\n    ins(4, 12);\n    ins(12, 11);\n    ins(67, 10);\n    del(31);\n\
    \    ins(45, 7);\n    ins(25, 14);\n    ins(44, 15);\n    kth(74, 19);\n    ins(7,\
    \ 11);\n    kth(82, 8);\n    ins(26, 5);\n    ins(80, 5);\n    kth(17, 4);\n \
    \   kth(20, 12);\n    kth(34, 18);\n    del(37);\n    kth(76, 12);\n    kth(51,\
    \ 16);\n    ins(54, 16);\n    del(50);\n    kth(42, 13);\n    del(29);\n    del(14);\n\
    \    kth(10, 11);\n    ins(1, 16);\n    ins(56, 9);\n    del(47);\n    ins(76,\
    \ 2);\n    kth(79, 5);\n    del(74);\n    kth(34, 1);\n    kth(68, 15);\n    ins(88,\
    \ 16);\n    kth(34, 1);\n    ins(90, 3);\n    kth(42, 5);\n    ins(81, 8);\n \
    \   del(6);\n    kth(34, 5);\n    ins(57, 10);\n    ins(18, 12);\n    ins(78,\
    \ 9);\n    del(80);\n    ins(12, 12);\n    kth(56, 9);\n    kth(49, 16);\n   \
    \ del(71);\n    kth(81, 13);\n    del(25);\n    kth(85, 9);\n    kth(6, 20);\n\
    \    del(76);\n    kth(63, 17);\n    del(55);\n    del(76);\n    kth(86, 16);\n\
    \    del(51);\n    del(25);\n    ins(76, 4);\n    ins(21, 16);\n    kth(43, 4);\n\
    \    ins(76, 15);\n    ins(24, 3);\n    kth(6, 20);\n    kth(1, 16);\n    kth(44,\
    \ 4);\n    ins(35, 14);\n    ins(65, 20);\n    ins(53, 13);\n    ins(84, 4);\n\
    \    ins(24, 17);\n    ins(78, 8);\n    del(2);\n    ins(6, 1);\n    ins(6, 4);\n\
    \    kth(23, 12);\n    kth(80, 2);\n    ins(44, 12);\n    ins(43, 16);\n    kth(48,\
    \ 5);\n    ins(2, 14);\n    ins(100, 2);\n    kth(81, 12);\n    kth(72, 9);\n\
    \    ins(81, 13);\n    kth(63, 5);\n    kth(78, 19);\n    ins(26, 5);\n    ins(62,\
    \ 7);\n    ins(21, 14);\n    kth(51, 5);\n    del(43);\n    kth(82, 20);\n   \
    \ kth(91, 4);\n    del(76);\n    kth(86, 9);\n    ins(100, 17);\n    kth(28, 17);\n\
    \    ins(1, 12);\n    ins(88, 17);\n    ins(49, 5);\n    ins(60, 19);\n    kth(101,\
    \ 7);\n    kth(59, 4);\n    ins(57, 11);\n    kth(73, 20);\n    del(81);\n   \
    \ del(82);\n    ins(44, 1);\n    del(27);\n    del(99);\n    ins(78, 19);\n  \
    \  kth(93, 13);\n    kth(31, 15);\n    kth(79, 9);\n    ins(93, 10);\n    kth(106,\
    \ 4);\n    ins(7, 7);\n    ins(49, 3);\n    del(75);\n    kth(99, 11);\n    ins(14,\
    \ 18);\n    ins(6, 15);\n    del(106);\n    ins(80, 6);\n    ins(58, 17);\n  \
    \  ins(24, 14);\n    ins(85, 6);\n    del(7);\n    kth(106, 1);\n    ins(60, 8);\n\
    \    ins(13, 12);\n    ins(21, 7);\n    ins(31, 15);\n    ins(23, 8);\n    ins(8,\
    \ 2);\n    kth(4, 2);\n    ins(62, 3);\n    ins(37, 18);\n    ins(72, 8);\n  \
    \  ins(67, 17);\n    kth(58, 12);\n    del(62);\n    kth(56, 1);\n    ins(65,\
    \ 14);\n    ins(77, 20);\n    ins(119, 12);\n    ins(104, 2);\n    kth(76, 19);\n\
    \    kth(3, 14);\n    ins(63, 2);\n    ins(64, 20);\n    ins(63, 17);\n    kth(17,\
    \ 11);\n    ins(115, 4);\n    del(42);\n    del(4);\n    kth(10, 1);\n    del(21);\n\
    \    ins(103, 7);\n    ins(90, 5);\n    del(126);\n    kth(120, 8);\n    del(127);\n\
    \    kth(5, 15);\n    ins(6, 12);\n    kth(20, 17);\n    ins(120, 14);\n    kth(121,\
    \ 11);\n    ins(31, 6);\n    kth(8, 2);\n    ins(131, 19);\n    kth(29, 12);\n\
    \    del(57);\n    del(95);\n    kth(101, 10);\n    del(5);\n    kth(16, 11);\n\
    \    del(27);\n    ins(115, 18);\n    kth(41, 10);\n    del(7);\n    kth(110,\
    \ 10);\n    kth(51, 16);\n    kth(48, 1);\n    kth(32, 5);\n    kth(72, 16);\n\
    \    kth(44, 18);\n    ins(112, 3);\n    del(128);\n    kth(112, 3);\n    ins(116,\
    \ 18);\n    ins(49, 6);\n    del(41);\n    ins(54, 3);\n    ins(5, 7);\n    ins(67,\
    \ 10);\n    kth(117, 4);\n    ins(27, 8);\n    kth(19, 17);\n    kth(43, 4);\n\
    \    ins(19, 5);\n    del(115);\n    del(44);\n    ins(88, 13);\n    kth(48, 5);\n\
    \    del(103);\n    ins(108, 20);\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: old/test.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/test.cpp
layout: document
redirect_from:
- /library/old/test.cpp
- /library/old/test.cpp.html
title: old/test.cpp
---
