#pragma once
#include <cstdint>
#include <cctype>

namespace openomd
{
struct PktHdr
{
    uint16_t size;
    uint8_t msgCnt;
    uint8_t filler;
    uint32_t seqNum;
    uint64_t sendTime;
};
struct MsgHdr
{
    uint16_t size;
    uint16_t type;
};

static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string& s)
{
    ltrim(s);
    rtrim(s);
}
#ifndef ONMESSAGE
#define ONMESSAGE(_MSG) void onMessage(_MSG const&, uint32_t){}
#endif

}