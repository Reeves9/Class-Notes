using System;

public class Game {
    public class Player {
        public string name;
        public int hp, coins, armor, dmg, lvl, exp, max_exp;

        public void Init() {
            Console.WriteLine("What is the player's name?");
            name = Console.ReadLine();
            hp = 100;
            coins = 0;
            armor = 0;
            dmg = 10;
            lvl = 0;
            exp = 0;
            max_exp = 40;
        }

        public void LevelUp() {
            lvl = lvl + 1;
            exp = 0;
            max_exp = max_exp + (lvl * 10);
            hp = hp + 10;
            dmg = dmg + 10;
        }
    }

    public class Enemy {
        public string type;
        public int hp, coins, armor, dmg, exp;

        public void Spawn(int enemyType) {
            if (enemyType == 0) {
                type = "goblin";
                hp = 40;
                coins = 10;
                armor = 0;
                dmg = 5;
                exp = 10;
            } else if (enemyType == 1) {
                type = "skeleton";
                hp = 50;
                coins = 20;
                armor = 10;
                dmg = 10;
                exp = 20;
            } else {
                type = "orc";
                hp = 70;
                coins = 40;
                armor = 20;
                dmg = 15;
                exp = 40;
            }
        }
    }

    public static void Main() {
        Player protag = new Player();
        Enemy badguy = new Enemy();
        protag.Init();
        int choice, hp_potion = 0, grenade = 0, evnt;
        Random rnd = new Random();
        Console.WriteLine("Welcome to console dungeon!");
        int floor = 1;
        Console.WriteLine($"{protag.name} opens his eyes to find himself in a dungeon with 50 floors");
        Console.WriteLine("He has a sword with him. With a sigh he heads towards the first floor");

        while (floor <= 50) {
            Console.WriteLine($"You are in floor {floor}. What do you do?");
            Console.WriteLine("1.Move  2.Rest");
            choice = Convert.ToInt32(Console.ReadLine());

            if (choice == 1) {
                evnt = rnd.Next(0, 3);  
                if (evnt == 0) {
                    Console.WriteLine("You found a treasure box!");
                    int money = rnd.Next(20, 50);
                    Console.WriteLine($"you find {money} coins");
                    protag.coins += money;
                    int treasure = rnd.Next(0, 3);
                    if (treasure == 0) {
                        Console.WriteLine("You found a health potion!");
                        hp_potion += 1;
                    } else if (treasure == 1) {
                        Console.WriteLine("You found armor!");
                        protag.armor += 20;
                    } else {
                        Console.WriteLine("You found a grenade!");
                        grenade += 1;
                    }
                } else if (evnt == 1) {
                    int enmy = rnd.Next(0, 3);
                    badguy.Spawn(enmy);
                    Console.WriteLine($"You encountered a {badguy.type}");

                    while (badguy.hp > 0) {
                        Console.WriteLine($"Enemy HP: {badguy.hp} Enemy Armor: {badguy.armor}");
                        Console.WriteLine($"Your HP: {protag.hp} Your Armor: {protag.armor}");
                        Console.WriteLine("What will you do?");
                        Console.WriteLine("1.Attack  2.Item");
                        choice = Convert.ToInt32(Console.ReadLine());

                        if (choice == 1) {
                            if (protag.armor >= badguy.dmg) {
                                protag.armor -= badguy.dmg;
                            } else if (protag.armor < badguy.dmg && protag.armor > 0) {
                                protag.hp -= badguy.dmg - protag.armor;
                                protag.armor = 0;
                            } else {
                                protag.hp -= badguy.dmg;
                            }

                            if (badguy.armor >= protag.dmg) {
                                badguy.armor -= protag.dmg;
                            } else if (badguy.armor < protag.dmg && badguy.armor > 0) {
                                badguy.hp -= protag.dmg - badguy.armor;
                                badguy.armor = 0;
                            } else {
                                badguy.hp -= protag.dmg;
                            }
                        } else if (choice == 2) {
                            Console.WriteLine($"1.Health Potion: {hp_potion}");
                            Console.WriteLine($"2.Grenade      : {grenade}");
                            choice = Convert.ToInt32(Console.ReadLine());
                            if (choice == 1) {
                                if (hp_potion != 0) {
                                    protag.hp += 30;
                                    hp_potion -= 1;
                                } else {
                                    Console.WriteLine("You don't have that item");
                                }
                            } else if (choice == 2) {
                                if (grenade != 0) {
                                    badguy.armor = 0;
                                    badguy.hp -= 20;
                                    if (badguy.hp < 0) {
                                        badguy.hp = 0;
                                    }
                                    grenade -= 1;
                                } else {
                                    Console.WriteLine("You don't have that item");
                                }
                            } else {
                                Console.WriteLine("Invalid Choice!");
                            }
                        } else {
                            Console.WriteLine("Invalid Choice!");
                        }

                        if (protag.hp <= 0) {
                            Console.WriteLine("Game Over! You died!");
                            return;
                        }
                    }

                    protag.coins += badguy.coins;
                    protag.exp += badguy.exp;
                    Console.WriteLine($"You defeated the {badguy.type}!");
                    Console.WriteLine($"You gained {badguy.coins} coins and {badguy.exp} experience!");

                    if (protag.exp >= protag.max_exp) {
                        protag.LevelUp();
                        Console.WriteLine("Level Up!");
                    }
                } else if (evnt == 2) {
                    // Merchant event
                    Console.WriteLine("You encountered a mysterious merchant!");
                    bool shopping = true;
                    
                    while (shopping) {
                        Console.WriteLine($"\nYour coins: {protag.coins}");
                        Console.WriteLine("Merchant's Wares:");
                        Console.WriteLine("1. Health Potion (30 coins)");
                        Console.WriteLine("2. Grenade (50 coins)");
                        Console.WriteLine("3. Leave shop");
                        
                        Console.WriteLine("\nWhat would you like to buy?");
                        choice = Convert.ToInt32(Console.ReadLine());
                        
                        switch (choice) {
                            case 1:
                                if (protag.coins >= 30) {
                                    protag.coins -= 30;
                                    hp_potion += 1;
                                    Console.WriteLine("You bought a Health Potion!");
                                    Console.WriteLine($"You have {hp_potion} Health Potions now.");
                                } else {
                                    Console.WriteLine("Not enough coins!");
                                }
                                break;
                            
                            case 2:
                                if (protag.coins >= 50) {
                                    protag.coins -= 50;
                                    grenade += 1;
                                    Console.WriteLine("You bought a Grenade!");
                                    Console.WriteLine($"You have {grenade} Grenades now.");
                                } else {
                                    Console.WriteLine("Not enough coins!");
                                }
                                break;
                            
                            case 3:
                                Console.WriteLine("\"Come back again!\" says the merchant as you leave.");
                                shopping = false;
                                break;
                            
                            default:
                                Console.WriteLine("Invalid choice!");
                                break;
                        }
                    }
                }
                floor++;
            } else if (choice == 2) {
                protag.hp += 20;
                Console.WriteLine("You rested and recovered 20 HP.");
            } else {
                Console.WriteLine("Invalid choice!");
            }
        }

        if (floor > 100) {
            Console.WriteLine("Congratulations! You cleared all 100 floors!");
        }
    }
}
