#define ll long long

class Solution
{
private:
    int gcd(ll a, ll b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int lcm(ll a, ll b)
    {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }

public:
    int minimizeSet(int d1, int d2, int uc1, int uc2)
    {
        int st = 1, r = INT_MAX, LCM = lcm(d1, d2);

        while (st <= r)
        {

            ll mid = st + (r - st) / 2;
            ll a = mid - (mid / d1);
            ll b = mid - (mid / d2);

            if (uc1 <= a && uc2 <= b && uc1 + uc2 <= (mid - (mid / LCM)))
            {
                r = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return st;
    }
};