#include "PlayerCoach.hpp"
#include "Formatter.hpp"
#include <string>

PlayerCoach::PlayerCoach(std::string name,int age,std::string contractEnd,std::string position,int stamina,double rating,std::string coachingLicense,int yearsAsPlayer,bool isCurrentlyPlaying)
    // TODO: Constructor
    : ClubMember(name, age, contractEnd), Player(name,age,contractEnd,position, stamina, rating),Staff(name, age, contractEnd,coachingLicense, "Coaching"),yearsAsPlayer(yearsAsPlayer), isCurrentlyPlaying(isCurrentlyPlaying)
{
}

void PlayerCoach::work() const {
    // TODO: log menggunakan Formatter::log, dengan pesan yang berbeda tergantung isCurrentlyPlaying
    // Jika isCurrentlyPlaying -> Output: "[PlayerCoach] Name plays AND coaches from the pitch."
    // else -> Output: "[PlayerCoach] Name coaches from the touchline."
    if (isCurrentlyPlaying) {
        Formatter::log("PlayerCoach",name,"plays AND coaches from the pitch.");
    } else {
        Formatter::log("PlayerCoach",name,"coaches from the touchline.");
    }
}

double PlayerCoach::calculateRating() const {
    // TODO: return rating dengan rumus: rating * 0.7 + (yearsAsPlayer / 20.0) * 3.0
    return rating * 0.7 + (yearsAsPlayer / 20.0) * 3.0;
}

std::string PlayerCoach::getSpecialty() const {
    // TODO: return "Playing + Coaching (Player-Coach, yearsAsPlayer yrs exp)"
    std::string output = "Playing + Coaching (Player-Coach, " + std::to_string(yearsAsPlayer) + " yrs exp)";
    return output;
}

double PlayerCoach::calculateWage() const {
    // TODO: Jumlahkan calculateWage dari kelas Player and Staff
    return Player::calculateWage() + Staff::calculateWage();
}

std::string PlayerCoach::getProfile() const {
    // TODO: gunakan Formatter::makeRow dengan label "PlayerCoach" dan fields: Pos, Lic, Specialty, Wage
    return Formatter::makeRow("PlayerCoach",name,{{"Pos",position},{"Lic",coachingLicense},{"Specialty",getSpecialty()},{"Wage",Formatter::wage(calculateWage())}});
}

PlayerCoach::~PlayerCoach() {
    // TODO: log destruction menggunakan Formatter::log
    Formatter::log("~PlayerCoach",name,"dual-role contract terminated.");
}
