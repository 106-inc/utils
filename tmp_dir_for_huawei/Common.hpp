#pragma once
#include <iostream>
#include <vector>

using Word = uint32_t;
using RegVal = uint32_t;
using RegId = uint8_t;

static constexpr int kRegFileSize = 32; //не понял, зачем именно так объявлять, еще на занятии прогуглил и так и не понял :D
static constexpr int kWordSize = 4;

template <unsigned high, unsigned low>
constexpr Word GetBits( Word word );

template <unsigned old_size, unsigned new_size>
constexpr Word SignExtend( Word word );

enum class InsnId
{
    kAdd,
    kSub,
    kLb,
    kLh,
    kLw,
    kLbu,
    kLhu,
    kSb,
    kSh,
    kSw,
    kBeq,
    kBne,
    kBlt,
    kBge,
    kBltu,
    kBgeu,
    kInvalidId
};
