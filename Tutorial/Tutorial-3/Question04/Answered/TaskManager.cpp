#include "TaskManager.hpp"

void TaskManager::add(const string& id, const string& title, int priority, int duration) {
    tasks.push_back(Task(id, title, priority, duration));
}

void TaskManager::add(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::update(const string& id, const string& title, int priority, int duration) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [&id](const Task& t) {
        return t.getId() == id;
    });
    if (it != tasks.end()) {
        it->setTitle(title);
        it->setPriority(priority);
        it->setDuration(duration);
    }
}

bool TaskManager::remove(const string& id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [&id](const Task& t) {
        return t.getId() == id;
    });
    if (it != tasks.end()) {
        tasks.erase(it);
        return true;
    }
    return false;
}

const Task* TaskManager::find(const string& id) const {
    auto it = std::find_if(tasks.begin(), tasks.end(), [&id](const Task& t) {
        return t.getId() == id;
    });
    if (it != tasks.end()) {
        return &(*it);
    }
    return nullptr;
}

void TaskManager::sort() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        if (a.getPriority() != b.getPriority()) {
            return a.getPriority() > b.getPriority();
        }
        if (a.getDuration() != b.getDuration()) {
            return a.getDuration() < b.getDuration();
        }
        return a.getId() < b.getId();
    });
}

long long TaskManager::totalDuration(long long minPriority) const {
    return std::accumulate(tasks.begin(), tasks.end(), 0LL, [minPriority](long long sum, const Task& t) {
        if (t.getPriority() >= minPriority) {
            return sum + t.getDuration();
        }
        return sum;
    });
}

void TaskManager::print(const string& keyword) const {
    bool found = false;
    for (const auto& t : tasks) {
        if (t.getTitle().find(keyword) != std::string::npos) {
            std::cout << t.getId() << "|" << t.getTitle() << "|" << t.getPriority() << "|" << t.getDuration() << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "EMPTY\n";
    }
}

void TaskManager::print() const {
    if (tasks.empty()) {
        std::cout << "EMPTY\n";
        return;
    }
    for (const auto& t : tasks) {
        std::cout << t.getId() << "|" << t.getTitle() << "|" << t.getPriority() << "|" << t.getDuration() << "\n";
    }
}
