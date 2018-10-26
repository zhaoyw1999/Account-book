/**
 * Project-name    : account-book
 * Project-author  : Q17010123 Q17010122 Q17010125
 * Name            : models.cc
 * Module-author   : Q17010125
 * License         : MIT
 * Version         : 1.0.0
 * Description     : models module
 */

#include "models.h"
#include <string>

using namespace std;

Item::Item(int cId,
           string cDate_,
           string cName_,
           int cType_,
           int cAmount_,
           string cRemark_) {
    id_ = cId;
    date_ = cDate_;
    name_ = cName_;
    type_ = cType_;
    amount_ = cAmount_;
    remark_ = cRemark_;
}

Item::~Item() {}

void Item::setDate(string x)  {
    date_ = x;
}

inline bool compareById(const Item &it_1, const Item &it_2) {
    return it_1.id_ < it_2.id_;
}

inline bool compareByDate(const Item &it_1, const Item &it_2) {
    int date_1 = (it_1.date_[0] - '0') * 1e7 + (it_1.date_[1] - '0') * 1e6 + (it_1.date_[2] - '0') * 1e5 + (it_1.date_[3] - '0') * 1e4
                 + (it_1.date_[5] - '0') * 1e3 + (it_1.date_[6] - '0') * 1e2
                 + (it_1.date_[8] - '0') * 1e1 + (it_1.date_[9] - '0');
    int date_2 = (it_2.date_[0] - '0') * 1e7 + (it_2.date_[1] - '0') * 1e6 + (it_2.date_[2] - '0') * 1e5 + (it_2.date_[3] - '0') * 1e4
                 + (it_2.date_[5] - '0') * 1e3 + (it_2.date_[6] - '0') * 1e2
                 + (it_2.date_[8] - '0') * 1e1 + (it_2.date_[9] - '0');

    return date_1 < date_2;
}

inline bool compareByAmount(const Item &it_1, const Item &it_2) {
    return it_1.amount_ < it_2.amount_;
}

bool operator < (const Item &it_1, const Item &it_2) {
    return it_1.id_ < it_2.id_;
}
