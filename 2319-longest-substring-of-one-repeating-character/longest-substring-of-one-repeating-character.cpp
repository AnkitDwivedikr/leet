class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;

        Node() {
            len = 0;
            pref = 0;
            suff = 0;
            best = 0;
            leftChar = '#';
            rightChar = '#';
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {

            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {

        if (l == r) {
            tree[node].len = 1;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {

        if (l == r) {
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            tree[node].leftChar = c;
            tree[node].rightChar = c;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, c);
        else
            update(node * 2 + 1, mid + 1, r, pos, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, index, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};//akd