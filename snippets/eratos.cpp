
struct Eratos
{
    // @! init -------------------------------------------------------
    Eratos(int table_lim)
        : n(table_lim)
        , e(table_lim, PRIME)
    {
        e[0] = e[1] = 1;
        for (int64_t i = 2; i < n; ++i) {
            if (e[i] == NOT_PRIME)
                continue;
            p.push_back(i);
            for (int64_t j = i * i; j < n; j += i)
                e[j] = NOT_PRIME;
        }
    }

    const int n;
    vector<int> p;  // p[i] == the i-th prime, 0-indexed
    vector<bool> e; // e[i] == 0 --> `i` is prime

    // @! operations -------------------------------------------------
    vector<int64_t> fact(int64_t x)
    {
        vector<int64_t> res;
        for (int64_t _i = 0, i = p[0]; _i < p.size() && i*i <= x; i = p[++_i]) {
            if (x % i == 0) {
                res.push_back(i);
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) res.push_back(x);
        return res;
    }

    map<int64_t, int> fact_map(int64_t x)
    {
        map<int64_t, int> res;
        for (int64_t _i = 0, i = p[0]; _i < p.size() && i*i <= x; i = p[++_i]) {
            while (x % i == 0) {
                res[i]++;
                x /= i;
            }
        }
        if (x > 1) res[x]++;
        return res;
    }

    vector<int64_t> get_divisors(int64_t x)
    {
        int len = 1;
        vector<int64_t> res = {1};

        for (int64_t _i = 0, i = p[0]; _i < p.size() && i*i <= x; i = p[++_i]) {
            if (x % i != 0)
                continue;

            int64_t t = i;
            while (x % i == 0) {
                for (int j = 0; j < len; j++)
                    res.push_back(res[j] * t);
                x /= i;
                t *= i;
            }
            len = res.size();
        }
        if (x > 1) {
            for (int j = 0; j < len; j++)
                res.push_back(res[j] * x);
        }

        return res;
    }

    // @! internal ---------------------------------------------------
    static constexpr bool PRIME = false;
    static constexpr bool NOT_PRIME = true;

} er(1e7 + 7);

