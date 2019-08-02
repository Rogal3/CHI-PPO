#include <cstdio>

const int dr[] = {0, 0, 1, -1, 0, 0};
const int dc[] = {0, 0, 0, 0, -1, 1};
const int dh[] = {1, -1, 0, 0, 0, 0};

enum {
    MAX_SIZE = 100
};

template<class T>
class queue {
    public:
        queue() : head_(0), tail_(0), size_(0) {}
        ~queue() {if (head_) delete head_;}
        T &front() const {return head_->val;}
        void push(const T &_val) {
            Node *n_node = new Node(_val);
            if (head_) {
                tail_->next = n_node;
                tail_ = n_node;
            } else {
                head_ = n_node;
                tail_ = n_node;
            }
            ++size_;
        }
        void pop() {
            if (head_) {
                Node *n_head = head_->next;
                head_->next = 0;
                delete head_;
                head_ = n_head;
                --size_;
            }
        }
        int size() {return size_;}
        bool isEmpty() {return size_ == 0;}
    private:
        struct Node {
            T val;
            Node *next;
            Node(const T &_val) : val(_val), next(0) {}
            ~Node() {if (next) delete next;}
        };
        Node *head_;
        Node *tail_;
        int size_;
};

template<class T>
class vector {
    public:
        vector() : s_(0), c_(0) {}
        ~vector() {if (con_) delete[] con_;}
        void reserve(const int &cap) {
            if (cap != c_) {
                T *n_con = new T[cap];
                s_ = s_ < cap ? s_ : cap;
                for (int i = 0; i < s_; ++i) {
                    n_con[i] = con_[i];
                }
                delete[] con_;
                con_ = n_con;
                c_ = cap;
            }
        }
        void push_back(const T &_val) {
            if (c_ <= s_) {
                if (c_ == 0) ++c_;
                reserve(c_ * 2);
            }
            con_[s_++] = _val;
        }
        T &operator[](const int &idx) const {return con_[idx];}
    private:
        T *con_;
        int s_;
        int c_;
};

struct Coord {
    int r;
    int c;
    int h;
    Coord() {}
    Coord(const int &_r, const int &_c, const int &_h) : r(_r), c(_c), h(_h) {}
};

int N, M, H;
vector<int> map;
queue<Coord> q;
int unmatures;
int ans;

inline int get_idx(const Coord &coord) {
    return (coord.h * N + coord.r) * M + coord.c;
}

void readInput() {
    scanf("%d %d %d", &M, &N, &H);
    int input;
    map.reserve(N * M * H);
    for (int ch = 0; ch < H; ++ch) {
        for (int cr = 0; cr < N; ++cr) {
            for (int cc = 0; cc < M; ++cc) {
                scanf("%d", &input);
                map.push_back(input);
                if (input == 1) {
                    q.push(Coord(cr, cc, ch));
                }
                if (input == 0)
                    ++unmatures;
            }
        }
    }
}

inline bool inRange(const Coord &coord) {
    return 0 <= coord.r && coord.r < N && 0 <= coord.c && coord.c < M && 0 <= coord.h && coord.h < H;
}

void bfs() {
    while (0 < unmatures) {
        if (q.isEmpty()) {
            ans = -1;
            return;
        }
        for (int q_left = q.size(); 0 < q_left; --q_left) {
            Coord now(q.front());
            q.pop();
            for (int dir = 0; dir < 6; ++dir) {
                Coord next(now);
                next.r += dr[dir];
                next.c += dc[dir];
                next.h += dh[dir];
                if (inRange(next) && map[get_idx(next)] == 0) {
                    map[get_idx(next)] = 1;
                    q.push(next);
                    --unmatures;
                }
            }
        }
        ++ans;
    }
}

int main() {
    readInput();
    bfs();
    printf("%d", ans);
    return 0;
}
