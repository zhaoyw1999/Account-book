/**
 * Project-name    : account-book
 * Project-author  : Q17010123 Q17010122 Q17010125
 * Name            : main.cc
 * Module-author   : Q17010123
 * License         : MIT
 * Version         : 1.0.0
 * Description     : main process
 */

#include "models.h"
#include "views.h"
#include "controller.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    Views::showWelcome();
    DataSet program_controller;
    Views program_views;
    program_views.watch(program_controller);
    return 0;
}
