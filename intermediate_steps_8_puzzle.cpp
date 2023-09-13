#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node 
{
    vector<vector<char>> data;
    int level;
    int fval;

    Node(vector<vector<char>> d, int l, int f) : data(d), level(l), fval(f) {}

    vector<Node> generate_child() {
        vector<Node> children;
        int x = -1, y = -1;

        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                if (data[i][j] == '_') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        vector<pair<int, int>> val_list = {{x, y - 1}, {x, y + 1}, {x - 1, y}, {x + 1, y}};

        for (const auto& i : val_list) {
            if (i.first >= 0 && i.first < data.size() && i.second >= 0 && i.second < data[0].size()) {
                vector<vector<char>> child = shuffle(data, x, y, i.first, i.second);
                if (!child.empty()) {
                    children.emplace_back(child, level + 1, 0);
                }
            }
        }

        return children;
    }

    vector<vector<char>> shuffle(vector<vector<char>> puz, int x1, int y1, int x2, int y2) {
        vector<vector<char>> temp_puz = puz;
        char temp = temp_puz[x2][y2];
        temp_puz[x2][y2] = temp_puz[x1][y1];
        temp_puz[x1][y1] = temp;
        return temp_puz;
    }
};

struct Puzzle {
    int n;
    vector<Node> open;
    vector<Node> closed;

    Puzzle(int size) : n(size) {}

    vector<vector<char>> accept() {
        vector<vector<char>> puz(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> puz[i][j];
            }
        }
        return puz;
    }

    int h(vector<vector<char>> start, vector<vector<char>> goal) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (start[i][j] != goal[i][j] && start[i][j] != '_') {
                    temp += 1;
                }
            }
        }
        return temp;
    }

    void process() {
        cout << "Enter the start state matrix:" << endl;
        vector<vector<char>> start = accept();
        cout << "Enter the goal state matrix:" << endl;
        vector<vector<char>> goal = accept();
        Node start_node(start, 0, 0);
        open.push_back(start_node);

        while (!open.empty()) {
            Node cur = open[0];
            open.erase(open.begin());

            cout << "==================================================" << endl;
            for (const auto& row : cur.data) {
                for (char j : row) {
                    cout << j << " ";
                }
                cout << endl;
            }

            if (h(cur.data, goal) == 0) {
                break;
            }

            for (Node i : cur.generate_child()) {
                i.fval = i.level + h(i.data, goal);
                open.push_back(i);
            }

            sort(open.begin(), open.end(), [](const Node& a, const Node& b) {
                return a.fval < b.fval;
            });
        }
    }
};

int main() {
    Puzzle puz(3);
    puz.process();
    return 0;
}
