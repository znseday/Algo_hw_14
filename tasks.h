#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <vector>

extern bool IsDebugOutput;

#define MY_DEBUG_ONLY(x) { if(IsDebugOutput) {x}  }

std::string Task1(const std::string &in);
int Task2(std::vector<std::vector<int>> &m);
unsigned long Task3(unsigned N);
unsigned Task4(std::vector<std::vector<int>> &m);

unsigned Shed1(std::vector<std::vector<int>> &m);
std::vector<std::vector<int>> Shed2(const std::vector<std::vector<int>> &m);
//std::pair<std::vector<int>, std::vector<int>> Shed3(const std::vector<int> &A);
void Shed3(const std::vector<int> &A, std::vector<int> &L, std::vector<int> &R);
int Shed4(const std::vector<std::vector<int>> &m);

#endif // TASKS_H
