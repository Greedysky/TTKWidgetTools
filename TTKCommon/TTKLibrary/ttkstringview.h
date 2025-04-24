#ifndef TTKSTRINGVIEW_H
#define TTKSTRINGVIEW_H

/***************************************************************************
 * This file is part of the TTK Library Module project
 * Copyright (C) 2015 - 2025 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <string>
#include "ttkmoduleexport.h"

/*! @brief The class of the string view modules.
 * @author Greedysky <greedysky@163.com>
 */
class TTKStringView
{
public:
    using size_type = size_t;
    static constexpr size_type npos = size_type(-1);

public:
    constexpr TTKStringView() noexcept
        : m_data(nullptr),
          m_length(0)
    {

    }

    template<size_type T>
    constexpr TTKStringView(const char(&data)[T])
        : m_data(data),
          m_length(T - 1)
    {

    }

    explicit constexpr TTKStringView(const char *data, const size_type length)
        : m_data(data),
          m_length(length)
    {

    }

    TTKStringView(const char *data)
        : m_data(data),
          m_length(std::char_traits<char>::length(data))
    {

    }

    constexpr TTKStringView(const TTKStringView &) noexcept = default;
    TTKStringView(const std::string &s) noexcept
        : m_data(s.data()),
          m_length(s.length())
    {

    }

    inline TTKStringView& operator=(const TTKStringView &sv) noexcept
    {
        m_data = sv.data();
        m_length = sv.size();
        return *this;
    }

    explicit operator std::string() const
    {
        return std::string(m_data, m_length);
    }

    inline const char *begin() const noexcept { return m_data; }
    inline const char *end() const noexcept { return m_data + m_length; }
    inline size_type size() const noexcept { return m_length; }
    inline bool empty() const noexcept { return m_length == 0; }
    inline const char& operator[](size_type o) const { return m_data[o]; }

    inline const char& at(size_type o) const
    {
        if(o >= m_length)
        {
            throw std::out_of_range("o exceeds length");
        }
        return m_data[o];
    }

    inline const char& front() const noexcept { return m_data[0]; }
    inline const char& back() const noexcept { return m_data[m_length - 1]; }
    inline const char *data() const noexcept { return m_data; }

    inline TTKStringView substr(size_type a) const noexcept
    {
        return a >= m_length ? TTKStringView() : TTKStringView(m_data + a, m_length - a);
    }

    inline TTKStringView substr(size_type a, size_type b) const noexcept
    {
        return a >= m_length ? TTKStringView() : TTKStringView(m_data + a, a + b > m_length ? m_length - a : b);
    }

    inline size_type find(const char c) const noexcept
    {
        size_type l = 0;
        while(l < m_length)
        {
            if(m_data[l] == c)
            {
                return l;
            }

            ++l;
        }
        return TTKStringView::npos;
    }

    inline size_type find(const std::string &c) const noexcept
    {
        size_type l = 0, a = 0;
        while(l < m_length)
        {
            if(m_data[l] != c[a])
            {
                a = 0;
            }

            ++l;
            ++a;

            if(a == c.length())
            {
                return l - c.length();
            }
        }
        return TTKStringView::npos;
    }

    inline size_type find(const TTKStringView &sv) const noexcept
    {
        size_type l = 0, a = 0;
        while(l < m_length)
        {
            if(m_data[l] != sv[a])
            {
                a = 0;
            }

            ++l;
            ++a;

            if(a == sv.size())
            {
                return l - sv.size();
            }
        }
        return TTKStringView::npos;
    }

    inline size_type find(const char *c) const noexcept
    {
        size_type l = 0, sl = strlen(c), a = 0;
        while(l < m_length)
        {
            if(m_data[l] != c[a])
            {
                a = 0;
            }

            ++l;
            ++a;

            if(a == sl)
            {
                return l - sl;
            }
        }
        return TTKStringView::npos;
    }

    inline size_type find(const char *c, size_type sl) const noexcept
    {
        size_type l = 0, a = 0;
        while(l < m_length)
        {
            if(m_data[l] != c[a])
            {
                a = 0;
            }

            ++l;
            ++a;

            if(a == sl)
            {
                return l - sl;
            }
        }
        return TTKStringView::npos;
    }

