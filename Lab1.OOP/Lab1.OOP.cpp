#include <iostream>
#include <string>

class WeaponStrategy {
public:
    virtual std::string useWeapon() = 0;
    virtual ~WeaponStrategy() {}
};

class SwordStrategy : public WeaponStrategy {
public:
    std::string useWeapon() override {
        return "Sword";
    }
};

class BowStrategy : public WeaponStrategy {
public:
    std::string useWeapon() override {
        return "Bow with arrows";
    }
};

class CrossbowStrategy : public WeaponStrategy {
public:
    std::string useWeapon() override {
        return "Crossbow";
    }
};

class Character {
private:
    std::string type_;
    std::string color_;
    WeaponStrategy* weaponStrategy_;
public:
    Character(const std::string& type, const std::string& color)
        : type_(type), color_(color), weaponStrategy_(nullptr) {}

    void setWeaponStrategy(WeaponStrategy* weaponStrategy) {
        weaponStrategy_ = weaponStrategy;
    }

    std::string useWeapon() {
        if (weaponStrategy_ == nullptr) {
            return "No weapon";
        }
        else {
            return weaponStrategy_->useWeapon();
        }
    }

    std::string getType() const {
        return type_;
    }

    std::string getColor() const {
        return color_;
    }
};

int main() {
    Character king("King", "blue");
    king.setWeaponStrategy(new SwordStrategy());

    Character queen("Queen", "red");
    queen.setWeaponStrategy(new BowStrategy());

    Character knight("Knight", "yellow");
    knight.setWeaponStrategy(new CrossbowStrategy());

    Character troll("Troll", "green");
    troll.setWeaponStrategy(new SwordStrategy());

    std::cout << king.getType() << " (" << king.getColor() << ") uses " << king.useWeapon() << std::endl;
    std::cout << queen.getType() << " (" << queen.getColor() << ") uses " << queen.useWeapon() << std::endl;
    std::cout << knight.getType() << " (" << knight.getColor() << ") uses " << knight.useWeapon() << std::endl;
    std::cout << troll.getType() << " (" << troll.getColor() << ") uses " << troll.useWeapon() << std::endl;

    return 0;
}
