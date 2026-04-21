#include "CommentsManager.hpp"
#include <algorithm>
#include <iostream>

void CommentsManager::kickSpammer(int threshold_score) {
    chat_log_.erase(
        std::remove_if(chat_log_.begin(), chat_log_.end(),
            [this, threshold_score](const Comment& c) {
                auto it = reputation_.find(c.getUsername());
                if (it != reputation_.end()) {
                    return it->second > threshold_score;
                }
                return false;
            }
        ),
        chat_log_.end()
    );
}

void CommentsManager::printViolation() {
    bool hasViolation = false;
    std::for_each(chat_log_.begin(), chat_log_.end(),
        [this, &hasViolation](const Comment& c) {
            std::for_each(c.getWords().begin(), c.getWords().end(),
                [this, &hasViolation, &c](const std::string& word) {
                    if (blacklist_.find(word) != blacklist_.end()) {
                        std::cout << "kata \"" << word << "\" oleh akun \"" << c.getUsername() << "\"\n";
                        hasViolation = true;
                    }
                }
            );
        }
    );
    if (!hasViolation) {
        std::cout << "TIDAK ADA PELANGGARAN\n";
    }
}

std::string CommentsManager::quizWinner(const std::set<std::string>& passwords) {
    auto it = std::find_if(chat_log_.begin(), chat_log_.end(),
        [&passwords](const Comment& c) {
            auto word_it = std::find_if(c.getWords().begin(), c.getWords().end(),
                [&passwords](const std::string& word) {
                    return passwords.find(word) != passwords.end();
                }
            );
            return word_it != c.getWords().end();
        }
    );
    
    if (it != chat_log_.end()) {
        return it->getUsername();
    }
    return "BELUM ADA PEMENANG";
}

void CommentsManager::upVIPComment() {
    std::stable_partition(chat_log_.begin(), chat_log_.end(),
        [](const Comment& c) {
            return c.isVip();
        }
    );
}