    inline size_type rfind(const char c) const noexcept
    {
        size_type s = m_length;
        while(0 < s)
        {
            if(m_data[s] == c)
            {
                return s;
            }

            --s;
        }
        return TTKStringView::npos;
    }

    size_type rfind(const char *s) const noexcept
    {
        const size_type m = strlen(s);
        if(m == 1)
        {
            return rfind(*s);
        }

        const size_type n = size();
        if(n < m)
        {
            return TTKStringView::npos;
        }

        size_type c[256] = { 0 };
        for(size_type i = m; i > 0; --i)
        {
            c[int(s[i - 1])] = i;
        }

        for(size_type j = n - m;;)
        {
            if(memcmp(s, m_data + j, m) == 0)
            {
                return j;
            }

            if(j == 0)
            {
                return TTKStringView::npos;
            }

            size_type x = c[int(m_data[j - 1])];
            if(x == 0)
            {
                x = m + 1;
            }

            if(j < x)
            {
                return TTKStringView::npos;
            }

            j -= x;
        }
    }

    inline size_type find_first_of(const std::string &s, size_type l = 0) const noexcept
    {
        size_type a = 0;
        while(l < m_length)
        {
            while(s[a])
            {
                if(m_data[l] == s[a])
                {
                    return l;
                }

                ++a;
            }

            ++l;
            a = 0;
        }
        return TTKStringView::npos;
    }

    inline size_type find_first_of(const char *s, size_type l = 0) const noexcept
    {
        size_type a = 0;
        while(l < m_length)
        {
            while(s[a])
            {
                if(m_data[l] == s[a])
                {
                    return l;
                }

                ++a;
            }

            ++l;
            a = 0;
        }
        return TTKStringView::npos;
    }

    inline size_type find_first_of(char c, size_type l = 0) const noexcept
    {
        while(l < m_length)
        {
            if(m_data[l] == c)
            {
                return l;
            }

            ++l;
        }
        return TTKStringView::npos;
    }

    inline size_type find_first_not_of(const std::string &s) const
    {
        if(empty())
        {
            return TTKStringView::npos;
        }

        const size_type r = strspn(data(), s.data());
        return m_data[r] ? r : TTKStringView::npos;
    }

    inline size_type find_first_not_of(const std::string &s, size_type o) const
    {
        if(size() <= o)
        {
            return TTKStringView::npos;
        }

        const size_type r = strspn(data() + o, s.data()) + o;
        return m_data[r] ? r : TTKStringView::npos;
    }

    inline size_type find_first_not_of(const char *s) const
    {
        if(empty())
        {
            return TTKStringView::npos;
        }

        const size_type r = strspn(this->data(), s);
        return m_data[r] ? r : TTKStringView::npos;
    }

    inline size_type find_first_not_of(const char *s, size_type o) const
    {
        if(size() <= o)
        {
            return TTKStringView::npos;
        }

        const size_type r = strspn(this->data() + o, s) + o;
        return m_data[r] ? r : TTKStringView::npos;
    }

    inline size_type find_first_not_of(char c, size_type o = 0) const
    {
        if(size() <= o)
        {
            return TTKStringView::npos;
        }

        const char s[2] = { c, '\0' };
        const size_type r = strspn(data() + o, s) + o;
        return m_data[r] ? r : TTKStringView::npos;
    }

    [[nodiscard]] int compare(const TTKStringView &sv) const noexcept
    {
        const int rc = std::char_traits<char>::compare(m_data, sv.m_data, (std::min)(m_length, sv.m_length));
        return rc != 0 ? rc : (m_length == sv.m_length ? 0 : m_length < sv.m_length ? -1 : 1);
    }

    [[nodiscard]] int compare(const char *data) const noexcept
    {
        const size_type l = std::char_traits<char>::length(data);
        const int rc = std::char_traits<char>::compare(m_data, data, (std::min)(m_length, l));
        return rc != 0 ? rc : (m_length == l ? 0 : m_length < l ? -1 : 1);
    }

    [[nodiscard]] int compare(const std::string &s) const noexcept
    {
        const int rc = std::char_traits<char>::compare(m_data, s.data(), (std::min)(m_length, s.length()));
        return rc != 0 ? rc : (m_length == s.length() ? 0 : m_length < s.length() ? -1 : 1);
    }

