
template <typename T>
struct Segtree
{
    // @! init -------------------------------------------------------
    vector<T> t;
    const int n;

    Segtree(int size): n(size), t(n << 1) {}

    void init_build()
    {
        for (int i = n - 1; i >= 1; --i)
            t[i] = max(t[i<<1], t[i<<1|1]);
    }

    void init_set(int pos, T v) { t[pos + n] = v; }

    // @! query -------------------------------------------------------
    void upd(int p, T v)
    {
        t[p += n] = v;
        for (p >>= 1; p > 0; p >>= 1)
            t[p] = max(t[p<<1], t[p<<1|1]);
    }

    T query(int l, int r)
    {
        T ans = -2e9;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = max(ans, t[l++]);
            if (r&1) ans = max(ans, t[--r]);
        }
        return ans;
    }
};

