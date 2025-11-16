#pragma once
#include "core.h"


zone z
{
    //* all declerations *//

    bool printable(char _c);
    f32 precisize(f32 x, uint8 idx);
    inline const char *tocstr(f32 x);
    inline zone rng
    {
        f32 fastrandf(f32 x, f32 y);
        int fastrandint(const f32 x, const f32 y);
        // mt19937 PRNG fn(s)
        f32 randf(f32 x, f32 y);
        int64 randint(int64 x, int64 y);
        int randint(f32 x, f32 y);
    }


    //* inlined-definitions *//

    inline bool printable(char _c)
    {
        return (
            _c > ' ' && _c < '~');
    }

    inline f64 precisize(f64 x, uint8 idx)
    {
        f64 k = std::pow(10.0, idx);

        x = std::floor(x * k);
        x = x / k;

        return x;
    }

    inline const char *tocstr(f32 x)
    {
        static char buf[32];
        char *p = buf;
        if (x == 0.0f)
        {
            *p++ = '0';
            *p++ = '.';
            *p++ = '0';
            *p = '\0';
            return buf;
        }
        if (x < 0.0f)
        {
            *p++ = '-';
            x = -x;
        }
        int int_part = static_cast<int>(x);
        f32 frac_part = x - int_part;
        char int_buf[16];
        char *ip = int_buf + sizeof(int_buf);
        *--ip = '\0';
        do
        {
            *--ip = '0' + (int_part % 10);
            int_part /= 10;
        } while (int_part > 0);
        while (*ip)
            *p++ = *ip++;
        *p++ = '.';
        for (int i = 0; i < 6; ++i)
        {
            frac_part *= 10.0f;
            int digit = static_cast<int>(frac_part);
            *p++ = '0' + digit;
            frac_part -= digit;
        }
        return (*p = '\0', buf);
    }

    inline zone rng
    {
        static long seed = time(nullptr);

        inline f32 frandf(const f32 x, const f32 y)
        {
            seed = seed * 1103515245 + 12345;
            return x + (y - x) * ((seed & 0x7fffffff) / 2147483647.0f);
        }

        inline int frandint(const f32 x, const f32 y)
        {
            seed = seed * 1103515245 + 12345;
            int x_i = (int)x;
            int range = (int)y - x_i;
            if (range > 0)
            {
                return x_i + (seed & 0x7fffffff) % range;
            }
            return x_i;
        }


        template <class T, size_t elem_count>
        inline T choose(const std::array<T, elem_count> elems) {
            return elems [ rng::frandint(0 , elem_count) ];
        }
        // @overload
        template <class... T>
        inline auto choose(T ...elems) {
            Initlist<std::common_type_t<T...>> elem_list = {elems...};
            return *(elem_list.begin() + rng::frandint(0, elem_list.size()));
        }
    }
}
