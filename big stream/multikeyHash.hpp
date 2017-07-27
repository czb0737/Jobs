#ifndef _MULTIKEY_HASH_
#define _MULTIKEY_HASH_

#include <iostream>
#include <tuple>
#include <vector>
#include "toBytes.cpp"

// using namespace std;

typedef unsigned char byte;
typedef uint32_t int32;

template <class ...K>
class MultikeyHash
{
public:
    MultikeyHash() : SEED(rand()) {};

    template<class Func>
    int32 apply(Func fun, K... keys)
    {
        auto tpl = fun(keys...);
        vector<byte> v = TraversalTuple<decltype(tpl), tuple_size<decltype(tpl)>::value>::traversal(tpl);
        return murmur3Hash(v, SEED);
    }

private:
    int32 murmur3Hash(const vector<byte> &v, int32 seed)
    {
        int32 h = seed;
        size_t len = v.size();
        if (len > 3)
        {
            const int32 *key4 = (const int32 *) &(v[0]);
            size_t i = len >> 2;
            while (i--)
            {
                int32 k = *key4++;
                k *= 0xcc9e2d51;
                k = (k << 15) | (k >> 17);
                k *= 0x1b873593;
                h ^= k;
                h = (h << 13) | (h >> 19);
                h = (h * 5) + 0xe6546b64;
            }
        }
        if (len & 3)
        {
            size_t i = len & 3;
            int32 k = 0;
            size_t index = len - i;
            while (i--)
            {
                k <<= 8;
                k |= v[index++];
            }
            k *= 0xcc9e2d51;
            k = (k << 15) | (k >> 17);
            k *= 0x1b873593;
            h ^= k;
        }
        h ^= len;
        h ^= h >> 16;
        h *= 0x85ebca6b;
        h ^= h >> 13;
        h *= 0xc2b2ae35;
        h ^= h >> 16;
        return h;
    }

    template <class Tpl, size_t N>
    struct TraversalTuple
    {
        static vector<byte> traversal(const Tpl &tp)
        {
            vector<byte> v1 = TraversalTuple<Tpl, N - 1>::traversal(tp);
            vector<byte> v2 = toBytes(get<N - 1>(tp));
            v1.insert(v1.end(), v2.begin(), v2.end());
            return v1;
        }
    };

    template <class Tpl>
    struct TraversalTuple<Tpl, 1>
    {
        static vector<byte> traversal(const Tpl &tp)
        {
            return toBytes(get<0>(tp));
        }
    };

    const int32 SEED;
};

#endif