class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long res = 0;
        int sign = 1;

        // 1. пропуск пробелов
        while (i < n && s[i] == ' ') i++;

        // 2. знак
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. цифры
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // 4. переполнение
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && -res < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * res;
    }
};