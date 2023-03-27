#include <iostream>
#include <string>
#include <map>

// Абстрактный класс, определяющий интерфейс для стратегий
class WeaponStrategy {
public:
    virtual std::string useWeapon() = 0;
};

// Конкретная стратегия для меча
class SwordStrategy : public WeaponStrategy {
public:
    std::string useWeapon() override {
        return "Удар мечом";
    }
};

// Конкретная стратегия для лука со стрелами
class BowStrategy : public WeaponStrategy {
public:
    std::string useWeapon() override {
        return "Выстрел из лука";
    }
};

// Конкретная стратегия для арбалета
class CrossbowStrategy : public WeaponStrategy {
public:
    std::string useWeapon() override {
        return "Выстрел из арбалета";
    }
};

// Абстрактный класс, определяющий интерфейс для персонажей
class Character {
protected:
    std::string color;
    WeaponStrategy* weaponStrategy; // Ссылка на стратегию оружия
public:
    virtual void setColor(std::string color) {
        this->color = color;
    }
    void setWeaponStrategy(WeaponStrategy* weaponStrategy) {
        this->weaponStrategy = weaponStrategy;
    }
    virtual void attack() = 0;
};

// Конкретный персонаж - король
class King : public Character {
public:
    void attack() override {
        std::cout << color << " король: " << weaponStrategy->useWeapon() << std::endl;
    }
};

// Конкретный персонаж - королева
class Queen : public Character {
public:
    void attack() override {
        std::cout << color << " королева: " << weaponStrategy->useWeapon() << std::endl;
    }
};

// Конкретный персонаж - рыцарь
class Knight : public Character {
public:
    void attack() override {
        std::cout << color << " рыцарь: " << weaponStrategy->useWeapon() << std::endl;
    }
};

// Конкретный персонаж - тролль
class Troll : public Character {
public:
    void attack() override {
        std::cout << color << " тролль: " << weaponStrategy->useWeapon() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); //Для адекватного отображения языка
    // Создаем объекты конкретных стратегий
    SwordStrategy swordStrategy;
    BowStrategy bowStrategy;
    CrossbowStrategy crossbowStrategy;

    // Создаем объекты конкретных персонажей
    King king;
    Queen queen;
    Knight knight;
    Troll troll;

    // Устанавливаем стратегии оружия для каждого персонажа
    king.setWeaponStrategy(&swordStrategy);
    queen.setWeaponStrategy(&bowStrategy);
    knight.setWeaponStrategy(&crossbowStrategy);
    troll.setWeaponStrategy(&swordStrategy);

    // Устанавливаем цвета для каждого персонажа
    king.setColor("Красный");
    queen.setColor("Зеленый");
    troll.setColor("Зеленый");

    // Атакуем выбранными персонажами
    king.attack();
    queen.attack();
    knight.attack();
    troll.attack();

    return 0;
}