    friend std::basic_ostream<char>& operator<<(std::basic_ostream<char> &os, const TTKStringView &sv)
    {
        os.write(sv.m_data, sv.m_length);
        return os;
    }

    friend std::string& operator+=(std::string &s, const TTKStringView &sv)
    {
        s.append(sv.m_data, sv.m_length);
        return s;
    }

private:
    const char *m_data;
    size_type m_length;

};


namespace TTK
{
    static TTKStringView split(const char *&cur, const char *line_end, char split_char)
    {
        const char *start = cur;
        while(start < (line_end - 1) && *start == split_char)
        {
            ++start;
        }

        const char *end = start + 1;
        while(end < (line_end - 1) && *end != split_char)
        {
            ++end;
        }

        cur = end + 1;
        return TTKStringView(start, cur - start - (*end == split_char ? 1 : 0));
    }
}


inline std::string& operator<<(std::string& s, const TTKStringView &sv) { s.append(sv.data(), sv.size()); return s; }
// ==
inline bool operator==(const TTKStringView &l, const TTKStringView &r) noexcept { return l.compare(r) == 0; }
inline bool operator==(const TTKStringView &l, const std::string &r) noexcept { return l.compare(r) == 0; }
inline bool operator==(const std::string &l, const TTKStringView &r) noexcept { return r.compare(l) == 0; }
inline bool operator==(const TTKStringView &l, const char *r) noexcept { return l.compare(r) == 0; }
inline bool operator==(const char *l, const TTKStringView &r) noexcept { return r.compare(l) == 0; }
// !=
inline bool operator!=(const TTKStringView &l, const TTKStringView &r) noexcept { return l.compare(r) != 0; }
inline bool operator!=(const TTKStringView &l, const std::string &r) noexcept { return l.compare(r) != 0; }
inline bool operator!=(const std::string &l, const TTKStringView &r) noexcept { return r.compare(l) != 0; }
inline bool operator!=(const TTKStringView &l, const char *r) noexcept { return l.compare(r) != 0; }
inline bool operator!=(const char *l, const TTKStringView &r) noexcept { return r.compare(l) != 0; }
// <=
inline bool operator<=(const TTKStringView &l, const TTKStringView &r) noexcept { return l.compare(r) <= 0; }
inline bool operator<=(const TTKStringView &l, const std::string &r) noexcept { return l.compare(r) <= 0; }
inline bool operator<=(const std::string &l, const TTKStringView &r) noexcept { return r.compare(l) >= 0; }
// <
inline bool operator<(const TTKStringView &l, const TTKStringView &r) noexcept { return l.compare(r) < 0; }
inline bool operator<(const TTKStringView &l, const std::string &r) noexcept { return l.compare(r) < 0; }
inline bool operator<(const std::string &l, const TTKStringView &r) noexcept { return r.compare(l) > 0; }
// >=
inline bool operator>=(const TTKStringView &l, const TTKStringView &r) noexcept { return l.compare(r) >= 0; }
inline bool operator>=(const TTKStringView &l, const std::string &r) noexcept { return l.compare(r) >= 0; }
inline bool operator>=(const std::string  &l, const TTKStringView &r) noexcept { return r.compare(l) <= 0; }
// >
inline bool operator>(const TTKStringView &l, const TTKStringView &r) noexcept { return l.compare(r) > 0; }
inline bool operator>(const TTKStringView &l, const std::string&r) noexcept { return l.compare(r) > 0; }
inline bool operator>(const std::string &l, const TTKStringView &r) noexcept { return r.compare(l) < 0; }
//
template <>
struct std::hash<TTKStringView>
{
    [[nodiscard]] size_t operator()(const TTKStringView sv) const noexcept
    {
#ifdef _MSVC_LANG
        return std::_Hash_array_representation(sv.data(), sv.size());
#else
        return std::_Hash_impl::hash(sv.data(), sv.size());
#endif
    }
};


// compatiblity for std string_view
namespace std
{
#if !TTK_HAS_CXX17
using string_view = TTKStringView;
#endif
}

#endif // TTKSTRINGVIEW_H
