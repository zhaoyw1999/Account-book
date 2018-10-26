/**
 * Project-name    : account-book
 * Project-author  : Q17010123 Q17010122 Q17010125
 * Name            : controller.cc
 * Module-author   : Q17010123
 * License         : MIT
 * Version         : 1.0.0
 * Description     : controller module
 */

#include "models.h"
#include "controller.h"
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

DataSet::DataSet() {
    readData();
    this->max_id_ = -1;
    for (auto const &x: dataContainner_) {
        max_id_ = max(max_id_, x.id_);
    }
}

DataSet::~DataSet() {
    saveData();
}

int DataSet::idAllocator() {
    ++max_id_;
    return max_id_;
}

std::set <Item> DataSet::getAllData() {
    return dataContainner_;
}

Item DataSet::getDataById(int id) {
    Item notFind(-1, "", "", 0, 0, "");
    for (auto const &x: dataContainner_) {
        if (x.id_ == id) {
            return x;
        }
    }
    return notFind;
}

std::set <Item> DataSet::getDataByDate(string minDate, string maxDate) {
    std::set <Item> retSet;
    for (auto const &x: dataContainner_) {
        if (x.date_ >= minDate && x.date_ <= maxDate) {
            retSet.insert(x);
        }
    }
    return retSet;
}

std::set <Item> DataSet::getDataByName(string name) {
    std::set <Item> retSet;
    for (auto const &x: dataContainner_) {
        if (x.name_ == name) {
            retSet.insert(x);
        }
    }
    return retSet;
}

std::set <Item> DataSet::getDataByType(int type) {
    std::set <Item> retSet;
    for (auto const &x: dataContainner_) {
        if (x.type_ == type) {
            retSet.insert(x);
        }
    }
    return retSet;
}

std::set <Item> DataSet::getDataByAmount(int minAmount, int maxAmount) {
    std::set <Item> retSet;
    for (auto const &x: dataContainner_) {
        if (x.amount_ >= minAmount && x.amount_ <= maxAmount) {
            retSet.insert(x);
        }
    }
    return retSet;
}

bool DataSet::setDateById(int id, string date) {
    for (auto &x: this->dataContainner_) {
        if (x.id_ == id) {
            Item tmp = x;
            tmp.date_ = date;
            dataContainner_.erase(x);
            dataContainner_.insert(tmp);
            return true;
        }
    }
    return false;
}

bool DataSet::setNameById(int id, string name) {
    for (auto &x: dataContainner_) {
        if (x.id_ == id) {
            Item tmp = x;
            tmp.name_ = name;
            dataContainner_.erase(x);
            dataContainner_.insert(tmp);
            return true;
        }
    }
    return false;
}

bool DataSet::setTypeById(int id, int type) {
    for (auto &x: dataContainner_) {
        if (x.id_ == id) {
            Item tmp = x;
            tmp.type_ = type;
            dataContainner_.erase(x);
            dataContainner_.insert(tmp);
            return true;
        }
    }
    return false;
}

bool DataSet::setAmountById(int id, int amount) {
    for (auto &x: dataContainner_) {
        if (x.id_ == id) {
            Item tmp = x;
            tmp.amount_ = amount;
            dataContainner_.erase(x);
            dataContainner_.insert(tmp);
            return true;
        }
    }
    return false;
}

bool DataSet::setRemarkById(int id, string remark) {
    for (auto &x: dataContainner_) {
        if (x.id_ == id) {
            Item tmp = x;
            tmp.remark_ = remark;
            dataContainner_.erase(x);
            dataContainner_.insert(tmp);
            return true;
        }
    }
    return false;
}

bool DataSet::addItem(Item it) {
    dataContainner_.insert(it);
    return true;
}

bool DataSet::deleteItem(int id) {
    for (auto &x: dataContainner_) {
        if (x.id_ == id) {
            dataContainner_.erase(x);
            return true;
        }
    }
    return false;
}

bool DataSet::readData() {
    ifstream fin("cash.db");
    Item tempInput = Item();
    while (fin >> tempInput.id_
               >> tempInput.date_
               >> tempInput.name_
               >> tempInput.type_
               >> tempInput.amount_
               >> tempInput.remark_) {

        dataContainner_.insert(tempInput);
    }
    fin.close();
    return true;
}

bool DataSet::saveData() {
    ofstream fout("cash.db");
    for (auto const &x: dataContainner_) {
        fout << x.id_ << " "
             << x.date_ << " "
             << x.name_ << " "
             << x.type_ << " "
             << x.amount_ << " "
             << x.remark_ << endl;
    }
    fout.close();
    return true;
}

int DataSet::sumByDate(string minDate, string maxDate) {
    int retSum = 0;
    for (auto const &x: dataContainner_) {
        if (x.date_ >= minDate && x.date_ <= maxDate) {
            retSum += (x.type_ == INCOME ? x.amount_ : -x.amount_);
        }
    }
    return retSum;
}

vector <Item> DataSet::getSortedData(int method) {
    vector <Item> retVec;
    for (auto const &x: dataContainner_) {
        retVec.push_back(x);
    }
    if (method == 1) {
        sort(retVec.begin(), retVec.end(), [](const Item &it_1, const Item &it_2)->bool{
                return it_1.id_ < it_2.id_;
             });
    } else if (method == 2) {
        sort(retVec.begin(), retVec.end(), [](const Item &it_1, const Item &it_2)->bool{
            int date_1 = (it_1.date_[0] - '0') * 1e7 + (it_1.date_[1] - '0') * 1e6 + (it_1.date_[2] - '0')* 1e5 + (it_1.date_[3] - '0') * 1e4
            + (it_1.date_[5] - '0') * 1e3 + (it_1.date_[6] - '0') * 1e2
            + (it_1.date_[8] - '0') * 1e1 + (it_1.date_[9] -'0');
            int date_2 = (it_2.date_[0] - '0') * 1e7 + (it_2.date_[1] - '0') * 1e6 + (it_2.date_[2] - '0')* 1e5 + (it_2.date_[3] - '0') * 1e4
            + (it_2.date_[5] - '0') * 1e3 + (it_2.date_[6] - '0') * 1e2
            + (it_2.date_[8] - '0') * 1e1 + (it_2.date_[9] -'0');
            return date_1 < date_2;
             });
    } else if (method == 3) {
        sort(retVec.begin(), retVec.end(), [](const Item &it_1, const Item &it_2)->bool{
                return it_1.amount_ < it_2.amount_;
             });
    }
    return retVec;
}
