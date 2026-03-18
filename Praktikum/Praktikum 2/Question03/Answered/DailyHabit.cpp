#include "DailyHabit.hpp"

DailyHabit::DailyHabit(const std::string& name) : Activity(name) { streak = 0; }

DailyHabit::~DailyHabit() { cout << "Menghapus DailyHabit " << name << "\n"; }

int DailyHabit::complete() {
  streak += 1;
  return 10 * streak;
}

string DailyHabit::getStatus() const {
  return "[HABIT] " + name + " - Streak: " + to_string(streak);
}